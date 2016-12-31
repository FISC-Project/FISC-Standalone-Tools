#include <headers.h>
#include <map>
#include <utility>
#include <string>
#include <sstream>
#include <stdint.h>
#include <external_tool.h>
#include <fisc_assembly.h>

extern int yyparse();
/* Command line API: */
extern void cmdline_parse(int argc, char ** argv);
extern char cmd_has_opt(string opt);
extern char cmd_has_opt(char opt);
extern std::pair<string,string> cmd_query(string opt_query);
extern std::pair<char,string> cmd_query(char opt_query);

map<string, int> sym_table;

void sym_add(char * key, int token_id) {
	if(sym_table.find(key) == sym_table.end())
		sym_table.insert(pair<string, int>(key, token_id));
}

int sym_check_type(void) {
	yylval.sval = new char[strlen(yytext)+1];
	strcpy(yylval.sval, yytext);
	/* Fetch symbol type from map: */
	if(sym_table.find(yytext) != sym_table.end())
		return sym_table.at(yytext);
	else /* Return default type: */
		return IDENTIFIER;
}

void yyerror(const char * str) {
	printf("\n\n>> ERROR: %s in line %d at: \"%s\"", str, lineno + 1, yytext);
	printf("\n\nPress enter to exit...");
	exit(-1);
}

int yywrap(void) { /* called at end of input/lex */
	return 1; /* terminate now */
}

void comment(void) {
	int c;

	while ((c = yyparse()) != 0) {
		if (c == '*') {
			while ((c = yyparse()) == '*');

			if (c == '/') return;

			if (c == 0) break;
		}
	}
	yyerror("unterminated comment");
}

void write_to_file(string filename, string source_code) {
	ofstream f;
	f.open(filename.c_str(), ios::binary);
	f << source_code;
	f.close();
}

void write_to_file_binary(string filename, std::vector<std::bitset<32> > * program_bin, char split, uint32_t gran) {
	if(split) {
		switch(gran) {
		case 8: case 16: case 32: break;
		default:
			printf("> ERROR: Granularity value '%d' is invalid for pure binary files.\nAccepted values are: 8, 16, 32.\n(ASCII output files do not have this limitation)\n\n", gran);
			exit(-1);
			break;
		}
	}
	ofstream f;
	f.open(filename.c_str(), ios::binary);
	for(int i = 0; i <  program_bin->size(); i++) {
		if(split && (gran == 8 || gran == 16 || gran == 32)) {
			/* Split the pure binary using new line characters: */
			uint8_t newline = '\n';
			uint32_t instr = (*program_bin)[i].to_ulong();

			switch(gran) {
			case 8: {
					uint8_t copy1 = instr & 0x000000FF;
					uint8_t copy2 = (instr & 0x0000FF00) >> 8;
					uint8_t copy3 = (instr & 0x00FF0000) >> 16;
					uint8_t copy4 = (instr & 0xFF000000) >> 24;
					f.write(reinterpret_cast<const char*>(&copy4), sizeof(uint8_t));
					f.write(reinterpret_cast<const char*>(&newline), sizeof(uint8_t));
					f.write(reinterpret_cast<const char*>(&copy3), sizeof(uint8_t));
					f.write(reinterpret_cast<const char*>(&newline), sizeof(uint8_t));
					f.write(reinterpret_cast<const char*>(&copy2), sizeof(uint8_t));
					f.write(reinterpret_cast<const char*>(&newline), sizeof(uint8_t));
					f.write(reinterpret_cast<const char*>(&copy1), sizeof(uint8_t));
					f.write(reinterpret_cast<const char*>(&newline), sizeof(uint8_t));
				}
				break;
			case 16: {
					uint16_t copy1 = instr & 0x0000FFFF;
					uint16_t copy2 = (instr & 0xFFFF0000) >> 16;
					copy1 = ((copy1 & 0x00FF) << 8) | ((copy1 & 0xFF00) >> 8);
					copy2 = ((copy2 & 0x00FF) << 8) | ((copy2 & 0xFF00) >> 8);
					f.write(reinterpret_cast<const char*>(&copy2), sizeof(uint16_t));
					f.write(reinterpret_cast<const char*>(&newline), sizeof(uint8_t));
					f.write(reinterpret_cast<const char*>(&copy1), sizeof(uint16_t));
					f.write(reinterpret_cast<const char*>(&newline), sizeof(uint8_t));
				}
				break;
			case 32: {
					uint32_t copy = instr;
					copy = ((copy & 0x000000FF) << 24) | ((copy & 0x0000FF00) << 8) | ((copy & 0x00FF0000) >> 8) | ((copy & 0xFF000000) >> 24);
					f.write(reinterpret_cast<const char*>(&copy), sizeof(uint32_t));
					f.write(reinterpret_cast<const char*>(&newline), sizeof(uint8_t));
				}
				break;
			}
		} else {
			/* Just normally write the instruction: */
			uint32_t instr = (*program_bin)[i].to_ulong();
			uint32_t copy = instr;
			instr = ((copy & 0x000000FF) << 24) | ((copy & 0x0000FF00) << 8) | ((copy & 0x00FF0000) >> 8) | ((copy & 0xFF000000) >> 24);
			f.write(reinterpret_cast<const char*>(&instr), sizeof(uint32_t));
		}
	}
	f.close();
}

void help() {
	printf("\n>>>>>> FISC Assembler - Help <<<<<<\n> The available options are: \n"
			"1> -h : Show this message\n"
			"2> -o <filename> : Output pure binary file\n"
			"3> -a : Convert output into ASCII formatted output, also using newlines\n"
			"4> --stdio : Output only to the console the binary result\n"
			"5> --debug : Output Instructions and their attributes to the stdio\n"
			"6> -n : Don't produce an output file\n"
			"\n>> NOTE: If no arguments are given, the Assembler will produce a.out\n"
			">> Also remember that you can combine these options\n\n");
	exit(-1);
}

#include "lib/tinyexpr.h"

int main(int argc, char ** argv) {

	printf("%f\n", te_interp("1+4", 0));

	if(argc > 1) {
		if(argc > 2)
			cmdline_parse(argc, argv);
		else
			help();
		if(cmd_has_opt('h')) {
			help();
			return -1;
		}

		/* Read input source: */
		FILE * file = fopen(argv[1], "r");
		if(!file) {
			cout << "Could not open '" << argv[1] << "'\n";
			return -1;
		}

		/* Parse it:  */
		yyin = file;
		yyparse();
		resolve_labels();

		/* Convert to binary: */
		for(int i = 0; i < program.size(); i++) {
			std::bitset<32> tmp = instruction_to_binary(&program[i]);
			program_bin.push_back(tmp);
			/* Output format is in ASCII format. 0's are actually 30 decimal and 1's are 31 decimal. There is also a newline included at the end */
			program_str += tmp.to_string();
		}

		int program_str_len = 0;
		int gran = 8; /* Default granularity value is 8 bits */

		if((program_str_len = program_str.size())) {
			/* Split the program_str into small pieces by inserting new lines every X bits/bytes */
			if(cmd_has_opt('g')) {
				std::string gran_str = cmd_query('g').second;
				if(gran_str.find_first_not_of("0123456789") == string::npos)
					std::stringstream(gran_str) >> gran;
				else
					printf("\n>ERROR: Granularity value '%s' is invalid. Defaulting to value: %d\n", gran_str.c_str(), gran);
			}

			int ctr = gran;
			int grow = 0;
			for(int i = 0; i < program_str_len + grow; i++) {
				if(!ctr--) {
					program_str.insert(i, "\n");
					ctr = gran;
					grow++;
				}
			}
		}

		/* Now use the command line arguments: */
		if(cmd_has_opt("debug")) {
			printf("Dumping program: \n");
			for(int i = 0; i < program.size(); i++) {
				printf("%d- %s (0x%x) ", i+1, program[i].mnemonic, program[i].opcode);
				for(int j = 0; j < program[i].args->argcount; j++) {
					argument_t * arg = program[i].args->arguments[j];
					printf("%s %s: %I64d, ", !arg->arg_type ? "REGISTER" : "IMMEDIATE", arg->is_offset ? "(OFFSET)": "", arg->value);
				}
				printf("\n");
			}
		}

		if(cmd_has_opt("stdio"))
			printf("%s", program_str.c_str());

		if(!cmd_has_opt('n')) {
			if(cmd_has_opt('o')) {
				if(cmd_has_opt('a'))
					write_to_file(cmd_query('o').second, program_str);
				else
					write_to_file_binary(cmd_query('o').second, &program_bin, cmd_has_opt('g'), gran);
			} else {
				if(cmd_has_opt('a'))
					write_to_file("a.o", program_str);
				else
					write_to_file_binary("a.o", &program_bin, cmd_has_opt('g'), gran);
			}
		}
	} else {
		help();
	}
	return 0;
}
