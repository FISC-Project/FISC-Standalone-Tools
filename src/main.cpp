#include <headers.h>
#include <map>
#include <utility>
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
	f.open(filename.c_str());
	f << source_code;
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

		/* Parse it:  */
		yyin = file;
		yyparse();
		resolve_labels();

		for(int i = 0; i < program.size(); i++) {
			printf("Instruction: %s ", program[i].mnemonic);
			for(int j=0;j<program[i].args->argcount;j++) {
				argument_t * arg = program[i].args->arguments[j];
				printf("%s %s: %d, ", !arg->arg_type ? "REGISTER" : "IMMEDIATE", arg->is_offset ? "(OFFSET)": "", arg->value);
			}
			printf("\n");
		}
	}
	return 0;
}
