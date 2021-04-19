/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "COOL.y"

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

#line 88 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 287,                 /* "invalid token"  */
    CLASS = 258,                   /* CLASS  */
    ELSE = 259,                    /* ELSE  */
    FI = 260,                      /* FI  */
    IF = 261,                      /* IF  */
    IFX = 286,                     /* IFX  */
    IN = 262,                      /* IN  */
    INHERITS = 263,                /* INHERITS  */
    LET = 264,                     /* LET  */
    LOOP = 265,                    /* LOOP  */
    POOL = 266,                    /* POOL  */
    THEN = 267,                    /* THEN  */
    WHILE = 268,                   /* WHILE  */
    CASE = 269,                    /* CASE  */
    ESAC = 270,                    /* ESAC  */
    OF = 271,                      /* OF  */
    DARROW = 272,                  /* DARROW  */
    NEW = 273,                     /* NEW  */
    ISVOID = 274,                  /* ISVOID  */
    STR_CONST = 275,               /* STR_CONST  */
    INT_CONST = 276,               /* INT_CONST  */
    TRUE = 277,                    /* TRUE  */
    FALSE = 284,                   /* FALSE  */
    TYPEID = 278,                  /* TYPEID  */
    OBJECTID = 279,                /* OBJECTID  */
    ASSIGN = 280,                  /* ASSIGN  */
    NOT = 281,                     /* NOT  */
    LE = 282,                      /* LE  */
    ERROR = 283,                   /* ERROR  */
    PARENTHESIS_O = 297,           /* PARENTHESIS_O  */
    PARENTHESIS_C = 298            /* PARENTHESIS_C  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 287
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
#line 19 "COOL.y"

	char* sval;
	int ival;
	char *error_msg;
	nodeType *nval;

#line 209 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CLASS = 3,                      /* CLASS  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FI = 5,                         /* FI  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_IFX = 7,                        /* IFX  */
  YYSYMBOL_IN = 8,                         /* IN  */
  YYSYMBOL_INHERITS = 9,                   /* INHERITS  */
  YYSYMBOL_LET = 10,                       /* LET  */
  YYSYMBOL_LOOP = 11,                      /* LOOP  */
  YYSYMBOL_POOL = 12,                      /* POOL  */
  YYSYMBOL_THEN = 13,                      /* THEN  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_CASE = 15,                      /* CASE  */
  YYSYMBOL_ESAC = 16,                      /* ESAC  */
  YYSYMBOL_OF = 17,                        /* OF  */
  YYSYMBOL_DARROW = 18,                    /* DARROW  */
  YYSYMBOL_NEW = 19,                       /* NEW  */
  YYSYMBOL_ISVOID = 20,                    /* ISVOID  */
  YYSYMBOL_STR_CONST = 21,                 /* STR_CONST  */
  YYSYMBOL_INT_CONST = 22,                 /* INT_CONST  */
  YYSYMBOL_TRUE = 23,                      /* TRUE  */
  YYSYMBOL_FALSE = 24,                     /* FALSE  */
  YYSYMBOL_TYPEID = 25,                    /* TYPEID  */
  YYSYMBOL_OBJECTID = 26,                  /* OBJECTID  */
  YYSYMBOL_ASSIGN = 27,                    /* ASSIGN  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_LE = 29,                        /* LE  */
  YYSYMBOL_ERROR = 30,                     /* ERROR  */
  YYSYMBOL_31_ = 31,                       /* "<"  */
  YYSYMBOL_32_ = 32,                       /* "="  */
  YYSYMBOL_33_ = 33,                       /* "+"  */
  YYSYMBOL_34_ = 34,                       /* "-"  */
  YYSYMBOL_35_ = 35,                       /* "*"  */
  YYSYMBOL_36_ = 36,                       /* "/"  */
  YYSYMBOL_37_ = 37,                       /* "~"  */
  YYSYMBOL_38_ = 38,                       /* "@"  */
  YYSYMBOL_39_ = 39,                       /* "."  */
  YYSYMBOL_PARENTHESIS_O = 40,             /* PARENTHESIS_O  */
  YYSYMBOL_PARENTHESIS_C = 41,             /* PARENTHESIS_C  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ')'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_49_ = 49,                       /* '@'  */
  YYSYMBOL_50_ = 50,                       /* '.'  */
  YYSYMBOL_51_ = 51,                       /* '+'  */
  YYSYMBOL_52_ = 52,                       /* '-'  */
  YYSYMBOL_53_ = 53,                       /* '*'  */
  YYSYMBOL_54_ = 54,                       /* '/'  */
  YYSYMBOL_55_ = 55,                       /* '~'  */
  YYSYMBOL_56_ = 56,                       /* '<'  */
  YYSYMBOL_57_ = 57,                       /* '='  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_class_list = 60,                /* class_list  */
  YYSYMBOL_class = 61,                     /* class  */
  YYSYMBOL_feature_list = 62,              /* feature_list  */
  YYSYMBOL_feature = 63,                   /* feature  */
  YYSYMBOL_formal = 64,                    /* formal  */
  YYSYMBOL_formals_list = 65,              /* formals_list  */
  YYSYMBOL_exprs_comma = 66,               /* exprs_comma  */
  YYSYMBOL_exprs_semi = 67,                /* exprs_semi  */
  YYSYMBOL_case = 68,                      /* case  */
  YYSYMBOL_cases = 69,                     /* cases  */
  YYSYMBOL_opt_assign = 70,                /* opt_assign  */
  YYSYMBOL_let_expr = 71,                  /* let_expr  */
  YYSYMBOL_expr = 72                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
{
       0,    72,    72,    77,    79,    81,    83,    91,    97,   103,
     109,   118,   120,   122,   124,   133,   135,   137,   139,   141,
     149,   155,   157,   185,   187,   191,   193,   197,   201,   203,
     207,   213,   216,   218,   225,   227,   231,   236,   244,   252,
     254,   259,   261,   263,   265,   267,   269,   271,   273,   275,
     277,   279,   281,   283,   285,   287,   289,   291,   293,   295,
     297,   302,   304,   306,   308
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CLASS", "ELSE", "FI",
  "IF", "IFX", "IN", "INHERITS", "LET", "LOOP", "POOL", "THEN", "WHILE",
  "CASE", "ESAC", "OF", "DARROW", "NEW", "ISVOID", "STR_CONST",
  "INT_CONST", "TRUE", "FALSE", "TYPEID", "OBJECTID", "ASSIGN", "NOT",
  "LE", "ERROR", "\"<\"", "\"=\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "\"~\"", "\"@\"", "\".\"", "PARENTHESIS_O", "PARENTHESIS_C", "';'",
  "'{'", "'}'", "'('", "')'", "':'", "','", "'@'", "'.'", "'+'", "'-'",
  "'*'", "'/'", "'~'", "'<'", "'='", "$accept", "program", "class_list",
  "class", "feature_list", "feature", "formal", "formals_list",
  "exprs_comma", "exprs_semi", "case", "cases", "opt_assign", "let_expr",
  "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   287,   258,   259,   260,   261,   286,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   284,   278,   279,   280,   281,   282,
     283,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,    59,   123,   125,    40,    41,    58,    44,    64,
      46,    43,    45,    42,    47,   126,    60,    61
};
#endif

#define YYPACT_NINF (-123)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

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
static const yytype_int8 yydefact[] =
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
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,    18,    19,    33,    34,   106,    83,
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
static const yytype_int8 yystos[] =
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
static const yytype_int8 yyr1[] =
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
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     3,     6,     5,     8,
       7,     2,     2,     3,     3,     9,     8,     7,     8,     4,
       3,     1,     3,     1,     3,     2,     3,     6,     1,     2,
       2,     6,     6,     3,     3,     7,     8,     3,     4,     5,
       6,     7,     5,     3,     2,     3,     2,     5,     2,     2,
       3,     3,     3,     3,     2,     3,     3,     3,     2,     3,
       1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: class_list  */
#line 73 "COOL.y"
        {}
#line 1435 "y.tab.c"
    break;

  case 3: /* class_list: class  */
#line 78 "COOL.y"
        {(yyval.sval)=(yyvsp[0].ival);}
#line 1441 "y.tab.c"
    break;

  case 4: /* class_list: error ';'  */
#line 80 "COOL.y"
        {yyerror("Incorrect class definition\n");}
#line 1447 "y.tab.c"
    break;

  case 5: /* class_list: class_list class  */
#line 82 "COOL.y"
        {(yyval.sval) = (yyvsp[0].ival);}
#line 1453 "y.tab.c"
    break;

  case 6: /* class_list: class_list error ';'  */
#line 84 "COOL.y"
        {yyerror("Incorrect class definition\n");}
#line 1459 "y.tab.c"
    break;

  case 7: /* class: CLASS TYPEID '{' feature_list '}' ';'  */
#line 92 "COOL.y"
                { 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
#line 1469 "y.tab.c"
    break;

  case 8: /* class: CLASS TYPEID '{' '}' ';'  */
#line 98 "COOL.y"
                { 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
#line 1479 "y.tab.c"
    break;

  case 9: /* class: CLASS TYPEID INHERITS TYPEID '{' feature_list '}' ';'  */
#line 104 "COOL.y"
                { 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
#line 1489 "y.tab.c"
    break;

  case 10: /* class: CLASS TYPEID INHERITS TYPEID '{' '}' ';'  */
#line 110 "COOL.y"
                { 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
#line 1499 "y.tab.c"
    break;

  case 11: /* feature_list: feature ';'  */
#line 119 "COOL.y"
                {(yyval.sval)=(yyvsp[-1].sval);}
#line 1505 "y.tab.c"
    break;

  case 12: /* feature_list: error ';'  */
#line 121 "COOL.y"
                {yyerror("Error in feature\n");}
#line 1511 "y.tab.c"
    break;

  case 13: /* feature_list: feature_list feature ';'  */
#line 123 "COOL.y"
                {(yyval.sval)=(yyvsp[-1].sval);}
#line 1517 "y.tab.c"
    break;

  case 14: /* feature_list: feature_list error ';'  */
#line 125 "COOL.y"
                {
			yyerror("Error in subsequent features\n");
		}
#line 1525 "y.tab.c"
    break;

  case 15: /* feature: OBJECTID '(' formals_list ')' ':' TYPEID '{' expr '}'  */
#line 134 "COOL.y"
        {(yyval.sval)=(yyvsp[-1].sval);}
#line 1531 "y.tab.c"
    break;

  case 16: /* feature: OBJECTID '(' formals_list ')' ':' TYPEID '{' '}'  */
#line 136 "COOL.y"
        {(yyval.sval)=ex(NULL);}
#line 1537 "y.tab.c"
    break;

  case 17: /* feature: OBJECTID '(' ')' ':' TYPEID '{' '}'  */
#line 138 "COOL.y"
        {(yyval.sval)=ex(NULL);}
#line 1543 "y.tab.c"
    break;

  case 18: /* feature: OBJECTID '(' ')' ':' TYPEID '{' expr '}'  */
#line 140 "COOL.y"
        {(yyval.sval)=ex((yyvsp[-1].sval));}
#line 1549 "y.tab.c"
    break;

  case 19: /* feature: OBJECTID ':' TYPEID opt_assign  */
#line 142 "COOL.y"
        {	
		(yyval.sval) = ex(opr(ASSIGN,3,identifier((yyvsp[-3].sval)),(yyvsp[-1].sval),(yyvsp[0].sval)));/**/
	}
#line 1557 "y.tab.c"
    break;

  case 20: /* formal: OBJECTID ':' TYPEID  */
#line 150 "COOL.y"
        {
		(yyval.sval)=identifier((yyvsp[-2].sval));
	}
#line 1565 "y.tab.c"
    break;

  case 21: /* formals_list: formal  */
#line 156 "COOL.y"
                {(yyval.sval)=(yyvsp[0].sval);}
#line 1571 "y.tab.c"
    break;

  case 22: /* formals_list: formals_list ',' formal  */
#line 158 "COOL.y"
                {(yyval.sval) = opr(',', 2, NULL, NULL);}
#line 1577 "y.tab.c"
    break;

  case 23: /* exprs_comma: expr  */
#line 186 "COOL.y"
                {(yyval.sval)=(yyvsp[0].sval);}
#line 1583 "y.tab.c"
    break;

  case 24: /* exprs_comma: exprs_comma ',' expr  */
#line 188 "COOL.y"
                {(yyval.sval) = opr(',', 2, NULL, (yyvsp[-2].sval));}
#line 1589 "y.tab.c"
    break;

  case 25: /* exprs_semi: expr ';'  */
#line 192 "COOL.y"
                {(yyval.sval)=ex((yyvsp[-1].sval));}
#line 1595 "y.tab.c"
    break;

  case 26: /* exprs_semi: exprs_semi expr ';'  */
#line 194 "COOL.y"
                {(yyval.sval) = ex(opr(';', 2,NULL,(yyvsp[-1].sval)));}
#line 1601 "y.tab.c"
    break;

  case 27: /* case: OBJECTID ':' TYPEID DARROW expr ';'  */
#line 198 "COOL.y"
        {(yyval.sval)=opr(DARROW,3,identifier((yyvsp[-5].sval)),(yyvsp[-3].sval),(yyvsp[-1].sval));/*a:A<=(5+3);*/}
#line 1607 "y.tab.c"
    break;

  case 28: /* cases: case  */
#line 202 "COOL.y"
        {(yyval.sval)=(yyvsp[0].sval);}
#line 1613 "y.tab.c"
    break;

  case 29: /* cases: cases case  */
#line 204 "COOL.y"
        {(yyval.sval)=(yyvsp[0].sval);}
#line 1619 "y.tab.c"
    break;

  case 30: /* opt_assign: ASSIGN expr  */
#line 208 "COOL.y"
                {
			(yyval.sval)=opr('=',1,(yyvsp[0].sval));
		}
#line 1627 "y.tab.c"
    break;

  case 31: /* let_expr: OBJECTID ':' TYPEID opt_assign IN expr  */
#line 215 "COOL.y"
                {(yyval.sval) = opr(IN, 3, identifier((yyvsp[-5].sval)),identifier((yyvsp[-2].sval)),(yyvsp[-1].sval));}
#line 1633 "y.tab.c"
    break;

  case 32: /* let_expr: OBJECTID ':' TYPEID opt_assign ',' let_expr  */
#line 217 "COOL.y"
                {(yyval.sval) = opr(LET, 3, identifier((yyvsp[-5].sval)),identifier((yyvsp[-2].sval)),(yyvsp[-1].sval));}
#line 1639 "y.tab.c"
    break;

  case 33: /* let_expr: error ',' let_expr  */
#line 219 "COOL.y"
                {
			yyerror("Error in let expression.\n");
			(yyval.sval)=(yyvsp[0].sval);
		}
#line 1648 "y.tab.c"
    break;

  case 34: /* expr: OBJECTID ASSIGN expr  */
#line 226 "COOL.y"
        {(yyval.sval)=opr(ASSIGN,2,identifier((yyvsp[-2].sval)),(yyvsp[0].sval));}
#line 1654 "y.tab.c"
    break;

  case 35: /* expr: expr '@' TYPEID '.' OBJECTID '(' ')'  */
#line 228 "COOL.y"
        {	/*operator identified by @*/
		(yyval.sval)=opr((yyvsp[-5].sval),3,(yyvsp[-6].sval),(yyvsp[-4].sval),(yyvsp[-2].sval));
	}
#line 1662 "y.tab.c"
    break;

  case 36: /* expr: expr '@' TYPEID '.' OBJECTID '(' exprs_comma ')'  */
#line 232 "COOL.y"
        {
		/*operator identified by (*/
		(yyval.sval)=opr((yyvsp[-2].ival),3,(yyvsp[-7].sval),(yyvsp[-3].sval),(yyvsp[-1].sval));
	}
#line 1671 "y.tab.c"
    break;

  case 37: /* expr: OBJECTID '(' ')'  */
#line 237 "COOL.y"
                { 
			curr_lineno++;
			node=create_entry((yyvsp[-2].sval),3,curr_lineno,5,0,"0");
			t=insert_entry(node,t);	
			/* operator identified by ' ' */
			(yyval.sval)=opr(' ',1,(yyvsp[-2].sval));	   
		}
#line 1683 "y.tab.c"
    break;

  case 38: /* expr: OBJECTID '(' exprs_comma ')'  */
#line 245 "COOL.y"
                { 
			curr_lineno++;
			node=create_entry((yyvsp[-3].sval),3,curr_lineno,5,0,(yyvsp[-1].sval));
			t=insert_entry(node,t);
			/* operator identified by ')' */
			(yyval.sval)=opr(')',2,(yyvsp[-3].sval),(yyvsp[-1].sval));		   
		}
#line 1695 "y.tab.c"
    break;

  case 39: /* expr: expr '.' OBJECTID '(' ')'  */
#line 253 "COOL.y"
        {(yyval.sval)=opr('.',2,(yyvsp[-4].sval),(yyvsp[-2].sval));}
#line 1701 "y.tab.c"
    break;

  case 40: /* expr: expr '.' OBJECTID '(' exprs_comma ')'  */
#line 255 "COOL.y"
        {
		/*operator identified by a */
		(yyval.sval)=opr('a',3,(yyvsp[-5].sval),(yyvsp[-3].sval),(yyvsp[-1].sval));
	}
#line 1710 "y.tab.c"
    break;

  case 41: /* expr: IF expr THEN expr ELSE expr FI  */
#line 260 "COOL.y"
        {(yyval.sval) = opr(IF, 3, (yyvsp[-5].sval), (yyvsp[-3].sval), (yyvsp[-1].sval));/**/}
#line 1716 "y.tab.c"
    break;

  case 42: /* expr: WHILE expr LOOP expr POOL  */
#line 262 "COOL.y"
        {(yyval.sval) = opr(WHILE, 2, (yyvsp[-3].sval), (yyvsp[-1].sval));/**/}
#line 1722 "y.tab.c"
    break;

  case 43: /* expr: '{' exprs_semi '}'  */
#line 264 "COOL.y"
        {(yyval.sval) = (yyvsp[-1].sval);}
#line 1728 "y.tab.c"
    break;

  case 44: /* expr: '{' '}'  */
#line 266 "COOL.y"
        {;}
#line 1734 "y.tab.c"
    break;

  case 45: /* expr: '{' error '}'  */
#line 268 "COOL.y"
        {yyerror("Incorrect expression\n");}
#line 1740 "y.tab.c"
    break;

  case 46: /* expr: LET let_expr  */
#line 270 "COOL.y"
        {(yyval.sval)=(yyvsp[-1].ival);}
#line 1746 "y.tab.c"
    break;

  case 47: /* expr: CASE expr OF cases ESAC  */
#line 272 "COOL.y"
        {(yyval.sval)=opr(CASE,2,(yyvsp[-3].sval),(yyvsp[-1].sval));}
#line 1752 "y.tab.c"
    break;

  case 48: /* expr: NEW TYPEID  */
#line 274 "COOL.y"
        {(yyval.sval)=identifier((yyvsp[0].sval));}
#line 1758 "y.tab.c"
    break;

  case 49: /* expr: ISVOID expr  */
#line 276 "COOL.y"
        {(yyval.sval)=opr((yyvsp[-1].ival),1,(yyvsp[0].sval));}
#line 1764 "y.tab.c"
    break;

  case 50: /* expr: expr '+' expr  */
#line 278 "COOL.y"
        {(yyval.sval)=opr('+',2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1770 "y.tab.c"
    break;

  case 51: /* expr: expr '-' expr  */
#line 280 "COOL.y"
        {(yyval.sval)=opr('-',2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1776 "y.tab.c"
    break;

  case 52: /* expr: expr '*' expr  */
#line 282 "COOL.y"
        {(yyval.sval)=opr('*',2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1782 "y.tab.c"
    break;

  case 53: /* expr: expr '/' expr  */
#line 284 "COOL.y"
        {(yyval.sval)=opr('/',2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1788 "y.tab.c"
    break;

  case 54: /* expr: '~' expr  */
#line 286 "COOL.y"
        {(yyval.sval)=opr('~',1,(yyvsp[0].sval));/**/}
#line 1794 "y.tab.c"
    break;

  case 55: /* expr: expr '<' expr  */
#line 288 "COOL.y"
        {(yyval.sval)=opr('<',2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1800 "y.tab.c"
    break;

  case 56: /* expr: expr LE expr  */
#line 290 "COOL.y"
        {(yyval.sval)=opr((yyvsp[-1].ival),2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1806 "y.tab.c"
    break;

  case 57: /* expr: expr '=' expr  */
#line 292 "COOL.y"
        {(yyval.sval)=opr(285,2,(yyvsp[-2].sval),(yyvsp[0].sval));/**/}
#line 1812 "y.tab.c"
    break;

  case 58: /* expr: NOT expr  */
#line 294 "COOL.y"
        {(yyval.sval)=opr(NOT,1,(yyvsp[0].sval));}
#line 1818 "y.tab.c"
    break;

  case 59: /* expr: '(' expr ')'  */
#line 296 "COOL.y"
        {(yyval.sval)=(yyvsp[-1].sval);}
#line 1824 "y.tab.c"
    break;

  case 60: /* expr: OBJECTID  */
#line 298 "COOL.y"
        {
		printf("OBJECT ID: %s\n",(yyvsp[0].sval));
		(yyval.sval)=identifier((yyvsp[0].sval));
	}
#line 1833 "y.tab.c"
    break;

  case 61: /* expr: STR_CONST  */
#line 303 "COOL.y"
        {(yyval.sval)=str_constant((yyvsp[0].sval));}
#line 1839 "y.tab.c"
    break;

  case 62: /* expr: INT_CONST  */
#line 305 "COOL.y"
        {(yyval.sval)=integer_constant((yyvsp[0].ival));}
#line 1845 "y.tab.c"
    break;

  case 63: /* expr: TRUE  */
#line 307 "COOL.y"
        {(yyval.sval)=bool_constant((yyvsp[0].sval));}
#line 1851 "y.tab.c"
    break;

  case 64: /* expr: FALSE  */
#line 309 "COOL.y"
        {(yyval.sval)=bool_constant((yyvsp[0].sval));}
#line 1857 "y.tab.c"
    break;


#line 1861 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 312 "COOL.y"


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
	int strRed1=strengthReduction(tactable);
	display_tac_table(tactable);
	int conProp1=constantPropagation(tactable);
	display_tac_table(tactable);
	int conFold1=constantFolding(tactable);
	display_tac_table(tactable);
	int deadEli1=deadcodeElimination(tactable);
	display_tac_table(tactable);
	int copyProp1=copyPropagation(tactable);
	display_tac_table(tactable);
	int commonSubExpr1=commonSubExprElimination(tactable);
	display_tac_table(tactable);
	return 0;
}
