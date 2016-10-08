/*
 * fisc_assembly.cpp
 *
 *  Created on: 08/10/2016
 *      Author: Miguel
 */
#include <stdarg.h>
#include <fisc_assembly.h>
#include <fisc_opcodes.h>
#include <string.h>

std::vector<instruction_t> program;
std::map<std::string, unsigned int> label_lst;

std::map<unsigned int, std::string> opcode_strings = {
		/* ARITHMETIC AND LOGIC */
		{ADD,   "ADD"}, {ADDI,   "ADDI"}, {ADDIS, "ADDIS"}, {ADDS,     "ADDS"},
		{SUB,   "SUB"}, {SUBI,   "SUBI"}, {SUBIS, "SUBIS"}, {SUBS,     "SUBS"},
		{MUL,   "MUL"}, {SMULH, "SMULH"}, {UMULH, "UMULH"},
		{SDIV, "SDIV"}, {UDIV,   "UDIV"},
		{AND,   "AND"}, {ANDI,   "ANDI"}, {ANDIS, "ANDIS"}, {ANDS,     "ANDS"},
		{ORR,   "ORR"}, {ORRI,   "ORRI"},
		{EOR,   "EOR"}, {EORI,   "EORI"},
		{LSL,   "LSL"}, {LSR,     "LSR"},
		{MOVK, "MOVK"}, {MOVZ,   "MOVZ"},
		/* BRANCHING */
		{B,       "B"}, {BCOND, "BCOND"}, {BL,       "BL"}, {BR,         "BR"}, {CBNZ, "CBNZ"}, {CBZ, "CBNZ"},
		/* LOAD AND STORE */
		{LDUR, "LDUR"}, {LDURB,  "LDUR"}, {LDURH, "LDURH"}, {LDURSW, "LDURSW"}, {LDXR, "LDXR"},
		{STUR, "STUR"}, {STURB, "STURB"}, {STURH, "STURH"}, {STURW,   "STURW"}, {STXR, "STXR"},
		/* PSEUDO INSTRUCTIONS */
		{CMP,   "CMP"}, {CMPI,   "CMPI"},
		{LDA,   "LDA"},
		{MOV,   "MOV"}
};

char make_instruction(char * mnemonic, arglist_t * args) {
	char success = 0;
	if(!args) return success;
	instruction_t instr;

	for (auto it = opcode_strings.begin(); it != opcode_strings.end(); ++it) {
		if (!strcmp(it->second.c_str(),mnemonic)) {
	    	success = 1;
	    	instr.opcode = it->first;
	    	break;
	    }
	}
	if(success) {
		instr.mnemonic = mnemonic;
		instr.args = args;
		program.push_back(instr);
	}
	return success;
}

argument_t * make_argument(char arg_type, char is_offset, unsigned int value) {
	argument_t * arg = (argument_t*)malloc(sizeof(argument_t));
	arg->arg_type = arg_type;
	arg->is_offset = is_offset;
	arg->value = value;
	arg->label = 0;
	return arg;
}

argument_t * make_argument(char arg_type, char is_offset, char * label) {
	argument_t * arg = (argument_t*)malloc(sizeof(argument_t));
	arg->arg_type = arg_type;
	arg->is_offset = is_offset;
	arg->value = -1;
	arg->label = label;
	return arg;
}

arglist_t * make_argument_list(unsigned int argcount, ...) {
	if(!argcount) return 0;

	arglist_t * ret = (arglist_t*)malloc(sizeof(arglist_t));
	ret->arguments = (argument_t**)malloc(sizeof(argument_t**) * argcount);
	ret->argcount = argcount;

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

extern void yyerror(const char * str);

void resolve_labels() {
	for(int i = 0; i < program.size(); i++) {
		for(int j = 0; j < program[i].args->argcount; j++) {
			argument_t * arg = program[i].args->arguments[j];
			if(arg->label) {
				/* Search in the label map for this label: */
				char found = 0;
				for (auto it = label_lst.begin(); it != label_lst.end(); ++it) {
					if (!strcmp(it->first.c_str(), arg->label)) {
				    	arg->value = it->second;
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
