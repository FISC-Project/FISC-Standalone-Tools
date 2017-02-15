
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
     B = 291,
     BCOND = 292,
     BL = 293,
     BR = 294,
     CBNZ = 295,
     CBZ = 296,
     LDR = 297,
     LDRB = 298,
     LDRH = 299,
     LDRSW = 300,
     LDXR = 301,
     STR = 302,
     STRB = 303,
     STRH = 304,
     STRW = 305,
     STXR = 306,
     LDRR = 307,
     LDRBR = 308,
     LDRHR = 309,
     LDRSWR = 310,
     LDXRR = 311,
     STRR = 312,
     STRBR = 313,
     STRHR = 314,
     STRWR = 315,
     STXRR = 316,
     MSR = 317,
     MRS = 318,
     LIVP = 319,
     SIVP = 320,
     LEVP = 321,
     SEVP = 322,
     SESR = 323,
     SINT = 324,
     RETI = 325,
     LPDP = 326,
     SPDP = 327,
     LPFLA = 328,
     CMP = 329,
     CMPI = 330,
     LDA = 331,
     MOV = 332,
     MOVI = 333,
     MOVIW = 334,
     INC = 335,
     DEC = 336,
     NORR = 337,
     NORRI = 338,
     RET = 339,
     PUSH = 340,
     PUSHI = 341,
     POP = 342,
     SWP = 343,
     NAND = 344,
     NANDI = 345,
     NEOR = 346,
     NEORI = 347,
     HALT = 348,
     NOP = 349,
     BW = 350,
     ONE = 351,
     ONES = 352,
     ZERO = 353,
     ALIGN8 = 354,
     ALIGN16 = 355,
     ALIGN32 = 356,
     ALIGN64 = 357,
     ALIGN128 = 358,
     ALIGN256 = 359,
     ALIGN512 = 360,
     ALIGN1024 = 361,
     ALIGN2048 = 362,
     ALIGN4096 = 363,
     ALIGN8192 = 364,
     UNALI8 = 365,
     UNALI16 = 366,
     UNALI32 = 367,
     UNALI64 = 368,
     UNALI128 = 369,
     UNALI256 = 370,
     UNALI512 = 371,
     UNALI1024 = 372,
     UNALI2048 = 373,
     UNALI4096 = 374,
     UNALI8192 = 375,
     REGISTER = 376,
     IMMEDIATE = 377
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
#line 185 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


