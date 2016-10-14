
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
     LDUR = 297,
     LDURB = 298,
     LDURH = 299,
     LDURSW = 300,
     LDXR = 301,
     STUR = 302,
     STURB = 303,
     STURH = 304,
     STURW = 305,
     STXR = 306,
     CMP = 307,
     CMPI = 308,
     LDA = 309,
     MOV = 310,
     MOVI = 311,
     INC = 312,
     DEC = 313,
     NORR = 314,
     NORRI = 315,
     RET = 316,
     PUSH = 317,
     PUSHI = 318,
     POP = 319,
     SWP = 320,
     NAND = 321,
     NANDI = 322,
     NEOR = 323,
     NEORI = 324,
     REGISTER = 325,
     IMMEDIATE = 326
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
#line 134 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


