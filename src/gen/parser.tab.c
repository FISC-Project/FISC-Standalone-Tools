
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "src/parser.y"

	#include <headers.h>
	int asm_lineno = 0;


/* Line 189 of yacc.c  */
#line 79 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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
     CMP = 307,
     CMPI = 308,
     LDA = 309,
     MOV = 310,
     MOVI = 311,
     MOVIW = 312,
     INC = 313,
     DEC = 314,
     NORR = 315,
     NORRI = 316,
     RET = 317,
     PUSH = 318,
     PUSHI = 319,
     POP = 320,
     SWP = 321,
     NAND = 322,
     NANDI = 323,
     NEOR = 324,
     NEORI = 325,
     HALT = 326,
     NOP = 327,
     BW = 328,
     ONE = 329,
     ONES = 330,
     ZERO = 331,
     ALIGN8 = 332,
     ALIGN16 = 333,
     ALIGN32 = 334,
     ALIGN64 = 335,
     ALIGN128 = 336,
     ALIGN256 = 337,
     ALIGN512 = 338,
     ALIGN1024 = 339,
     ALIGN2048 = 340,
     ALIGN4096 = 341,
     ALIGN8192 = 342,
     UNALI8 = 343,
     UNALI16 = 344,
     UNALI32 = 345,
     UNALI64 = 346,
     UNALI128 = 347,
     UNALI256 = 348,
     UNALI512 = 349,
     UNALI1024 = 350,
     UNALI2048 = 351,
     UNALI4096 = 352,
     UNALI8192 = 353,
     REGISTER = 354,
     IMMEDIATE = 355
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 6 "src/parser.y"

	long long         llval;
	int               ival;
	unsigned int      uival;
	float             fval;
	char           *  sval;
	struct arglist * arglist_t;



/* Line 214 of yacc.c  */
#line 226 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 238 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  107
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   286

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  106
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  256

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   355

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   101,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   105,   104,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   102,     2,   103,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    23,    30,
      37,    42,    51,    60,    69,    74,    79,    82,    85,    88,
      96,   104,   112,   120,   122,   124,   125,   128,   134,   140,
     146,   154,   162,   168,   174,   180,   186,   192,   200,   204,
     208,   216,   224,   232,   240,   248,   256,   264,   272,   280,
     283,   287,   291,   295,   299,   305,   308,   311,   315,   319,
     323,   327,   331,   335,   339,   343,   347,   351,   355,   359,
     363,   367,   371,   375,   379,   383,   387,   391,   395,   399,
     403,   407
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
     107,     0,    -1,    -1,   108,   107,    -1,   112,   107,    -1,
     111,   107,    -1,    10,   109,    -1,    99,   101,    99,   101,
      99,   110,    -1,    99,   101,    99,   101,   100,   110,    -1,
      99,   101,    99,   101,    10,   110,    -1,    99,   101,    99,
     110,    -1,    99,   101,   102,    99,   101,   100,   103,   110,
      -1,    99,   101,   102,    99,   101,    10,   103,   110,    -1,
      99,   101,    99,   101,   102,    99,   103,   110,    -1,    99,
     101,    10,   110,    -1,    99,   101,   100,   110,    -1,    99,
     110,    -1,    10,   110,    -1,   100,   110,    -1,    99,   101,
     100,   101,    32,   100,   110,    -1,    99,   101,   100,   101,
      32,    10,   110,    -1,    99,   101,    10,   101,    32,   100,
     110,    -1,    99,   101,    10,   101,    32,    10,   110,    -1,
     110,    -1,   104,    -1,    -1,    10,   105,    -1,    52,    99,
     101,    99,   110,    -1,    53,    99,   101,    10,   110,    -1,
      53,    99,   101,   100,   110,    -1,    54,    99,   101,    99,
     101,    10,   110,    -1,    54,    99,   101,    99,   101,   100,
     110,    -1,    55,    99,   101,    99,   110,    -1,    56,    99,
     101,    10,   110,    -1,    56,    99,   101,   100,   110,    -1,
      57,    99,   101,    10,   110,    -1,    57,    99,   101,   100,
     110,    -1,    32,    99,   101,    99,   101,   100,   110,    -1,
      58,    99,   110,    -1,    59,    99,   110,    -1,    60,    99,
     101,    99,   101,    99,   110,    -1,    61,    99,   101,    99,
     101,   100,   110,    -1,    61,    99,   101,    99,   101,    10,
     110,    -1,    67,    99,   101,    99,   101,    99,   110,    -1,
      68,    99,   101,    99,   101,   100,   110,    -1,    68,    99,
     101,    99,   101,    10,   110,    -1,    69,    99,   101,    99,
     101,    99,   110,    -1,    70,    99,   101,    99,   101,   100,
     110,    -1,    70,    99,   101,    99,   101,    10,   110,    -1,
      62,   110,    -1,    63,    99,   110,    -1,    64,   100,   110,
      -1,    64,    10,   110,    -1,    65,    99,   110,    -1,    66,
      99,   101,    99,   110,    -1,    71,   110,    -1,    72,   110,
      -1,    73,   100,   110,    -1,    73,    10,   110,    -1,    74,
      99,   110,    -1,    75,    99,   110,    -1,    76,    99,   110,
      -1,    78,    99,   110,    -1,    79,    99,   110,    -1,    80,
      99,   110,    -1,    81,    99,   110,    -1,    82,    99,   110,
      -1,    83,    99,   110,    -1,    84,    99,   110,    -1,    85,
      99,   110,    -1,    86,    99,   110,    -1,    87,    99,   110,
      -1,    89,    99,   110,    -1,    90,    99,   110,    -1,    91,
      99,   110,    -1,    92,    99,   110,    -1,    93,    99,   110,
      -1,    94,    99,   110,    -1,    95,    99,   110,    -1,    96,
      99,   110,    -1,    97,    99,   110,    -1,    98,    99,   110,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    72,    73,    74,    78,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   101,   102,   104,   107,   112,   123,
     134,   135,   136,   137,   138,   139,   148,   157,   158,   159,
     160,   165,   170,   175,   180,   185,   190,   195,   200,   205,
     206,   211,   222,   233,   238,   244,   245,   246,   259,   272,
     275,   278,   281,   284,   287,   290,   293,   296,   299,   302,
     305,   308,   311,   314,   317,   320,   323,   326,   329,   332,
     335,   338
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "STRING", "I_CONSTANT",
  "F_CONSTANT", "D_CONSTANT", "STRING_LITERAL", "IDENTIFIER", "ADD",
  "ADDI", "ADDIS", "ADDS", "SUB", "SUBI", "SUBIS", "SUBS", "MUL", "SMULH",
  "UMULH", "SDIV", "UDIV", "AND", "ANDI", "ANDIS", "ANDS", "ORR", "ORRI",
  "EOR", "EORI", "LSL", "LSR", "MOVK", "MOVZ", "B", "BCOND", "BL", "BR",
  "CBNZ", "CBZ", "LDR", "LDRB", "LDRH", "LDRSW", "LDXR", "STR", "STRB",
  "STRH", "STRW", "STXR", "CMP", "CMPI", "LDA", "MOV", "MOVI", "MOVIW",
  "INC", "DEC", "NORR", "NORRI", "RET", "PUSH", "PUSHI", "POP", "SWP",
  "NAND", "NANDI", "NEOR", "NEORI", "HALT", "NOP", "BW", "ONE", "ONES",
  "ZERO", "ALIGN8", "ALIGN16", "ALIGN32", "ALIGN64", "ALIGN128",
  "ALIGN256", "ALIGN512", "ALIGN1024", "ALIGN2048", "ALIGN4096",
  "ALIGN8192", "UNALI8", "UNALI16", "UNALI32", "UNALI64", "UNALI128",
  "UNALI256", "UNALI512", "UNALI1024", "UNALI2048", "UNALI4096",
  "UNALI8192", "REGISTER", "IMMEDIATE", "','", "'['", "']'", "';'", "':'",
  "$accept", "program", "instruction", "args", "eol", "label",
  "special_cases", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,    44,    91,    93,    59,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   106,   107,   107,   107,   107,   108,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   110,   110,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     6,     6,     6,
       4,     8,     8,     8,     4,     4,     2,     2,     2,     7,
       7,     7,     7,     1,     1,     0,     2,     5,     5,     5,
       7,     7,     5,     5,     5,     5,     5,     7,     3,     3,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     2,
       3,     3,     3,     3,     5,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       2,     2,    25,    25,    25,    24,    26,     6,    23,     0,
       0,     0,     0,     0,     0,     0,    25,    25,     0,     0,
      49,    25,    25,    25,    25,     0,     0,     0,     0,     0,
      55,    56,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,     1,     3,     5,
       4,    17,     0,    16,    18,     0,     0,     0,     0,     0,
       0,     0,    38,    39,     0,     0,    50,    52,    51,    53,
       0,     0,     0,     0,     0,    58,    57,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      25,    25,    25,     0,     0,    25,    25,    25,     0,    25,
      25,    25,    25,    25,     0,     0,    25,     0,     0,     0,
       0,     0,    14,     0,    10,     0,    15,     0,     0,    27,
      28,    29,     0,    32,    33,    34,    35,    36,     0,     0,
      54,     0,     0,     0,     0,     0,    25,    25,    25,     0,
       0,     0,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,    25,     9,     7,     8,     0,
      25,    25,     0,     0,    37,    30,    31,    40,    42,    41,
      43,    45,    44,    46,    48,    47,    22,    21,    25,    20,
      19,    25,    25,    13,    12,    11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    48,    49,    57,    58,    50,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int16 yypact[] =
{
     188,    -5,   -97,   -96,   -72,   -71,   -66,   -65,   -64,   -63,
     -62,   -61,   -57,   -60,   -56,    -4,   -54,   -53,   -52,   -51,
     -50,   -49,   -60,   -60,    -3,   -48,   -47,   -44,   -43,   -42,
     -37,   -36,   -35,   -34,   -33,   -32,   -31,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   127,   188,
     188,   188,   -60,  -100,   -60,  -101,  -101,  -101,  -101,    28,
      29,    30,    31,    32,    33,    34,   -60,   -60,    35,    36,
    -101,   -60,   -60,   -60,   -60,    37,    38,    39,    40,    41,
    -101,  -101,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,  -101,  -101,  -101,
    -101,  -101,     2,  -101,  -101,    44,    45,    -2,    46,    47,
       3,     7,  -101,  -101,    51,    52,  -101,  -101,  -101,  -101,
      56,    62,    63,    65,    66,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
     -90,   -86,   -75,    67,    68,   -60,   -60,   -60,    69,   -60,
     -60,   -60,   -60,   -60,    70,    71,   -60,    72,    73,    74,
      75,    96,  -101,     6,  -101,   135,  -101,    76,    78,  -101,
    -101,  -101,     9,  -101,  -101,  -101,  -101,  -101,    80,    10,
    -101,    81,    11,    82,    12,    13,   -60,   -60,   -60,    83,
      14,    15,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,  -101,  -101,  -101,    84,
     -60,   -60,    85,    86,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,   -60,  -101,
    -101,   -60,   -60,  -101,  -101,  -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -101,   -19,  -101,  -101,   -13,  -101,  -101
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      70,   112,    59,    60,    55,    52,    72,    82,   166,    80,
      81,   181,   160,   170,    55,   183,   206,   172,    55,   213,
     216,   219,   222,   224,   230,   232,   185,    61,    62,    55,
     108,   109,   110,    63,    64,    65,    66,    67,    68,   111,
     113,   114,    69,    71,    55,    74,    75,    76,    77,    78,
      79,    84,    85,   122,   123,    86,    87,    88,   126,   127,
     128,   129,    89,    90,    91,    92,    93,    94,    95,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    53,    54,    73,    83,   167,    55,
      56,   161,   162,   171,   163,   207,   208,   173,   209,   214,
     217,   220,   223,   225,   231,   233,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   205,   115,
     116,   117,   118,   119,   120,   121,   124,   125,   130,   131,
     132,   133,   134,   164,   165,   168,   169,   182,   184,   186,
     174,   175,   189,   190,   191,   176,   193,   194,   195,   196,
     197,   177,   178,   200,   179,   180,   187,   210,     0,   188,
     192,   198,   199,   201,   202,   203,   204,   211,   212,   215,
     218,   221,   229,     0,     0,     0,     0,   248,   251,   252,
       0,     0,     0,   226,   227,   228,     0,     0,     1,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,   249,   250,     0,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,     0,     0,   254,   255,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     0,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47
};

static const yytype_int16 yycheck[] =
{
      13,   101,    99,    99,   104,    10,    10,    10,    10,    22,
      23,   101,    10,    10,   104,   101,    10,    10,   104,    10,
      10,    10,    10,    10,    10,    10,   101,    99,    99,   104,
      49,    50,    51,    99,    99,    99,    99,    99,    99,    52,
      53,    54,    99,    99,   104,    99,    99,    99,    99,    99,
      99,    99,    99,    66,    67,    99,    99,    99,    71,    72,
      73,    74,    99,    99,    99,    99,    99,    99,    99,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    99,   100,   100,   100,   100,   104,
     105,    99,   100,   100,   102,    99,   100,   100,   102,   100,
     100,   100,   100,   100,   100,   100,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,     0,    32,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,    99,    99,    99,    99,   160,   161,   162,
      99,    99,   165,   166,   167,    99,   169,   170,   171,   172,
     173,    99,    99,   176,    99,    99,    99,    32,    -1,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   100,    99,
      99,    99,    99,    -1,    -1,    -1,    -1,   103,   103,   103,
      -1,    -1,    -1,   206,   207,   208,    -1,    -1,    10,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,   230,   231,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,   251,   252,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    32,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   107,   108,
     111,   112,    10,    99,   100,   104,   105,   109,   110,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     110,    99,    10,   100,    99,    99,    99,    99,    99,    99,
     110,   110,    10,   100,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,     0,   107,   107,
     107,   110,   101,   110,   110,   101,   101,   101,   101,   101,
     101,   101,   110,   110,   101,   101,   110,   110,   110,   110,
     101,   101,   101,   101,   101,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
      10,    99,   100,   102,    99,    99,    10,   100,    99,    99,
      10,   100,    10,   100,    99,    99,    99,    99,    99,    99,
      99,   101,   110,   101,   110,   101,   110,    99,   101,   110,
     110,   110,   101,   110,   110,   110,   110,   110,   101,   101,
     110,   101,   101,   101,   101,    32,    10,    99,   100,   102,
      32,   101,   100,    10,   100,    99,    10,   100,    99,    10,
     100,    99,    10,   100,    10,   100,   110,   110,   110,    99,
      10,   100,    10,   100,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   103,   110,
     110,   103,   103,   110,   110,   110
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:

/* Line 1455 of yacc.c  */
#line 78 "src/parser.y"
    { make_instruction((yyvsp[(1) - (2)].sval), (yyvsp[(2) - (2)].arglist_t)); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 82 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(3, make_argument(0, 0, (yyvsp[(1) - (6)].uival)), make_argument(0, 0, (yyvsp[(3) - (6)].uival)), make_argument(0, 0, (yyvsp[(5) - (6)].uival))); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 83 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(3, make_argument(0, 0, (yyvsp[(1) - (6)].uival)), make_argument(0, 0, (yyvsp[(3) - (6)].uival)), make_argument(1, 0, (yyvsp[(5) - (6)].llval))); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 84 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(3, make_argument(0, 0, (yyvsp[(1) - (6)].uival)), make_argument(0, 0, (yyvsp[(3) - (6)].uival)), make_argument(1, 0, (yyvsp[(5) - (6)].sval))); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 85 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(2, make_argument(0, 0, (yyvsp[(1) - (4)].uival)), make_argument(0, 0, (yyvsp[(3) - (4)].uival))); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 86 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(3, make_argument(0, 0, (yyvsp[(1) - (8)].uival)), make_argument(0, 1, (yyvsp[(4) - (8)].uival)), make_argument(1, 1, (yyvsp[(6) - (8)].llval))); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 87 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(3, make_argument(0, 0, (yyvsp[(1) - (8)].uival)), make_argument(0, 1, (yyvsp[(4) - (8)].uival)), make_argument(1, 1, (yyvsp[(6) - (8)].sval))); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 88 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(3, make_argument(0, 0, (yyvsp[(1) - (8)].uival)), make_argument(0, 0, (yyvsp[(3) - (8)].uival)), make_argument(0, 1, (yyvsp[(6) - (8)].uival))); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 89 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(2, make_argument(0, 0, (yyvsp[(1) - (4)].uival)), make_argument(1, 0, (yyvsp[(3) - (4)].sval))); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 90 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(2, make_argument(0, 0, (yyvsp[(1) - (4)].uival)), make_argument(1, 0, (yyvsp[(3) - (4)].llval))); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 91 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(1, make_argument(0, 0, (yyvsp[(1) - (2)].uival)));                          ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 92 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(1, make_argument(1, 0, (yyvsp[(1) - (2)].sval)));                          ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 93 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(1, make_argument(1, 0, (yyvsp[(1) - (2)].llval)));                          ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 94 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(3, make_argument(0, 0, (yyvsp[(1) - (7)].uival)), make_argument(1, 0, (yyvsp[(3) - (7)].llval)), make_argument(1, 0, (yyvsp[(6) - (7)].llval))); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 95 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(3, make_argument(0, 0, (yyvsp[(1) - (7)].uival)), make_argument(1, 0, (yyvsp[(3) - (7)].llval)), make_argument(1, 0, (yyvsp[(6) - (7)].sval))); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 96 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(3, make_argument(0, 0, (yyvsp[(1) - (7)].uival)), make_argument(1, 0, (yyvsp[(3) - (7)].sval)), make_argument(1, 0, (yyvsp[(6) - (7)].llval))); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 97 "src/parser.y"
    { (yyval.arglist_t) = make_argument_list(3, make_argument(0, 0, (yyvsp[(1) - (7)].uival)), make_argument(1, 0, (yyvsp[(3) - (7)].sval)), make_argument(1, 0, (yyvsp[(6) - (7)].sval))); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 98 "src/parser.y"
    { (yyval.arglist_t) = 0; ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 101 "src/parser.y"
    { asm_lineno++; ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 102 "src/parser.y"
    { asm_lineno++; ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 104 "src/parser.y"
    { add_label((yyvsp[(1) - (2)].sval), asm_lineno); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 107 "src/parser.y"
    { 
		  make_instruction((char*)"SUBS", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(0, 0, (yyvsp[(4) - (5)].uival)))); 
		  make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		  adjust_labels_offset(2);
	  ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 112 "src/parser.y"
    { 
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(4) - (5)].sval), 1),  make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(4) - (5)].sval), 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(4) - (5)].sval), 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(4) - (5)].sval), 48), make_argument(1, 0, (long long)48))); 
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"SUBS", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(0, 0, (long long)9))); 
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		adjust_labels_offset(8);
	;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 123 "src/parser.y"
    { 
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(4) - (5)].llval) & 0xFFFF),  make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ((yyvsp[(4) - (5)].llval) & 0xFFFF0000) >> 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ((yyvsp[(4) - (5)].llval) & 0xFFFF00000000) >> 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ((yyvsp[(4) - (5)].llval) & 0xFFFF000000000000) >> 48), make_argument(1, 0, (long long)48))); 
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"SUBS", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(0, 0, (long long)9))); 
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		adjust_labels_offset(8);
	;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 134 "src/parser.y"
    { make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(4) - (7)].uival)), make_argument(1, 0, (yyvsp[(6) - (7)].sval)))); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 135 "src/parser.y"
    { make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(4) - (7)].uival)), make_argument(1, 0, (yyvsp[(6) - (7)].llval)))); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 136 "src/parser.y"
    { make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(0, 0, (yyvsp[(4) - (5)].uival)), make_argument(1, 0, (long long)0))); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 137 "src/parser.y"
    { make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(0, 0, (long long)31), make_argument(1, 0, (yyvsp[(4) - (5)].sval)))); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 138 "src/parser.y"
    { make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(0, 0, (long long)31), make_argument(1, 0, (long long)(yyvsp[(4) - (5)].llval)))); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 139 "src/parser.y"
    {
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(1, 0, (yyvsp[(4) - (5)].sval), 1),  make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(1, 0, (yyvsp[(4) - (5)].sval), 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(1, 0, (yyvsp[(4) - (5)].sval), 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(1, 0, (yyvsp[(4) - (5)].sval), 48), make_argument(1, 0, (long long)48))); 
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		adjust_labels_offset(6);
	;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 148 "src/parser.y"
    { 
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(1, 0, (yyvsp[(4) - (5)].llval) & 0xFFFF), make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(1, 0, ((yyvsp[(4) - (5)].llval) & 0xFFFF0000) >> 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(1, 0, ((yyvsp[(4) - (5)].llval) & 0xFFFF00000000) >> 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(1, 0, ((yyvsp[(4) - (5)].llval) & 0xFFFF000000000000) >> 48), make_argument(1, 0, (long long)48))); 
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		adjust_labels_offset(6);
	;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 157 "src/parser.y"
    { make_instruction((char*)"LSL",   make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(4) - (7)].uival)), make_argument(1, 0, (yyvsp[(6) - (7)].llval)))); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 158 "src/parser.y"
    { make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (3)].uival)), make_argument(0, 0, (yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)1))); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 159 "src/parser.y"
    { make_instruction((char*)"SUBI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (3)].uival)), make_argument(0, 0, (yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)1))); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 160 "src/parser.y"
    { 
		make_instruction((char*)"ORR", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(4) - (7)].uival)), make_argument(0, 0, (yyvsp[(6) - (7)].uival)))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(2) - (7)].uival)))); 
		adjust_labels_offset(2);
	;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 165 "src/parser.y"
    { 
		make_instruction((char*)"ORRI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(4) - (7)].uival)), make_argument(1, 0, (yyvsp[(6) - (7)].llval)))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(2) - (7)].uival)))); 
		adjust_labels_offset(2);
	;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 170 "src/parser.y"
    { 
		make_instruction((char*)"ORRI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(4) - (7)].uival)), make_argument(1, 0, (yyvsp[(6) - (7)].sval)))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(2) - (7)].uival)))); 
		adjust_labels_offset(2);
	;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 175 "src/parser.y"
    { 
		make_instruction((char*)"AND", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(4) - (7)].uival)), make_argument(0, 0, (yyvsp[(6) - (7)].uival)))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(2) - (7)].uival)))); 
		adjust_labels_offset(2);
	;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 180 "src/parser.y"
    { 
		make_instruction((char*)"ANDI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(4) - (7)].uival)), make_argument(1, 0, (yyvsp[(6) - (7)].llval)))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(2) - (7)].uival)))); 
		adjust_labels_offset(2);
	;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 185 "src/parser.y"
    { 
		make_instruction((char*)"ANDI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(4) - (7)].uival)), make_argument(1, 0, (yyvsp[(6) - (7)].sval)))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(2) - (7)].uival)))); 
		adjust_labels_offset(2);
	;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 190 "src/parser.y"
    { 
		make_instruction((char*)"EOR", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(4) - (7)].uival)), make_argument(0, 0, (yyvsp[(6) - (7)].uival)))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(2) - (7)].uival)))); 
		adjust_labels_offset(2);
	;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 195 "src/parser.y"
    { 
		make_instruction((char*)"EORI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(4) - (7)].uival)), make_argument(1, 0, (yyvsp[(6) - (7)].llval)))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(2) - (7)].uival)))); 
		adjust_labels_offset(2);
	;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 200 "src/parser.y"
    { 
		make_instruction((char*)"EORI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(4) - (7)].uival)), make_argument(1, 0, (yyvsp[(6) - (7)].sval)))); 
		make_instruction((char*)"NOT", make_argument_list(2, make_argument(0, 0, (yyvsp[(2) - (7)].uival)), make_argument(0, 0, (yyvsp[(2) - (7)].uival)))); 
		adjust_labels_offset(2);
	;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 205 "src/parser.y"
    { make_instruction((char*)"BR", make_argument_list(1, make_argument(0, 0, (long long)30))); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 206 "src/parser.y"
    {
		make_instruction((char*)"SUBI", make_argument_list(3, make_argument(0, 0, (long long)28), make_argument(0, 0, (long long)28), make_argument(1, 0, (long long)8)));
		make_instruction((char*)"STR", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (3)].uival)), make_argument(0, 1, (long long)28), make_argument(1, 1, (long long)0)));
		adjust_labels_offset(2);
	;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 211 "src/parser.y"
    {
		make_instruction((char*)"SUBI", make_argument_list(3, make_argument(0, 0, (long long)28), make_argument(0, 0, (long long)28), make_argument(1, 0, (long long)8)));
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(2) - (3)].llval) & 0xFFFF), make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ((yyvsp[(2) - (3)].llval) & 0xFFFF0000) >> 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ((yyvsp[(2) - (3)].llval) & 0xFFFF00000000) >> 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ((yyvsp[(2) - (3)].llval) & 0xFFFF000000000000) >> 48), make_argument(1, 0, (long long)48))); 		
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));		
		make_instruction((char*)"STR", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(0, 1, (long long)28), make_argument(1, 1, (long long)0)));
		adjust_labels_offset(8);
	;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 222 "src/parser.y"
    {
		make_instruction((char*)"SUBI", make_argument_list(3, make_argument(0, 0, (long long)28), make_argument(0, 0, (long long)28), make_argument(1, 0, (long long)8)));
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(2) - (3)].sval), 1),  make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(2) - (3)].sval), 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(2) - (3)].sval), 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(2) - (3)].sval), 48), make_argument(1, 0, (long long)48))); 
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"STR", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(0, 1, (long long)28), make_argument(1, 1, (long long)0)));
		adjust_labels_offset(8);
	;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 233 "src/parser.y"
    {
		make_instruction((char*)"LDR", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (3)].uival)), make_argument(0, 1, (long long)28), make_argument(1, 1, (long long)0)));
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (long long)28), make_argument(0, 0, (long long)28), make_argument(1, 0, (long long)8)));
		adjust_labels_offset(2);
	;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 238 "src/parser.y"
    {
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(1, 0, (long long)0)));
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (5)].uival)), make_argument(0, 0, (yyvsp[(4) - (5)].uival)), make_argument(1, 0, (long long)0)));
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (yyvsp[(4) - (5)].uival)), make_argument(0, 0, (long long)9), make_argument(1, 0, (long long)0)));
		adjust_labels_offset(3);	
	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 244 "src/parser.y"
    { make_instruction((char*)"B", make_argument_list(1, make_argument(1, 0, (long long)0))); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 245 "src/parser.y"
    { make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31))); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 246 "src/parser.y"
    { 
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(2) - (3)].llval) & 0xFFFF), make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ((yyvsp[(2) - (3)].llval) & 0xFFFF0000) >> 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ((yyvsp[(2) - (3)].llval) & 0xFFFF00000000) >> 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, ((yyvsp[(2) - (3)].llval) & 0xFFFF000000000000) >> 48), make_argument(1, 0, (long long)48))); 
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"BL", make_argument_list(1, make_argument(1, 0, 1)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (long long)30), make_argument(0, 0, (long long)30), make_argument(1, 0, (long long)3)));
		make_instruction((char*)"BR", make_argument_list(1, make_argument(0, 0, (long long)9)));
		adjust_labels_offset(10);
	;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 259 "src/parser.y"
    { 
		make_instruction((char*)"MOVZ", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(2) - (3)].sval), 1), make_argument(1, 0, (long long)0))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(2) - (3)].sval), 16), make_argument(1, 0, (long long)16))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(2) - (3)].sval), 32), make_argument(1, 0, (long long)32))); 
		make_instruction((char*)"MOVK", make_argument_list(3, make_argument(0, 0, (long long)9), make_argument(1, 0, (yyvsp[(2) - (3)].sval), 48), make_argument(1, 0, (long long)48))); 
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"BL", make_argument_list(1, make_argument(1, 0, 1)));
		make_instruction((char*)"ADD", make_argument_list(3, make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31), make_argument(0, 0, (long long)31)));
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (long long)30), make_argument(0, 0, (long long)30), make_argument(1, 0, (long long)3)));
		make_instruction((char*)"BR", make_argument_list(1, make_argument(0, 0, (long long)9)));
		adjust_labels_offset(10);
	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 272 "src/parser.y"
    {
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)31), make_argument(1, 0, (long long)1)));
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 275 "src/parser.y"
    {
		make_instruction((char*)"SUBI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)31), make_argument(1, 0, (long long)1)));
	;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 278 "src/parser.y"
    {
		make_instruction((char*)"ADDI", make_argument_list(3, make_argument(0, 0, (yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)31), make_argument(1, 0, (long long)0)));
	;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 281 "src/parser.y"
    {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)1))); 
	;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 284 "src/parser.y"
    {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)2))); 
	;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 287 "src/parser.y"
    {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)3))); 
	;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 290 "src/parser.y"
    {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)4))); 
	;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 293 "src/parser.y"
    {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)5))); 
	;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 296 "src/parser.y"
    {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)6))); 
	;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 299 "src/parser.y"
    {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)7))); 
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 302 "src/parser.y"
    {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)8))); 
	;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 305 "src/parser.y"
    {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)9))); 
	;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 308 "src/parser.y"
    {
		make_instruction((char*)"LSL", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)10))); 
	;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 311 "src/parser.y"
    {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)1))); 
	;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 314 "src/parser.y"
    {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)2))); 
	;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 317 "src/parser.y"
    {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)3))); 
	;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 320 "src/parser.y"
    {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)4))); 
	;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 323 "src/parser.y"
    {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)5))); 
	;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 326 "src/parser.y"
    {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)6))); 
	;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 329 "src/parser.y"
    {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)7))); 
	;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 332 "src/parser.y"
    {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)8))); 
	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 335 "src/parser.y"
    {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)9))); 
	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 338 "src/parser.y"
    {
		make_instruction((char*)"LSR", make_argument_list(3, make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(0, 0, (long long)(yyvsp[(2) - (3)].uival)), make_argument(1, 0, (long long)10))); 
	;}
    break;



/* Line 1455 of yacc.c  */
#line 2364 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 341 "src/parser.y"


