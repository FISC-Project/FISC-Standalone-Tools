%{
	#include <headers.h>
	int lineno;
%}

%option caseless

%e  1019
%p  2807
%n  371
%k  284
%a  1213
%o  1117

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
B   [0-1]
HV  [a-fA-F0-9xXzZ]
HP  (0[xX])
BP  (0[bB])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

%%

	/* Comments: */
"/*"	{ comment(); }
"//".*	{ /* consume //-comment */ }

	/* Single characters: */
";"	 return ';';
"("	 return '(';
")"	 return ')';
"{"	 return '{';
"}"	 return '}';
"'"	 return '\'';
"/"	 return '/';
"\\" return '\\';
"["	 return '[';
"]"	 return ']';
"_"	 return '_';
"."	 return '.';
"?"	 return '?';
","  return ',';
"#"	 return '#';
":"  return ':';

	/* Operators: */
"+"	 return '+';
"-"	 return '-';
"*"	 return '*';
"%"	 return '%';
"="	 return '=';
"!"	 return '!';
"&"	 return '&';
"|"	 return '|';
"^"	 return '^';
"~"	 return '~';
">"	 return '>';
"<"	 return '<';

	/* Pseudoinstructions: */
CMP    { yylval.sval = strdup(yytext); return CMP;    }
CMPI   { yylval.sval = strdup(yytext); return CMPI;   }
LDA    { yylval.sval = strdup(yytext); return LDA;    }
MOV    { yylval.sval = strdup(yytext); return MOV;    }
MOVI   { yylval.sval = strdup(yytext); return MOVI;   }
INC    { yylval.sval = strdup(yytext); return INC;    }
DEC    { yylval.sval = strdup(yytext); return DEC;    }
NORR   { yylval.sval = strdup(yytext); return NORR;   }
NORRI  { yylval.sval = strdup(yytext); return NORRI;  }
RET    { yylval.sval = strdup(yytext); return RET;    }
PUSH   { yylval.sval = strdup(yytext); return PUSH;   }
PUSHI  { yylval.sval = strdup(yytext); return PUSHI;  }
POP    { yylval.sval = strdup(yytext); return POP;    }
SWP    { yylval.sval = strdup(yytext); return SWP;    }
NAND   { yylval.sval = strdup(yytext); return NAND;   }
NANDI  { yylval.sval = strdup(yytext); return NANDI;  }
NEOR   { yylval.sval = strdup(yytext); return NEOR;   }
NEORI  { yylval.sval = strdup(yytext); return NEORI;  }
HALT   { yylval.sval = strdup(yytext); return HALT;   }
NOP    { yylval.sval = strdup(yytext); return NOP;    }
LDPC   { yylval.sval = strdup(yytext); return LDPC;   }
BW     { yylval.sval = strdup(yytext); return BW;     }

	/* MSR and MRS Operands: */
CPSR      { yylval.uival = 0;  return REGISTER; }
CPSR_F    { yylval.uival = 1;  return REGISTER; }
CPSR_FN   { yylval.uival = 2;  return REGISTER; }
CPSR_FZ   { yylval.uival = 3;  return REGISTER; }
CPSR_FV   { yylval.uival = 4;  return REGISTER; }
CPSR_FC   { yylval.uival = 5;  return REGISTER; }
CPSR_AE   { yylval.uival = 6;  return REGISTER; }
CPSR_PG   { yylval.uival = 7;  return REGISTER; }
CPSR_IEN  { yylval.uival = 8;  return REGISTER; }
CPSR_IEN0 { yylval.uival = 9; return REGISTER; }
CPSR_IEN1 { yylval.uival = 10; return REGISTER; }
CPSR_MODE { yylval.uival = 11; return REGISTER; }
SPSR      { yylval.uival = 16; return REGISTER; }
SPSR_F    { yylval.uival = 17; return REGISTER; }
SPSR_FN   { yylval.uival = 18; return REGISTER; }
SPSR_FZ   { yylval.uival = 19; return REGISTER; }
SPSR_FV   { yylval.uival = 20; return REGISTER; }
SPSR_FC   { yylval.uival = 21; return REGISTER; }
SPSR_AE   { yylval.uival = 22; return REGISTER; }
SPSR_PG   { yylval.uival = 23; return REGISTER; }
SPSR_IEN  { yylval.uival = 24; return REGISTER; }
SPSR_IEN0 { yylval.uival = 25; return REGISTER; }
SPSR_IEN1 { yylval.uival = 26; return REGISTER; }
SPSR_MODE { yylval.uival = 27; return REGISTER; }

LSL       { return LSL; } /* Not a pseudoinstruction */
	
	/* Arguments (for example, a Register): */
X[0-9]+          { yylval.uival = atoi(yytext+1);            return REGISTER;  } // Normal Register
IP0              { yylval.uival = 16;                        return REGISTER;  } // Temporary Register
IP1              { yylval.uival = 17;                        return REGISTER;  } // Temporary Register
XZR              { yylval.uival = 31;                        return REGISTER;  } // Register Zero
SP               { yylval.uival = 28;                        return REGISTER;  } // Stack Pointer
FP               { yylval.uival = 29;                        return REGISTER;  } // Frame Pointer
LR               { yylval.uival = 30;                        return REGISTER;  } // Return Address
{NZ}{D}*{IS}?    { yylval.llval = strtoull(yytext, 0, 10);   return IMMEDIATE; } // Immediate Decimal (normal number)
{HP}{H}+?        { yylval.llval = strtoull(yytext, 0, 16);   return IMMEDIATE; } // Immediate Hexadecimal
{BP}{B}+?        { yylval.llval = strtoull(yytext+2, 0, 2);  return IMMEDIATE; } // Immediate Binary
"0"{O}*{IS}?     { yylval.llval = strtoull(yytext+1, 0, 8);  return IMMEDIATE; } // Immediate Octal
"-"{NZ}{D}*{IS}? { yylval.llval = strtoull(yytext, 0, 10);   return IMMEDIATE; } // Immediate Negative Decimal (normal number)
"-"{HP}{H}+?     { yylval.llval = strtoull(yytext, 0, 16);   return IMMEDIATE; } // Immediate Negative Hexadecimal
"-"{BP}{B}+?     { yylval.llval = -strtoull(yytext+3, 0, 2); return IMMEDIATE; } // Immediate Negative Binary
"-0"{O}*{IS}?    { yylval.llval = -strtoull(yytext+1, 0, 8); return IMMEDIATE; } // Immediate Negative Octal

{D}+{E}{FS}?					{ yylval.fval = atof(yytext); return F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?			{ yylval.fval = atof(yytext); return F_CONSTANT; }
{D}+"."{E}?{FS}?				{ yylval.fval = atof(yytext); return F_CONSTANT; }
{HP}{H}+{P}{FS}?				{ yylval.fval = atof(yytext); return F_CONSTANT; }
{HP}{H}*"."{H}+{P}{FS}?			{ yylval.fval = atof(yytext); return F_CONSTANT; }
{HP}{H}+"."{P}{FS}?				{ yylval.fval = atof(yytext); return F_CONSTANT; }

({SP}?\"([^"\\\n]|{ES})*\")+    { yylval.sval = new char[strlen(yytext)+1]; strcpy(yylval.sval, yytext); return STRING_LITERAL; }
{L}{A}*							{ return sym_check_type(); }
.								;
[ \t\n]        					lineno++;

%%
