#include <headers.h>
#include <map>
#include <utility>
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

void write_to_file_binary(string filename, std::vector<std::bitset<32> > * program_bin) {
	ofstream f;
	f.open(filename.c_str(), ios::binary);
	for(int i = 0; i <  program_bin->size(); i++) {
		uint32_t instr = (*program_bin)[i].to_ulong();
		uint32_t copy = instr;
		instr = ((copy & 0x000000FF) << 24) | ((copy & 0x0000FF00) << 8) | ((copy & 0x00FF0000) >> 8) | ((copy & 0xFF000000) >> 24);
		f.write( reinterpret_cast<const char*>(&instr), sizeof(uint32_t));
	}
	f.close();
}

int main(int argc, char ** argv) {
	if(argc > 1) {
		/* Read input source: */
		FILE * file = fopen(argv[1], "r");
		if(!file) {
			cout << "Could not open '" << argv[1] << "'\n";
			return -1;
		}

		if(argc > 2)
			cmdline_parse(argc, argv);
		if(cmd_has_opt('h')) {
			printf("\n>>>>>> FISC Assembler - Help <<<<<<\n> The available options are: \n"
					"1> -h : Show this message\n"
					"2> -o <filename> : Output pure binary file\n"
					"3> -a : Convert output into ASCII formatted output, also using newlines\n"
					"4> --stdio : Output only to the console the binary result\n"
					"5> --debug : Output Instructions and their attributes to the stdio\n"
					"\n>> NOTE: If no arguments are given, the Assembler will produce a.out\n"
					">> Also remember that you can combine these options\n\n");
			exit(-1);
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
			if(cmd_has_opt('a') || cmd_has_opt("stdio")) {
				/* Output format is in ASCII format. 0's are actually 30 decimal and 1's are 31 decimal. There is also a newline included at the end */
				program_str += tmp.to_string() + "\n";
			}
		}

		/* Now use the command line arguments: */
		if(cmd_has_opt("debug")) {
			printf("Dumping program: \n");
			for(int i = 0; i < program.size(); i++) {
				printf("%d- %s (0x%x) ", i+1, program[i].mnemonic, program[i].opcode);
				for(int j = 0; j < program[i].args->argcount; j++) {
					argument_t * arg = program[i].args->arguments[j];
					printf("%s %s: %d, ", !arg->arg_type ? "REGISTER" : "IMMEDIATE", arg->is_offset ? "(OFFSET)": "", arg->value);
				}
				printf("\n");
			}
		}

		if(cmd_has_opt("stdio")) {
			printf("%s", program_str.c_str());
		}

		if(cmd_has_opt('o')) {
			if(cmd_has_opt('a'))
				write_to_file(cmd_query('o').second, program_str);
			else
				write_to_file_binary(cmd_query('o').second, &program_bin);
		} else {
			if(cmd_has_opt('a'))
				write_to_file("a.o", program_str);
			else
				write_to_file_binary("a.o", &program_bin);
		}
	}
	return 0;
}
