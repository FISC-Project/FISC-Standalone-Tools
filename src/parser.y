%{
	#include <headers.h>
	int asm_lineno = 0;
%}

%union {
	long long         llval;
	int               ival;
	unsigned int      uival;
	float             fval;
	char           *  sval;
	struct arglist * arglist_t;
}

%type <arglist_t> args

%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING

%token <ival> I_CONSTANT <fval> F_CONSTANT <sval> D_CONSTANT STRING_LITERAL IDENTIFIER

/* Opcodes: */
/* ARITHMETIC AND LOGIC */
%token<sval> ADD ADDI ADDIS ADDS
%token<sval> SUB SUBI SUBIS SUBS
%token<sval> MUL SMULH UMULH
%token<sval> SDIV UDIV
%token<sval> AND ANDI ANDIS ANDS
%token<sval> ORR ORRI
%token<sval> EOR EORI
%token<sval> LSL LSR
%token<sval> MOVK MOVZ
/* BRANCHING */
%token<sval> B BCOND BL BR CBNZ CBZ
/* LOAD AND STORE */
%token<sval> LDUR LDURB LDURH LDURSW LDXR
%token<sval> STUR STURB STURH STURW STXR
/* PSEUDO INSTRUCTIONS */
%token<sval> CMP CMPI
%token<sval> LDA
%token<sval> MOV

%token<uival> REGISTER
%token<llval> IMMEDIATE

%start program
%%
program
	:
	| instruction program
	| special_cases program
	| label program
	;

instruction
	: IDENTIFIER args { make_instruction($1, $2); }

args
	: 
	  REGISTER ',' REGISTER ',' REGISTER   eol { $$ = make_argument_list(3, make_argument(0, 0, $1), make_argument(0, 0, $3), make_argument(0, 0, $5)); }
	| REGISTER ',' REGISTER ',' IMMEDIATE  eol { $$ = make_argument_list(3, make_argument(0, 0, $1), make_argument(0, 0, $3), make_argument(1, 0, $5)); }
	| REGISTER ',' REGISTER ',' IDENTIFIER eol { $$ = make_argument_list(3, make_argument(0, 0, $1), make_argument(0, 0, $3), make_argument(1, 0, $5)); }
	| REGISTER ',' REGISTER                eol { $$ = make_argument_list(2, make_argument(0, 0, $1), make_argument(0, 0, $3)); }
	| REGISTER ',' '[' REGISTER ',' IMMEDIATE ']' eol { $$ = make_argument_list(3, make_argument(0, 0, $1), make_argument(0, 1, $4), make_argument(1, 1, $6)); }
	| REGISTER ',' '[' REGISTER ',' IDENTIFIER ']'eol { $$ = make_argument_list(3, make_argument(0, 0, $1), make_argument(0, 1, $4), make_argument(1, 1, $6)); }
	| REGISTER ',' REGISTER ',' '[' REGISTER  ']' eol { $$ = make_argument_list(3, make_argument(0, 0, $1), make_argument(0, 0, $3), make_argument(0, 1, $6)); }
	| REGISTER ',' IDENTIFIER eol { $$ = make_argument_list(2, make_argument(0, 0, $1), make_argument(1, 0, $3)); }
	| REGISTER ',' IMMEDIATE  eol { $$ = make_argument_list(2, make_argument(0, 0, $1), make_argument(1, 0, $3)); }
	| REGISTER                eol { $$ = make_argument_list(1, make_argument(0, 0, $1));                          }
	| IDENTIFIER              eol { $$ = make_argument_list(1, make_argument(1, 0, $1));                          }
	| IMMEDIATE               eol { $$ = make_argument_list(1, make_argument(1, 0, $1));                          }
	| REGISTER ',' IMMEDIATE ','  LSL IMMEDIATE  eol { $$ = make_argument_list(3, make_argument(0, 0, $1), make_argument(1, 0, $3), make_argument(1, 0, $6)); }
	| REGISTER ',' IMMEDIATE ','  LSL IDENTIFIER eol { $$ = make_argument_list(3, make_argument(0, 0, $1), make_argument(1, 0, $3), make_argument(1, 0, $6)); }
	| REGISTER ',' IDENTIFIER ',' LSL IMMEDIATE  eol { $$ = make_argument_list(3, make_argument(0, 0, $1), make_argument(1, 0, $3), make_argument(1, 0, $6)); }
	| REGISTER ',' IDENTIFIER ',' LSL IDENTIFIER eol { $$ = make_argument_list(3, make_argument(0, 0, $1), make_argument(1, 0, $3), make_argument(1, 0, $6)); }
			
eol:
	';' { asm_lineno++; }
	|   { asm_lineno++; }
	
label: IDENTIFIER ':' { add_label($1, asm_lineno); }

special_cases:
	  CMP REGISTER ',' REGISTER eol { make_instruction((char*)"SUBS", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, $2), make_argument(0, 0, $4))); }
	| CMPI REGISTER ',' IDENTIFIER eol { make_instruction((char*)"SUBIS", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, (long long)31))); }
	| CMPI REGISTER ',' IMMEDIATE eol { make_instruction((char*)"SUBIS", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, (long long)31))); }
	| LDA REGISTER ',' REGISTER ',' IDENTIFIER eol { make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, $6))); }
	| LDA REGISTER ',' REGISTER ',' IMMEDIATE eol { make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, $6))); }
	| MOV REGISTER ',' REGISTER eol { make_instruction((char*)"ADDI",   make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, (long long)31))); }
		
%%
