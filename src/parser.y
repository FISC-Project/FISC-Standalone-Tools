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
%token<sval> LDR LDRB LDRH LDRSW LDXR
%token<sval> STR STRB STRH STRW STXR
/* CPU STATUS CONTROL */

/* INTERRUPTS */

/* VIRTUAL MEMORY */

/* PSEUDO INSTRUCTIONS */
%token<sval> CMP CMPI
%token<sval> LDA
%token<sval> MOV MOVI MOVIW
%token<sval> INC DEC
%token<sval> NORR NORRI
%token<sval> RET
%token<sval> PUSH PUSHI POP
%token<sval> SWP
%token<sval> NAND NANDI
%token<sval> NEOR NEORI
%token<sval> HALT
%token<sval> NOP
%token<sval> BW
%token<sval> ONE ONES ZERO
%token<sval> ALIGN8 ALIGN16 ALIGN32 ALIGN64 ALIGN128 ALIGN256 
%token<sval> ALIGN512 ALIGN1024 ALIGN2048 ALIGN4096 ALIGN8192
%token<sval> UNALI8 UNALI16 UNALI32 UNALI64 UNALI128 UNALI256 
%token<sval> UNALI512 UNALI1024 UNALI2048 UNALI4096 UNALI8192

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
	| eol { $$ = 0; }
	
eol:
	';' { asm_lineno++; }
	|   { asm_lineno++; }
	
label: IDENTIFIER ':' { add_label($1, asm_lineno); }

special_cases: // **** PSEUDO INSTRUCTIONS' DECLARATION HERE: ****
	  CMP REGISTER ',' REGISTER    eol { 
		  make_instruction((char*)"SUBS", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, $2), make_argument(0, 0, $4))); 
		  make_instruction((char*)"ADD",  make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		  adjust_labels_offset(2);
	  }
	| CMPI REGISTER ',' IDENTIFIER eol { 
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, $4, 1),  make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, $4, 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, $4, 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, $4, 48), make_argument(1, 0, (long long)48))); 
		make_instruction((char*)"ADD",  make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD",  make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"SUBS", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, $2), make_argument(0, 0, (long long)9))); 
		make_instruction((char*)"ADD",  make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		adjust_labels_offset(8);
	}
	| CMPI REGISTER ',' IMMEDIATE  eol { 
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, (long long)9),  make_argument(1, 0, $4 & 0xFFFF),  make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9),  make_argument(1, 0, ($4 & 0xFFFF0000) >> 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9),  make_argument(1, 0, ($4 & 0xFFFF00000000) >> 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9),  make_argument(1, 0, ($4 & 0xFFFF000000000000) >> 48), make_argument(1, 0, (long long)48))); 
		make_instruction((char*)"ADD",  make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD",  make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"SUBS", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, $2), make_argument(0, 0, (long long)9))); 
		make_instruction((char*)"ADD",  make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		adjust_labels_offset(8);
	}
	| LDA REGISTER ',' REGISTER ',' IDENTIFIER eol { make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, $6))); }
	| LDA REGISTER ',' REGISTER ',' IMMEDIATE eol  { make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, $6))); }
	| MOV REGISTER ',' REGISTER eol { make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, (long long)0))); }
	| MOVI REGISTER ',' IDENTIFIER eol { make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, (long long)31), make_argument(1, 0, $4))); }
	| MOVI REGISTER ',' IMMEDIATE  eol { make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, (long long)31), make_argument(1, 0, (long long)$4))); }
	| MOVIW REGISTER ',' IDENTIFIER eol {
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, $2), make_argument(1, 0, $4, 1),  make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, $2), make_argument(1, 0, $4, 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, $2), make_argument(1, 0, $4, 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, $2), make_argument(1, 0, $4, 48), make_argument(1, 0, (long long)48))); 
		make_instruction((char*)"ADD",  make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD",  make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		adjust_labels_offset(6);
	}
	| MOVIW REGISTER ',' IMMEDIATE  eol { 
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, $2), make_argument(1, 0, $4 & 0xFFFF), make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, $2), make_argument(1, 0, ($4 & 0xFFFF0000) >> 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, $2), make_argument(1, 0, ($4 & 0xFFFF00000000) >> 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, $2), make_argument(1, 0, ($4 & 0xFFFF000000000000) >> 48), make_argument(1, 0, (long long)48))); 
		make_instruction((char*)"ADD",  make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD",  make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		adjust_labels_offset(6);
	}
	| LSL REGISTER ',' REGISTER ',' IMMEDIATE eol  { make_instruction((char*)"LSL",   make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, $6))); }
	| INC REGISTER eol { make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $2), make_argument(1, 0, (long long)1))); }
	| DEC REGISTER eol { make_instruction((char*)"SUBI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $2), make_argument(1, 0, (long long)1))); }
	| NORR REGISTER ',' REGISTER ',' REGISTER eol { 
		make_instruction((char*)"ORR", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(0, 0, $6))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, $2), make_argument(0, 0, $2))); 
		adjust_labels_offset(2);
	}
	| NORRI REGISTER ',' REGISTER ',' IMMEDIATE eol { 
		make_instruction((char*)"ORRI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, $6))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, $2), make_argument(0, 0, $2))); 
		adjust_labels_offset(2);
	}
	| NORRI REGISTER ',' REGISTER ',' IDENTIFIER eol { 
		make_instruction((char*)"ORRI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, $6))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, $2), make_argument(0, 0, $2))); 
		adjust_labels_offset(2);
	}
	| NAND REGISTER ',' REGISTER ',' REGISTER eol { 
		make_instruction((char*)"AND", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(0, 0, $6))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, $2), make_argument(0, 0, $2))); 
		adjust_labels_offset(2);
	}
	| NANDI REGISTER ',' REGISTER ',' IMMEDIATE eol { 
		make_instruction((char*)"ANDI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, $6))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, $2), make_argument(0, 0, $2))); 
		adjust_labels_offset(2);
	}
	| NANDI REGISTER ',' REGISTER ',' IDENTIFIER eol { 
		make_instruction((char*)"ANDI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, $6))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, $2), make_argument(0, 0, $2))); 
		adjust_labels_offset(2);
	}
	| NEOR REGISTER ',' REGISTER ',' REGISTER eol { 
		make_instruction((char*)"EOR", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(0, 0, $6))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, $2), make_argument(0, 0, $2))); 
		adjust_labels_offset(2);
	}
	| NEORI REGISTER ',' REGISTER ',' IMMEDIATE eol { 
		make_instruction((char*)"EORI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, $6))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, $2), make_argument(0, 0, $2))); 
		adjust_labels_offset(2);
	}
	| NEORI REGISTER ',' REGISTER ',' IDENTIFIER eol { 
		make_instruction((char*)"EORI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, $6))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, $2), make_argument(0, 0, $2))); 
		adjust_labels_offset(2);
	}
	| RET eol { make_instruction((char*)"BR", make_argument_list(1, make_argument(0, 0, (long long)30))); }
	| PUSH REGISTER eol {
		make_instruction((char*)"SUBI", make_argument_list(3, make_argument(0, 0, (long long)28), make_argument(0, 0, (long long)28), make_argument(1, 0, (long long)8)));
		make_instruction((char*)"STR", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 1, (long long)28), make_argument(1, 1, (long long)0)));
		adjust_labels_offset(2);
	}
	| PUSHI IMMEDIATE eol {
		make_instruction((char*)"SUBI", make_argument_list(3, make_argument(0, 0, (long long)28), make_argument(0, 0, (long long)28), make_argument(1, 0, (long long)8)));
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, $2 & 0xFFFF), make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ($2 & 0xFFFF0000) >> 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ($2 & 0xFFFF00000000) >> 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ($2 & 0xFFFF000000000000) >> 48), make_argument(1, 0, (long long)48))); 		
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));		
		make_instruction((char*)"STR", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(0, 1, (long long)28), make_argument(1, 1, (long long)0)));
		adjust_labels_offset(8);
	}
	| PUSHI IDENTIFIER eol {
		make_instruction((char*)"SUBI", make_argument_list(3, make_argument(0, 0, (long long)28), make_argument(0, 0, (long long)28), make_argument(1, 0, (long long)8)));
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, $2, 1),  make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, $2, 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, $2, 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, $2, 48), make_argument(1, 0, (long long)48))); 
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"STR", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(0, 1, (long long)28), make_argument(1, 1, (long long)0)));
		adjust_labels_offset(8);
	}
	| POP REGISTER eol {
		make_instruction((char*)"LDR", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 1, (long long)28), make_argument(1, 1, (long long)0)));
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (long long)28), make_argument(0, 0, (long long)28), make_argument(1, 0, (long long)8)));
		adjust_labels_offset(2);
	}
	| SWP REGISTER ',' REGISTER eol {
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(0, 0, $2), make_argument(1, 0, (long long)0)));
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, $4), make_argument(1, 0, (long long)0)));
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, $4), make_argument(0, 0, (long long)9), make_argument(1, 0, (long long)0)));
		adjust_labels_offset(3);	
	}
	| HALT eol { make_instruction((char*)"B", make_argument_list(1, make_argument(1, 0, (long long)0))); }
	| NOP  eol { make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31))); }
	| BW IMMEDIATE eol { 
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, $2 & 0xFFFF), make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ($2 & 0xFFFF0000) >> 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ($2 & 0xFFFF00000000) >> 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ($2 & 0xFFFF000000000000) >> 48), make_argument(1, 0, (long long)48))); 
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"BL", make_argument_list(1, make_argument(1, 0, 1)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (long long)30), make_argument(0, 0, (long long)30), make_argument(1, 0, (long long)3)));
		make_instruction((char*)"BR", make_argument_list(1, make_argument(0, 0, (long long)9)));
		adjust_labels_offset(10);
	}
	| BW IDENTIFIER eol { 
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, $2, 1), make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, $2, 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, $2, 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, $2, 48), make_argument(1, 0, (long long)48))); 
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"BL", make_argument_list(1, make_argument(1, 0, 1)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (long long)30), make_argument(0, 0, (long long)30), make_argument(1, 0, (long long)3)));
		make_instruction((char*)"BR", make_argument_list(1, make_argument(0, 0, (long long)9)));
		adjust_labels_offset(10);
	}
	| ONE REGISTER eol {
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, (long long)31), make_argument(1, 0, (long long)1)));
	}
	| ONES REGISTER eol {
		make_instruction((char*)"SUBI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, (long long)31), make_argument(1, 0, (long long)1)));
	}
	| ZERO REGISTER eol {
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, $2), make_argument(0, 0, (long long)31), make_argument(1, 0, (long long)0)));
	}
	| ALIGN16 REGISTER eol {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)1))); 
	}
	| ALIGN32 REGISTER eol {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)2))); 
	}
	| ALIGN64 REGISTER eol {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)3))); 
	}
	| ALIGN128 REGISTER eol {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)4))); 
	}
	| ALIGN256 REGISTER eol {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)5))); 
	}
	| ALIGN512 REGISTER eol {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)6))); 
	}
	| ALIGN1024 REGISTER eol {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)7))); 
	}
	| ALIGN2048 REGISTER eol {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)8))); 
	}
	| ALIGN4096 REGISTER eol {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)9))); 
	}
	| ALIGN8192 REGISTER eol {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)10))); 
	}
	| UNALI16 REGISTER eol {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)1))); 
	}
	| UNALI32 REGISTER eol {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)2))); 
	}
	| UNALI64 REGISTER eol {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)3))); 
	}
	| UNALI128 REGISTER eol {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)4))); 
	}
	| UNALI256 REGISTER eol {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)5))); 
	}
	| UNALI512 REGISTER eol {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)6))); 
	}
	| UNALI1024 REGISTER eol {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)7))); 
	}
	| UNALI2048 REGISTER eol {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)8))); 
	}
	| UNALI4096 REGISTER eol {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)9))); 
	}
	| UNALI8192 REGISTER eol {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)$2), make_argument(0, 0, (long long)$2), make_argument(1, 0, (long long)10))); 
	}
%%
