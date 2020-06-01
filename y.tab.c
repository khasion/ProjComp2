/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

     #include <stdio.h>
     #include <unistd.h>
     #include <stdlib.h>
     #include <string.h>
     #include "quads.h"
     #include "stack.h"
     #include "avm.h"

     #define  YY_DECL int alpha_yylex (void* yylval)
     void yyerror (char* yaccProovidedMessage);
     int yylex();
     extern int yylineno;
     extern char* yytext;
     extern FILE* yyin;
     unsigned loopcounter = 0;
     unsigned retaddr = 0;

#line 85 "y.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ASSIGN = 258,
    OR = 259,
    AND = 260,
    EQ = 261,
    NOT_EQ = 262,
    GREATER = 263,
    GREATER_EQ = 264,
    LESS = 265,
    LESS_EQ = 266,
    PLUS = 267,
    MINUS = 268,
    MUL = 269,
    DIV = 270,
    MOD = 271,
    NOT = 272,
    D_PLUS = 273,
    D_MINUS = 274,
    UMINUS = 275,
    DOT = 276,
    D_DOT = 277,
    L_BRA = 278,
    R_BRA = 279,
    L_PAR = 280,
    R_PAR = 281,
    INT = 282,
    REAL = 283,
    ID = 284,
    STRING = 285,
    IF = 286,
    ELSE = 287,
    WHILE = 288,
    FOR = 289,
    FUNC = 290,
    RETURN = 291,
    BREAK = 292,
    CONTINUE = 293,
    LOCAL = 294,
    TRUE = 295,
    FALSE = 296,
    NIL = 297,
    LC_BRA = 298,
    RC_BRA = 299,
    SEMI = 300,
    COMMA = 301,
    COLON = 302,
    D_COLON = 303
  };
#endif
/* Tokens.  */
#define ASSIGN 258
#define OR 259
#define AND 260
#define EQ 261
#define NOT_EQ 262
#define GREATER 263
#define GREATER_EQ 264
#define LESS 265
#define LESS_EQ 266
#define PLUS 267
#define MINUS 268
#define MUL 269
#define DIV 270
#define MOD 271
#define NOT 272
#define D_PLUS 273
#define D_MINUS 274
#define UMINUS 275
#define DOT 276
#define D_DOT 277
#define L_BRA 278
#define R_BRA 279
#define L_PAR 280
#define R_PAR 281
#define INT 282
#define REAL 283
#define ID 284
#define STRING 285
#define IF 286
#define ELSE 287
#define WHILE 288
#define FOR 289
#define FUNC 290
#define RETURN 291
#define BREAK 292
#define CONTINUE 293
#define LOCAL 294
#define TRUE 295
#define FALSE 296
#define NIL 297
#define LC_BRA 298
#define RC_BRA 299
#define SEMI 300
#define COMMA 301
#define COLON 302
#define D_COLON 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 22 "parser.y" /* yacc.c:355  */

     int intval;
     char* strval;
     float floatval;
     struct expr* exprval;
     struct stmt_t stmtval;
     struct call callval;
     struct symbol* symval;
     struct prefix prefval;

#line 232 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 247 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   598

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  194

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    74,    77,    83,    90,    91,    92,    93,
      94,   100,   106,   107,   108,   114,   115,   120,   125,   130,
     135,   140,   150,   160,   170,   182,   192,   202,   202,   225,
     225,   247,   250,   251,   257,   274,   290,   307,   323,   344,
     347,   367,   368,   369,   370,   374,   377,   381,   388,   392,
     395,   396,   402,   403,   406,   407,   416,   423,   424,   427,
     433,   439,   446,   448,   452,   455,   466,   483,   489,   493,
     496,   503,   504,   507,   507,   510,   514,   520,   533,   539,
     546,   547,   549,   566,   567,   568,   569,   570,   571,   574,
     575,   576,   579,   589,   595,   598,   604,   610,   619,   628,
     633,   636,   636,   646,   646,   656,   664,   673,   681
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "OR", "AND", "EQ", "NOT_EQ",
  "GREATER", "GREATER_EQ", "LESS", "LESS_EQ", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "NOT", "D_PLUS", "D_MINUS", "UMINUS", "DOT", "D_DOT",
  "L_BRA", "R_BRA", "L_PAR", "R_PAR", "INT", "REAL", "ID", "STRING", "IF",
  "ELSE", "WHILE", "FOR", "FUNC", "RETURN", "BREAK", "CONTINUE", "LOCAL",
  "TRUE", "FALSE", "NIL", "LC_BRA", "RC_BRA", "SEMI", "COMMA", "COLON",
  "D_COLON", "$accept", "program", "stmts", "stmt", "expr", "$@1", "$@2",
  "term", "assignexpr", "primary", "lvalue", "member", "call",
  "callsuffix", "normcall", "methodcall", "elist", "comma_elist",
  "objectdef", "indexed", "indexed_tmp", "indexedelem", "rec_stmt",
  "block", "$@3", "funcname", "funcprefix", "funcargs", "funcbody",
  "funcblockstart", "funcblockend", "funcdef", "const", "idlist",
  "ifprefix", "elseprefix", "ifstmt", "whilestart", "whilecond",
  "whilestmt", "N", "M", "forprefix", "$@4", "forstmt", "$@5", "break",
  "continue", "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -166

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-166)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     296,   426,   426,    19,    19,   329,   361,  -166,  -166,  -166,
    -166,     3,  -166,  -166,    -7,   393,  -166,  -166,    -4,  -166,
    -166,  -166,  -166,  -166,    14,    47,   296,  -166,   183,  -166,
    -166,  -166,    92,  -166,    -2,  -166,  -166,    27,  -166,  -166,
     296,  -166,    28,  -166,  -166,  -166,    10,    11,  -166,  -166,
    -166,    24,    -5,    -2,    -5,   426,   128,    36,    38,    17,
     471,    40,   426,    39,  -166,  -166,  -166,   196,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,   426,   426,   426,   426,   426,
     426,   426,   426,   426,   426,   426,  -166,   426,  -166,  -166,
      41,    56,   426,   426,  -166,  -166,  -166,    58,   426,   426,
      60,  -166,    37,   426,   296,   426,  -166,  -166,    45,    26,
     426,  -166,  -166,  -166,    25,  -166,  -166,    65,   494,   426,
    -166,   263,  -166,  -166,   169,   169,   234,   234,   234,   234,
      -3,    -3,  -166,  -166,  -166,   582,  -166,    68,   540,    70,
    -166,   561,    73,  -166,   -19,    51,  -166,   296,   517,  -166,
      74,    65,   426,   128,    17,   426,  -166,    61,  -166,  -166,
     426,   426,   426,  -166,  -166,  -166,  -166,  -166,    72,  -166,
    -166,  -166,  -166,  -166,   251,  -166,  -166,    77,  -166,   114,
     223,    81,  -166,  -166,   296,  -166,  -166,   426,  -166,  -166,
     209,  -166,  -166,  -166
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    62,     0,    83,    84,    46,
      85,     0,    96,   101,    76,     0,   105,   106,     0,    87,
      88,    86,    73,    14,     0,     0,     2,     3,     0,    31,
      15,    39,    41,    49,    42,    43,    12,     0,    13,    45,
       0,     6,     0,     7,    99,     8,     0,     0,     9,    33,
      34,     0,    35,     0,    37,     0,    64,     0,     0,    69,
       0,     0,     0,     0,    75,    77,   107,     0,    47,    72,
      48,     1,     4,    29,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,    36,    38,
       0,     0,     0,    62,    55,    57,    58,     0,     0,    62,
      91,    80,    94,     0,     0,    62,    10,    11,     0,     0,
       0,    61,    65,    66,     0,    67,    32,    44,     0,    62,
     108,     0,   100,   100,    25,    26,    21,    22,    23,    24,
      16,    17,    18,    19,    20,    40,    50,     0,     0,     0,
      52,     0,     0,    89,     0,     0,    93,     0,     0,    98,
       0,     0,     0,    64,    69,    62,    92,     0,    74,    71,
       0,     0,    62,    51,    59,    53,    54,    78,     0,    79,
      81,    95,    97,    99,     0,    63,    68,     0,   100,    30,
      28,     0,    90,    82,     0,    70,    56,     0,    60,   103,
       0,    99,   102,   104
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,   -16,    -1,  -166,  -166,  -166,  -166,  -166,
      42,  -166,    46,  -166,  -166,  -166,   -90,   -45,  -166,  -166,
     -42,     2,  -166,     1,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,     0,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -165,  -121,  -166,  -166,  -166,  -166,  -166,  -166,  -166
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,   123,   122,    29,    30,    31,
      32,    33,    34,    94,    95,    96,    57,   111,    35,    58,
     115,    59,   121,    36,    69,    65,    37,   101,   170,   145,
     183,    38,    39,   144,    40,   147,    41,    42,   104,    43,
     105,   160,    44,    63,    45,   191,    46,    47,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    50,   161,   139,    56,    60,    61,   167,   184,   142,
      72,    83,    84,    85,    67,   150,    90,    91,    92,    97,
      93,    98,    64,    99,   102,    68,   193,   168,    62,   157,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    70,    51,    52,    54,    71,     9,    53,
      53,   108,   100,   103,   109,   106,   107,   187,    18,    14,
     112,   118,   113,   114,   119,   177,   117,    24,    55,   146,
     136,   151,   181,   152,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   137,   135,   140,   149,   143,
     155,   138,    56,   162,    22,    87,   164,   141,    56,   166,
     173,   182,   148,   186,    56,   159,   178,   188,   175,   153,
      88,    89,   176,    90,    91,    92,   154,    93,    56,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   171,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,   169,     0,     0,     0,
       0,   174,     0,     0,    56,     0,     0,     0,     0,   179,
     180,    56,     0,     0,     0,     0,     0,     0,   189,     0,
       0,     0,     0,     0,   110,    -1,    -1,    77,    78,    79,
      80,    81,    82,    83,    84,    85,   190,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,     0,    86,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,   120,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,     0,     0,     0,   192,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       2,     3,     4,     0,     0,     0,     5,     0,     6,     0,
       7,     8,     9,    10,    11,   185,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   158,    23,     1,
       0,    24,     0,     2,     3,     4,     0,     0,     0,     5,
       0,     6,     0,     7,     8,     9,    10,    11,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       0,    23,     1,     0,    24,     0,     2,     3,     4,     0,
       0,     0,     5,     0,     6,     0,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,    21,    55,     0,     1,     0,     0,    24,     2,     3,
       4,     0,     0,     0,     5,     0,     6,     0,     7,     8,
       9,    10,     0,     0,     0,     0,    14,     0,     0,     0,
      18,    19,    20,    21,     0,     0,     1,     0,     0,    24,
       2,     3,     4,     0,     0,     0,     5,     0,     6,     0,
       7,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,     0,     0,    66,     1,
       0,    24,     0,     2,     3,     4,     0,     0,     0,     5,
       0,     6,     0,     7,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,    20,    21,     0,
       0,     0,     0,     0,    24,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   172,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,     0,     0,
       0,     0,     0,     0,   163,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,     0,     0,     0,   165,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
       1,     2,   123,    93,     5,     6,     6,    26,   173,    99,
      26,    14,    15,    16,    15,   105,    21,    22,    23,    21,
      25,    23,    29,    25,    40,    29,   191,    46,    25,   119,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    29,    25,     3,     4,     0,    29,     3,
       4,    51,    25,    25,    55,    45,    45,   178,    39,    35,
      24,    62,    24,    46,    25,   155,    26,    48,    43,    32,
      29,    26,   162,    47,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    29,    87,    29,   104,    29,
      25,    92,    93,    25,    43,     3,    26,    98,    99,    26,
      26,    29,   103,    26,   105,   121,    45,    26,   153,   110,
      18,    19,   154,    21,    22,    23,   114,    25,   119,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   147,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,   145,    -1,    -1,    -1,
      -1,   152,    -1,    -1,   155,    -1,    -1,    -1,    -1,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,
      -1,    -1,    -1,    -1,    46,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   187,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    45,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    45,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    45,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      17,    18,    19,    -1,    -1,    -1,    23,    -1,    25,    -1,
      27,    28,    29,    30,    31,    44,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    13,
      -1,    48,    -1,    17,    18,    19,    -1,    -1,    -1,    23,
      -1,    25,    -1,    27,    28,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    45,    13,    -1,    48,    -1,    17,    18,    19,    -1,
      -1,    -1,    23,    -1,    25,    -1,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    -1,    13,    -1,    -1,    48,    17,    18,
      19,    -1,    -1,    -1,    23,    -1,    25,    -1,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      39,    40,    41,    42,    -1,    -1,    13,    -1,    -1,    48,
      17,    18,    19,    -1,    -1,    -1,    23,    -1,    25,    -1,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    -1,    -1,    45,    13,
      -1,    48,    -1,    17,    18,    19,    -1,    -1,    -1,    23,
      -1,    25,    -1,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    48,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    17,    18,    19,    23,    25,    27,    28,    29,
      30,    31,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    45,    48,    50,    51,    52,    53,    56,
      57,    58,    59,    60,    61,    67,    72,    75,    80,    81,
      83,    85,    86,    88,    91,    93,    95,    96,    97,    53,
      53,    25,    59,    61,    59,    43,    53,    65,    68,    70,
      53,    80,    25,    92,    29,    74,    45,    53,    29,    73,
      29,     0,    52,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    45,     3,    18,    19,
      21,    22,    23,    25,    62,    63,    64,    21,    23,    25,
      25,    76,    52,    25,    87,    89,    45,    45,    80,    53,
      46,    66,    24,    24,    46,    69,    26,    26,    53,    25,
      45,    71,    55,    54,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    29,    29,    53,    65,
      29,    53,    65,    29,    82,    78,    32,    84,    53,    52,
      65,    26,    47,    53,    70,    25,    26,    65,    44,    52,
      90,    90,    25,    24,    26,    24,    26,    26,    46,    72,
      77,    52,    26,    26,    53,    66,    69,    65,    45,    53,
      53,    65,    29,    79,    89,    44,    26,    90,    26,    52,
      53,    94,    45,    89
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    53,    55,
      53,    53,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    58,    58,    58,    58,    58,    59,    59,    59,    59,
      60,    60,    60,    60,    61,    61,    61,    62,    62,    63,
      64,    65,    65,    66,    66,    67,    67,    68,    69,    69,
      70,    71,    71,    73,    72,    74,    74,    75,    76,    77,
      78,    79,    80,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    83,    84,    85,    85,    86,    87,    88,    89,
      90,    92,    91,    94,    93,    95,    96,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     0,     5,     0,
       5,     1,     3,     2,     2,     2,     2,     2,     2,     1,
       3,     1,     1,     1,     3,     1,     1,     2,     2,     1,
       3,     4,     3,     4,     4,     2,     6,     1,     1,     3,
       5,     2,     0,     3,     0,     3,     3,     2,     3,     0,
       5,     2,     0,     0,     4,     1,     0,     2,     3,     1,
       0,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     4,     1,     2,     4,     1,     3,     3,     0,
       0,     0,     8,     0,     8,     1,     1,     2,     3
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
#line 71 "parser.y" /* yacc.c:1646  */
    {;}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "parser.y" /* yacc.c:1646  */
    {
               (yyval.stmtval) = (yyvsp[0].stmtval);
          }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 77 "parser.y" /* yacc.c:1646  */
    {
               (yyval.stmtval).breaklist = mergelist((yyvsp[-1].stmtval).breaklist, (yyvsp[0].stmtval).breaklist); 
               (yyval.stmtval).contlist = mergelist((yyvsp[-1].stmtval).contlist, (yyvsp[0].stmtval).contlist);
          }
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 83 "parser.y" /* yacc.c:1646  */
    {
               make_stmt(&(yyval.stmtval));
               resettemp();
               if ((yyvsp[-1].exprval)->type == 5) {
                    patchboolean((yyvsp[-1].exprval), yylineno);
               }
          }
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 90 "parser.y" /* yacc.c:1646  */
    { make_stmt(&(yyval.stmtval));}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 91 "parser.y" /* yacc.c:1646  */
    { make_stmt(&(yyval.stmtval));}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 92 "parser.y" /* yacc.c:1646  */
    { make_stmt(&(yyval.stmtval));}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 93 "parser.y" /* yacc.c:1646  */
    { make_stmt(&(yyval.stmtval));}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 94 "parser.y" /* yacc.c:1646  */
    {
               make_stmt(&(yyval.stmtval));
               (yyval.stmtval).breaklist = (yyvsp[-1].stmtval).breaklist;
               (yyval.stmtval).contlist = (yyvsp[-1].stmtval).contlist;
               if (loopcounter == 0) Error(3, yytext, yylineno);
          }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 100 "parser.y" /* yacc.c:1646  */
    {
               make_stmt(&(yyval.stmtval));
               (yyval.stmtval).breaklist = (yyvsp[-1].stmtval).breaklist;
               (yyval.stmtval).contlist = (yyvsp[-1].stmtval).contlist;
               if (loopcounter == 0) Error(4, yytext, yylineno);
          }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 106 "parser.y" /* yacc.c:1646  */
    { (yyval.stmtval) = (yyvsp[0].stmtval);}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 107 "parser.y" /* yacc.c:1646  */
    { make_stmt(&(yyval.stmtval));}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 108 "parser.y" /* yacc.c:1646  */
    { make_stmt(&(yyval.stmtval));}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.exprval) = (yyvsp[0].exprval);}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 115 "parser.y" /* yacc.c:1646  */
    {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_add, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 120 "parser.y" /* yacc.c:1646  */
    {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_sub, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 125 "parser.y" /* yacc.c:1646  */
    {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_mul, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 130 "parser.y" /* yacc.c:1646  */
    {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_div, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "parser.y" /* yacc.c:1646  */
    {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_mod, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 140 "parser.y" /* yacc.c:1646  */
    {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad() + 1);
               emit(if_greater, (yyvsp[-2].exprval), (yyvsp[0].exprval), NULL, 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $$, nextquad() + 1, yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $$, nextquad() + 1, yylineno);
          }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 150 "parser.y" /* yacc.c:1646  */
    {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad()+1);
               emit(if_lesseq, (yyvsp[-2].exprval), (yyvsp[0].exprval), NULL, 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $$, 69, yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //(assign, newexpr_constbool('1'), NULL, $$, 69 ,yylineno);
          }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 160 "parser.y" /* yacc.c:1646  */
    {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad()+1);
               emit(if_less, (yyvsp[-2].exprval), (yyvsp[0].exprval), NULL, 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
           }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 170 "parser.y" /* yacc.c:1646  */
    {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();

               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad()+1);

               emit(if_greatereq, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
          }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 182 "parser.y" /* yacc.c:1646  */
    {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad()+1);
               emit(if_eq, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
           }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 192 "parser.y" /* yacc.c:1646  */
    {
               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = newlist(nextquad());
               (yyval.exprval)->falselist = newlist(nextquad()+1);
               emit(if_noteq, (yyvsp[-2].exprval), (yyvsp[0].exprval), NULL, 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
           }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 202 "parser.y" /* yacc.c:1646  */
    {
               if( (yyvsp[-1].exprval) && (yyvsp[-1].exprval)->type != 5){
                    (yyvsp[-1].exprval)->truelist = newlist(nextquad());
                    (yyvsp[-1].exprval)->falselist = newlist(nextquad()+1);
                    emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, 0, yylineno);
                    emit(jump, NULL, NULL, NULL , 0, yylineno);
              
               }
          }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 210 "parser.y" /* yacc.c:1646  */
    {
               if((yyvsp[0].exprval) && (yyvsp[0].exprval)->type != 5){
                    (yyvsp[0].exprval)->truelist = newlist(nextquad());
                    (yyvsp[0].exprval)->falselist = newlist(nextquad()+1);
                    emit(if_eq, (yyvsp[0].exprval), newexpr_constbool(1), NULL, 0, yylineno);
                    emit(jump, NULL, NULL, NULL , 0, yylineno);
               }

              (yyval.exprval) = newexpr(boolexpr_e);
              (yyval.exprval)->sym = newtemp();
              backpatch((yyvsp[-4].exprval)->truelist, (yyvsp[-1].intval));

              (yyval.exprval)->truelist = (yyvsp[0].exprval)->truelist;
              (yyval.exprval)->falselist = mergelist((yyvsp[-4].exprval)->falselist, (yyvsp[0].exprval)->falselist);
          }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 225 "parser.y" /* yacc.c:1646  */
    {
               if((yyvsp[-1].exprval) && (yyvsp[-1].exprval)->type != 5){
                    (yyvsp[-1].exprval)->truelist = newlist(nextquad());
                    (yyvsp[-1].exprval)->falselist = newlist(nextquad()+1);
                    emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, 0, yylineno);
                    emit(jump, NULL, NULL, NULL , 0, yylineno);
               }
          }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 232 "parser.y" /* yacc.c:1646  */
    {
               if( (yyvsp[0].exprval) && (yyvsp[0].exprval)->type != 5){
                    (yyvsp[0].exprval)->truelist = newlist(nextquad());
                    (yyvsp[0].exprval)->falselist = newlist(nextquad()+1);
                    emit(if_eq, (yyvsp[0].exprval), newexpr_constbool(1), NULL, 0, yylineno);
                    emit(jump, NULL, NULL, NULL , 0, yylineno);
               }
               backpatch((yyvsp[-4].exprval)->falselist, (yyvsp[-1].intval));

               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();

               (yyval.exprval)->truelist = mergelist((yyvsp[-4].exprval)->truelist, (yyvsp[0].exprval)->truelist);
               (yyval.exprval)->falselist = (yyvsp[0].exprval)->falselist;
          }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 247 "parser.y" /* yacc.c:1646  */
    {(yyval.exprval) = (yyvsp[0].exprval);}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 250 "parser.y" /* yacc.c:1646  */
    {(yyval.exprval) = (yyvsp[-1].exprval);}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 251 "parser.y" /* yacc.c:1646  */
    {
               check_arith((yyvsp[0].exprval), (yyvsp[0].exprval)->sym->name);
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = istempexpr((yyvsp[0].exprval)) ? (yyvsp[0].exprval)->sym : newtemp();
               emit(uminus, (yyvsp[0].exprval), NULL, (yyval.exprval), nextquad() + 1,yylineno); 
          }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 257 "parser.y" /* yacc.c:1646  */
    {
               /*if($2->type != 5){
                    $2->truelist = newlist(nextquad());
                    $2->falselist = newlist(nextquad()+1);
                    emit(if_eq, $2, newexpr_constbool(1), NULL, 0, yylineno);
                    emit(jump, NULL, NULL, NULL , 0, yylineno);
               }*/
               (yyvsp[0].exprval)->truelist = newlist(nextquad());
               (yyvsp[0].exprval)->falselist = newlist(nextquad() + 1);
               emit(if_eq, (yyvsp[0].exprval), newexpr_constbool(1), NULL, 0, yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);

               (yyval.exprval) = newexpr(boolexpr_e);
               (yyval.exprval)->sym = newtemp();
               (yyval.exprval)->truelist = (yyvsp[0].exprval)->falselist;
               (yyval.exprval)->falselist = (yyvsp[0].exprval)->truelist;
          }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 274 "parser.y" /* yacc.c:1646  */
    {
               if((yyvsp[0].exprval) != NULL && (yyvsp[0].exprval)->type == programfunc_e) Error(0, yytext, yylineno);
               else if((yyvsp[0].exprval) != NULL && (yyvsp[0].exprval)->type == libraryfunc_e) Error(1, yytext, yylineno);
               check_arith((yyvsp[0].exprval), (yyvsp[0].exprval)->sym->name);
               if ((yyvsp[0].exprval)->type == tableitem_e) {
                    (yyval.exprval) = emit_iftableitem((yyvsp[0].exprval), yylineno);
                    emit(op_add, (yyval.exprval), newexpr_constnum(1), (yyval.exprval), nextquad() + 1,yylineno);
                    emit(tablesetelem, (yyvsp[0].exprval)->index, (yyval.exprval), (yyvsp[0].exprval), nextquad() + 1, yylineno);
               }
               else {
                    emit(op_add, (yyvsp[0].exprval), newexpr_constnum(1), (yyvsp[0].exprval), nextquad() + 1, yylineno);
                    (yyval.exprval) = newexpr(arithexpr_e);
                    (yyval.exprval)->sym = newtemp();
                    emit(assign, (yyvsp[0].exprval), NULL, (yyval.exprval), nextquad() + 1,yylineno);
               }
          }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 290 "parser.y" /* yacc.c:1646  */
    {
               if((yyvsp[-1].exprval) != NULL && (yyvsp[-1].exprval)->type == programfunc_e) Error(0, yytext, yylineno);
               else if((yyvsp[-1].exprval) != NULL && (yyvsp[-1].exprval)->type == libraryfunc_e) Error(1,yytext, yylineno);
               check_arith((yyval.exprval), (yyvsp[-1].exprval)->sym->name);
               (yyval.exprval) = newexpr(var_e);
               (yyval.exprval)->sym= newtemp();
               if ((yyvsp[-1].exprval)->type == tableitem_e){
                    Expr* value = emit_iftableitem((yyvsp[-1].exprval), yylineno);
                    emit(assign, value, NULL,(yyval.exprval),0,yylineno);
                    emit(op_add, value, newexpr_constnum(1), value,0,yylineno);
                    emit(tablesetelem, (yyvsp[-1].exprval)->index,value, (yyvsp[-1].exprval), nextquad() + 1,yylineno);
               }
               else {
                    emit(assign, (yyvsp[-1].exprval), NULL , (yyval.exprval), nextquad() + 1, yylineno);
                    emit(op_add, (yyvsp[-1].exprval), newexpr_constnum(1), (yyvsp[-1].exprval), nextquad() + 1, yylineno);
               }
          }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 307 "parser.y" /* yacc.c:1646  */
    {
               if((yyvsp[0].exprval) != NULL && (yyvsp[0].exprval)->type == programfunc_e) Error(0, yytext, yylineno);
               else if((yyvsp[0].exprval) != NULL && (yyvsp[0].exprval)->type == libraryfunc_e) Error(1, yytext, yylineno);
               check_arith((yyvsp[0].exprval), (yyvsp[0].exprval)->sym->name);
               if ((yyvsp[0].exprval)->type == tableitem_e) {
                    (yyval.exprval) = emit_iftableitem((yyvsp[0].exprval), yylineno);
                    emit(op_sub, (yyval.exprval), newexpr_constnum(1), (yyval.exprval), 0,yylineno);
                    emit(tablesetelem, (yyvsp[0].exprval)->index, (yyval.exprval), (yyvsp[0].exprval), nextquad() + 1, yylineno);
               }
               else {
                    emit(op_sub, (yyvsp[0].exprval), newexpr_constnum(1), (yyvsp[0].exprval), nextquad() + 1,yylineno);
                    (yyval.exprval) = newexpr(arithexpr_e);
                    (yyval.exprval)->sym = newtemp();
                    emit(assign, (yyvsp[0].exprval), NULL, (yyval.exprval), nextquad() + 1,yylineno);
               }
          }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 323 "parser.y" /* yacc.c:1646  */
    {
               if((yyvsp[-1].exprval) != NULL && (yyvsp[-1].exprval)->type == programfunc_e) {
                    Error(0, yytext, yylineno);
               }
               else if((yyvsp[-1].exprval) != NULL && (yyvsp[-1].exprval)->type == libraryfunc_e) {
                    Error(1, yytext, yylineno);
               }
               check_arith((yyval.exprval), (yyvsp[-1].exprval)->sym->name);
               (yyval.exprval) = newexpr(var_e);
               (yyval.exprval)->sym= newtemp();
               if ((yyvsp[-1].exprval)->type == tableitem_e){
                    Expr* value = emit_iftableitem((yyvsp[-1].exprval), yylineno);
                    emit(assign, value, NULL,(yyval.exprval),0,yylineno);
                    emit(op_sub, value, newexpr_constnum(1), value,0,yylineno);
                    emit(tablesetelem, (yyvsp[-1].exprval)->index,value, (yyvsp[-1].exprval), nextquad() + 1,yylineno);
               }
               else {
                    emit(assign, (yyvsp[-1].exprval), NULL, (yyval.exprval), nextquad() + 1,yylineno);
                    emit(op_sub, (yyvsp[-1].exprval), newexpr_constnum(1), (yyvsp[-1].exprval), nextquad() + 1,yylineno);
               }
          }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 344 "parser.y" /* yacc.c:1646  */
    {(yyval.exprval) = (yyvsp[0].exprval);}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 347 "parser.y" /* yacc.c:1646  */
    {
                    if((yyvsp[-2].exprval) != NULL && (yyvsp[-2].exprval)->type == programfunc_e) Error(0, yytext, yylineno);
                    else if((yyvsp[-2].exprval) != NULL && (yyvsp[-2].exprval)->type == libraryfunc_e) Error(1, yytext, yylineno);
                    if ((yyvsp[-2].exprval)->type == tableitem_e)  {
                         emit(tablesetelem, (yyvsp[-2].exprval)->index, (yyvsp[0].exprval), (yyvsp[-2].exprval), nextquad() + 1, yylineno);
                         (yyval.exprval) = emit_iftableitem ((yyvsp[-2].exprval), yylineno);
                         (yyval.exprval)->type = assignexpr_e;
                    }
                    else {
                         if ( (yyvsp[0].exprval)->type == 5) {
                              patchboolean((yyvsp[0].exprval), yylineno);
                         }
                         (yyval.exprval) = newexpr(assignexpr_e);
                         (yyval.exprval)->sym = newtemp();
                         emit(assign, (yyvsp[0].exprval), (Expr*) 0, (yyvsp[-2].exprval), nextquad() + 1, yylineno);
                         emit(assign, (yyvsp[-2].exprval), (Expr*) 0, (yyval.exprval), nextquad() + 1, yylineno);
                    }
               }
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 367 "parser.y" /* yacc.c:1646  */
    { (yyval.exprval) = emit_iftableitem((yyvsp[0].exprval), yylineno);}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 368 "parser.y" /* yacc.c:1646  */
    {;}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 369 "parser.y" /* yacc.c:1646  */
    {;}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 370 "parser.y" /* yacc.c:1646  */
    {
               (yyval.exprval) = newexpr(programfunc_e);
               (yyval.exprval)->sym = (yyvsp[-1].symval);
          }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 374 "parser.y" /* yacc.c:1646  */
    { (yyval.exprval) = (yyvsp[0].exprval);}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 377 "parser.y" /* yacc.c:1646  */
    {
               Symbol* item = lvalue_id(yytext, yylineno);
               (yyval.exprval) = lvalue_expr(item);
          }
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 381 "parser.y" /* yacc.c:1646  */
    {
               Symbol* item = lvalue_localid(yytext, yylineno);
               if ( item && item->type == programfunc_s) {
                    fprintf(stderr, "Warning  :  %s is a function.", yytext);
               }
               (yyval.exprval) = lvalue_expr(item);
          }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 388 "parser.y" /* yacc.c:1646  */
    {
               Symbol* item = lvalue_dcolonid(yytext, yylineno);
               (yyval.exprval) = lvalue_expr(item);
          }
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 392 "parser.y" /* yacc.c:1646  */
    {(yyval.exprval) = (yyvsp[0].exprval);}
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 395 "parser.y" /* yacc.c:1646  */
    {(yyval.exprval) = member_item((yyvsp[-2].exprval), yytext,yylineno);}
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 396 "parser.y" /* yacc.c:1646  */
    {
               (yyvsp[-3].exprval) = emit_iftableitem((yyvsp[-3].exprval), yylineno);
               (yyval.exprval) = newexpr(tableitem_e);
               (yyval.exprval)->sym = (yyvsp[-3].exprval)->sym;
               (yyval.exprval)->index = (yyvsp[-1].exprval);
          }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 402 "parser.y" /* yacc.c:1646  */
    {;}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 403 "parser.y" /* yacc.c:1646  */
    {;}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 406 "parser.y" /* yacc.c:1646  */
    { (yyval.exprval) = make_call((yyval.exprval), (yyvsp[-1].exprval),yylineno);}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 407 "parser.y" /* yacc.c:1646  */
    {
               (yyvsp[-1].exprval) = emit_iftableitem((yyvsp[-1].exprval), yylineno);
               if ((yyvsp[0].callval).method){
                    Expr* t = (yyvsp[-1].exprval);
                    (yyvsp[-1].exprval) = emit_iftableitem(member_item(t, (yyvsp[0].callval).name,yylineno), yylineno);
                    (yyvsp[0].callval).elist->next = t;
               }
               (yyval.exprval) = make_call((yyvsp[-1].exprval), (yyvsp[0].callval).elist,yylineno);
          }
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 416 "parser.y" /* yacc.c:1646  */
    {
               Expr* func = newexpr(programfunc_e);
               func->sym = (yyvsp[-4].symval);
               (yyval.exprval) = make_call(func, (yyvsp[-1].exprval),yylineno);
          }
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 423 "parser.y" /* yacc.c:1646  */
    { (yyval.callval) = (yyvsp[0].callval); }
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 424 "parser.y" /* yacc.c:1646  */
    {(yyval.callval) = (yyvsp[0].callval);}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 427 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.callval).elist = (yyvsp[-1].exprval);
                    (yyval.callval).method = 0;
                    (yyval.callval).name = NULL;
               }
#line 2169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 433 "parser.y" /* yacc.c:1646  */
    {
               (yyval.callval).elist = (yyvsp[-1].exprval);
               (yyval.callval).method = 1;
               (yyval.callval).name = (yyvsp[-3].strval);
          }
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 439 "parser.y" /* yacc.c:1646  */
    {
               if ( (yyvsp[-1].exprval)->type == boolexpr_e) {
                    patchboolean((yyvsp[-1].exprval), yylineno);
               }
               (yyval.exprval) = (yyvsp[-1].exprval);
               (yyval.exprval)->next = (yyvsp[0].exprval);
          }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 446 "parser.y" /* yacc.c:1646  */
    {(yyval.exprval) = NULL;}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 448 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.exprval) = (yyvsp[-1].exprval);
                    (yyval.exprval)->next = (yyvsp[0].exprval);
               }
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 452 "parser.y" /* yacc.c:1646  */
    {(yyval.exprval) = NULL;}
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 455 "parser.y" /* yacc.c:1646  */
    {
                    int i;
                    Expr* t = newexpr(newtable_e);
                    t->sym = newtemp();
                    emit(tablecreate, t, NULL, NULL, nextquad() + 1,yylineno);
                    Expr* tmp = (yyvsp[-1].exprval);
                    for (i = 0; tmp; tmp = tmp->next)  {
                         emit(tablesetelem, newexpr_constnum(i++), tmp, t, nextquad() + 1, yylineno);
                    }
                    (yyval.exprval) = t;
               }
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 466 "parser.y" /* yacc.c:1646  */
    {
                    Expr* t = newexpr(newtable_e);
                    t->sym = newtemp();
                    emit(tablecreate, t, NULL, NULL, nextquad() + 1, yylineno);
                    Expr *tmp= (yyvsp[-1].exprval);
                    while (tmp) {
                         Expr* tmp2 = tmp->index;
                         while (tmp2) {
                              emit(tablesetelem, tmp, tmp2, t, nextquad() + 1, yylineno);
                              tmp2 = tmp2->index;
                         }
                         tmp=tmp->next;
                    }
                    (yyval.exprval) = t;
               }
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 483 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.exprval) = (yyvsp[-1].exprval);
                    (yyval.exprval)->next=(yyvsp[0].exprval);
               }
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 489 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.exprval) = (yyvsp[-1].exprval);
                    (yyval.exprval)->next = (yyvsp[0].exprval);
               }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 493 "parser.y" /* yacc.c:1646  */
    {(yyval.exprval)=NULL;}
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 496 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.exprval)=(yyvsp[-3].exprval);
                    (yyval.exprval)->index = (yyvsp[-1].exprval); 
               }
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 503 "parser.y" /* yacc.c:1646  */
    { (yyval.stmtval) = (yyvsp[0].stmtval);}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 504 "parser.y" /* yacc.c:1646  */
    {;}
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 507 "parser.y" /* yacc.c:1646  */
    { nextscope();}
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 507 "parser.y" /* yacc.c:1646  */
    { (yyval.stmtval) = (yyvsp[-1].stmtval); hide(currscope()); exitscope();}
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 510 "parser.y" /* yacc.c:1646  */
    {
                    funcname_id(yytext, yylineno);
                    (yyval.strval) = (yyvsp[0].strval);
               }
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 514 "parser.y" /* yacc.c:1646  */
    {
                    Symbol* temp;
                    temp = funcname_noname(yytext, yylineno);
                    (yyval.strval) = temp->name;
               }
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 520 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.symval) = table_lookup((yyvsp[0].strval), currscope());
                    (yyval.symval)->iaddress = nextquad();
                    Expr* e = newexpr(programfunc_e);
                    e->sym = (yyval.symval);
                    emit(jump, NULL, NULL, NULL, 0, yylineno);
                    emit(funcstart, e, NULL, NULL, nextquad() + 1, yylineno);
                    push(&scopeoffsetstack, currscopespaceoffset());
                    enterscopespace();
                    resetformalargsoffset();
               }
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 533 "parser.y" /* yacc.c:1646  */
    {
                    enterfuncscope();
                    enterscopespace();
                    resetfunctionlocaloffset();
               }
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 539 "parser.y" /* yacc.c:1646  */
    {
                    exitfuncscope();
                    (yyval.intval) = currscopespaceoffset();
                    exitscopespace();
               }
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 546 "parser.y" /* yacc.c:1646  */
    { push(&loopcounterstack, loopcounter); loopcounter=0;}
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 547 "parser.y" /* yacc.c:1646  */
    { loopcounter = pop(&loopcounterstack); }
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 549 "parser.y" /* yacc.c:1646  */
    {
               patchlabel(retaddr, nextquad());
               retaddr=0;
               int offset;
               (yyvsp[-4].symval)->totalLocals = (yyvsp[-1].intval);
               exitscopespace();
               offset = pop_and_top(&scopeoffsetstack);
               restorecurrscopeoffset(offset);
               (yyval.symval) = (yyvsp[-4].symval);

               Expr* e = newexpr(programfunc_e);
               e->sym = (yyval.symval);
               emit(funcend, e,  NULL,  NULL, nextquad() + 1, yylineno);
               backpatch((yyvsp[-4].symval)->iaddress, nextquad());
          }
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 566 "parser.y" /* yacc.c:1646  */
    { (yyval.exprval) = newexpr_constnum((yyvsp[0].intval));}
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 567 "parser.y" /* yacc.c:1646  */
    {(yyval.exprval) = newexpr_constnum((yyvsp[0].floatval));}
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 568 "parser.y" /* yacc.c:1646  */
    { (yyval.exprval) = newexpr_conststring((yyvsp[0].strval));}
#line 2410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 569 "parser.y" /* yacc.c:1646  */
    { (yyval.exprval) = newexpr(nil_e);}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 570 "parser.y" /* yacc.c:1646  */
    { (yyval.exprval) = newexpr_constbool(1);}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 571 "parser.y" /* yacc.c:1646  */
    { (yyval.exprval) = newexpr_constbool(0);}
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 574 "parser.y" /* yacc.c:1646  */
    { idlist_id(yytext, yylineno);}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 575 "parser.y" /* yacc.c:1646  */
    { idlist_commaid(yytext, yylineno);}
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 576 "parser.y" /* yacc.c:1646  */
    {;}
#line 2446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 579 "parser.y" /* yacc.c:1646  */
    {
               if ((yyvsp[-1].exprval) && (yyvsp[-1].exprval)->type == 5) {
                    patchboolean((yyvsp[-1].exprval), yylineno);
               }
               emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, nextquad() + 2, yylineno);
               (yyval.intval) = nextquad();
               emit(jump, NULL , NULL, NULL, 0, yylineno);
          }
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 589 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.intval) = nextquad();
                    emit(jump, NULL, NULL, NULL, 0, yylineno);
               }
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 595 "parser.y" /* yacc.c:1646  */
    {
                    patchlabel((yyvsp[-1].intval), nextquad());
               }
#line 2476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 598 "parser.y" /* yacc.c:1646  */
    {
                    patchlabel((yyvsp[-3].intval), ((yyvsp[-1].intval))+1);
                    patchlabel((yyvsp[-1].intval), nextquad());
               }
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 604 "parser.y" /* yacc.c:1646  */
    {
                    loopcounter++;
                    (yyval.intval) = nextquad();
               }
#line 2494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 610 "parser.y" /* yacc.c:1646  */
    {
                    if ( (yyvsp[-1].exprval)->type == 5) {
                         patchboolean((yyvsp[-1].exprval), yylineno);
                    }
                    emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, nextquad()+2, yylineno);
                    (yyval.intval) = nextquad();
                    emit(jump, NULL, NULL, NULL, 0, yylineno);
               }
#line 2507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 619 "parser.y" /* yacc.c:1646  */
    {
                    loopcounter--;
                    emit(jump, NULL, NULL, NULL, (yyvsp[-2].intval), yylineno);
                    patchlabel((yyvsp[-1].intval), nextquad());

                    patchlist(pop(&breakstack), nextquad());
                    patchlist(pop(&contstack), (yyvsp[-2].intval));
               }
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 628 "parser.y" /* yacc.c:1646  */
    {
          (yyval.intval) = nextquad();
          emit(jump, NULL, NULL, NULL, 0, yylineno);
     }
#line 2529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 633 "parser.y" /* yacc.c:1646  */
    {(yyval.intval) = nextquad();}
#line 2535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 636 "parser.y" /* yacc.c:1646  */
    {loopcounter++;}
#line 2541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 636 "parser.y" /* yacc.c:1646  */
    {
                    if ( (yyvsp[-1].exprval)->type == 5) {
                         patchboolean((yyvsp[-1].exprval), yylineno);
                    }
                    (yyval.prefval).test = (yyvsp[-2].intval);
                    (yyval.prefval).enter = nextquad();
                    emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, 0, yylineno);
               }
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 646 "parser.y" /* yacc.c:1646  */
    {loopcounter--;}
#line 2560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 646 "parser.y" /* yacc.c:1646  */
    {
               patchlabel((yyvsp[-7].prefval).enter, (yyvsp[-3].intval)+1);
               patchlabel((yyvsp[-6].intval), nextquad());
               patchlabel((yyvsp[-3].intval), (yyvsp[-7].prefval).test);
               patchlabel((yyvsp[0].intval), (yyvsp[-6].intval)+1);

               patchlist(pop(&breakstack), nextquad());
               patchlist(pop(&contstack), (yyvsp[-6].intval)+1);
          }
#line 2574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 656 "parser.y" /* yacc.c:1646  */
    {
               make_stmt(&(yyval.stmtval));
               (yyval.stmtval).breaklist = newlist(nextquad());
               emit(jump, NULL, NULL, NULL, 0, yylineno);
               push(&breakstack, (yyval.stmtval).breaklist);
          }
#line 2585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 664 "parser.y" /* yacc.c:1646  */
    {
               make_stmt(&(yyval.stmtval));
               (yyval.stmtval).contlist = newlist(nextquad());
               emit(jump, NULL, NULL, NULL, 0, yylineno);
               push(&contstack, (yyval.stmtval).contlist);
          }
#line 2596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 673 "parser.y" /* yacc.c:1646  */
    {
                    if (currfuncscope() == 0) Error(2, yytext, yylineno);
                    else {
                         emit(ret, NULL, NULL, NULL, nextquad() + 1, yylineno);
                         retaddr = nextquad();
                         emit(jump, NULL, NULL, NULL, 0, yylineno);
                    }
               }
#line 2609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 681 "parser.y" /* yacc.c:1646  */
    {
                    if (currfuncscope() == 0) Error(2, yytext, yylineno);
                    else {
                         emit(ret, (yyvsp[-1].exprval), NULL, NULL, nextquad() + 1, yylineno);
                         retaddr = nextquad();
                         emit(jump, NULL, NULL, NULL, 0, yylineno);
                    }
               }
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2626 "y.tab.c" /* yacc.c:1646  */
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
#line 691 "parser.y" /* yacc.c:1906  */


void yyerror(char* yaccProovidedMessage) {
       fprintf(stderr, "%s: at line %d, before token: %s\n",yaccProovidedMessage, yylineno, yytext);
       fprintf(stderr, "INPUT NOT VALID\n");
}

int main(int argc, char** argv) {
     symtable = create_new_symtable();
     init_quad();
     table_insert(libraryfunc_s, "print", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "input", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "objectmemberkyes", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "objectotslmembers", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "objectcopy", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "totalarguments", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "argument", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "typeof", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "strtonum", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "sqrt", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "cos", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     table_insert(libraryfunc_s, "sin", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     if(argc > 1){
          if(!(yyin = fopen(argv[1], "r"))){
               fprintf(stderr, "Cannot read  file: %s\n", argv[1]);
               return 1;
          }
     } else {
          yyin = stdin;
     }
     yyparse();
     //print_table();
     print_intermediate();
     generate1();
     generate_bin();
     free_table(symtable);
     return 0;
}
