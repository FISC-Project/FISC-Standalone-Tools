/*
 * fisc_assembly.cpp
 *
 *  Created on: 08/10/2016
 *      Author: Miguel
 */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdint.h>
#include <fisc_assembly.h>
#include <fisc_opcodes.h>

extern void yyerror(const char * str);

std::vector<instruction_t> program;
std::vector<std::bitset<32> > program_bin;
std::string program_str;
std::string program_str_ihex;
std::map<std::string, unsigned long long> label_lst;

char validate_instruction(char * mnemonic, unsigned int opcode, arglist_t * args) {
	/* Grab instruction argument formats: */
	std::vector<afmt> * argfmts = 0;
	for (auto it = instruction_lookup.begin(); it != instruction_lookup.end(); ++it) {
		std::string mnemonic_str(mnemonic);

		std::transform(mnemonic_str.begin(), mnemonic_str.end(), mnemonic_str.begin(), ::tolower);
		std::transform(it->second.first.mnemonic.begin(), it->second.first.mnemonic.end(), it->second.first.mnemonic.begin(), ::tolower);

		if (!strcmp(it->second.first.mnemonic.c_str(), mnemonic_str.c_str())) {
			argfmts = &it->second.second;
			break;
		}
	}

	if(!argfmts) return 0;

	/* Check if it's valid: */
	if(argfmts->size() != args->argcount) return 0; /* Argument count does not match */

	for(int i = 0; i < argfmts->size(); i++) {
		afmt fmt = (*argfmts)[i];
		/* Check if fields match: */
		if(fmt.arg_type  != args->arguments[i]->arg_type)  return 0;
		if(fmt.is_offset != args->arguments[i]->is_offset) return 0;
	}
	return 1;
}

char make_instruction(char * mnemonic, arglist_t * args) {
	char success = 0;
	char accepts_nullargs = 0;
	if(!mnemonic) return success;
	instruction_t instr;

	for (auto it = instruction_lookup.begin(); it != instruction_lookup.end(); ++it) {
		std::string mnemonic_str(mnemonic);

		std::transform(mnemonic_str.begin(), mnemonic_str.end(), mnemonic_str.begin(), ::tolower);
		std::transform(it->second.first.mnemonic.begin(), it->second.first.mnemonic.end(), it->second.first.mnemonic.begin(), ::tolower);

		if (!strcmp(it->second.first.mnemonic.c_str(), mnemonic_str.c_str())) {
			success = 1;
			accepts_nullargs = it->second.first.nullargs;
			if(it->second.first.pseudo_opcode)
				instr.opcode = it->second.first.pseudo_opcode;
			else
				instr.opcode = it->first;
	    	break;
	    }
	}

	if(!success) {
		char msg[100];
		sprintf(msg, "Instruction '%s' is non existant.",  mnemonic);
		if(args)
			free_argument_list(args);
		free(mnemonic);
		yyerror(msg);
	}

	if((!accepts_nullargs && !args) || (accepts_nullargs && args)) {
		char msg[100];
		sprintf(msg, "Instruction '%s' is malformed.",  mnemonic);
		free(mnemonic);
		yyerror(msg);
		return success;
	}

	if(accepts_nullargs || (success = validate_instruction(mnemonic, instr.opcode, args))) {
		instr.mnemonic = mnemonic;
		if(!args) {
			/* This instruction requires no arguments. We still need to allocate them: */
			instr.args = make_argument_list(0);
		} else {
			instr.args = args;
		}
		program.push_back(instr);
	} else {
		char msg[100];
		sprintf(msg, "Instruction '%s' is malformed.",  mnemonic);
		free_argument_list(args);
		free(mnemonic);
		yyerror(msg);
	}
	return success;
}

void free_argument_list(arglist_t * args) {
	for(int i=0;i<args->argcount;i++) {
		argument_t * arg = args->arguments[i];
		free(arg);
	}
	free(args->arguments);
	free(args);
}

argument_t * make_argument(char arg_type, char is_offset, long long value) {
	argument_t * arg = (argument_t*)malloc(sizeof(argument_t));
	arg->arg_type = arg_type;
	arg->is_offset = is_offset;
	arg->value = value;
	arg->label = 0;
	arg->shift_quadrant = 0;
	return arg;
}

argument_t * make_argument(char arg_type, char is_offset, char * label) {
	argument_t * arg = (argument_t*)malloc(sizeof(argument_t));
	arg->arg_type = arg_type;
	arg->is_offset = is_offset;
	arg->value = -1;
	arg->label = label;
	arg->shift_quadrant = 0;
	return arg;
}

argument_t * make_argument(char arg_type, char is_offset, char * label, char shift_quadrant) {
	argument_t * arg = (argument_t*)malloc(sizeof(argument_t));
	arg->arg_type = arg_type;
	arg->is_offset = is_offset;
	arg->value = -1;
	arg->label = label;
	arg->shift_quadrant = shift_quadrant;
	return arg;
}

arglist_t * make_argument_list(unsigned int argcount, ...) {
	arglist_t * ret = (arglist_t*)malloc(sizeof(arglist_t));
	if(argcount)
		ret->arguments = (argument_t**)malloc(sizeof(argument_t**) * argcount);
	else
		ret->arguments = 0;
	ret->argcount = argcount;

	if(!argcount) return ret;

	va_list vl;
	va_start(vl, argcount);
	for(int i = 0; i < argcount; i++)
		ret->arguments[i] = (argument_t*)va_arg(vl, argument_t*);
	return ret;
}

void add_label(std::string label_name, unsigned int line_number) {
	if(label_lst.find(label_name) == label_lst.end())
		label_lst.insert(std::pair<std::string, unsigned int>(label_name, line_number));
}

void resolve_labels() {
	for(int i = 0; i < program.size(); i++) {
		for(int j = 0; j < program[i].args->argcount; j++) {
			argument_t * arg = program[i].args->arguments[j];
			if(arg->label) {
				/* Search in the label map for this label: */
				char found = 0;
				for (auto it = label_lst.begin(); it != label_lst.end(); ++it) {
					if (!strcmp(it->first.c_str(), arg->label)) {
				    	switch(program[i].opcode) {
				    	case BEQ: case BNE: case BLT: case BLE: case BGT: case BGE:
				    	case BLO: case BLS: case BHI: case BHS: case BMI: case BPL:
				    	case BVS: case BVC: case B: case BL: case CBNZ: case CBZ: case SINT:
				    	case LDRR: case LDRBR: case LDRHR: case LDRSWR: case LDXRR:
				    	case STRR: case STRBR: case STRHR: case STRWR: case STXRR: {
				    		switch(arg->shift_quadrant) {
								case 1: arg->value = ((it->second - i) & 0xFFFF) << 2; break; /* Insert lower 16 bits */
								case 16: arg->value = (((it->second - i) & 0xFFFF0000) >> 16) << 2; break; /* Insert 2nd 16 bits */
								case 32: arg->value = (((it->second - i) & 0xFFFF00000000) >> 32) << 2; break; /* Insert 3rd 16 bits */
								case 48: arg->value = (((it->second - i) & 0xFFFF000000000000) >> 48) << 2; break; /* Insert 4th 16 bits */
								case 0: default: arg->value = ((unsigned long long)(it->second - i)) << 2; break; /* Don't shift anything */
								}
				    		}
				    		break;
				    	default: {
				    		switch(arg->shift_quadrant) {
								case 1: arg->value = it->second & 0xFFFF; break; /* Insert lower 16 bits */
								case 16: arg->value = (it->second & 0xFFFF0000) >> 16; break; /* Insert 2nd 16 bits */
								case 32: arg->value = (it->second & 0xFFFF00000000) >> 32; break; /* Insert 3rd 16 bits */
								case 48: arg->value = (it->second & 0xFFFF000000000000) >> 48; break; /* Insert 4th 16 bits */
								case 0: default: arg->value = it->second; break; /* Don't shift anything */
				    		}
				    		}
				    		break;
				    	}
				    	found = 1;
				    	break;
				    }
				}
				if(!found) {
					char msg[100];
					sprintf(msg, "Could not find label '%s'.", arg->label);
					yyerror(msg);
				}
			}
		}
	}
}

extern int asm_lineno;

void adjust_labels_offset(unsigned int offset_amount) {
	asm_lineno += offset_amount - 1;
}

std::bitset<32> instruction_to_binary(instruction_t * instr) {
	unsigned shamt = 0;

	/* Special cases for LSL, LSR, MUL, SDIV and UDIV (because of the shamt field): */
	std::string mnemonic_str(instr->mnemonic);
	std::string mnemonic_lsl("LSL");
	std::string mnemonic_lsr("LSR");
	std::string mnemonic_mul("MUL");
	std::string mnemonic_sdiv("SDIV");
	std::string mnemonic_udiv("UDIV");

	std::transform(mnemonic_str.begin(),  mnemonic_str.end(),  mnemonic_str.begin(),  ::tolower);
	std::transform(mnemonic_lsl.begin(),  mnemonic_lsl.end(),  mnemonic_lsl.begin(),  ::tolower);
	std::transform(mnemonic_lsr.begin(),  mnemonic_lsr.end(),  mnemonic_lsr.begin(),  ::tolower);
	std::transform(mnemonic_mul.begin(),  mnemonic_mul.end(),  mnemonic_mul.begin(),  ::tolower);
	std::transform(mnemonic_sdiv.begin(), mnemonic_sdiv.end(), mnemonic_sdiv.begin(), ::tolower);
	std::transform(mnemonic_udiv.begin(), mnemonic_udiv.end(), mnemonic_udiv.begin(), ::tolower);

	if(!strcmp(mnemonic_str.c_str(), mnemonic_lsl.c_str()) || !strcmp(mnemonic_str.c_str(), mnemonic_lsr.c_str()))
		if(instr->args->argcount >= 3)
			shamt = instr->args->arguments[2]->value;

	if(!strcmp(mnemonic_str.c_str(), mnemonic_mul.c_str()) && instr->args->argcount >= 3)
		shamt = 0x1F;
	if(!strcmp(mnemonic_str.c_str(), mnemonic_sdiv.c_str()) && instr->args->argcount >= 3)
		shamt = 0x02;
	if(!strcmp(mnemonic_str.c_str(), mnemonic_udiv.c_str()) && instr->args->argcount >= 3)
		shamt = 0x03;

	switch(instruction_lookup[instr->opcode].first.fmt) {
	case IFMT_R: {
			ifmt_r_t fmt;

			fmt.opcode= instr->opcode;

			if(instr->args->argcount >= 3 && mnemonic_str != "lsl" && mnemonic_str!= "lsr")
				fmt.rm = instr->args->arguments[2]->value;
			else
				fmt.rm = 0;
			fmt.shamt = shamt;
			if(instr->args->argcount >= 2)
				fmt.rn = instr->args->arguments[1]->value;
			else
				fmt.rn = 0;

			if(instr->args->argcount > 0)
				fmt.rd = instr->args->arguments[0]->value;
			else
				fmt.rd = 0;
			return std::bitset<32>(*((uint32_t*)&fmt));
		}
		break;
	case IFMT_I: {
			ifmt_i_t fmt;
			fmt.opcode = instr->opcode;

			if(instr->args->argcount >= 3)
				fmt.alu_immediate = instr->args->arguments[2]->value;
			else if(instr->args->argcount >= 2 && (instr->opcode == NEGI || instr->opcode == NOTI)) /* Cover these 2 special cases */
				fmt.alu_immediate = instr->args->arguments[1]->value;
			else
				fmt.alu_immediate = 0;
			if(instr->args->argcount >= 2 && (instr->opcode != NEGI && instr->opcode != NOTI))
				fmt.rn = instr->args->arguments[1]->value;
			else
				fmt.rn = 0;

			if(instr->args->argcount > 0)
				fmt.rd = instr->args->arguments[0]->value;
			else
				fmt.rd = 0;

			/* Add instruction format */
			uint32_t * fmt_int = (uint32_t*)&fmt;
			*fmt_int |= 0x20000000;

			return std::bitset<32>(*fmt_int);
		}
		break;
	case IFMT_D: {
			ifmt_d_t fmt;
			fmt.opcode= instr->opcode;
			if(instr->args->argcount >= 3)
				fmt.dt_address = instr->args->arguments[2]->value >> 2;
			else
				fmt.dt_address = 0;
			switch(instruction_lookup[instr->opcode].first.width) {
				case 0:  fmt.op = 3; break;
				case 8:  fmt.op = 0; break;
				case 16: fmt.op = 1; break;
				case 32: fmt.op = 2; break;
				case 64: fmt.op = 3; break;
			}
			if(instr->args->argcount >= 2)
				fmt.rn = instr->args->arguments[1]->value;
			else
				fmt.rn = 0;

			if(instr->args->argcount > 0)
				fmt.rt = instr->args->arguments[0]->value;
			else
				fmt.rt = 0;

			/* Add instruction format */
			uint32_t * fmt_int = (uint32_t*)&fmt;
			*fmt_int |= 0x40000000;

			return std::bitset<32>(*fmt_int);
		}
		break;
	case IFMT_B: {
			ifmt_b_t fmt;
			fmt.opcode = instr->opcode;
			if(instr->args->argcount > 0)
				fmt.br_address = instr->args->arguments[0]->value;
			else
				fmt.br_address = 0;

			/* Add instruction format */
			uint32_t * fmt_int = (uint32_t*)&fmt;
			*fmt_int |= 0x60000000;

			return std::bitset<32>(*fmt_int);
		}
		break;
	case IFMT_CB: {
			ifmt_cb_t fmt;
			fmt.opcode = instr->opcode;

			if(!strcmp(mnemonic_str.c_str(), "cbnz") || !strcmp(mnemonic_str.c_str(), "cbz")) {
				/* Fill up instruction for CBNZ and CBZ: */
				if(instr->args->argcount >= 2)
					fmt.cond_br_address = instr->args->arguments[1]->value;
				else
					fmt.cond_br_address = 0;

				if(instr->args->argcount > 0)
					fmt.rt = instr->args->arguments[0]->value;
				else
					fmt.rt = 0;
			} else {
				/* Fill up instruction for b.cond: */
				if(instr->args->argcount > 0)
					fmt.cond_br_address = instr->args->arguments[0]->value;
				else
					fmt.cond_br_address = 0;
				fmt.rt = instr->opcode & 0b11111;
			}

			/* Add instruction format */
			uint32_t * fmt_int = (uint32_t*)&fmt;
			*fmt_int |= 0x80000000;

			return std::bitset<32>(*fmt_int);
		}
		break;
	case IFMT_IW: {
			ifmt_iw_t fmt;
			char lsl_val = 0;
			if(instr->args->argcount > 0) {
				if(instr->args->arguments[2]->value == 0)       lsl_val = 0;
				else if(instr->args->arguments[2]->value == 16) lsl_val = 1;
				else if(instr->args->arguments[2]->value == 32) lsl_val = 2;
				else if(instr->args->arguments[2]->value == 48) lsl_val = 3;
			}

			fmt.opcode = instr->opcode | lsl_val; /* Add the LSL value in the first 2 bits of the opcode */
			if(instr->args->argcount >= 2)
				fmt.mov_immediate = instr->args->arguments[1]->value;
			else
				fmt.mov_immediate = 0;

			if(instr->args->argcount >= 2)
				fmt.rt = instr->args->arguments[0]->value;
			else
				fmt.rt = 0;

			/* Add instruction format */
			uint32_t * fmt_int = (uint32_t*)&fmt;
			*fmt_int |= 0xA0000000;

			return std::bitset<32>(*fmt_int);
		}
		break;
	}
	return std::bitset<32>(0xFFFFFFFF);
}
