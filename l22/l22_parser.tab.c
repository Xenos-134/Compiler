/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "l22_parser.y"

//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!

#define NIL (new cdk::nil_node(LINE))

#line 86 "l22_parser.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_L22_PARSER_TAB_H_INCLUDED
# define YY_YY_L22_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tINTEGER = 258,
    tREAL = 259,
    tAND = 260,
    tOR = 261,
    tNE = 262,
    tLE = 263,
    tGE = 264,
    tSIZEOF = 265,
    tNOT = 266,
    tWHILE = 267,
    tREAD = 268,
    tBEGIN = 269,
    tEND = 270,
    tTYPE_STRING = 271,
    tTYPE_INT = 272,
    tTYPE_REAL = 273,
    tTYPE_POINTER = 274,
    tTYPE_AUTO = 275,
    tTYPE_VOID = 276,
    tRETURN = 277,
    tPUBLIC = 278,
    tUSE = 279,
    tFOREIGN = 280,
    tPRIVATE = 281,
    tVAR = 282,
    tDO = 283,
    tSTOP = 284,
    tAGAIN = 285,
    tIF = 286,
    tTHEN = 287,
    tELIF = 288,
    tELSE = 289,
    tINPUT = 290,
    tWRITE = 291,
    tWRITELN = 292,
    tIDENTIFIER = 293,
    tSTRING = 294,
    tNULLPTR = 295,
    tEQ = 296,
    tUNARY = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "l22_parser.y"

  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;	/* integer value */
  double                d;  /* integer value */
  std::string          *s;	/* symbol name or string literal */

  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::basic_type      *expr_type; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  l22::block_node      *block;

  std::vector<std::shared_ptr<cdk::basic_type>> *types;

#line 205 "l22_parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (std::shared_ptr<cdk::compiler> compiler);

#endif /* !YY_YY_L22_PARSER_TAB_H_INCLUDED  */

/* Second part of user prologue.  */
#line 92 "l22_parser.y"

//-- The rules below will be included in yyparse, the main parsing function.

#line 225 "l22_parser.tab.c"


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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
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
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   847

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  222

#define YYUNDEFTOK  2
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    49,     2,     2,
      52,    55,    47,    45,    59,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    58,
      43,    41,    44,    61,    60,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    53,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    42,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,    98,   101,   102,   104,   105,   106,   107,
     111,   112,   113,   116,   119,   123,   124,   125,   128,   129,
     133,   134,   138,   142,   145,   150,   151,   154,   155,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   170,   171,
     176,   177,   178,   182,   186,   187,   191,   192,   193,   194,
     195,   198,   199,   202,   203,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   236,   237,
     241,   242,   243,   247,   248,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   288,   289,   293,
     294,   295,   296
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tINTEGER", "tREAL", "tAND", "tOR",
  "tNE", "tLE", "tGE", "tSIZEOF", "tNOT", "tWHILE", "tREAD", "tBEGIN",
  "tEND", "tTYPE_STRING", "tTYPE_INT", "tTYPE_REAL", "tTYPE_POINTER",
  "tTYPE_AUTO", "tTYPE_VOID", "tRETURN", "tPUBLIC", "tUSE", "tFOREIGN",
  "tPRIVATE", "tVAR", "tDO", "tSTOP", "tAGAIN", "tIF", "tTHEN", "tELIF",
  "tELSE", "tINPUT", "tWRITE", "tWRITELN", "tIDENTIFIER", "tSTRING",
  "tNULLPTR", "'='", "tEQ", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'{'", "'['", "'('", "'}'", "']'", "')'", "tUNARY", "':'", "';'",
  "','", "'@'", "'?'", "$accept", "file", "declarations", "declaration",
  "fundec", "fundeff", "fundef", "vardec", "opt_initializer",
  "identifiers", "program", "block", "opt_vardecs", "opt_instructions",
  "vardecs", "instructions", "argdecs", "argdec", "data_type",
  "basic_type", "function_type", "data_types", "stmt", "funcal_exr",
  "rec_fun_cal", "elif", "expressions", "expr", "lval", "integer", "real",
  "string", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    61,   296,    60,    62,    43,    45,    42,    47,    37,
     123,    91,    40,   125,    93,    41,   297,    58,    59,    44,
      64,    63
};
# endif

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-99)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     160,   -29,  -136,  -136,  -136,  -136,  -136,   237,   237,  -136,
     237,    24,   160,  -136,  -136,  -136,  -136,   305,  -136,    60,
    -136,  -136,   191,    11,    87,    95,   -14,  -136,  -136,    -7,
     107,    -4,   780,  -136,  -136,    -8,    96,    10,    96,    26,
      39,    96,   235,    52,    96,    96,  -136,  -136,  -136,    96,
     414,   299,   299,    80,    81,  -136,  -136,    85,   235,    93,
     796,   235,  -136,    97,   437,   -25,  -136,  -136,   115,  -136,
    -136,  -136,  -136,    96,  -136,    -4,    96,  -136,  -136,   118,
     -40,    96,    96,  -136,   760,    96,   462,  -136,  -136,   687,
    -136,  -136,    16,   734,    18,  -136,   414,  -136,   637,   117,
      49,  -136,   114,   484,   325,  -136,  -136,   122,  -136,   121,
    -136,   131,  -136,  -136,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,  -136,    96,
     351,  -136,  -136,    47,   734,  -136,  -136,   237,   509,   535,
    -136,   -29,  -136,    96,  -136,  -136,  -136,    96,   127,   237,
    -136,  -136,   273,  -136,  -136,   142,   -41,   734,  -136,  -136,
    -136,   760,   744,   120,   451,   451,   120,   451,   451,   111,
     111,   139,   139,   139,   662,   734,  -136,    12,   118,  -136,
     163,    53,   734,  -136,   149,  -136,   141,   560,   156,    96,
    -136,   389,  -136,  -136,   -29,    96,   -29,  -136,   237,  -136,
      13,   147,   586,   273,  -136,   734,  -136,   715,  -136,   -12,
     237,  -136,  -136,   150,   611,   -29,   -29,  -136,    33,    53,
    -136,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    46,    47,    48,    49,    21,     0,     0,    20,
       0,     0,     3,     4,     8,     7,     6,     0,     9,     0,
      44,    45,    25,     0,     0,     0,     0,     1,     5,    18,
       0,    11,     0,   119,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,   121,    88,     0,
       0,     0,    40,     0,     0,    98,    31,    30,    27,     0,
      26,    28,    38,   116,    56,   112,    85,    86,    87,    22,
      12,    10,    50,     0,    17,    18,     0,    16,    52,    53,
       0,     0,     0,   116,    89,     0,    64,    60,    61,     0,
      65,    62,     0,    83,     0,    95,     0,    94,     0,    98,
       0,    41,     0,     0,     0,    32,    29,     0,    23,    37,
      36,    35,    39,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,   113,   122,    14,    19,    15,    51,     0,     0,     0,
      63,     0,    66,     0,    67,    93,    91,     0,     0,     0,
      43,   111,    40,    79,    70,     0,     0,    69,    24,    34,
      33,   109,   110,   107,   106,   105,   108,   103,   104,    96,
      99,   100,   101,   102,     0,    92,   115,     0,    54,    90,
       0,    57,    84,    97,     0,    42,     0,     0,     0,     0,
      78,     0,   118,   114,     0,     0,     0,    58,     0,    72,
     111,     0,     0,    40,    73,    74,    59,     0,    80,     0,
      40,    14,    77,     0,     0,     0,     0,    75,   111,    81,
      13,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,   192,   -17,   -50,   -21,    -2,   -18,     3,
    -136,  -135,  -136,   148,  -136,  -136,  -136,    61,     0,  -136,
    -136,  -136,   -33,    89,     8,     4,   172,    -3,  -136,  -136,
    -136,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    55,    15,    16,    74,   155,
      18,    23,    58,    59,    60,    61,   100,   101,   102,    20,
      21,    80,    62,   156,    83,   197,    92,    64,    65,    66,
      67,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    56,    99,    17,   136,    54,   181,    24,    25,    90,
      26,   189,    19,    77,   190,    17,   129,    30,   191,   137,
      57,    22,    19,   133,    27,    17,    69,   130,   112,    32,
      63,    32,    79,    84,    73,    86,   131,    76,    89,   110,
      72,    93,    93,   109,    81,   216,    95,    97,    98,   103,
      63,    26,   -98,   -98,   -98,   -98,   -98,   135,   111,   206,
      19,   208,    85,    17,   189,   -71,    63,   193,   -71,    63,
     134,   191,   -71,   134,   142,   143,   144,   143,   138,    98,
     219,   220,   139,   154,    87,   -76,   195,   196,   -76,   -98,
     -98,   -98,   -76,   145,   -98,   -98,   -98,    88,    31,    33,
      34,   157,    99,    32,   148,   -98,    35,    36,   149,   154,
      91,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    70,   175,   157,   117,   118,
      32,   186,   104,    71,    46,    47,    48,   178,    32,   105,
     182,    49,    50,   106,   183,    75,   108,    82,    52,   187,
      32,   211,   150,    99,   132,   113,    53,    32,   124,   125,
     126,    32,   127,   120,   121,   122,   123,   124,   125,   126,
     204,   127,   147,   184,     1,   158,     2,     3,     4,   159,
     188,     5,   213,     6,     7,     8,   202,     9,   205,   160,
     127,   194,   207,   198,    33,    34,   199,   201,   209,   210,
     214,    35,    36,    37,    28,   217,   107,     2,     3,     4,
     185,    10,     5,    38,     6,     7,     8,    94,     9,   177,
      39,    40,    41,   221,     0,    42,    43,    44,    45,    46,
      47,    48,     0,     0,     0,     0,    49,    50,    33,    34,
       0,     0,    51,    52,     0,    35,    36,    37,     0,     0,
       0,    53,     0,     2,     3,     4,     0,    38,     5,     0,
       0,     0,     0,     0,    39,    40,    41,     0,     0,    42,
      43,    44,    45,    46,    47,    48,    33,    34,     0,     0,
      49,    50,     0,    35,    36,     0,    82,    52,    10,     2,
       3,     4,     0,     0,     5,    53,     6,     0,     0,     0,
       9,     0,    33,    34,     0,     0,     0,     0,     0,    35,
      36,    46,    47,    48,     0,     2,     3,     4,    49,    50,
       5,     2,     3,     4,    51,    52,     5,     0,    33,    34,
       0,     0,     0,    53,     0,    35,    36,    46,    47,    48,
       0,     0,     0,    29,    49,    50,     0,     0,     6,     0,
      51,    52,     9,     0,    33,    34,    10,     0,     0,    53,
       0,    35,    36,    46,    47,    48,     0,     0,     0,     0,
      49,    50,     0,     0,     6,     0,    82,   152,     9,     0,
     153,     0,     0,     0,     0,    53,     0,     0,     0,    46,
      47,    48,    33,    34,     0,     0,    49,    50,     0,    35,
      36,     0,    82,   152,     0,     0,   176,     0,     0,     0,
       0,    53,     6,     0,     0,     0,     9,    33,    34,     0,
       0,     0,     0,     0,    35,    36,     0,    46,    47,    48,
       0,     0,     0,     0,    49,    50,     0,     0,     0,     0,
      82,   203,   114,   115,   116,   117,   118,     0,     0,    53,
       0,     0,    46,    47,    48,     0,     0,     0,     0,    49,
      96,     0,     0,     0,     0,    82,    52,   114,   115,   116,
     117,   118,     0,     0,    53,     0,     0,     0,     0,   119,
     120,   121,   122,   123,   124,   125,   126,     0,   127,   114,
     115,   116,   117,   118,     0,   128,   122,   123,   124,   125,
     126,     0,   127,     0,   119,   120,   121,   122,   123,   124,
     125,   126,     0,   127,   114,   115,   116,   117,   118,     0,
     140,     0,     0,     0,     0,     0,   119,   120,   121,   122,
     123,   124,   125,   126,     0,   127,     0,     0,     0,   151,
     114,   115,   116,   117,   118,     0,     0,     0,     0,     0,
       0,   119,   120,   121,   122,   123,   124,   125,   126,     0,
     127,     0,     0,     0,   179,   114,   115,   116,   117,   118,
       0,     0,     0,     0,     0,     0,     0,   119,   120,   121,
     122,   123,   124,   125,   126,     0,   127,     0,     0,     0,
     180,   114,   115,   116,   117,   118,     0,     0,     0,     0,
       0,     0,   119,   120,   121,   122,   123,   124,   125,   126,
       0,   127,     0,     0,     0,   200,   114,   115,   116,   117,
     118,     0,     0,     0,     0,     0,     0,     0,   119,   120,
     121,   122,   123,   124,   125,   126,     0,   127,     0,     0,
       0,   212,   114,   115,   116,   117,   118,     0,     0,     0,
       0,     0,     0,   119,   120,   121,   122,   123,   124,   125,
     126,     0,   127,     0,     0,     0,   218,   114,   115,   116,
     117,   118,     0,     0,     0,     0,     0,     0,     0,   119,
     120,   121,   122,   123,   124,   125,   126,     0,   127,     0,
       0,   146,   114,   115,   116,   117,   118,     0,     0,     0,
       0,     0,     0,     0,   119,   120,   121,   122,   123,   124,
     125,   126,     0,   127,     0,     0,   192,     0,     0,   141,
     114,   115,   116,   117,   118,     0,     0,     0,     0,   119,
     120,   121,   122,   123,   124,   125,   126,     0,   127,   114,
     115,   116,   117,   118,     0,     0,     0,   215,     0,   114,
       0,   116,   117,   118,     0,     0,     0,   119,   120,   121,
     122,   123,   124,   125,   126,     0,   127,   116,   117,   118,
       0,     0,     0,     0,     0,     0,   119,   120,   121,   122,
     123,   124,   125,   126,     0,   127,   119,   120,   121,   122,
     123,   124,   125,   126,     0,   127,     2,     3,     4,     0,
       0,     5,   119,   120,   121,   122,   123,   124,   125,   126,
       0,   127,     2,     3,     4,     0,     0,     5,     0,     6,
       7,     8,     0,     9,    78,     0,     0,     0,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10
};

static const yytype_int16 yycheck[] =
{
       0,    22,    52,     0,    44,    22,   141,     7,     8,    42,
      10,    52,    12,    31,    55,    12,    41,    17,    59,    59,
      22,    50,    22,    73,     0,    22,    15,    52,    61,    43,
      22,    43,    32,    36,    41,    38,    61,    41,    41,    60,
      54,    44,    45,    60,    52,    57,    49,    50,    51,    52,
      42,    51,     5,     6,     7,     8,     9,    75,    60,   194,
      60,   196,    52,    60,    52,    52,    58,    55,    55,    61,
      73,    59,    59,    76,    58,    59,    58,    59,    81,    82,
     215,   216,    85,   104,    58,    52,    33,    34,    55,    42,
      43,    44,    59,    96,    47,    48,    49,    58,    38,     3,
       4,   104,   152,    43,    55,    58,    10,    11,    59,   130,
      58,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    38,   129,   130,     8,     9,
      43,   152,    52,    38,    38,    39,    40,   137,    43,    58,
     143,    45,    46,    58,   147,    38,    53,    51,    52,   152,
      43,   201,    38,   203,    39,    58,    60,    43,    47,    48,
      49,    43,    51,    43,    44,    45,    46,    47,    48,    49,
     191,    51,    55,    46,    14,    53,    16,    17,    18,    58,
      38,    21,   203,    23,    24,    25,   189,    27,   191,    58,
      51,    28,   195,    44,     3,     4,    55,    41,   198,    52,
     203,    10,    11,    12,    12,    55,    58,    16,    17,    18,
     149,    51,    21,    22,    23,    24,    25,    45,    27,   130,
      29,    30,    31,   219,    -1,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,    46,     3,     4,
      -1,    -1,    51,    52,    -1,    10,    11,    12,    -1,    -1,
      -1,    60,    -1,    16,    17,    18,    -1,    22,    21,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,     3,     4,    -1,    -1,
      45,    46,    -1,    10,    11,    -1,    51,    52,    51,    16,
      17,    18,    -1,    -1,    21,    60,    23,    -1,    -1,    -1,
      27,    -1,     3,     4,    -1,    -1,    -1,    -1,    -1,    10,
      11,    38,    39,    40,    -1,    16,    17,    18,    45,    46,
      21,    16,    17,    18,    51,    52,    21,    -1,     3,     4,
      -1,    -1,    -1,    60,    -1,    10,    11,    38,    39,    40,
      -1,    -1,    -1,    38,    45,    46,    -1,    -1,    23,    -1,
      51,    52,    27,    -1,     3,     4,    51,    -1,    -1,    60,
      -1,    10,    11,    38,    39,    40,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    23,    -1,    51,    52,    27,    -1,
      55,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    38,
      39,    40,     3,     4,    -1,    -1,    45,    46,    -1,    10,
      11,    -1,    51,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    60,    23,    -1,    -1,    -1,    27,     3,     4,    -1,
      -1,    -1,    -1,    -1,    10,    11,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      51,    52,     5,     6,     7,     8,     9,    -1,    -1,    60,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    -1,    51,    52,     5,     6,     7,
       8,     9,    -1,    -1,    60,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,     5,
       6,     7,     8,     9,    -1,    58,    45,    46,    47,    48,
      49,    -1,    51,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,     5,     6,     7,     8,     9,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    -1,    -1,    -1,    55,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      51,    -1,    -1,    -1,    55,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,    -1,    -1,    -1,
      55,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    -1,    -1,    -1,    55,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    -1,    -1,
      -1,    55,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    51,    -1,    -1,    -1,    55,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,    -1,
      -1,    54,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    51,    -1,    -1,    54,    -1,    -1,    32,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    51,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    32,    -1,     5,
      -1,     7,     8,     9,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    16,    17,    18,    -1,
      -1,    21,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,    51,    16,    17,    18,    -1,    -1,    21,    -1,    23,
      24,    25,    -1,    27,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    16,    17,    18,    21,    23,    24,    25,    27,
      51,    63,    64,    65,    66,    68,    69,    71,    72,    80,
      81,    82,    50,    73,    80,    80,    80,     0,    65,    38,
      80,    38,    43,     3,     4,    10,    11,    12,    22,    29,
      30,    31,    34,    35,    36,    37,    38,    39,    40,    45,
      46,    51,    52,    60,    66,    67,    68,    69,    74,    75,
      76,    77,    84,    86,    89,    90,    91,    92,    93,    15,
      38,    38,    54,    41,    70,    38,    41,    70,    44,    80,
      83,    52,    51,    86,    89,    52,    89,    58,    58,    89,
      84,    58,    88,    89,    88,    89,    46,    89,    89,    67,
      78,    79,    80,    89,    52,    58,    58,    75,    53,    66,
      68,    69,    84,    58,     5,     6,     7,     8,     9,    42,
      43,    44,    45,    46,    47,    48,    49,    51,    58,    41,
      52,    61,    39,    67,    89,    70,    44,    59,    89,    89,
      58,    32,    58,    59,    58,    89,    54,    55,    55,    59,
      38,    55,    52,    55,    68,    71,    85,    89,    53,    58,
      58,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    55,    85,    80,    55,
      55,    73,    89,    89,    46,    79,    68,    89,    38,    52,
      55,    59,    54,    55,    28,    33,    34,    87,    44,    55,
      55,    41,    89,    52,    68,    89,    73,    89,    73,    80,
      52,    67,    55,    68,    89,    32,    57,    55,    55,    73,
      73,    87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      66,    66,    66,    67,    68,    69,    69,    69,    70,    70,
      71,    71,    72,    73,    73,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    77,
      78,    78,    78,    79,    80,    80,    81,    81,    81,    81,
      81,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    86,    86,
      87,    87,    87,    88,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    90,    91,
      92,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     1,     1,
       3,     2,     3,     8,     4,     4,     3,     3,     0,     2,
       1,     1,     3,     3,     4,     0,     1,     0,     1,     2,
       1,     1,     2,     3,     3,     2,     2,     2,     1,     2,
       0,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     1,     3,     2,     1,     4,     5,     6,
       2,     2,     2,     3,     2,     2,     3,     3,     2,     1,
       1,     3,     3,     3,     3,     5,     5,     4,     4,     3,
       2,     4,     5,     1,     3,     1,     1,     1,     1,     2,
       4,     3,     3,     3,     2,     2,     3,     4,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     2,     4,     3,     1,     1,     4,     1,
       1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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
        yyerror (compiler, YY_("syntax error: cannot back up")); \
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
                  Type, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (compiler);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, compiler);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, std::shared_ptr<cdk::compiler> compiler)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYUSE (yyvaluep);
  YYUSE (compiler);
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
yyparse (std::shared_ptr<cdk::compiler> compiler)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
# undef YYSTACK_RELOCATE
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
  case 2:
#line 97 "l22_parser.y"
                            { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE)); }
#line 1674 "l22_parser.tab.c"
    break;

  case 3:
#line 98 "l22_parser.y"
                            { compiler->ast((yyval.sequence) = (yyvsp[0].sequence)); }
#line 1680 "l22_parser.tab.c"
    break;

  case 4:
#line 101 "l22_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1686 "l22_parser.tab.c"
    break;

  case 5:
#line 102 "l22_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1692 "l22_parser.tab.c"
    break;

  case 6:
#line 104 "l22_parser.y"
                         { (yyval.node) = (yyvsp[0].node);}
#line 1698 "l22_parser.tab.c"
    break;

  case 7:
#line 105 "l22_parser.y"
                         { (yyval.node) = (yyvsp[0].node);}
#line 1704 "l22_parser.tab.c"
    break;

  case 8:
#line 106 "l22_parser.y"
                         { (yyval.node) = (yyvsp[0].node);}
#line 1710 "l22_parser.tab.c"
    break;

  case 9:
#line 107 "l22_parser.y"
                         { (yyval.node) = (yyvsp[0].node);}
#line 1716 "l22_parser.tab.c"
    break;

  case 10:
#line 111 "l22_parser.y"
                                              { (yyval.node) = new l22::var_declaration_node(LINE, tPRIVATE,  (yyvsp[-1].type), *(yyvsp[0].s), nullptr);}
#line 1722 "l22_parser.tab.c"
    break;

  case 11:
#line 112 "l22_parser.y"
                                              { (yyval.node) = new l22::var_declaration_node(LINE, tPRIVATE,  (yyvsp[-1].type), *(yyvsp[0].s), nullptr);}
#line 1728 "l22_parser.tab.c"
    break;

  case 12:
#line 113 "l22_parser.y"
                                              { (yyval.node) = new l22::var_declaration_node(LINE, tPRIVATE,  (yyvsp[-1].type), *(yyvsp[0].s), nullptr);}
#line 1734 "l22_parser.tab.c"
    break;

  case 13:
#line 116 "l22_parser.y"
                                                           { (yyval.expression) = new l22::func_definition_node(LINE, (yyvsp[-6].sequence), (yyvsp[0].block), (yyvsp[-2].type)); }
#line 1740 "l22_parser.tab.c"
    break;

  case 14:
#line 119 "l22_parser.y"
                                                            { (yyval.node) = new l22::var_declaration_node(LINE, (yyvsp[-3].i),  nullptr, *(yyvsp[-2].s), (yyvsp[0].expression));}
#line 1746 "l22_parser.tab.c"
    break;

  case 15:
#line 123 "l22_parser.y"
                                                                       { (yyval.node) = new l22::var_declaration_node(LINE, (yyvsp[-3].i),  (yyvsp[-2].type), *(yyvsp[-1].s), (yyvsp[0].expression)); }
#line 1752 "l22_parser.tab.c"
    break;

  case 16:
#line 124 "l22_parser.y"
                                                                      { (yyval.node) = new l22::var_declaration_node(LINE, tPRIVATE,  (yyvsp[-2].type), *(yyvsp[-1].s), (yyvsp[0].expression)); }
#line 1758 "l22_parser.tab.c"
    break;

  case 17:
#line 125 "l22_parser.y"
                                                                      { (yyval.node) = new l22::var_declaration_node(LINE, (yyvsp[-2].i),  nullptr, *(yyvsp[-1].s), (yyvsp[0].expression)); }
#line 1764 "l22_parser.tab.c"
    break;

  case 18:
#line 128 "l22_parser.y"
                                        { (yyval.expression) = nullptr; }
#line 1770 "l22_parser.tab.c"
    break;

  case 19:
#line 129 "l22_parser.y"
                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 1776 "l22_parser.tab.c"
    break;

  case 20:
#line 133 "l22_parser.y"
                    { (yyval.i) = tPRIVATE;}
#line 1782 "l22_parser.tab.c"
    break;

  case 21:
#line 134 "l22_parser.y"
                    { (yyval.i) = tPUBLIC; }
#line 1788 "l22_parser.tab.c"
    break;

  case 22:
#line 138 "l22_parser.y"
                            { (yyval.node) = new l22::program_node(LINE, (yyvsp[-1].block)); }
#line 1794 "l22_parser.tab.c"
    break;

  case 23:
#line 142 "l22_parser.y"
                                           {
         (yyval.block) = new l22::block_node(LINE, nullptr, (yyvsp[-1].sequence));
     }
#line 1802 "l22_parser.tab.c"
    break;

  case 24:
#line 145 "l22_parser.y"
                                            {
         (yyval.block) = new l22::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence));
     }
#line 1810 "l22_parser.tab.c"
    break;

  case 25:
#line 150 "l22_parser.y"
                           { (yyval.sequence) = NULL; }
#line 1816 "l22_parser.tab.c"
    break;

  case 26:
#line 151 "l22_parser.y"
                           { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1822 "l22_parser.tab.c"
    break;

  case 27:
#line 154 "l22_parser.y"
                                        { (yyval.sequence) = NULL; }
#line 1828 "l22_parser.tab.c"
    break;

  case 28:
#line 155 "l22_parser.y"
                                        { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1834 "l22_parser.tab.c"
    break;

  case 29:
#line 158 "l22_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node));     }
#line 1840 "l22_parser.tab.c"
    break;

  case 30:
#line 159 "l22_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1846 "l22_parser.tab.c"
    break;

  case 31:
#line 160 "l22_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1852 "l22_parser.tab.c"
    break;

  case 32:
#line 161 "l22_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node));     }
#line 1858 "l22_parser.tab.c"
    break;

  case 33:
#line 162 "l22_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[-2].sequence)); }
#line 1864 "l22_parser.tab.c"
    break;

  case 34:
#line 163 "l22_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[-2].sequence)); }
#line 1870 "l22_parser.tab.c"
    break;

  case 35:
#line 164 "l22_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1876 "l22_parser.tab.c"
    break;

  case 36:
#line 165 "l22_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1882 "l22_parser.tab.c"
    break;

  case 37:
#line 166 "l22_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1888 "l22_parser.tab.c"
    break;

  case 38:
#line 170 "l22_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));}
#line 1894 "l22_parser.tab.c"
    break;

  case 39:
#line 171 "l22_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence));}
#line 1900 "l22_parser.tab.c"
    break;

  case 40:
#line 176 "l22_parser.y"
                               { (yyval.sequence) = new cdk::sequence_node(LINE);  }
#line 1906 "l22_parser.tab.c"
    break;

  case 41:
#line 177 "l22_parser.y"
                               { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));}
#line 1912 "l22_parser.tab.c"
    break;

  case 42:
#line 178 "l22_parser.y"
                               { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 1918 "l22_parser.tab.c"
    break;

  case 43:
#line 182 "l22_parser.y"
                                    { (yyval.node) = new l22::var_declaration_node(LINE, tPRIVATE, (yyvsp[-1].type), *(yyvsp[0].s), nullptr);}
#line 1924 "l22_parser.tab.c"
    break;

  case 44:
#line 186 "l22_parser.y"
                                                                                       { (yyval.type) = (yyvsp[0].type); }
#line 1930 "l22_parser.tab.c"
    break;

  case 45:
#line 187 "l22_parser.y"
                                                                                       { (yyval.type) = (yyvsp[0].type); }
#line 1936 "l22_parser.tab.c"
    break;

  case 46:
#line 191 "l22_parser.y"
                                                { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
#line 1942 "l22_parser.tab.c"
    break;

  case 47:
#line 192 "l22_parser.y"
                                                { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT);     }
#line 1948 "l22_parser.tab.c"
    break;

  case 48:
#line 193 "l22_parser.y"
                                                { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
#line 1954 "l22_parser.tab.c"
    break;

  case 49:
#line 194 "l22_parser.y"
                                                { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_VOID);  }
#line 1960 "l22_parser.tab.c"
    break;

  case 50:
#line 195 "l22_parser.y"
                                                { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 1966 "l22_parser.tab.c"
    break;

  case 51:
#line 198 "l22_parser.y"
                                                                      { (yyval.type) = cdk::functional_type::create(*(yyvsp[-1].types), (yyvsp[-3].type)); }
#line 1972 "l22_parser.tab.c"
    break;

  case 52:
#line 199 "l22_parser.y"
                                                                      { (yyval.type) = cdk::functional_type::create((yyvsp[-2].type)); }
#line 1978 "l22_parser.tab.c"
    break;

  case 53:
#line 202 "l22_parser.y"
                                                                      { (yyval.types) = new std::vector<std::shared_ptr<cdk::basic_type>>(); (yyval.types)->push_back((yyvsp[0].type)); }
#line 1984 "l22_parser.tab.c"
    break;

  case 54:
#line 203 "l22_parser.y"
                                                                      { (yyval.types) = (yyvsp[-2].types); (yyval.types)->push_back((yyvsp[0].type));}
#line 1990 "l22_parser.tab.c"
    break;

  case 55:
#line 207 "l22_parser.y"
                                                              { (yyval.node) = new l22::evaluation_node(LINE, (yyvsp[-1].expression)); }
#line 1996 "l22_parser.tab.c"
    break;

  case 56:
#line 208 "l22_parser.y"
                                                              { (yyval.node) = new l22::evaluation_node(LINE, (yyvsp[0].expression)); }
#line 2002 "l22_parser.tab.c"
    break;

  case 57:
#line 209 "l22_parser.y"
                                                              { (yyval.node) = new l22::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].block)); }
#line 2008 "l22_parser.tab.c"
    break;

  case 58:
#line 210 "l22_parser.y"
                                                              { (yyval.node) = new l22::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].block), (yyvsp[0].node)); }
#line 2014 "l22_parser.tab.c"
    break;

  case 59:
#line 211 "l22_parser.y"
                                                              { (yyval.node) = new l22::while_node(LINE, (yyvsp[-3].expression), (yyvsp[0].block)); }
#line 2020 "l22_parser.tab.c"
    break;

  case 60:
#line 212 "l22_parser.y"
                                                              { (yyval.node) = new l22::stop_node(LINE); }
#line 2026 "l22_parser.tab.c"
    break;

  case 61:
#line 213 "l22_parser.y"
                                                              { (yyval.node) = new l22::again_node(LINE); }
#line 2032 "l22_parser.tab.c"
    break;

  case 62:
#line 214 "l22_parser.y"
                                                              { (yyval.node) = new l22::input_node(LINE);}
#line 2038 "l22_parser.tab.c"
    break;

  case 63:
#line 215 "l22_parser.y"
                                                              { (yyval.node) = new l22::return_node(LINE, (yyvsp[-1].expression)); }
#line 2044 "l22_parser.tab.c"
    break;

  case 64:
#line 216 "l22_parser.y"
                                                              { (yyval.node) = new l22::return_node(LINE, (yyvsp[0].expression)); }
#line 2050 "l22_parser.tab.c"
    break;

  case 65:
#line 217 "l22_parser.y"
                                                              { (yyval.node) = (yyvsp[0].node); }
#line 2056 "l22_parser.tab.c"
    break;

  case 66:
#line 218 "l22_parser.y"
                                                              { (yyval.node) = new l22::print_node(LINE, (yyvsp[-1].sequence), false);}
#line 2062 "l22_parser.tab.c"
    break;

  case 67:
#line 219 "l22_parser.y"
                                                              { (yyval.node) = new l22::print_node(LINE, (yyvsp[-1].sequence), true);}
#line 2068 "l22_parser.tab.c"
    break;

  case 68:
#line 220 "l22_parser.y"
                                                              { (yyval.node) = (yyvsp[-1].expression); }
#line 2074 "l22_parser.tab.c"
    break;

  case 69:
#line 225 "l22_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression));     }
#line 2080 "l22_parser.tab.c"
    break;

  case 70:
#line 226 "l22_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 2086 "l22_parser.tab.c"
    break;

  case 71:
#line 227 "l22_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].expression));     }
#line 2092 "l22_parser.tab.c"
    break;

  case 72:
#line 228 "l22_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node)); }
#line 2098 "l22_parser.tab.c"
    break;

  case 73:
#line 229 "l22_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 2104 "l22_parser.tab.c"
    break;

  case 74:
#line 230 "l22_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 2110 "l22_parser.tab.c"
    break;

  case 75:
#line 231 "l22_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[-4].sequence)); }
#line 2116 "l22_parser.tab.c"
    break;

  case 76:
#line 232 "l22_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].expression), (yyvsp[-4].sequence)); }
#line 2122 "l22_parser.tab.c"
    break;

  case 77:
#line 233 "l22_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].expression), (yyvsp[-3].sequence)); }
#line 2128 "l22_parser.tab.c"
    break;

  case 78:
#line 236 "l22_parser.y"
                                      { (yyval.expression) = new l22::function_call_node(LINE, (yyvsp[-1].sequence));}
#line 2134 "l22_parser.tab.c"
    break;

  case 79:
#line 237 "l22_parser.y"
                                      { (yyval.expression) = new l22::function_call_node(LINE);}
#line 2140 "l22_parser.tab.c"
    break;

  case 80:
#line 241 "l22_parser.y"
                                                   { (yyval.node) = (yyvsp[0].block); }
#line 2146 "l22_parser.tab.c"
    break;

  case 81:
#line 242 "l22_parser.y"
                                                   { (yyval.node) = new l22::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].block)); }
#line 2152 "l22_parser.tab.c"
    break;

  case 82:
#line 243 "l22_parser.y"
                                                   { (yyval.node) = new l22::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].block), (yyvsp[0].node)); }
#line 2158 "l22_parser.tab.c"
    break;

  case 83:
#line 247 "l22_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression));     }
#line 2164 "l22_parser.tab.c"
    break;

  case 84:
#line 248 "l22_parser.y"
                                                  { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 2170 "l22_parser.tab.c"
    break;

  case 85:
#line 253 "l22_parser.y"
                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2176 "l22_parser.tab.c"
    break;

  case 86:
#line 254 "l22_parser.y"
                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2182 "l22_parser.tab.c"
    break;

  case 87:
#line 255 "l22_parser.y"
                                           { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s)); }
#line 2188 "l22_parser.tab.c"
    break;

  case 88:
#line 256 "l22_parser.y"
                                        { (yyval.expression) = new l22::nullptr_node(LINE); }
#line 2194 "l22_parser.tab.c"
    break;

  case 89:
#line 257 "l22_parser.y"
                                        { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[0].expression)); }
#line 2200 "l22_parser.tab.c"
    break;

  case 90:
#line 258 "l22_parser.y"
                                        { (yyval.expression) = new l22::sizeof_node(LINE, (yyvsp[-1].expression)); }
#line 2206 "l22_parser.tab.c"
    break;

  case 91:
#line 259 "l22_parser.y"
                                        { (yyval.expression) = new l22::stack_alloc_node(LINE, (yyvsp[-1].expression)); }
#line 2212 "l22_parser.tab.c"
    break;

  case 92:
#line 260 "l22_parser.y"
                                        { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lvalue), (yyvsp[0].expression)); }
#line 2218 "l22_parser.tab.c"
    break;

  case 93:
#line 261 "l22_parser.y"
                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2224 "l22_parser.tab.c"
    break;

  case 94:
#line 262 "l22_parser.y"
                                        { (yyval.expression) = new cdk::neg_node(LINE, (yyvsp[0].expression)); }
#line 2230 "l22_parser.tab.c"
    break;

  case 95:
#line 263 "l22_parser.y"
                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2236 "l22_parser.tab.c"
    break;

  case 96:
#line 264 "l22_parser.y"
                                       { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2242 "l22_parser.tab.c"
    break;

  case 97:
#line 266 "l22_parser.y"
                                          { (yyval.expression) = (yyvsp[-2].expression); }
#line 2248 "l22_parser.tab.c"
    break;

  case 98:
#line 267 "l22_parser.y"
                                         { (yyval.expression) = (yyvsp[0].expression); }
#line 2254 "l22_parser.tab.c"
    break;

  case 99:
#line 268 "l22_parser.y"
                                       { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2260 "l22_parser.tab.c"
    break;

  case 100:
#line 269 "l22_parser.y"
                                       { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2266 "l22_parser.tab.c"
    break;

  case 101:
#line 270 "l22_parser.y"
                                       { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2272 "l22_parser.tab.c"
    break;

  case 102:
#line 271 "l22_parser.y"
                                       { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2278 "l22_parser.tab.c"
    break;

  case 103:
#line 272 "l22_parser.y"
                                       { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2284 "l22_parser.tab.c"
    break;

  case 104:
#line 273 "l22_parser.y"
                                       { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2290 "l22_parser.tab.c"
    break;

  case 105:
#line 274 "l22_parser.y"
                                       { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2296 "l22_parser.tab.c"
    break;

  case 106:
#line 275 "l22_parser.y"
                                        { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2302 "l22_parser.tab.c"
    break;

  case 107:
#line 276 "l22_parser.y"
                                       { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2308 "l22_parser.tab.c"
    break;

  case 108:
#line 277 "l22_parser.y"
                                       { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2314 "l22_parser.tab.c"
    break;

  case 109:
#line 278 "l22_parser.y"
                                       { (yyval.expression) = new cdk::and_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2320 "l22_parser.tab.c"
    break;

  case 110:
#line 279 "l22_parser.y"
                                       { (yyval.expression) = new cdk::or_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2326 "l22_parser.tab.c"
    break;

  case 111:
#line 280 "l22_parser.y"
                                        { (yyval.expression) = (yyvsp[-1].expression); }
#line 2332 "l22_parser.tab.c"
    break;

  case 112:
#line 281 "l22_parser.y"
                                        { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lvalue)); }
#line 2338 "l22_parser.tab.c"
    break;

  case 113:
#line 282 "l22_parser.y"
                                        { (yyval.expression) = new l22::address_of_node(LINE, (yyvsp[-1].lvalue)); }
#line 2344 "l22_parser.tab.c"
    break;

  case 114:
#line 283 "l22_parser.y"
                                        { (yyval.expression) = new l22::function_call_node(LINE, new cdk::rvalue_node(LINE, (yyvsp[-3].lvalue)), (yyvsp[-1].sequence));}
#line 2350 "l22_parser.tab.c"
    break;

  case 115:
#line 284 "l22_parser.y"
                                        { (yyval.expression) = new l22::function_call_node(LINE, new cdk::rvalue_node(LINE, (yyvsp[-2].lvalue)));}
#line 2356 "l22_parser.tab.c"
    break;

  case 116:
#line 285 "l22_parser.y"
                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2362 "l22_parser.tab.c"
    break;

  case 117:
#line 288 "l22_parser.y"
                                   { (yyval.lvalue) = new cdk::variable_node(LINE, (yyvsp[0].s)); }
#line 2368 "l22_parser.tab.c"
    break;

  case 118:
#line 289 "l22_parser.y"
                                   { (yyval.lvalue) = new l22::index_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 2374 "l22_parser.tab.c"
    break;

  case 119:
#line 293 "l22_parser.y"
                                                { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i)); }
#line 2380 "l22_parser.tab.c"
    break;

  case 120:
#line 294 "l22_parser.y"
                                                { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d)); }
#line 2386 "l22_parser.tab.c"
    break;

  case 121:
#line 295 "l22_parser.y"
                                                { (yyval.s) = (yyvsp[0].s); }
#line 2392 "l22_parser.tab.c"
    break;

  case 122:
#line 296 "l22_parser.y"
                                                { (yyval.s) = (yyvsp[-1].s); (yyval.s)->append(*(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2398 "l22_parser.tab.c"
    break;


#line 2402 "l22_parser.tab.c"

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (compiler, YY_("syntax error"));
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
        yyerror (compiler, yymsgp);
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
                      yytoken, &yylval, compiler);
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
                  yystos[yystate], yyvsp, compiler);
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
  yyerror (compiler, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, compiler);
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
#line 298 "l22_parser.y"







