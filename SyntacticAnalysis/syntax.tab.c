/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRUCT = 258,
     RETURN = 259,
     IF = 260,
     ELSE = 261,
     WHILE = 262,
     TYPE = 263,
     INT = 264,
     FLOAT = 265,
     ID = 266,
     SEMI = 267,
     COMMA = 268,
     ASSIGNOP = 269,
     RELOP = 270,
     PLUS = 271,
     MINUS = 272,
     STAR = 273,
     DIV = 274,
     AND = 275,
     OR = 276,
     DOT = 277,
     NOT = 278,
     LP = 279,
     RP = 280,
     LB = 281,
     RB = 282,
     LC = 283,
     RC = 284
   };
#endif
/* Tokens.  */
#define STRUCT 258
#define RETURN 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define TYPE 263
#define INT 264
#define FLOAT 265
#define ID 266
#define SEMI 267
#define COMMA 268
#define ASSIGNOP 269
#define RELOP 270
#define PLUS 271
#define MINUS 272
#define STAR 273
#define DIV 274
#define AND 275
#define OR 276
#define DOT 277
#define NOT 278
#define LP 279
#define RP 280
#define LB 281
#define RB 282
#define LC 283
#define RC 284




/* Copy the first part of user declarations.  */
#line 1 "syntax.y"

 #include<stdlib.h>
 #include<stdarg.h>
 #include<string.h>
 #include<stdio.h>
 #define YYDEBUG 1
 #define YYERROR_VERBOSE 1
 struct node
 {
     int line;
     char *name;
     struct node *left;
     struct node *right;
     union
     {
         float float_value;
         int int_value;
         char  *string;
     };
 };

struct List
{
    char *type;
    char *value;
    struct List *next;
};
struct node* create_node(char *name,int num,...);
void print_list();
void print_tree(struct node *head,int leavel);
FILE* file;


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 34 "syntax.y"
{
    struct node* a;
}
/* Line 193 of yacc.c.  */
#line 191 "syntax.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 204 "syntax.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  118

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    16,    20,    22,
      26,    28,    30,    36,    39,    41,    42,    44,    46,    51,
      54,    59,    63,    66,    70,    72,    75,    80,    83,    84,
      87,    89,    93,    99,   107,   113,   116,   119,   120,   124,
     126,   130,   132,   136,   140,   144,   148,   152,   156,   160,
     164,   168,   172,   175,   178,   183,   187,   192,   196,   198,
     200,   202,   204,   208
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      31,     0,    -1,    32,    -1,    33,    32,    -1,    -1,    35,
      34,    12,    -1,    35,    12,    -1,    35,    40,    43,    -1,
      39,    -1,    39,    13,    34,    -1,     8,    -1,    36,    -1,
       3,    37,    28,    46,    29,    -1,     3,    38,    -1,    11,
      -1,    -1,    11,    -1,    11,    -1,    39,    26,     9,    27,
      -1,     1,    27,    -1,    11,    24,    41,    25,    -1,    11,
      24,    25,    -1,     1,    25,    -1,    42,    13,    41,    -1,
      42,    -1,    35,    39,    -1,    28,    46,    44,    29,    -1,
      45,    44,    -1,    -1,    50,    12,    -1,    43,    -1,     4,
      50,    12,    -1,     5,    24,    50,    25,    45,    -1,     5,
      24,    50,    25,    45,     6,    45,    -1,     7,    24,    50,
      25,    45,    -1,     1,    12,    -1,    47,    46,    -1,    -1,
      35,    48,    12,    -1,    49,    -1,    49,    13,    48,    -1,
      39,    -1,    39,    14,    50,    -1,    50,    14,    50,    -1,
      50,    20,    50,    -1,    50,    21,    50,    -1,    50,    15,
      50,    -1,    50,    16,    50,    -1,    50,    17,    50,    -1,
      50,    18,    50,    -1,    50,    19,    50,    -1,    24,    50,
      25,    -1,    17,    50,    -1,    23,    50,    -1,    11,    24,
      51,    25,    -1,    11,    24,    25,    -1,    50,    26,    50,
      27,    -1,    50,    22,    11,    -1,    11,    -1,     9,    -1,
      10,    -1,     1,    -1,    50,    13,    51,    -1,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    56,    57,    60,    61,    62,    65,    66,
      69,    70,    73,    74,    77,    78,    81,    84,    85,    86,
      89,    90,    91,    94,    95,    98,   101,   104,   105,   108,
     109,   110,   111,   112,   113,   114,   117,   118,   121,   124,
     125,   128,   129,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   153,   154
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRUCT", "RETURN", "IF", "ELSE",
  "WHILE", "TYPE", "INT", "FLOAT", "ID", "SEMI", "COMMA", "ASSIGNOP",
  "RELOP", "PLUS", "MINUS", "STAR", "DIV", "AND", "OR", "DOT", "NOT", "LP",
  "RP", "LB", "RB", "LC", "RC", "$accept", "Program", "ExtDefList",
  "ExtDef", "ExtDecList", "Specifier", "StructSpecifier", "OptTag", "Tag",
  "VarDec", "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt",
  "DefList", "Def", "DecList", "Dec", "Exp", "Args", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    33,    34,    34,
      35,    35,    36,    36,    37,    37,    38,    39,    39,    39,
      40,    40,    40,    41,    41,    42,    43,    44,    44,    45,
      45,    45,    45,    45,    45,    45,    46,    46,    47,    48,
      48,    49,    49,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    51,    51
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     1,     3,
       1,     1,     5,     2,     1,     0,     1,     1,     4,     2,
       4,     3,     2,     3,     1,     2,     4,     2,     0,     2,
       1,     3,     5,     7,     5,     2,     2,     0,     3,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     4,     3,     4,     3,     1,     1,
       1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    15,    10,     0,     2,     4,     0,    11,    16,     0,
      13,     1,     3,     0,    17,     6,     0,     8,     0,    37,
      22,    19,     0,     5,     0,     0,    37,     7,     0,     0,
      37,    21,     0,     0,    24,     0,    17,     9,     0,     0,
      41,     0,    39,    12,    36,    25,    20,     0,    18,    61,
       0,     0,     0,    59,    60,    58,     0,     0,     0,    30,
       0,     0,     0,     0,    38,     0,    23,    35,    61,     0,
       0,     0,     0,    52,    53,     0,    26,    27,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
      40,    31,     0,     0,    55,    63,     0,    51,    43,    46,
      47,    48,    49,    50,    44,    45,    57,     0,     0,     0,
       0,    54,    56,    32,    34,    62,     0,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    16,    28,     7,     9,    10,    17,
      18,    33,    34,    59,    60,    61,    29,    30,    41,    42,
      62,    96
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -51
static const yytype_int16 yypact[] =
{
      34,    -8,   -51,    25,   -51,    34,     0,   -51,   -12,    11,
     -51,   -51,   -51,    46,    21,   -51,    40,   -11,    30,    34,
     -51,   -51,    16,   -51,    17,    55,    34,   -51,    17,    36,
      34,   -51,    17,    56,    78,    70,   -51,   -51,    74,    39,
      -9,    91,    92,   -51,   -51,    81,   -51,    34,   -51,    99,
      89,    80,   101,   -51,   -51,   114,    89,    89,    89,   -51,
      86,    39,   102,    89,   -51,    17,   -51,   -51,   -51,   115,
      89,    89,    85,    35,     1,   156,   -51,   -51,   -51,    89,
      89,    89,    89,    89,    89,    89,    89,   128,    89,   195,
     -51,   -51,   169,   182,   -51,   129,   127,   -51,   195,    61,
      35,    35,     1,     1,   219,   207,   -51,   142,    65,    65,
      89,   -51,   -51,   120,   -51,   -51,    65,   -51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -51,   -51,   135,   -51,   130,     4,   -51,   -51,   -51,   -18,
     -51,   106,   -51,   147,   105,   -24,    29,   -51,   140,   -51,
     -50,    57
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -29
static const yytype_int8 yytable[] =
{
      69,    13,    24,     8,     6,    63,    73,    74,    75,     6,
      40,    14,    15,    89,    45,    25,   -14,    25,    35,     1,
      92,    93,    95,    87,     2,    11,    32,    88,    36,    98,
      99,   100,   101,   102,   103,   104,   105,     1,   107,    19,
      49,    31,     2,    50,    51,    22,    52,    40,    53,    54,
      55,    32,    23,    83,    84,    39,    56,    87,    26,    44,
      95,    88,    57,    58,    38,    43,    49,    26,   -28,    50,
      51,    20,    52,    21,    53,    54,    55,    81,    82,    83,
      84,    46,    56,    87,   113,   114,    68,    88,    57,    58,
      68,    47,   117,    26,    53,    54,    55,    21,    53,    54,
      55,    48,    56,    64,    70,    65,    56,    25,    57,    58,
      94,    67,    57,    58,    78,    76,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    71,   116,    91,    88,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    72,   106,
      12,    88,   110,    79,    80,    81,    82,    83,    84,    85,
      86,    87,   111,    66,    37,    88,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    27,    77,   115,    88,   112,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,    97,    88,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,   108,    88,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    90,     0,   109,    88,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
       0,    88,    80,    81,    82,    83,    84,    85,     0,    87,
       0,     0,     0,    88,    80,    81,    82,    83,    84,     0,
       0,    87,     0,     0,     0,    88
};

static const yytype_int8 yycheck[] =
{
      50,     1,    13,    11,     0,    14,    56,    57,    58,     5,
      28,    11,    12,    63,    32,    26,    28,    26,     1,     3,
      70,    71,    72,    22,     8,     0,    22,    26,    11,    79,
      80,    81,    82,    83,    84,    85,    86,     3,    88,    28,
       1,    25,     8,     4,     5,    24,     7,    65,     9,    10,
      11,    47,    12,    18,    19,    26,    17,    22,    28,    30,
     110,    26,    23,    24,     9,    29,     1,    28,    29,     4,
       5,    25,     7,    27,     9,    10,    11,    16,    17,    18,
      19,    25,    17,    22,   108,   109,     1,    26,    23,    24,
       1,    13,   116,    28,     9,    10,    11,    27,     9,    10,
      11,    27,    17,    12,    24,    13,    17,    26,    23,    24,
      25,    12,    23,    24,    12,    29,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    24,     6,    12,    26,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    24,    11,
       5,    26,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    25,    47,    24,    26,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    18,    61,   110,    26,    27,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    65,    -1,    25,    26,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    15,    16,    17,    18,    19,    20,    -1,    22,
      -1,    -1,    -1,    26,    15,    16,    17,    18,    19,    -1,
      -1,    22,    -1,    -1,    -1,    26
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     8,    31,    32,    33,    35,    36,    11,    37,
      38,     0,    32,     1,    11,    12,    34,    39,    40,    28,
      25,    27,    24,    12,    13,    26,    28,    43,    35,    46,
      47,    25,    35,    41,    42,     1,    11,    34,     9,    46,
      39,    48,    49,    29,    46,    39,    25,    13,    27,     1,
       4,     5,     7,     9,    10,    11,    17,    23,    24,    43,
      44,    45,    50,    14,    12,    13,    41,    12,     1,    50,
      24,    24,    24,    50,    50,    50,    29,    44,    12,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    26,    50,
      48,    12,    50,    50,    25,    50,    51,    25,    50,    50,
      50,    50,    50,    50,    50,    50,    11,    50,    25,    25,
      13,    25,    27,    45,    45,    51,     6,    45
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 2:
#line 53 "syntax.y"
    {(yyval.a)=create_node("Program",1,(yyvsp[(1) - (1)].a));print_tree((yyval.a),0);;}
    break;

  case 3:
#line 56 "syntax.y"
    {(yyval.a)=create_node("ExtDefList",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));;}
    break;

  case 4:
#line 57 "syntax.y"
    {(yyval.a)=create_node("ExtDefList",0,-1);;}
    break;

  case 5:
#line 60 "syntax.y"
    {(yyval.a)=create_node("ExtDef",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 6:
#line 61 "syntax.y"
    {(yyval.a)=create_node("ExtDef",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));;}
    break;

  case 7:
#line 62 "syntax.y"
    {(yyval.a)=create_node("ExtDef",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 8:
#line 65 "syntax.y"
    {(yyval.a)=create_node("ExtDecList",1,(yyvsp[(1) - (1)].a));;}
    break;

  case 9:
#line 66 "syntax.y"
    {(yyval.a)=create_node("ExtDecList",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 10:
#line 69 "syntax.y"
    {(yyval.a)=create_node("Specifier",1,(yyvsp[(1) - (1)].a));;}
    break;

  case 11:
#line 70 "syntax.y"
    {(yyval.a)=create_node("Specifier",1,(yyvsp[(1) - (1)].a));;}
    break;

  case 12:
#line 73 "syntax.y"
    {(yyval.a)=create_node("StructSpecifier",5,(yyvsp[(1) - (5)].a),(yyvsp[(2) - (5)].a),(yyvsp[(3) - (5)].a),(yyvsp[(4) - (5)].a),(yyvsp[(5) - (5)].a));;}
    break;

  case 13:
#line 74 "syntax.y"
    {(yyval.a)=create_node("StructSpecifier",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));;}
    break;

  case 14:
#line 77 "syntax.y"
    {(yyval.a)=create_node("OptTag",1,(yyvsp[(1) - (1)].a));;}
    break;

  case 15:
#line 78 "syntax.y"
    {(yyval.a)=create_node("OptTag",0,-1);;}
    break;

  case 16:
#line 81 "syntax.y"
    {(yyval.a)=create_node("Tag",1,(yyvsp[(1) - (1)].a));;}
    break;

  case 17:
#line 84 "syntax.y"
    {(yyval.a)=create_node("VarDec",1,(yyvsp[(1) - (1)].a));;}
    break;

  case 18:
#line 85 "syntax.y"
    {(yyval.a)=create_node("VarDec",4,(yyvsp[(1) - (4)].a),(yyvsp[(2) - (4)].a),(yyvsp[(3) - (4)].a),(yyvsp[(4) - (4)].a));;}
    break;

  case 19:
#line 86 "syntax.y"
    {;}
    break;

  case 20:
#line 89 "syntax.y"
    {(yyval.a)=create_node("FunDec",4,(yyvsp[(1) - (4)].a),(yyvsp[(2) - (4)].a),(yyvsp[(3) - (4)].a),(yyvsp[(4) - (4)].a));;}
    break;

  case 21:
#line 90 "syntax.y"
    {(yyval.a)=create_node("FunDec",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 22:
#line 91 "syntax.y"
    {;}
    break;

  case 23:
#line 94 "syntax.y"
    {(yyval.a)=create_node("VarList",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 24:
#line 95 "syntax.y"
    {(yyval.a)=create_node("VarList",1,(yyvsp[(1) - (1)].a));;}
    break;

  case 25:
#line 98 "syntax.y"
    {(yyval.a)=create_node("ParamDec",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));;}
    break;

  case 26:
#line 101 "syntax.y"
    {(yyval.a)=create_node("CompSt",4,(yyvsp[(1) - (4)].a),(yyvsp[(2) - (4)].a),(yyvsp[(3) - (4)].a),(yyvsp[(4) - (4)].a));;}
    break;

  case 27:
#line 104 "syntax.y"
    {(yyval.a)=create_node("StmtList",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));;}
    break;

  case 28:
#line 105 "syntax.y"
    {(yyval.a)=create_node("StmtList",0,-1);;}
    break;

  case 29:
#line 108 "syntax.y"
    {(yyval.a)=create_node("Stmt",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));;}
    break;

  case 30:
#line 109 "syntax.y"
    {(yyval.a)=create_node("Stmt",1,(yyvsp[(1) - (1)].a));;}
    break;

  case 31:
#line 110 "syntax.y"
    {(yyval.a)=create_node("Stmt",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 32:
#line 111 "syntax.y"
    {(yyval.a)=create_node("Stmt",5,(yyvsp[(1) - (5)].a),(yyvsp[(2) - (5)].a),(yyvsp[(3) - (5)].a),(yyvsp[(4) - (5)].a),(yyvsp[(5) - (5)].a));;}
    break;

  case 33:
#line 112 "syntax.y"
    {(yyval.a)=create_node("Stmt",7,(yyvsp[(1) - (7)].a),(yyvsp[(2) - (7)].a),(yyvsp[(3) - (7)].a),(yyvsp[(4) - (7)].a),(yyvsp[(5) - (7)].a),(yyvsp[(6) - (7)].a),(yyvsp[(7) - (7)].a));;}
    break;

  case 34:
#line 113 "syntax.y"
    {(yyval.a)=create_node("Stmt",5,(yyvsp[(1) - (5)].a),(yyvsp[(2) - (5)].a),(yyvsp[(3) - (5)].a),(yyvsp[(4) - (5)].a),(yyvsp[(5) - (5)].a));;}
    break;

  case 35:
#line 114 "syntax.y"
    {;}
    break;

  case 36:
#line 117 "syntax.y"
    {(yyval.a)=create_node("DefList",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));;}
    break;

  case 37:
#line 118 "syntax.y"
    {(yyval.a)=create_node("DefList",0,-1);;}
    break;

  case 38:
#line 121 "syntax.y"
    {(yyval.a)=create_node("Def",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 39:
#line 124 "syntax.y"
    {(yyval.a)=create_node("DecList",1,(yyvsp[(1) - (1)].a));;}
    break;

  case 40:
#line 125 "syntax.y"
    {(yyval.a)=create_node("DecList",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 41:
#line 128 "syntax.y"
    {(yyval.a)=create_node("Dec",1,(yyvsp[(1) - (1)].a));;}
    break;

  case 42:
#line 129 "syntax.y"
    {(yyval.a)=create_node("Dec",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 43:
#line 132 "syntax.y"
    {(yyval.a)=create_node("Exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 44:
#line 133 "syntax.y"
    {(yyval.a)=create_node("Exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 45:
#line 134 "syntax.y"
    {(yyval.a)=create_node("Exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 46:
#line 135 "syntax.y"
    {(yyval.a)=create_node("Exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 47:
#line 136 "syntax.y"
    {(yyval.a)=create_node("Exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 48:
#line 137 "syntax.y"
    {(yyval.a)=create_node("Exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 49:
#line 138 "syntax.y"
    {(yyval.a)=create_node("Exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 50:
#line 139 "syntax.y"
    {(yyval.a)=create_node("Exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 51:
#line 140 "syntax.y"
    {(yyval.a)=create_node("Exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 52:
#line 141 "syntax.y"
    {(yyval.a)=create_node("Exp",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));;}
    break;

  case 53:
#line 142 "syntax.y"
    {(yyval.a)=create_node("Exp",2,(yyvsp[(1) - (2)].a),(yyvsp[(2) - (2)].a));;}
    break;

  case 54:
#line 143 "syntax.y"
    {(yyval.a)=create_node("Exp",4,(yyvsp[(1) - (4)].a),(yyvsp[(2) - (4)].a),(yyvsp[(3) - (4)].a),(yyvsp[(4) - (4)].a));;}
    break;

  case 55:
#line 144 "syntax.y"
    {(yyval.a)=create_node("Exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 56:
#line 145 "syntax.y"
    {(yyval.a)=create_node("Exp",4,(yyvsp[(1) - (4)].a),(yyvsp[(2) - (4)].a),(yyvsp[(3) - (4)].a),(yyvsp[(4) - (4)].a));;}
    break;

  case 57:
#line 146 "syntax.y"
    {(yyval.a)=create_node("Exp",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 58:
#line 147 "syntax.y"
    {(yyval.a)=create_node("Exp",1,(yyvsp[(1) - (1)].a));;}
    break;

  case 59:
#line 148 "syntax.y"
    {(yyval.a)=create_node("Exp",1,(yyvsp[(1) - (1)].a));;}
    break;

  case 60:
#line 149 "syntax.y"
    {(yyval.a)=create_node("Exp",1,(yyvsp[(1) - (1)].a));;}
    break;

  case 61:
#line 150 "syntax.y"
    {yyerrok;;}
    break;

  case 62:
#line 153 "syntax.y"
    {(yyval.a)=create_node("Args",3,(yyvsp[(1) - (3)].a),(yyvsp[(2) - (3)].a),(yyvsp[(3) - (3)].a));;}
    break;

  case 63:
#line 154 "syntax.y"
    {(yyval.a)=create_node("Args",1,(yyvsp[(1) - (1)].a));;}
    break;


/* Line 1267 of yacc.c.  */
#line 1832 "syntax.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 156 "syntax.y"

#include "lex.yy.c"
#include<stdio.h>
int main(int argc, char const *argv[])
{
    file=fopen("output.txt","a+");
    if(argc>1)
    {
        FILE * f= fopen(argv[1],"r");
        if(!f)
        {
            perror(argv[1]);
            return 1;
        }
        //yydebug=1;
        yyrestart(f);
        yyparse();
        print_list();
        fclose(file);
        return 0;
    }
    yyparse();
    print_list();
    fclose(file);
    return 0;
}

struct node * create_node(char *name,int num,...)
{
    va_list valist;

    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->left=NULL;
    head->right=NULL;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    head->name=name;
    va_start(valist, num);
    if(num>0)
    {
        temp=va_arg(valist, struct node *);
        head->left=temp;
        head->line=temp->line;
        if(num>=2)
        {
            for(int i=0;i<num-1;++i)
            {
                temp->right=va_arg(valist, struct node*);
                temp=temp->right;
            }
        }
    }
    else
    {
        int line=va_arg(valist, int);
        head->line=line;
        if((strcmp(head->name,"ID")==0)||(strcmp(head->name,"TYPE")==0))
        {
            char *string=(char*)malloc(strlen(yytext)+1);
            strcpy(string,yytext);
            head->string=string;
        }
        else if(strcmp(head->name,"INT")==0)
        {
            int value;
            if(strlen(yytext)>1&&yytext[0]=='0'&&yytext[1]!='x')
            {
                sscanf(yytext,"%o",&value);
            }
            else if(strlen(yytext)>1&&yytext[1]=='x')
            {
                sscanf(yytext,"%X",&value);
            }
            else
                value=atoi(yytext);
            char *string=(char*)malloc(strlen(yytext)+1);
            strcpy(string,yytext);
            head->int_value=value;
        }
        else if(strcmp(head->name,"FLOAT")==0)
        {
            char *string=(char*)malloc(strlen(yytext)+1);
            strcpy(string,yytext);
        }
    }
    return head;
}

void print_list()
{
    struct List *p=List_head;
    while(p->next!=NULL)
    {
        p=p->next;
        printf("<%s,%s>\n",p->type,p->value);
    }
}
void print_tree(struct node *head,int leavel)
{
    if(head!=NULL)
    {
        if(head->line!=-1)
        {
            for(int i=0;i<leavel;++i)
            {
                printf("  ");
                fprintf(file, "%s","  ");
            }
            printf("%s",head->name);
            fprintf(file, "%s",head->name);
            if((strcmp(head->name,"ID")==0)||(strcmp(head->name,"TYPE")==0))
            {
                printf(":%s",head->string);
                fprintf(file, ":%s",head->string);
            }
            else if(strcmp(head->name,"INT")==0)
            {
                printf(":%d ",head->int_value );
                fprintf(file, ":%d",head->int_value);
            }
            else if(strcmp(head->name,"FLOAT")==0)
            {
                printf(":%f ",head->float_value );
                fprintf(file, "%f",head->float_value);
            }
            else
            {
                printf("(%d)",head->line);
                fprintf(file, "(%d)",head->line);
            }
            printf("\n");
            fprintf(file, "%s","\n");
        }
        print_tree(head->left,leavel+1);
        print_tree(head->right,leavel);
    }
}

yyerror(char *msg)
{
    printf("type B at Line %d:%s\n",yylineno,msg);
}

