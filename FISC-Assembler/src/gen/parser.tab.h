
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     STRING = 260,
     I_CONSTANT = 261,
     F_CONSTANT = 262,
     D_CONSTANT = 263,
     STRING_LITERAL = 264,
     IDENTIFIER = 265,
     ADD = 266,
     ADDI = 267,
     ADDIS = 268,
     ADDS = 269,
     SUB = 270,
     SUBI = 271,
     SUBIS = 272,
     SUBS = 273,
     MUL = 274,
     SMULH = 275,
     UMULH = 276,
     SDIV = 277,
     UDIV = 278,
     AND = 279,
     ANDI = 280,
     ANDIS = 281,
     ANDS = 282,
     ORR = 283,
     ORRI = 284,
     EOR = 285,
     EORI = 286,
     LSL = 287,
     LSR = 288,
     MOVK = 289,
     MOVZ = 290,
     MOVRK = 291,
     MOVRZ = 292,
     B = 293,
     BCOND = 294,
     BL = 295,
     BR = 296,
     CBNZ = 297,
     CBZ = 298,
     LDR = 299,
     LDRB = 300,
     LDRH = 301,
     LDRSW = 302,
     LDXR = 303,
     STR = 304,
     STRB = 305,
     STRH = 306,
     STRW = 307,
     STXR = 308,
     LDRR = 309,
     LDRBR = 310,
     LDRHR = 311,
     LDRSWR = 312,
     LDXRR = 313,
     STRR = 314,
     STRBR = 315,
     STRHR = 316,
     STRWR = 317,
     STXRR = 318,
     MSR = 319,
     MRS = 320,
     LIVP = 321,
     SIVP = 322,
     LEVP = 323,
     SEVP = 324,
     SESR = 325,
     SINT = 326,
     RETI = 327,
     LPDP = 328,
     SPDP = 329,
     LPFLA = 330,
     CMP = 331,
     CMPI = 332,
     LDA = 333,
     MOV = 334,
     MOVI = 335,
     MOVIW = 336,
     INC = 337,
     DEC = 338,
     NORR = 339,
     NORRI = 340,
     RET = 341,
     PUSH = 342,
     PUSHI = 343,
     POP = 344,
     SWP = 345,
     NAND = 346,
     NANDI = 347,
     NEOR = 348,
     NEORI = 349,
     NOP = 350,
     BW = 351,
     ONE = 352,
     ONES = 353,
     ZERO = 354,
     ALIGN8 = 355,
     ALIGN16 = 356,
     ALIGN32 = 357,
     ALIGN64 = 358,
     ALIGN128 = 359,
     ALIGN256 = 360,
     ALIGN512 = 361,
     ALIGN1024 = 362,
     ALIGN2048 = 363,
     ALIGN4096 = 364,
     ALIGN8192 = 365,
     UNALI8 = 366,
     UNALI16 = 367,
     UNALI32 = 368,
     UNALI64 = 369,
     UNALI128 = 370,
     UNALI256 = 371,
     UNALI512 = 372,
     UNALI1024 = 373,
     UNALI2048 = 374,
     UNALI4096 = 375,
     UNALI8192 = 376,
     REGISTER = 377,
     IMMEDIATE = 378
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 6 "src/parser.y"

	long long         llval;
	int               ival;
	unsigned int      uival;
	float             fval;
	char           *  sval;
	struct arglist * arglist_t;



/* Line 1676 of yacc.c  */
#line 186 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


