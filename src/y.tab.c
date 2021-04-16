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
#include "cool.h"
#include "typeChecking.h"

extern FILE *yyin;	
int curr_lineno=0;
table *t;
int yylex();
extern entry* node;
int omerrs = 0;               /* number of errors in lexing and parsing */

#line 81 "y.tab.c" /* yacc.c:339  */

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
    PARENTHESIS_O = 295,
    PARENTHESIS_C = 296
  };
#endif
/* Tokens.  */
#define CLASS 258
#define ELSE 259
#define FI 260
#define IF 261
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
#define PARENTHESIS_O 295
#define PARENTHESIS_C 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "COOL.y" /* yacc.c:355  */

	char* sval;
	int ival;
	char *error_msg;

#line 186 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 203 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   471

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      44,    45,    52,    50,    47,    51,    49,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    41,
      55,    56,     2,     2,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,    54,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    24,    25,
      26,    27,    28,    29,    23,     2,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    74,    76,    77,    79,    87,    93,    99,
     105,   113,   115,   116,   118,   124,   126,   128,   130,   132,
     140,   144,   146,   174,   176,   180,   182,   186,   190,   192,
     196,   197,   203,   206,   208,   212,   214,   218,   223,   231,
     239,   241,   246,   248,   250,   252,   253,   254,   256,   258,
     260,   262,   264,   266,   268,   270,   272,   274,   276,   278,
     280,   282,   284,   286,   288,   290
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "ELSE", "FI", "IF", "IN",
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
       0,   256,   285,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   284,   278,   279,   280,   281,   282,   283,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,    59,   123,   125,    40,    41,    58,    44,    64,    46,
      43,    45,    42,    47,   126,    60,    61
};
# endif

#define YYPACT_NINF -129

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-129)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-3)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      63,   -35,   -11,    30,    31,  -129,  -129,    14,  -129,   -27,
    -129,    12,     1,  -129,    10,    20,    -9,    24,    15,    28,
      16,  -129,   -20,    68,  -129,    69,    84,    85,  -129,    88,
      70,    53,    65,  -129,    33,   104,  -129,  -129,  -129,  -129,
      90,   116,   118,    92,   125,   342,  -129,  -129,  -129,   101,
     130,  -129,   342,     3,   342,   342,   131,   342,  -129,  -129,
    -129,  -129,   -15,   342,    54,   342,   342,   391,   114,   119,
     248,   113,   117,  -129,    96,   137,  -129,   415,   342,   153,
     391,   121,  -129,   190,   288,   213,   391,   342,   145,   152,
     342,   342,   342,   342,   342,   342,  -129,   325,   229,   342,
       3,   146,   342,   154,   391,  -129,    55,   391,  -129,  -129,
     351,  -129,  -129,   406,   132,   138,   391,   391,   391,   391,
     391,   391,  -129,  -129,   362,    66,  -129,   104,   172,   148,
    -129,    76,  -129,   342,  -129,   159,   268,  -129,   342,    -4,
    -129,   167,  -129,  -129,   391,   157,  -129,    58,    34,   342,
       3,   185,   305,  -129,  -129,   391,  -129,   342,  -129,    62,
     380,  -129,  -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     4,     0,     1,     0,
       5,     0,     0,     6,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,     8,     0,     0,     0,    11,     0,
       0,     0,     0,    21,     0,    30,    14,     7,    13,    10,
       0,     0,     0,     0,     0,     0,    19,     9,    20,     0,
       0,    22,     0,     0,     0,     0,     0,     0,    62,    63,
      64,    65,    61,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,    47,     0,     0,    49,    50,     0,     0,
      59,     0,    45,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,     0,     0,     0,    35,    38,     0,    23,    46,    44,
       0,    25,    60,    57,     0,     0,    51,    52,    53,    54,
      56,    58,    18,    16,     0,     0,    34,    30,     0,     0,
      28,     0,    39,     0,    26,     0,     0,    15,     0,     0,
      43,     0,    48,    29,    24,     0,    40,     0,     0,     0,
       0,     0,     0,    41,    42,    32,    33,     0,    36,     0,
       0,    37,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,   201,   186,    -3,   170,  -129,  -128,  -129,
      87,  -129,    89,   -99,   -45
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
      67,   126,    15,   149,    71,    31,     6,    70,   147,    74,
      75,    78,    77,     7,    13,    27,    25,    15,    80,    84,
      85,    86,    11,    97,   159,    32,    16,    27,    72,    79,
       8,    -2,     9,   104,     2,    22,    14,    23,   110,   154,
      16,    16,   113,   150,    17,   116,   117,   118,   119,   120,
     121,   156,    20,   124,   125,    81,    12,   128,    26,    29,
      52,    21,    87,    53,     1,    24,     2,    54,    55,    28,
     138,    25,    56,    57,    58,    59,    60,    61,    43,    62,
      44,    63,    88,    89,    90,    91,    92,    93,   144,    94,
      95,   142,    35,   148,    87,    16,    64,    82,    65,    41,
     132,   129,   133,   153,   155,   133,   102,   161,    66,   133,
      36,    42,   160,    40,    88,    89,    90,    91,    92,    93,
      52,    94,    95,    53,    87,    37,    38,    54,    55,    39,
      45,    47,    56,    57,    58,    59,    60,    61,    50,    62,
      48,    63,    49,    68,    88,    89,    90,    91,    92,    93,
      31,    94,    95,   103,    69,    76,    64,    96,    65,    52,
     100,    98,    53,   101,   108,    87,    54,    55,    66,   114,
     127,    56,    57,    58,    59,    60,    61,   115,    62,   129,
      63,   135,   136,   140,   145,    88,    89,    90,    91,    92,
      93,   151,    94,    95,   141,    64,    52,    65,   105,    53,
      87,   152,   157,    54,    55,    10,    30,    66,    56,    57,
      58,    59,    60,    61,    51,    62,   139,    63,   143,     0,
      88,    89,    90,    91,    92,    93,     0,    94,    95,     0,
       0,     0,    64,   109,    65,    52,     0,     0,    53,     0,
       0,    87,    54,    55,    66,     0,     0,    56,    57,    58,
      59,    60,    61,     0,    62,     0,    63,     0,   112,     0,
      99,    88,    89,    90,    91,    92,    93,     0,    94,    95,
       0,    64,   123,    65,    52,     0,    87,    53,     0,     0,
       0,    54,    55,    66,     0,     0,    56,    57,    58,    59,
      60,    61,     0,    62,     0,    63,    88,    89,    90,    91,
      92,    93,     0,    94,    95,     0,     0,     0,     0,     0,
      64,    52,    65,   146,    53,     0,    87,     0,    54,    55,
       0,     0,    66,    56,    57,    58,    59,    60,    61,   111,
      62,     0,    63,     0,     0,     0,    88,    89,    90,    91,
      92,    93,     0,    94,    95,     0,     0,    64,    52,    65,
     158,    53,     0,    87,     0,    54,    55,     0,     0,    66,
      56,    57,    58,    59,    60,    61,     0,    62,   122,    63,
       0,     0,     0,    88,    89,    90,    91,    92,    93,    87,
      94,    95,     0,     0,    64,     0,    65,     0,     0,     0,
      87,     0,   134,     0,     0,     0,    66,     0,     0,    88,
      89,    90,    91,    92,    93,   137,    94,    95,    87,     0,
      88,    89,    90,    91,    92,    93,     0,    94,    95,    87,
       0,   162,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,    92,    93,    -3,    94,    95,     0,     0,    88,
      89,    90,    91,    92,    93,     0,    94,    95,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,    92,    93,
       0,    94,    95,    88,    89,    90,    91,    92,    93,     0,
      94,    95
};

static const yytype_int16 yycheck[] =
{
      45,   100,     1,     7,     1,    25,    41,    52,   136,    54,
      55,    26,    57,    24,    41,    18,     1,     1,    63,    64,
      65,    66,     8,    68,   152,    45,    25,    30,    25,    44,
       0,     0,     1,    78,     3,    44,    24,    46,    83,     5,
      25,    25,    87,    47,    43,    90,    91,    92,    93,    94,
      95,   150,    42,    98,    99,     1,    42,   102,    43,    43,
       6,    41,    28,     9,     1,    41,     3,    13,    14,    41,
       4,     1,    18,    19,    20,    21,    22,    23,    45,    25,
      47,    27,    48,    49,    50,    51,    52,    53,   133,    55,
      56,    15,    24,   138,    28,    25,    42,    43,    44,    46,
      45,    25,    47,    45,   149,    47,    10,    45,    54,    47,
      41,    46,   157,    43,    48,    49,    50,    51,    52,    53,
       6,    55,    56,     9,    28,    41,    41,    13,    14,    41,
      26,    41,    18,    19,    20,    21,    22,    23,    46,    25,
      24,    27,    24,    42,    48,    49,    50,    51,    52,    53,
      25,    55,    56,    16,    24,    24,    42,    43,    44,     6,
      47,    42,     9,    46,    43,    28,    13,    14,    54,    24,
      24,    18,    19,    20,    21,    22,    23,    25,    25,    25,
      27,    49,    44,    11,    25,    48,    49,    50,    51,    52,
      53,    24,    55,    56,    46,    42,     6,    44,    45,     9,
      28,    44,    17,    13,    14,     4,    20,    54,    18,    19,
      20,    21,    22,    23,    44,    25,   127,    27,   131,    -1,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    -1,
      -1,    -1,    42,    43,    44,     6,    -1,    -1,     9,    -1,
      -1,    28,    13,    14,    54,    -1,    -1,    18,    19,    20,
      21,    22,    23,    -1,    25,    -1,    27,    -1,    45,    -1,
      12,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      -1,    42,    43,    44,     6,    -1,    28,     9,    -1,    -1,
      -1,    13,    14,    54,    -1,    -1,    18,    19,    20,    21,
      22,    23,    -1,    25,    -1,    27,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      42,     6,    44,    45,     9,    -1,    28,    -1,    13,    14,
      -1,    -1,    54,    18,    19,    20,    21,    22,    23,    41,
      25,    -1,    27,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    -1,    42,     6,    44,
      45,     9,    -1,    28,    -1,    13,    14,    -1,    -1,    54,
      18,    19,    20,    21,    22,    23,    -1,    25,    43,    27,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    28,
      55,    56,    -1,    -1,    42,    -1,    44,    -1,    -1,    -1,
      28,    -1,    41,    -1,    -1,    -1,    54,    -1,    -1,    48,
      49,    50,    51,    52,    53,    43,    55,    56,    28,    -1,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    28,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    28,    55,    56,    -1,    -1,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    48,    49,    50,    51,    52,    53,    -1,
      55,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    58,    59,    60,    41,    24,     0,     1,
      60,     8,    42,    41,    24,     1,    25,    43,    61,    62,
      42,    41,    44,    46,    41,     1,    43,    62,    41,    43,
      61,    25,    45,    63,    64,    24,    41,    41,    41,    41,
      43,    46,    46,    45,    47,    26,    69,    41,    24,    24,
      46,    63,     6,     9,    13,    14,    18,    19,    20,    21,
      22,    23,    25,    27,    42,    44,    54,    71,    42,    24,
      71,     1,    25,    70,    71,    71,    24,    71,    26,    44,
      71,     1,    43,    66,    71,    71,    71,    28,    48,    49,
      50,    51,    52,    53,    55,    56,    43,    71,    42,    12,
      47,    46,    10,    16,    71,    45,    65,    71,    43,    43,
      71,    41,    45,    71,    24,    25,    71,    71,    71,    71,
      71,    71,    43,    43,    71,    71,    70,    24,    71,    25,
      67,    68,    45,    47,    41,    49,    44,    43,     4,    69,
      11,    46,    15,    67,    71,    25,    45,    65,    71,     7,
      47,    24,    44,    45,     5,    71,    70,    17,    45,    65,
      71,    45,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    59,    59,    60,    60,    60,
      60,    61,    61,    61,    61,    62,    62,    62,    62,    62,
      63,    64,    64,    65,    65,    66,    66,    67,    68,    68,
      69,    69,    70,    70,    70,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     3,     6,     5,     8,
       7,     2,     2,     3,     3,     9,     8,     7,     8,     4,
       3,     1,     3,     1,     3,     2,     3,     6,     1,     2,
       0,     2,     6,     6,     3,     3,     7,     8,     3,     4,
       5,     6,     7,     5,     3,     2,     3,     2,     5,     2,
       2,     3,     3,     3,     3,     2,     3,     3,     3,     2,
       3,     1,     1,     1,     1,     1
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
#line 70 "COOL.y" /* yacc.c:1646  */
    {}
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 75 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].ival);}
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 78 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[0].ival);}
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 80 "COOL.y" /* yacc.c:1646  */
    {}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 88 "COOL.y" /* yacc.c:1646  */
    { 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 94 "COOL.y" /* yacc.c:1646  */
    { 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 100 "COOL.y" /* yacc.c:1646  */
    { 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 106 "COOL.y" /* yacc.c:1646  */
    { 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 114 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-1].sval);}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 117 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-1].sval);}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 125 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=ex((yyvsp[-1].sval));}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 127 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=ex(NULL);}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 129 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=ex(NULL);}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 131 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=ex((yyvsp[-1].sval));}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 133 "COOL.y" /* yacc.c:1646  */
    {	
		(yyval.sval) = ex(opr(ASSIGN,3,(yyvsp[-3].sval),(yyvsp[-1].sval),(yyvsp[0].sval)));/**/
	}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 141 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=identifier((yyvsp[-2].sval));}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 145 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 147 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = opr(',', 2, NULL, NULL);}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 175 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 177 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = opr(',', 2, NULL, NULL);}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 181 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-1].sval);}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 183 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = opr(';', 2, NULL, NULL);}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 187 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr(DARROW,3,(yyvsp[-5].sval),(yyvsp[-3].sval),(yyvsp[-1].sval));/*a:A<=(5+3);*/}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 191 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 193 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 198 "COOL.y" /* yacc.c:1646  */
    {
			(yyval.sval)=opr('=',1,(yyvsp[0].sval));
		}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 205 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = opr(IN, 3, (yyvsp[-5].sval),(yyvsp[-2].sval),(yyvsp[-1].sval));}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 207 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = opr(LET, 3, (yyvsp[-5].sval),(yyvsp[-2].sval),(yyvsp[-1].sval));}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 209 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 213 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr((yyvsp[-1].ival),2,(yyvsp[-2].sval),(yyvsp[0].sval));}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 215 "COOL.y" /* yacc.c:1646  */
    {	/*operator identified by @*/
		(yyval.sval)=opr((yyvsp[-5].sval),3,(yyvsp[-6].sval),(yyvsp[-4].sval),(yyvsp[-2].sval));
	}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 219 "COOL.y" /* yacc.c:1646  */
    {
		/*operator identified by (*/
		(yyval.sval)=opr((yyvsp[-2].ival),3,(yyvsp[-7].sval),(yyvsp[-3].sval),(yyvsp[-1].sval));
	}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 224 "COOL.y" /* yacc.c:1646  */
    { 
			curr_lineno++;
			node=create_entry((yyvsp[-2].sval),3,curr_lineno,5,0,"0");
			t=insert_entry(node,t);	
			/* operator identified by ' ' */
			(yyval.sval)=opr(' ',1,(yyvsp[-2].sval));	   
		}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 232 "COOL.y" /* yacc.c:1646  */
    { 
			curr_lineno++;
			node=create_entry((yyvsp[-3].sval),3,curr_lineno,5,0,(yyvsp[-1].sval));
			t=insert_entry(node,t);
			/* operator identified by ')' */
			(yyval.sval)=opr((yyvsp[0].ival),2,(yyvsp[-3].sval),(yyvsp[-1].sval));		   
		}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 240 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr((yyvsp[-3].sval),2,(yyvsp[-4].sval),(yyvsp[-2].sval));}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 242 "COOL.y" /* yacc.c:1646  */
    {
		/*operator identified by a */
		(yyval.sval)=opr('a',3,(yyvsp[-5].sval),(yyvsp[-3].sval),(yyvsp[-1].sval));
	}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 247 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = opr(IF, 3, (yyvsp[-5].sval), (yyvsp[-3].sval), (yyvsp[-1].sval));/**/}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 249 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = opr(WHILE, 2, (yyvsp[-3].sval), (yyvsp[-1].sval));/**/}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 251 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval) = (yyvsp[-1].sval);}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 255 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-1].ival);}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 257 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr(CASE,2,(yyvsp[-3].sval),(yyvsp[-1].sval));}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 259 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=identifier((yyvsp[0].sval));}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 261 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr((yyvsp[-1].ival),1,(yyvsp[0].sval));}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 263 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr((yyvsp[-1].sval),2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 265 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr((yyvsp[-1].sval),2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 267 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr((yyvsp[-1].sval),2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 269 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr((yyvsp[-1].sval),2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 271 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr((yyvsp[-1].sval),1,(yyvsp[0].sval));/**/}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 273 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr((yyvsp[-1].sval),2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 275 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr((yyvsp[-1].ival),2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 277 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=opr(284,2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 279 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[0].sval);}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 281 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=(yyvsp[-1].sval);}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 283 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=identifier((yyvsp[0].sval));}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 285 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=ex(str_constant((yyvsp[0].sval)));}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 287 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=integer_constant((yyvsp[0].ival));}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 289 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=ex(bool_constant((yyvsp[0].sval)));}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 291 "COOL.y" /* yacc.c:1646  */
    {(yyval.sval)=ex(bool_constant((yyvsp[0].sval)));}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1833 "y.tab.c" /* yacc.c:1646  */
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
#line 295 "COOL.y" /* yacc.c:1906  */


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
	printf("Inside main\n");
	FILE * fp= fopen(argv[1], "r");
	yyin = fp;
	printf("Read the input file, continue with Lexing and Parsing\n");
	printf("Performing Lexical analysis......\n\n");
	yyparse ( );
	printf("\n\033[0;32mParsing completed.\033[0m\n\n");
	printf("Symbol Table:\n");
	display_table(t);
	return 0;
}
