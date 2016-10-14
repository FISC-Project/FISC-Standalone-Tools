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
"/*"			{ comment(); }
"//".*			{ /* consume //-comment */ }

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

	/* Keywords/Opcodes: */
	/*ADD    { yylval.sval = strdup(yytext); return ADD;    }
	ADDI   { yylval.sval = strdup(yytext); return ADDI;   }
	ADDIS  { yylval.sval = strdup(yytext); return ADDIS;  }
	ADDS   { yylval.sval = strdup(yytext); return ADDS;   }
	SUB    { yylval.sval = strdup(yytext); return SUB;    }
	SUBI   { yylval.sval = strdup(yytext); return SUBI;   }
	SUBIS  { yylval.sval = strdup(yytext); return SUBIS;  }
	SUBS   { yylval.sval = strdup(yytext); return SUBS;   }
	MUL    { yylval.sval = strdup(yytext); return MUL;    }
	SMULH  { yylval.sval = strdup(yytext); return SMULH;  }
	UMULH  { yylval.sval = strdup(yytext); return UMULH;  }
	SDIV   { yylval.sval = strdup(yytext); return SDIV;   }
	UDIV   { yylval.sval = strdup(yytext); return UDIV;   }
	AND    { yylval.sval = strdup(yytext); return AND;    }
	ANDI   { yylval.sval = strdup(yytext); return ANDI;   }
	ANDIS  { yylval.sval = strdup(yytext); return ANDIS;  }
	ANDS   { yylval.sval = strdup(yytext); return ANDS;   }
	ORR    { yylval.sval = strdup(yytext); return ORR;    }
	ORRI   { yylval.sval = strdup(yytext); return ORRI;   }
	EOR    { yylval.sval = strdup(yytext); return EOR;    }
	EORI   { yylval.sval = strdup(yytext); return EORI;   }
	LSL    { yylval.sval = strdup(yytext); return LSL;    }
	LSR    { yylval.sval = strdup(yytext); return LSR;    }
	MOVK   { yylval.sval = strdup(yytext); return MOVK;   }
	MOVZ   { yylval.sval = strdup(yytext); return MOVZ;   }
	B      { yylval.sval = strdup(yytext); return B;      }
	BCOND  { yylval.sval = strdup(yytext); return BCOND;  }
	BL     { yylval.sval = strdup(yytext); return BL;     }
	BR     { yylval.sval = strdup(yytext); return BR;     }
	CBNZ   { yylval.sval = strdup(yytext); return CBNZ;   }
	CBZ    { yylval.sval = strdup(yytext); return CBZ;    }
	LDUR   { yylval.sval = strdup(yytext); return LDUR;   }
	LDURB  { yylval.sval = strdup(yytext); return LDURB;  }
	LDURH  { yylval.sval = strdup(yytext); return LDURH;  }
	LDURSW { yylval.sval = strdup(yytext); return LDURSW; }
	LDXR   { yylval.sval = strdup(yytext); return LDXR;   }
	STUR   { yylval.sval = strdup(yytext); return STUR;   }
	STURB  { yylval.sval = strdup(yytext); return STURB;  }
	STURH  { yylval.sval = strdup(yytext); return STURH;  }
	STURW  { yylval.sval = strdup(yytext); return STURW;  }
	STXR   { yylval.sval = strdup(yytext); return STXR;   }*/
	CMP    { yylval.sval = strdup(yytext); return CMP;    }
	CMPI   { yylval.sval = strdup(yytext); return CMPI;   }
	LDA    { yylval.sval = strdup(yytext); return LDA;    }
	MOV    { yylval.sval = strdup(yytext); return MOV;    }
	MOVI   { yylval.sval = strdup(yytext); return MOVI;   }
	INC    { yylval.sval = strdup(yytext); return INC;   }
	DEC    { yylval.sval = strdup(yytext); return DEC;   }

	LSL { return LSL; }
	
	/* Arguments (for example, a Register): */
X[0-9]+ { yylval.uival = atoi(yytext+1); return REGISTER;                      } // Normal Register
IP0     { yylval.uival = 16; return REGISTER;                                  } // Temporary Register
IP1     { yylval.uival = 17; return REGISTER;                                  } // Temporary Register
XZR     { yylval.uival = 31; return REGISTER;                                  } // Register Zero
SP      { yylval.uival = 28; return REGISTER;                                  } // Stack Pointer
FP      { yylval.uival = 29; return REGISTER;                                  } // Frame Pointer
LR      { yylval.uival = 30; return REGISTER;                                  } // Return Address
{NZ}{D}*{IS}? { yylval.llval = strtoull(yytext, 0, 10);  return IMMEDIATE;     } // Immediate Decimal (normal number)
{HP}{H}+?     { yylval.llval = strtoull(yytext, 0, 16);  return IMMEDIATE;     } // Immediate Hexadecimal
{BP}{B}+?     { yylval.llval = strtoull(yytext+2, 0, 2); return IMMEDIATE;     } // Immediate Binary
"0"{O}*{IS}?  { yylval.llval = strtoull(yytext+1, 0, 8); return IMMEDIATE;     } // Immediate Octal
"-"{NZ}{D}*{IS}? { yylval.llval = strtoull(yytext, 0, 10);  return IMMEDIATE;  } // Immediate Negative Decimal (normal number)
"-"{HP}{H}+?     { yylval.llval = strtoull(yytext, 0, 16);  return IMMEDIATE;  } // Immediate Negative Hexadecimal
"-"{BP}{B}+?     { yylval.llval = -strtoull(yytext+3, 0, 2); return IMMEDIATE; } // Immediate Negative Binary
"-0"{O}*{IS}?  { yylval.llval = -strtoull(yytext+1, 0, 8); return IMMEDIATE;   } // Immediate Negative Octal

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
