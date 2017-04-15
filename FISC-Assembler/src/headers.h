#ifndef HEADERS_H_
#define HEADERS_H_

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "parser.tab.h"
#include <vector>
#include <fisc_assembly.h>

using namespace std;

#define DEBUG 0

extern "C" int yylex();
#ifdef YYPARSE_PARAM
extern "C" int yyparse();
#endif /* ! YYPARSE_PARAM */
extern "C" int yywrap();
extern void yyerror(const char * str);
extern void comment(void);
extern void sym_add(char * key, int token_id);
extern int sym_check_type(void);

extern FILE * yyin;
extern int lineno;
extern int asm_lineno;
extern char * yytext;

#endif
