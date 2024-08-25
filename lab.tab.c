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
     INTEGER = 258,
     STRING = 259,
     BOOL = 260,
     LEFT = 261,
     RIGHT = 262,
     FORWARD = 263,
     BACK = 264,
     LEFTROT = 265,
     RIGHTROT = 266,
     TYPE_INTEGER = 267,
     TYPE_STRING = 268,
     TYPE_BOOL = 269,
     ID = 270,
     BEG = 271,
     EN = 272,
     FUNC = 273,
     RETURN = 274,
     ENTER = 275,
     DO = 276,
     UNTIL = 277,
     ARRAY = 278,
     ENDL = 279,
     EoF = 280,
     LOGOPERATOR = 281,
     CALL = 282
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define STRING 259
#define BOOL 260
#define LEFT 261
#define RIGHT 262
#define FORWARD 263
#define BACK 264
#define LEFTROT 265
#define RIGHTROT 266
#define TYPE_INTEGER 267
#define TYPE_STRING 268
#define TYPE_BOOL 269
#define ID 270
#define BEG 271
#define EN 272
#define FUNC 273
#define RETURN 274
#define ENTER 275
#define DO 276
#define UNTIL 277
#define ARRAY 278
#define ENDL 279
#define EoF 280
#define LOGOPERATOR 281
#define CALL 282




/* Copy the first part of user declarations.  */
#line 1 "B.y"
  #include "ast/ast.h"
    #include "ast/robot_function.cpp"
    #include <iostream>
    #define YYSTYPE val
    struct val
    {
        int i;
        bool b;
        std::string s;
        std::shared_ptr<ASTNode> a;
        Type t;
    };
    #include <stdio.h>
    #include <FlexLexer.h>
    #include <any>
    extern FILE* yyin;
    extern int yylex();
    void yyerror(const char*);
    std::string map_name = "maze.txt";
    auto container = std::make_shared<VariableContainer>();
    auto container_ = std::make_shared<ParseVariableContainer>();
    int l = 0;
    ASTNode *tree;
    auto map  = std::make_shared<Map>(map_name);
    auto robot = std::make_shared<Robot>(map, 100);



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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 188 "lab.tab.c"

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNRULES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,     2,    36,    34,    35,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
       2,    33,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    15,    18,    21,    24,
      25,    27,    29,    31,    33,    35,    40,    45,    50,    55,
      59,    63,    69,    75,    79,    83,    87,    92,    96,    99,
     102,   106,   110,   114,   118,   119,   122,   129,   136,   138,
     140,   142,   144,   148,   152,   156,   161,   164,   169,   172,
     177,   180,   186,   190,   194,   201,   205,   212,   214,   216,
     218,   222,   226,   228,   232,   236,   240,   244,   248,   252,
     255,   258,   261,   263,   266,   269,   272,   275,   278
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    38,    59,    -1,    38,    56,    -1,    38,
      57,    -1,    38,    47,    -1,    38,    44,    -1,    38,    48,
      -1,    38,    25,    -1,    -1,     3,    -1,     4,    -1,     5,
      -1,    46,    -1,    15,    -1,    15,    29,     3,    30,    -1,
      31,    12,    32,    53,    -1,    31,    14,    32,    53,    -1,
      31,    13,    32,    53,    -1,    15,    33,    53,    -1,    15,
      33,    54,    -1,    41,    34,    15,    33,    53,    -1,    41,
      34,    15,    33,    54,    -1,    12,    18,    15,    -1,    13,
      18,    15,    -1,    14,    18,    15,    -1,    42,    31,    41,
      32,    -1,    42,    31,    32,    -1,    43,    59,    -1,    43,
      48,    -1,    15,    31,    53,    -1,    15,    31,    54,    -1,
      45,    34,    53,    -1,    45,    34,    54,    -1,    -1,    45,
      32,    -1,    20,    54,    21,    48,    22,    54,    -1,    20,
      54,    21,    59,    22,    54,    -1,    56,    -1,    57,    -1,
      52,    -1,    49,    -1,    19,    15,    28,    -1,    19,    53,
      28,    -1,    19,    54,    28,    -1,    12,    15,    33,    53,
      -1,    12,    15,    -1,    13,    15,    33,    53,    -1,    13,
      15,    -1,    14,    15,    33,    53,    -1,    14,    15,    -1,
      50,    34,    15,    33,    53,    -1,    50,    34,    15,    -1,
      15,    33,    53,    -1,    15,    29,    53,    30,    33,    53,
      -1,    15,    33,    52,    -1,    27,    31,    15,    34,    15,
      32,    -1,    54,    -1,    40,    -1,    39,    -1,    53,    35,
      39,    -1,    53,    36,    39,    -1,    39,    -1,    54,    33,
      39,    -1,    54,    26,    39,    -1,    23,    12,    15,    -1,
      23,    13,    15,    -1,    23,    14,    15,    -1,    55,    34,
      15,    -1,    50,    28,    -1,    55,    28,    -1,    51,    28,
      -1,    16,    -1,    58,    44,    -1,    58,    56,    -1,    58,
      49,    -1,    58,    57,    -1,    58,    47,    -1,    58,    17,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    44,    45,    46,    47,    48,    49,    50,
      63,    67,    71,    75,    78,    83,    91,    96,   102,   110,
     117,   124,   131,   140,   146,   152,   160,   165,   170,   174,
     179,   184,   189,   190,   191,   192,   195,   199,   204,   205,
     206,   207,   210,   216,   221,   228,   237,   247,   256,   266,
     275,   285,   293,   304,   309,   315,   322,   327,   328,   329,
     330,   337,   346,   347,   355,   365,   370,   375,   380,   386,
     387,   390,   393,   394,   395,   396,   397,   398,   400
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "STRING", "BOOL", "LEFT",
  "RIGHT", "FORWARD", "BACK", "LEFTROT", "RIGHTROT", "TYPE_INTEGER",
  "TYPE_STRING", "TYPE_BOOL", "ID", "BEG", "EN", "FUNC", "RETURN", "ENTER",
  "DO", "UNTIL", "ARRAY", "ENDL", "EoF", "LOGOPERATOR", "CALL", "';'",
  "'['", "']'", "'('", "')'", "'='", "','", "'-'", "'+'", "$accept",
  "program", "value", "type_coversion", "function_argument",
  "function_declaration_begin", "function_declaration_end", "function",
  "function_call_begin", "function_call_end", "cycle", "sentence",
  "return", "group_variable_defenition", "assigning_value",
  "call_function", "expresion", "logical_expresion",
  "group_array_defenition", "variable_defenition", "assigning_defenition",
  "gropu_beg", "group", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    59,    91,
      93,    40,    41,    61,    44,    45,    43
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    38,    38,    38,    38,    38,    38,
      39,    39,    39,    39,    39,    39,    40,    40,    40,    41,
      41,    41,    41,    42,    42,    42,    43,    43,    44,    44,
      45,    45,    45,    45,    46,    46,    47,    47,    48,    48,
      48,    48,    49,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    51,    52,    53,    53,    53,
      53,    53,    54,    54,    54,    55,    55,    55,    55,    56,
      56,    57,    58,    58,    58,    58,    58,    58,    59
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     0,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     3,
       3,     5,     5,     3,     3,     3,     4,     3,     2,     2,
       3,     3,     3,     3,     0,     2,     6,     6,     1,     1,
       1,     1,     3,     3,     3,     4,     2,     4,     2,     4,
       2,     5,     3,     3,     6,     3,     6,     1,     1,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     1,     2,     2,     2,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     0,     1,     0,     0,     0,     0,    72,    34,    34,
       0,     8,     0,     0,     0,     6,     5,     7,    41,     0,
       0,    40,     0,     3,     4,     0,     2,    46,     0,    48,
       0,    50,     0,    34,    34,    10,    11,    12,    14,     0,
      59,    58,     0,    13,     0,    57,    14,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    38,    39,
      28,    69,     0,    71,    70,     0,    78,    73,    77,    75,
      74,    76,    34,    23,    34,    24,    34,    25,     0,    57,
      55,    53,    42,     0,    34,     0,     0,     0,    35,    34,
      43,    34,    34,    34,    44,    34,     0,    65,    66,    67,
       0,     0,    27,     0,    52,    68,    45,    47,    49,     0,
       0,    30,    31,    34,    34,    34,    32,    33,    60,    61,
      64,    63,     0,     0,     0,    34,    26,     0,    34,    34,
      15,    16,    18,    17,    34,    34,     0,    19,    20,     0,
      51,    54,    36,    37,    56,    34,    21,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    40,    41,   103,    13,    14,    15,    42,    43,
      16,    17,    18,    19,    20,    21,    44,    79,    22,    58,
      59,    25,    26
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -24
static const yytype_int16 yypact[] =
{
     -24,    44,   -24,    50,    97,   115,    14,   -24,     4,    33,
     122,   -24,   -11,     9,    84,   -24,   -24,   -24,   -24,    54,
      -1,   -24,    67,   -24,   -24,    60,   -24,    37,    63,    71,
      95,    98,   117,    10,     1,   -24,   -24,   -24,    92,   126,
       0,   -24,   109,   -24,    -5,    -4,    23,   -24,    29,   130,
     131,   132,   133,     2,   134,   135,   136,   -24,   -24,   -24,
     -24,   -24,   137,   -24,   -24,   138,   -24,   -24,   -24,   -24,
     -24,   -24,    10,   -24,    10,   -24,    10,   -24,    78,    13,
     -24,    89,   -24,    90,    10,   123,   124,   125,   -24,    10,
     -24,    33,    33,    33,   -24,    33,    84,   -24,   -24,   -24,
     120,   127,   -24,   110,   128,   -24,    89,    89,    89,   129,
     139,    89,    83,    10,    10,    10,    89,    83,   -24,   -24,
     -24,   -24,   141,   142,   143,    10,   -24,   144,    10,    10,
     -24,    89,    89,    89,    33,    33,   140,    89,    83,   145,
      89,    89,    13,    13,   -24,    10,    89,    83
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -24,   -24,    -6,   -24,   -24,   -24,   -24,   146,   -24,   -24,
     148,   -12,   149,   -24,   -24,   147,   -23,    -8,   -24,    17,
      20,   -24,    -2
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -63
static const yytype_int16 yytable[] =
{
      45,    48,    57,    47,    35,    36,    37,    35,    36,    37,
      78,    81,    60,    35,    36,    37,    46,   101,    23,    38,
      52,    24,    93,    90,    94,    46,   -62,    63,    12,    95,
      91,    92,    39,   -62,   102,    39,    35,    36,    37,    93,
      53,    39,    70,    33,     2,    71,    95,    34,    46,   106,
      96,   107,    83,   108,    84,    93,     3,     4,     5,     6,
       7,   111,    95,     8,     9,    27,   116,    10,    28,    11,
      72,    12,     3,     4,     5,     6,   112,    66,    73,     8,
       9,   117,    61,    10,   122,   118,   119,   120,    62,   121,
     131,   132,   133,   110,   123,    64,    54,    55,    56,     6,
       7,    65,   137,     8,    74,   140,   141,    10,   109,    93,
      75,    12,    29,    91,    92,    30,    95,   138,   -57,   -57,
      82,    83,   146,    84,    91,    92,   142,   143,    47,    47,
      31,    76,    77,    32,    49,    50,    51,   147,    85,    86,
      87,    88,   126,    89,   127,    97,    98,    99,   100,    27,
      29,    31,   104,   105,   124,   113,   114,   115,   136,   139,
     125,   128,   129,   134,   135,     0,     0,     0,     0,   130,
       0,    67,   144,    68,    69,     0,     0,     0,   145,     0,
       0,    80
};

static const yytype_int16 yycheck[] =
{
       8,     9,    14,     9,     3,     4,     5,     3,     4,     5,
      33,    34,    14,     3,     4,     5,    15,    15,     1,    15,
      31,     1,    26,    28,    28,    15,    26,    28,    27,    33,
      35,    36,    31,    33,    32,    31,     3,     4,     5,    26,
      31,    31,    25,    29,     0,    25,    33,    33,    15,    72,
      21,    74,    29,    76,    31,    26,    12,    13,    14,    15,
      16,    84,    33,    19,    20,    15,    89,    23,    18,    25,
      33,    27,    12,    13,    14,    15,    84,    17,    15,    19,
      20,    89,    28,    23,    96,    91,    92,    93,    34,    95,
     113,   114,   115,     3,    96,    28,    12,    13,    14,    15,
      16,    34,   125,    19,    33,   128,   129,    23,    30,    26,
      15,    27,    15,    35,    36,    18,    33,   125,    35,    36,
      28,    29,   145,    31,    35,    36,   134,   135,   134,   135,
      15,    33,    15,    18,    12,    13,    14,   145,    12,    13,
      14,    32,    32,    34,    34,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    34,    32,    32,    32,    15,    15,
      33,    33,    33,    22,    22,    -1,    -1,    -1,    -1,    30,
      -1,    25,    32,    25,    25,    -1,    -1,    -1,    33,    -1,
      -1,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,     0,    12,    13,    14,    15,    16,    19,    20,
      23,    25,    27,    42,    43,    44,    47,    48,    49,    50,
      51,    52,    55,    56,    57,    58,    59,    15,    18,    15,
      18,    15,    18,    29,    33,     3,     4,     5,    15,    31,
      39,    40,    45,    46,    53,    54,    15,    39,    54,    12,
      13,    14,    31,    31,    12,    13,    14,    48,    56,    57,
      59,    28,    34,    28,    28,    34,    17,    44,    47,    49,
      56,    57,    33,    15,    33,    15,    33,    15,    53,    54,
      52,    53,    28,    29,    31,    12,    13,    14,    32,    34,
      28,    35,    36,    26,    28,    33,    21,    15,    15,    15,
      15,    15,    32,    41,    15,    15,    53,    53,    53,    30,
       3,    53,    54,    32,    32,    32,    53,    54,    39,    39,
      39,    39,    48,    59,    34,    33,    32,    34,    33,    33,
      30,    53,    53,    53,    22,    22,    15,    53,    54,    15,
      53,    53,    54,    54,    32,    33,    53,    54
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
#line 43 "B.y"
    {std::cout<<"group->program"<<std::endl;;}
    break;

  case 3:
#line 44 "B.y"
    {(yyvsp[(1) - (2)]).a->addChildren((yyvsp[(2) - (2)]).a); std::cout<<"variable_defenition->program"<<std::endl;;}
    break;

  case 4:
#line 45 "B.y"
    {(yyvsp[(1) - (2)]).a->addChildren((yyvsp[(2) - (2)]).a); std::cout<<"assigning_defenition->program"<<std::endl;;}
    break;

  case 5:
#line 46 "B.y"
    {(yyvsp[(1) - (2)]).a->addChildren((yyvsp[(2) - (2)]).a); std::cout<<"cycle->program"<<std::endl;;}
    break;

  case 6:
#line 47 "B.y"
    {(yyvsp[(1) - (2)]).a->addChildren((yyvsp[(2) - (2)]).a); std::cout<<"function->program"<<std::endl;;}
    break;

  case 7:
#line 48 "B.y"
    {(yyvsp[(1) - (2)]).a->addChildren((yyvsp[(2) - (2)]).a); std::cout<<"function->program"<<std::endl;;}
    break;

  case 8:
#line 49 "B.y"
    {container_->print();(yyvsp[(1) - (2)]).a->execute();std::cout<<"val"<<std::endl;container->print();;}
    break;

  case 9:
#line 50 "B.y"
    {(yyval).a = std::make_shared<StartNode>(container); std::cout<<"Start"<<std::endl; container_->Up(); container->Up();;}
    break;

  case 10:
#line 63 "B.y"
    {std::cout<<"get NUMBER"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<ValueNode>(container, std::any((yyvsp[(1) - (1)]).i)));
            (yyval).a = n;
        ;}
    break;

  case 11:
#line 67 "B.y"
    {std::cout<<"get STRING"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<ValueNode>(container, std::any((yyvsp[(1) - (1)]).s)));
            (yyval).a = n;
        ;}
    break;

  case 12:
#line 71 "B.y"
    {std::cout<<"get BOOL"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<ValueNode>(container, std::any((yyvsp[(1) - (1)]).b)));
            (yyval).a = n;
        ;}
    break;

  case 13:
#line 75 "B.y"
    { std::cout<<"get function call"<<std::endl;
            (yyval).a = (yyvsp[(1) - (1)]).a;
        ;}
    break;

  case 14:
#line 78 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableNode>(container, (yyvsp[(1) - (1)]).s));
            if(!container_->find((yyvsp[(1) - (1)]).s)) throw std::runtime_error("Variable already exist"+(yyvsp[(1) - (1)]).s);
            (yyval).a = n;
        ;}
    break;

  case 15:
#line 83 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableArrayNode>(container, (yyvsp[(1) - (4)]).s, (yyvsp[(3) - (4)]).i));
            if(!container_->find((yyvsp[(1) - (4)]).s)) throw std::runtime_error("Variable already exist"+(yyvsp[(1) - (4)]).s);
            (yyval).a = n;
            std::cout<<"get Array"<<std::endl;
        ;}
    break;

  case 16:
#line 91 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<TypeConversionNode>(container, (yyvsp[(2) - (4)]).s, Type::INT_));
            n -> addChildren((yyvsp[(4) - (4)]).a);
            (yyval).a = n;
        ;}
    break;

  case 17:
#line 97 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<TypeConversionNode>(container, (yyvsp[(2) - (4)]).s, Type::BOOL_));
            n -> addChildren((yyvsp[(4) - (4)]).a);
            (yyval).a = n;
        ;}
    break;

  case 18:
#line 102 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<TypeConversionNode>(container, (yyvsp[(2) - (4)]).s, Type::STR_));
            n -> addChildren((yyvsp[(4) - (4)]).a);
            (yyval).a = n;
        ;}
    break;

  case 19:
#line 110 "B.y"
    {
            std::cout<<"function_argument"<<std::endl;
            container_->push((yyvsp[(1) - (3)]).s);
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionVariableDefinitionNode>(container, (yyvsp[(1) - (3)]).s));
            n->addChildren((yyvsp[(3) - (3)]).a);
            (yyval).a = n;
        ;}
    break;

  case 20:
#line 117 "B.y"
    {
            std::cout<<"function_argument"<<std::endl;
            container_->push((yyvsp[(1) - (3)]).s);
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionVariableDefinitionNode>(container, (yyvsp[(1) - (3)]).s));
            n->addChildren((yyvsp[(3) - (3)]).a);
            (yyval).a = n;
        ;}
    break;

  case 21:
#line 124 "B.y"
    {
            std::cout<<"function_argument"<<std::endl;
            container_->push((yyvsp[(3) - (5)]).s);
            (yyvsp[(1) - (5)]).a->addChildren((yyvsp[(5) - (5)]).a);
            std::dynamic_pointer_cast<FunctionVariableDefinitionNode>((yyvsp[(1) - (5)]).a)->addName((yyvsp[(3) - (5)]).s);
            (yyval).a = (yyvsp[(1) - (5)]).a;
        ;}
    break;

  case 22:
#line 131 "B.y"
    {
            std::cout<<"function_argument"<<std::endl;
            container_->push((yyvsp[(3) - (5)]).s);
            (yyvsp[(1) - (5)]).a->addChildren((yyvsp[(5) - (5)]).a);
            std::dynamic_pointer_cast<FunctionVariableDefinitionNode>((yyvsp[(1) - (5)]).a)->addName((yyvsp[(3) - (5)]).s);
            (yyval).a = (yyvsp[(1) - (5)]).a;
        ;}
    break;

  case 23:
#line 140 "B.y"
    {
            std::cout<<"function_declaration_begin"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionStartNode>(container, (yyvsp[(3) - (3)]).s, Type::INT_));
            container_->Up();
            (yyval).a = n;
        ;}
    break;

  case 24:
#line 146 "B.y"
    {
            std::cout<<"function_declaration_begin"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionStartNode>(container, (yyvsp[(3) - (3)]).s, Type::STR_));
            container_->Up();
            (yyval).a = n;
        ;}
    break;

  case 25:
#line 152 "B.y"
    {
            std::cout<<"function_declaration_begin"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionStartNode>(container, (yyvsp[(3) - (3)]).s, Type::BOOL_));
            container_->Up();
            (yyval).a = n;
        ;}
    break;

  case 26:
#line 160 "B.y"
    {
            std::cout<<"function_declaration_end"<<std::endl;
            (yyvsp[(1) - (4)]).a->addChildren((yyvsp[(3) - (4)]).a);
            (yyval).a = (yyvsp[(1) - (4)]).a;
        ;}
    break;

  case 27:
#line 165 "B.y"
    {
            (yyval).a = (yyvsp[(1) - (3)]).a;
        ;}
    break;

  case 28:
#line 170 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionDefinitionNode>(container, std::dynamic_pointer_cast<FunctionStartNode>((yyvsp[(1) - (2)]).a)->getName(), (yyvsp[(1) - (2)]).a));
            std::cout<<"function_declaration_end+group"<<std::endl;(yyvsp[(1) - (2)]).a->addChildren((yyvsp[(2) - (2)]).a); (yyval).a = n;
        ;}
    break;

  case 29:
#line 174 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionDefinitionNode>(container, std::dynamic_pointer_cast<FunctionStartNode>((yyvsp[(1) - (2)]).a)->getName(), (yyvsp[(1) - (2)]).a));
            std::cout<<"function_declaration_end->function"<<std::endl;(yyvsp[(1) - (2)]).a->addChildren((yyvsp[(2) - (2)]).a); (yyval).a = n;
        ;}
    break;

  case 30:
#line 179 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionCallNode>(container, (yyvsp[(1) - (3)]).s));
            n->addChildren((yyvsp[(3) - (3)]).a);
            (yyval).a = n;
        ;}
    break;

  case 31:
#line 184 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionCallNode>(container, (yyvsp[(1) - (3)]).s));
            n->addChildren((yyvsp[(3) - (3)]).a);
            (yyval).a = n;
        ;}
    break;

  case 32:
#line 189 "B.y"
    {(yyvsp[(1) - (3)]).a->addChildren((yyvsp[(3) - (3)]).a);;}
    break;

  case 33:
#line 190 "B.y"
    {(yyvsp[(1) - (3)]).a->addChildren((yyvsp[(3) - (3)]).a);;}
    break;

  case 35:
#line 192 "B.y"
    {(yyval).a = (yyvsp[(1) - (2)]).a;;}
    break;

  case 36:
#line 195 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<CycleNode>((yyvsp[(2) - (6)]).a, (yyvsp[(4) - (6)]).a, (yyvsp[(6) - (6)]).a));
            (yyval).a = n;
        ;}
    break;

  case 37:
#line 199 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<CycleNode>((yyvsp[(2) - (6)]).a, (yyvsp[(4) - (6)]).a, (yyvsp[(6) - (6)]).a));
            (yyval).a = n;
        ;}
    break;

  case 38:
#line 204 "B.y"
    {(yyval).a = (yyvsp[(1) - (1)]).a;;}
    break;

  case 39:
#line 205 "B.y"
    {(yyval).a = (yyvsp[(1) - (1)]).a;;}
    break;

  case 40:
#line 206 "B.y"
    {(yyval).a = (yyvsp[(1) - (1)]).a;;}
    break;

  case 41:
#line 207 "B.y"
    {(yyval).a = (yyvsp[(1) - (1)]).a;;}
    break;

  case 42:
#line 210 "B.y"
    {
        auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionReturnNode>());
        auto n1 = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableNode>(container, (yyvsp[(2) - (3)]).s));
        n->addChildren(n1);
        (yyval).a = n;
        ;}
    break;

  case 43:
#line 216 "B.y"
    {
        auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionReturnNode>());
        n->addChildren((yyvsp[(2) - (3)]).a);
        (yyval).a = n;
        ;}
    break;

  case 44:
#line 221 "B.y"
    {
        auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionReturnNode>());
        n->addChildren((yyvsp[(2) - (3)]).a);
        (yyval).a = n;
        ;}
    break;

  case 45:
#line 229 "B.y"
    {
            container_->push((yyvsp[(2) - (4)]).s);
            std::cout<<"TYPE_INTEGER ID '=' expresion -> group_variable_defenition"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableDefinitionNode>(container, std::string((yyvsp[(2) - (4)]).s), Type::INT_));
            n->addChildren((yyvsp[(4) - (4)]).a);
            (yyval).a = n;
            (yyval).t = Type::INT_;
            ;}
    break;

  case 46:
#line 238 "B.y"
    {
            container_->push((yyvsp[(2) - (2)]).s);
            std::cout<<"TYPE_INTEGER ID '=' expresion -> group_variable_defenition"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableDefinitionNode>(container, std::string((yyvsp[(2) - (2)]).s), Type::INT_));
            auto n1 = std::dynamic_pointer_cast<ASTNode>(std::make_shared<DefaultValueNode>(Type::INT_));
            n->addChildren(n1);
            (yyval).a = n;
            (yyval).t = Type::INT_;
            ;}
    break;

  case 47:
#line 248 "B.y"
    {
            container_->push((yyvsp[(2) - (4)]).s);
            std::cout<<"TYPE_INTEGER ID '=' expresion -> group_variable_defenition"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableDefinitionNode>(container, std::string((yyvsp[(2) - (4)]).s), Type::STR_));
            n->addChildren((yyvsp[(4) - (4)]).a);
            (yyval).a = n;
            (yyval).t = Type::STR_;
            ;}
    break;

  case 48:
#line 257 "B.y"
    {
            container_->push((yyvsp[(2) - (2)]).s);
            std::cout<<"TYPE_STRING ID -> group_variable_defenition"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableDefinitionNode>(container, std::string((yyvsp[(2) - (2)]).s), Type::STR_));
            auto n1 = std::dynamic_pointer_cast<ASTNode>(std::make_shared<DefaultValueNode>(Type::STR_));
            n->addChildren(n1);
            (yyval).a = n;
            (yyval).t = Type::STR_;
            ;}
    break;

  case 49:
#line 267 "B.y"
    {
            container_->push((yyvsp[(2) - (4)]).s);
            std::cout<<"TYPE_BOOL ID '=' expresion -> group_variable_defenition"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableDefinitionNode>(container, std::string((yyvsp[(2) - (4)]).s), Type::BOOL_));
            n->addChildren((yyvsp[(4) - (4)]).a);
            (yyval).a = n;
            (yyval).t = Type::BOOL_;
            ;}
    break;

  case 50:
#line 276 "B.y"
    {
            container_->push((yyvsp[(2) - (2)]).s);
            std::cout<<"TYPE_BOOL ID  -> group_variable_defenition"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<VariableDefinitionNode>(container, std::string((yyvsp[(2) - (2)]).s), Type::BOOL_));
            auto n1 = std::dynamic_pointer_cast<ASTNode>(std::make_shared<DefaultValueNode>(Type::BOOL_));
            n->addChildren(n1);
            (yyval).a = n;
            (yyval).t = Type::BOOL_;
        ;}
    break;

  case 51:
#line 286 "B.y"
    {
        container_->push((yyvsp[(3) - (5)]).s);
        std::cout<<"group_variable_defenition ',' ID '=' expresion -> group_variable_defenition"<<std::endl;
        (yyvsp[(1) - (5)]).a->addChildren((yyvsp[(5) - (5)]).a);
        std::dynamic_pointer_cast<VariableDefinitionNode>((yyvsp[(1) - (5)]).a)->addVariableName((yyvsp[(3) - (5)]).s);
        (yyval).a = (yyvsp[(1) - (5)]).a;
        ;}
    break;

  case 52:
#line 294 "B.y"
    {
        std::cout<<"group_variable_defenition ',' ID '=' expresion -> group_variable_defenition"<<std::endl;
        container_->push((yyvsp[(3) - (3)]).s);
        auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<DefaultValueNode>((yyvsp[(1) - (3)]).t));
        (yyvsp[(1) - (3)]).a->addChildren(n);
        std::dynamic_pointer_cast<VariableDefinitionNode>((yyvsp[(1) - (3)]).a)->addVariableName((yyvsp[(3) - (3)]).s);
        (yyval).a = (yyvsp[(1) - (3)]).a;
        ;}
    break;

  case 53:
#line 304 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<EqualNode>(container, (yyvsp[(1) - (3)]).s));
            n->addChildren((yyvsp[(3) - (3)]).a);
            (yyval).a = n;
        ;}
    break;

  case 54:
#line 309 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<EqualArrayNode>(container, (yyvsp[(1) - (6)]).s, 0));
            n->addChildren((yyvsp[(6) - (6)]).a);
            n->addChildren((yyvsp[(3) - (6)]).a);
            (yyval).a = n;
        ;}
    break;

  case 55:
#line 315 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<EqualNode>(container, (yyvsp[(1) - (3)]).s));
            n->addChildren((yyvsp[(3) - (3)]).a);
            (yyval).a = n;
        ;}
    break;

  case 56:
#line 322 "B.y"
    {
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<FunctionCallOperatorNode>(container,(yyvsp[(3) - (6)]).s, (yyvsp[(5) - (6)]).s));
            (yyval).a = n
        ;}
    break;

  case 57:
#line 327 "B.y"
    {(yyval).a = (yyvsp[(1) - (1)]).a;}
    break;

  case 58:
#line 328 "B.y"
    {(yyval).a = (yyvsp[(1) - (1)]).a;;}
    break;

  case 59:
#line 329 "B.y"
    {(yyval).a = (yyvsp[(1) - (1)]).a;}
    break;

  case 60:
#line 330 "B.y"
    {
            std::cout<<"expresion '-' -> expresion"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<ArithmeticNode>(container, Operation::MIN));
            n->addChildren((yyvsp[(1) - (3)]).a);
            n->addChildren((yyvsp[(3) - (3)]).a);
            (yyval).a = n;
            std::cout<<"MIN something"<<std::endl;;}
    break;

  case 61:
#line 337 "B.y"
    {
            std::cout<<"expresion '+' -> expresion"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<ArithmeticNode>(container, Operation::PLUS));
            n->addChildren((yyvsp[(1) - (3)]).a);
            n->addChildren((yyvsp[(3) - (3)]).a);
            (yyval).a = n;
            std::cout<<"PLUS somethinf"<<std::endl;;}
    break;

  case 62:
#line 346 "B.y"
    {(yyval).a = (yyvsp[(1) - (1)]).a;}
    break;

  case 63:
#line 347 "B.y"
    {
            std::cout<<"expresion EQUAL -> expresion"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<LogicalArithmeticNode>(container, LogicalOperators::QL));
            n->addChildren((yyvsp[(1) - (3)]).a);
            n->addChildren((yyvsp[(3) - (3)]).a);
            (yyval).a = n;
            std::cout<<"QL something"<<std::endl;
            ;}
    break;

  case 64:
#line 355 "B.y"
    {
            std::cout<<"expresion LOGOPERATOR -> expresion"<<std::endl;
            auto n = std::dynamic_pointer_cast<ASTNode>(std::make_shared<LogicalArithmeticNode>(container, (yyvsp[(2) - (3)]).s));
            n->addChildren((yyvsp[(1) - (3)]).a);
            n->addChildren((yyvsp[(3) - (3)]).a);
            (yyval).a = n;
            std::cout<<"Compare something"<<std::endl;
            ;}
    break;

  case 65:
#line 365 "B.y"
    {
            auto n = std::make_shared<VariableArrayDefinitionNode>(container, (yyvsp[(3) - (3)]).s, Type::INT_);
            (yyval).a = n;
            container_->push((yyvsp[(3) - (3)]).s);
        ;}
    break;

  case 66:
#line 370 "B.y"
    {
           auto n = std::make_shared<VariableArrayDefinitionNode>(container, (yyvsp[(3) - (3)]).s, Type::STR_);
           (yyval).a = n;
           container_->push((yyvsp[(3) - (3)]).s);
        ;}
    break;

  case 67:
#line 375 "B.y"
    {
           auto n = std::make_shared<VariableArrayDefinitionNode>(container, (yyvsp[(3) - (3)]).s, Type::BOOL_);
           (yyval).a = n;
           container_->push((yyvsp[(3) - (3)]).s);
        ;}
    break;

  case 68:
#line 380 "B.y"
    {
            std::dynamic_pointer_cast<VariableArrayDefinitionNode>((yyvsp[(1) - (3)]).a)->addVariableName((yyvsp[(3) - (3)]).s);
            (yyval).a = (yyvsp[(1) - (3)]).a;
        ;}
    break;

  case 69:
#line 386 "B.y"
    {(yyval).a = (yyvsp[(1) - (2)]).a;;}
    break;

  case 70:
#line 387 "B.y"
    {(yyval).a = (yyvsp[(1) - (2)]).a;;}
    break;

  case 71:
#line 390 "B.y"
    {(yyval).a = (yyvsp[(1) - (2)]).a;;}
    break;

  case 72:
#line 393 "B.y"
    {std::cout<<"Begin of gropup"<<std::endl; (yyval).a = std::make_shared<StartNode>(container);}
    break;

  case 73:
#line 394 "B.y"
    {(yyvsp[(1) - (2)]).a->addChildren((yyvsp[(2) - (2)]).a); (yyval).a = (yyvsp[(1) - (2)]).a;;}
    break;

  case 74:
#line 395 "B.y"
    {std::cout<<"variable_defenition->group"<<std::endl;(yyvsp[(1) - (2)]).a->addChildren((yyvsp[(2) - (2)]).a); (yyval).a = (yyvsp[(1) - (2)]).a;;}
    break;

  case 75:
#line 396 "B.y"
    {(yyvsp[(1) - (2)]).a->addChildren((yyvsp[(2) - (2)]).a);;}
    break;

  case 76:
#line 397 "B.y"
    {(yyvsp[(1) - (2)]).a->addChildren((yyvsp[(2) - (2)]).a);;}
    break;

  case 77:
#line 398 "B.y"
    {(yyvsp[(1) - (2)]).a->addChildren((yyvsp[(2) - (2)]).a); (yyval).a = (yyvsp[(1) - (2)]).a;;}
    break;

  case 78:
#line 400 "B.y"
    {(yyval).a = (yyvsp[(1) - (2)]).a;;}
    break;


/* Line 1267 of yacc.c.  */
#line 2126 "lab.tab.c"
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


#line 402 "B.y"

int main() {
    yyin = fopen ("./test.txt", "r");
    try{
    yyparse();
    robot->print();
    } catch(std::runtime_error b){
    std::cout<<b.what()<<std::endl;
    container->print();
    }
    fclose (yyin);
    std::cout << "Hello, World!" << std::endl;
}
    


