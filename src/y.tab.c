/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "COOL.y" /* yacc.c:339  */

void yyerror (char *s);
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "cool.h"
#include "typeChecking.h"

extern FILE *yyin;	
int curr_lineno=0;
table *t;
TAC *tactable;
int yylex();
extern entry* node;
int omerrs = 0;               /* number of errors in lexing and parsing */

#line 83 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    ELSE = 259,
    FI = 260,
    IF = 261,
    IFX = 286,
    IN = 262,
    INHERITS = 263,
    LET = 264,
    LOOP = 265,
    POOL = 266,
    THEN = 267,
    WHILE = 268,
    CASE = 269,
    ESAC = 270,
    OF = 271,
    DARROW = 272,
    NEW = 273,
    ISVOID = 274,
    STR_CONST = 275,
    INT_CONST = 276,
    TRUE = 277,
    FALSE = 284,
    TYPEID = 278,
    OBJECTID = 279,
    ASSIGN = 280,
    NOT = 281,
    LE = 282,
    ERROR = 283,
    PARENTHESIS_O = 297,
    PARENTHESIS_C = 298
  };
#endif
/* Tokens.  */
#define CLASS 258
#define ELSE 259
#define FI 260
#define IF 261
#define IFX 286
#define IN 262
#define INHERITS 263
#define LET 264
#define LOOP 265
#define POOL 266
#define THEN 267
#define WHILE 268
#define CASE 269
#define ESAC 270
#define OF 271
#define DARROW 272
#define NEW 273
#define ISVOID 274
#define STR_CONST 275
#define INT_CONST 276
#define TRUE 277
#define FALSE 284
#define TYPEID 278
#define OBJECTID 279
#define ASSIGN 280
#define NOT 281
#define LE 282
#define ERROR 283
#define PARENTHESIS_O 297
#define PARENTHESIS_C 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "COOL.y" /* yacc.c:355  */

	char* sval;
	int ival;
	char *error_msg;
	nodeType *nval;

#line 191 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 208 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    46,    53,    51,    48,    52,    50,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    42,
      56,    57,     2,     2,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,    55,     2,     2,     2,
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
       5,     6,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    25,    26,
      27,    28,    29,    30,    24,     2,     7,     2,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    77,    79,    81,    83,    91,    97,   103,
     109,   118,   120,   122,   124,   133,   135,   137,   139,   141,
     149,   155,   157,   185,   187,   191,   193,   197,   201,   203,
     207,   213,   216,   218,   225,   227,   231,   236,   244,   252,
     254,   259,   261,   263,   265,   267,   269,   271,   273,   275,
     277,   279,   281,   283,   285,   287,   289,   291,   293,   295,
     297,   301,   303,   305,   307
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "ELSE", "FI", "IF", "IFX", "IN",
  "INHERITS", "LET", "LOOP", "POOL", "THEN", "WHILE", "CASE", "ESAC", "OF",
  "DARROW", "NEW", "ISVOID", "STR_CONST", "INT_CONST", "TRUE", "FALSE",
  "TYPEID", "OBJECTID", "ASSIGN", "NOT", "LE", "ERROR", "\"<\"", "\"=\"",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"~\"", "\"@\"", "\".\"",
  "PARENTHESIS_O", "PARENTHESIS_C", "';'", "'{'", "'}'", "'('", "')'",
  "':'", "','", "'@'", "'.'", "'+'", "'-'", "'*'", "'/'", "'~'", "'<'",
  "'='", "$accept", "program", "class_list", "class", "feature_list",
  "feature", "formal", "formals_list", "exprs_comma", "exprs_semi", "case",
  "cases", "opt_assign", "let_expr", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   287,   258,   259,   260,   261,   286,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   284,   278,   279,   280,   281,   282,
     283,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,    59,   123,   125,    40,    41,    58,    44,    64,
      46,    43,    45,    42,    47,   126,    60,    61
};
# endif

#define YYPACT_NINF -123

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-123)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-3)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    -7,    38,    67,    86,  -123,  -123,    -4,  -123,    24,
    -123,    46,    14,  -123,    29,    49,   -34,    50,    15,    58,
      35,  -123,   -24,    71,  -123,    60,    72,    79,  -123,    82,
      64,    59,    63,  -123,    37,    80,  -123,  -123,  -123,  -123,
      95,   113,   116,    96,   124,   365,  -123,  -123,  -123,    99,
     127,  -123,   365,    36,   365,   365,   129,   365,  -123,  -123,
    -123,  -123,     7,   365,    54,   365,   365,   432,   125,   112,
     269,   108,   118,  -123,   147,   307,  -123,   110,   365,   167,
     432,   128,  -123,   205,   -25,   348,   432,   365,   132,   145,
     365,   365,   365,   365,   365,   365,  -123,   374,   247,   365,
      36,   149,   365,   152,   432,  -123,    55,   432,  -123,  -123,
     387,  -123,  -123,   442,   133,   130,   432,   432,   432,   432,
     432,   432,  -123,  -123,   403,    66,  -123,    80,   227,   137,
    -123,    68,  -123,   365,  -123,   153,   289,  -123,   365,    -5,
    -123,   160,  -123,  -123,   432,   157,  -123,    65,    76,   365,
      36,   174,   327,  -123,  -123,   432,  -123,   365,  -123,    88,
     416,  -123,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     4,     0,     1,     0,
       5,     0,     0,     6,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,     8,     0,     0,     0,    11,     0,
       0,     0,     0,    21,     0,     0,    14,     7,    13,    10,
       0,     0,     0,     0,     0,     0,    19,     9,    20,     0,
       0,    22,     0,     0,     0,     0,     0,     0,    61,    62,
      63,    64,    60,     0,     0,     0,     0,    30,     0,     0,
       0,     0,     0,    46,     0,     0,    48,    49,     0,     0,
      58,     0,    44,     0,     0,     0,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,     0,     0,     0,    34,    37,     0,    23,    45,    43,
       0,    25,    59,    56,     0,     0,    50,    51,    52,    53,
      55,    57,    18,    16,     0,     0,    33,     0,     0,     0,
      28,     0,    38,     0,    26,     0,     0,    15,     0,     0,
      42,     0,    47,    29,    24,     0,    39,     0,     0,     0,
       0,     0,     0,    40,    41,    31,    32,     0,    35,     0,
       0,    36,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,   190,   185,    26,   162,  -123,  -122,  -123,
      77,  -123,    87,   -99,   -45
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    18,    19,    33,    34,   106,    83,
     130,   131,    46,    73,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,   126,    31,   149,    87,    11,     1,    70,     2,    74,
      75,    22,    77,    23,   147,    15,    25,   111,    80,    84,
      85,    86,    32,    97,    88,    89,    90,    91,    92,    93,
     159,    94,    95,   104,    78,     6,    15,    71,   110,    12,
      16,    16,   113,   150,    27,   116,   117,   118,   119,   120,
     121,   156,    79,   124,   125,    81,    27,   128,    17,    26,
      52,    16,    72,     7,    53,    25,    13,     8,    54,    55,
     138,    14,    20,    56,    57,    58,    59,    60,    61,    29,
      62,   154,    63,    43,   142,    44,    -2,     9,   144,     2,
      16,    21,    24,   148,   129,    87,    35,    64,    82,    65,
      28,   132,    36,   133,   155,    87,    41,    45,    40,    66,
      42,   153,   160,   133,    37,    88,    89,    90,    91,    92,
      93,    38,    94,    95,    39,    88,    89,    90,    91,    92,
      93,    52,    94,    95,   161,    53,   133,    47,    48,    54,
      55,    49,    68,    50,    56,    57,    58,    59,    60,    61,
      31,    62,    69,    63,    76,    98,   100,   114,   102,    88,
      89,    90,    91,    92,    93,   101,    94,    95,    64,    96,
      65,   115,   108,    52,   127,   136,    87,    53,   129,   145,
      66,    54,    55,   135,   141,   151,    56,    57,    58,    59,
      60,    61,   157,    62,    10,    63,    88,    89,    90,    91,
      92,    93,   152,    94,    95,    30,    51,     0,   143,     0,
      64,    52,    65,   105,   139,    53,     0,     0,     0,    54,
      55,     0,    66,     0,    56,    57,    58,    59,    60,    61,
       0,    62,     0,    63,     0,     0,     0,     0,     0,   140,
       0,     0,     0,     0,     0,     0,     0,     0,    64,   109,
      65,     0,     0,    52,     0,     0,    87,    53,     0,     0,
      66,    54,    55,     0,     0,     0,    56,    57,    58,    59,
      60,    61,     0,    62,     0,    63,    88,    89,    90,    91,
      92,    93,    99,    94,    95,     0,     0,     0,     0,     0,
      64,   123,    65,     0,     0,    52,     0,     0,    87,    53,
       0,     0,    66,    54,    55,     0,     0,     0,    56,    57,
      58,    59,    60,    61,     0,    62,     0,    63,    88,    89,
      90,    91,    92,    93,   103,    94,    95,     0,     0,     0,
       0,     0,    64,    52,    65,   146,    87,    53,     0,     0,
       0,    54,    55,     0,    66,     0,    56,    57,    58,    59,
      60,    61,     0,    62,     0,    63,    88,    89,    90,    91,
      92,    93,     0,    94,    95,     0,     0,     0,     0,     0,
      64,    52,    65,   158,     0,    53,     0,    87,     0,    54,
      55,     0,    66,     0,    56,    57,    58,    59,    60,    61,
       0,    62,     0,    63,   112,     0,     0,    88,    89,    90,
      91,    92,    93,    87,    94,    95,     0,     0,    64,     0,
      65,     0,     0,     0,     0,     0,    87,     0,   122,     0,
      66,     0,     0,    88,    89,    90,    91,    92,    93,   134,
      94,    95,    87,     0,     0,     0,    88,    89,    90,    91,
      92,    93,     0,    94,    95,    87,     0,   137,     0,     0,
       0,     0,    88,    89,    90,    91,    92,    93,   162,    94,
      95,    87,     0,     0,     0,    88,    89,    90,    91,    92,
      93,    -3,    94,    95,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,    92,    93,     0,    94,    95,
       0,    88,    89,    90,    91,    92,    93,     0,    94,    95
};

static const yytype_int16 yycheck[] =
{
      45,   100,    26,     8,    29,     9,     1,    52,     3,    54,
      55,    45,    57,    47,   136,     1,     1,    42,    63,    64,
      65,    66,    46,    68,    49,    50,    51,    52,    53,    54,
     152,    56,    57,    78,    27,    42,     1,     1,    83,    43,
      26,    26,    87,    48,    18,    90,    91,    92,    93,    94,
      95,   150,    45,    98,    99,     1,    30,   102,    44,    44,
       6,    26,    26,    25,    10,     1,    42,     0,    14,    15,
       4,    25,    43,    19,    20,    21,    22,    23,    24,    44,
      26,     5,    28,    46,    16,    48,     0,     1,   133,     3,
      26,    42,    42,   138,    26,    29,    25,    43,    44,    45,
      42,    46,    42,    48,   149,    29,    47,    27,    44,    55,
      47,    46,   157,    48,    42,    49,    50,    51,    52,    53,
      54,    42,    56,    57,    42,    49,    50,    51,    52,    53,
      54,     6,    56,    57,    46,    10,    48,    42,    25,    14,
      15,    25,    43,    47,    19,    20,    21,    22,    23,    24,
      26,    26,    25,    28,    25,    43,    48,    25,    11,    49,
      50,    51,    52,    53,    54,    47,    56,    57,    43,    44,
      45,    26,    44,     6,    25,    45,    29,    10,    26,    26,
      55,    14,    15,    50,    47,    25,    19,    20,    21,    22,
      23,    24,    18,    26,     4,    28,    49,    50,    51,    52,
      53,    54,    45,    56,    57,    20,    44,    -1,   131,    -1,
      43,     6,    45,    46,   127,    10,    -1,    -1,    -1,    14,
      15,    -1,    55,    -1,    19,    20,    21,    22,    23,    24,
      -1,    26,    -1,    28,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    -1,    -1,     6,    -1,    -1,    29,    10,    -1,    -1,
      55,    14,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    26,    -1,    28,    49,    50,    51,    52,
      53,    54,    13,    56,    57,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    -1,    -1,     6,    -1,    -1,    29,    10,
      -1,    -1,    55,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    26,    -1,    28,    49,    50,
      51,    52,    53,    54,    17,    56,    57,    -1,    -1,    -1,
      -1,    -1,    43,     6,    45,    46,    29,    10,    -1,    -1,
      -1,    14,    15,    -1,    55,    -1,    19,    20,    21,    22,
      23,    24,    -1,    26,    -1,    28,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,
      43,     6,    45,    46,    -1,    10,    -1,    29,    -1,    14,
      15,    -1,    55,    -1,    19,    20,    21,    22,    23,    24,
      -1,    26,    -1,    28,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    29,    56,    57,    -1,    -1,    43,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    29,    -1,    44,    -1,
      55,    -1,    -1,    49,    50,    51,    52,    53,    54,    42,
      56,    57,    29,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    29,    -1,    44,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    42,    56,
      57,    29,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    29,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      -1,    49,    50,    51,    52,    53,    54,    -1,    56,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    59,    60,    61,    42,    25,     0,     1,
      61,     9,    43,    42,    25,     1,    26,    44,    62,    63,
      43,    42,    45,    47,    42,     1,    44,    63,    42,    44,
      62,    26,    46,    64,    65,    25,    42,    42,    42,    42,
      44,    47,    47,    46,    48,    27,    70,    42,    25,    25,
      47,    64,     6,    10,    14,    15,    19,    20,    21,    22,
      23,    24,    26,    28,    43,    45,    55,    72,    43,    25,
      72,     1,    26,    71,    72,    72,    25,    72,    27,    45,
      72,     1,    44,    67,    72,    72,    72,    29,    49,    50,
      51,    52,    53,    54,    56,    57,    44,    72,    43,    13,
      48,    47,    11,    17,    72,    46,    66,    72,    44,    44,
      72,    42,    46,    72,    25,    26,    72,    72,    72,    72,
      72,    72,    44,    44,    72,    72,    71,    25,    72,    26,
      68,    69,    46,    48,    42,    50,    45,    44,     4,    70,
      12,    47,    16,    68,    72,    26,    46,    66,    72,     8,
      48,    25,    45,    46,     5,    72,    71,    18,    46,    66,
      72,    46,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    60,    60,    61,    61,    61,
      61,    62,    62,    62,    62,    63,    63,    63,    63,    63,
      64,    65,    65,    66,    66,    67,    67,    68,    69,    69,
      70,    71,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     3,     6,     5,     8,
       7,     2,     2,     3,     3,     9,     8,     7,     8,     4,
       3,     1,     3,     1,     3,     2,     3,     6,     1,     2,
       2,     6,     6,     3,     3,     7,     8,     3,     4,     5,
       6,     7,     5,     3,     2,     3,     2,     5,     2,     2,
       3,     3,     3,     3,     2,     3,     3,     3,     2,     3,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 73 "COOL.y" /* yacc.c:1646  */
    {}
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 78 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].ival);}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 80 "COOL.y" /* yacc.c:1646  */
    {yyerror("Incorrect class definition\n");}
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 82 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].ival);}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 84 "COOL.y" /* yacc.c:1646  */
    {yyerror("Incorrect class definition\n");}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 92 "COOL.y" /* yacc.c:1646  */
    { 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 98 "COOL.y" /* yacc.c:1646  */
    { 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 104 "COOL.y" /* yacc.c:1646  */
    { 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 110 "COOL.y" /* yacc.c:1646  */
    { 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-1].sval);}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 121 "COOL.y" /* yacc.c:1646  */
    {yyerror("Error in feature\n");}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 123 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-1].sval);}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 125 "COOL.y" /* yacc.c:1646  */
    {
			yyerror("Error in subsequent features\n");
		}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 134 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-1].sval);}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 136 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=ex(NULL);}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 138 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=ex(NULL);}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 140 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=ex((yyvsp[-1].sval));}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 142 "COOL.y" /* yacc.c:1646  */
    {	
		(yyval.sval) = ex(opr(ASSIGN,3,identifier((yyvsp[-3].sval)),(yyvsp[-1].sval),(yyvsp[0].sval)));/**/
	}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 150 "COOL.y" /* yacc.c:1646  */
    {
		(yyval.sval)=identifier((yyvsp[-2].sval));
	}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 156 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 158 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = opr(',', 2, NULL, NULL);}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 186 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 188 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = opr(',', 2, NULL, (yyvsp[-2].sval));}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 192 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=ex((yyvsp[-1].sval));}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 194 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = ex(opr(';', 2,NULL,(yyvsp[-1].sval)));}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 198 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr(DARROW,3,identifier((yyvsp[-5].sval)),(yyvsp[-3].sval),(yyvsp[-1].sval));/*a:A<=(5+3);*/}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 202 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 204 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 208 "COOL.y" /* yacc.c:1646  */
    {
			(yyval.sval)=opr('=',1,(yyvsp[0].sval));
		}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 215 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = opr(IN, 3, identifier((yyvsp[-5].sval)),identifier((yyvsp[-2].sval)),(yyvsp[-1].sval));}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 217 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = opr(LET, 3, identifier((yyvsp[-5].sval)),identifier((yyvsp[-2].sval)),(yyvsp[-1].sval));}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 219 "COOL.y" /* yacc.c:1646  */
    {
			yyerror("Error in let expression.\n");
			(yyval.sval)=(yyvsp[0].sval);
		}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 226 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr(ASSIGN,2,identifier((yyvsp[-2].sval)),(yyvsp[0].sval));}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 228 "COOL.y" /* yacc.c:1646  */
    {	/*operator identified by @*/
		(yyval.sval)=opr((yyvsp[-5].sval),3,(yyvsp[-6].sval),(yyvsp[-4].sval),(yyvsp[-2].sval));
	}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 232 "COOL.y" /* yacc.c:1646  */
    {
		/*operator identified by (*/
		(yyval.sval)=opr((yyvsp[-2].ival),3,(yyvsp[-7].sval),(yyvsp[-3].sval),(yyvsp[-1].sval));
	}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 237 "COOL.y" /* yacc.c:1646  */
    { 
			curr_lineno++;
			node=create_entry((yyvsp[-2].sval),3,curr_lineno,5,0,"0");
			t=insert_entry(node,t);	
			/* operator identified by ' ' */
			(yyval.sval)=opr(' ',1,(yyvsp[-2].sval));	   
		}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 245 "COOL.y" /* yacc.c:1646  */
    { 
			curr_lineno++;
			node=create_entry((yyvsp[-3].sval),3,curr_lineno,5,0,(yyvsp[-1].sval));
			t=insert_entry(node,t);
			/* operator identified by ')' */
			(yyval.sval)=opr(')',2,(yyvsp[-3].sval),(yyvsp[-1].sval));		   
		}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 253 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr('.',2,(yyvsp[-4].sval),(yyvsp[-2].sval));}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 255 "COOL.y" /* yacc.c:1646  */
    {
		/*operator identified by a */
		(yyval.sval)=opr('a',3,(yyvsp[-5].sval),(yyvsp[-3].sval),(yyvsp[-1].sval));
	}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 260 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = opr(IF, 3, (yyvsp[-5].sval), (yyvsp[-3].sval), (yyvsp[-1].sval));/**/}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 262 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = opr(WHILE, 2, (yyvsp[-3].sval), (yyvsp[-1].sval));/**/}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 264 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[-1].sval);}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 266 "COOL.y" /* yacc.c:1646  */
    {;}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 268 "COOL.y" /* yacc.c:1646  */
    {yyerror("Incorrect expression\n");}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 270 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-1].ival);}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 272 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr(CASE,2,(yyvsp[-3].sval),(yyvsp[-1].sval));}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 274 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=identifier((yyvsp[0].sval));}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 276 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr((yyvsp[-1].ival),1,(yyvsp[0].sval));}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 278 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr('+',2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 280 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr('-',2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 282 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr('*',2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 284 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr('/',2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 286 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr('~',1,(yyvsp[0].sval));/**/}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 288 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr('<',2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 290 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr((yyvsp[-1].ival),2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 292 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr(285,2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 294 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr(NOT,1,(yyvsp[0].sval));}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 296 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-1].sval);}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 298 "COOL.y" /* yacc.c:1646  */
    {
		(yyval.sval)=identifier((yyvsp[0].sval));
	}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 302 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=str_constant((yyvsp[0].sval));}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 304 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=integer_constant((yyvsp[0].ival));}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 306 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=bool_constant((yyvsp[0].sval));}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 308 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=bool_constant((yyvsp[0].sval));}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1881 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 311 "COOL.y" /* yacc.c:1906  */


void yyerror(char *s)
{
	fprintf(stderr,"%s\n",s);
	omerrs++;
	if(omerrs>50) 
 	{
 		fprintf(stdout, "More than 50 errors\n"); 
 		exit(1);
 	}
}
int main(int argc, char **argv)
{	
	t = initialize();

	tactable=(TAC *)malloc(sizeof(TAC));
	tactable->nrows=0;
	tactable->tacRow=NULL;

	printf("Inside main\n");
	FILE * fp= fopen(argv[1], "r");
	yyin = fp;
	printf("Read the input file, continue with Lexing and Parsing\n");
	printf("Performing Lexical analysis......\n\n");
	yyparse ( );
	printf("\n\033[0;32mParsing completed.\033[0m\n\n");
	printf("Symbol Table:\n");
	display_table(t);
	display_tac_table(tactable);
	CFG* cfg = create_cfg(tactable);
	/*
	int strRed1=strengthReduction(tactable);
	display_tac_table(tactable);
	int conProp1=constantPropagation(tactable);
	display_tac_table(tactable);
	int conFold1=constantFolding(tactable);
	display_tac_table(tactable);
	*/
	//int deadEli1=deadcodeElimination(tactable);
	//display_tac_table(tactable);
	//int copyProp1=copyPropagation(tactable);
	//display_tac_table(tactable);
	//int commonSubExpr1=commonSubExprElimination(tactable);
	//display_tac_table(tactable);
	return 0;
}
