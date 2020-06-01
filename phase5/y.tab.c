/* A Bison parser, made by GNU Bison 3.6.2.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "vm_parser.y"

     #include <stdio.h>
     #include <unistd.h>
     #include <stdlib.h>
     #include <string.h>
     #include "avm.h"

     #define  YY_DECL int alpha_yylex (void* yylval)
     void yyerror (char* yaccProvidedMessage);
     int yylex();
     extern int yylineno;
     extern char* yytext;
     extern FILE* yyin;

     unsigned globalSize = 0;

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    YYUNDEF = 257,                 /* "invalid token"  */
    REAL = 258,                    /* REAL  */
    INT = 259,                     /* INT  */
    ID = 260,                      /* ID  */
    TEMP = 261,                    /* TEMP  */
    MAGIC = 262,                   /* MAGIC  */
    CODE = 263,                    /* CODE  */
    STRINGARRAY = 264,             /* STRINGARRAY  */
    NUMARRAY = 265,                /* NUMARRAY  */
    LIBARRAY = 266,                /* LIBARRAY  */
    USERFUNCARRAY = 267,           /* USERFUNCARRAY  */
    STRING = 268,                  /* STRING  */
    ASSIGN = 269,                  /* ASSIGN  */
    ADD = 270,                     /* ADD  */
    SUB = 271,                     /* SUB  */
    MUL = 272,                     /* MUL  */
    DIV = 273,                     /* DIV  */
    MOD = 274,                     /* MOD  */
    UMINUS = 275,                  /* UMINUS  */
    AND = 276,                     /* AND  */
    OR = 277,                      /* OR  */
    NOT = 278,                     /* NOT  */
    JEQ = 279,                     /* JEQ  */
    JNE = 280,                     /* JNE  */
    JLE = 281,                     /* JLE  */
    JGE = 282,                     /* JGE  */
    JLT = 283,                     /* JLT  */
    JGT = 284,                     /* JGT  */
    CALLFUNC = 285,                /* CALLFUNC  */
    PUSHARG = 286,                 /* PUSHARG  */
    ENTERFUNC = 287,               /* ENTERFUNC  */
    EXITFUNC = 288,                /* EXITFUNC  */
    NEWTABLE = 289,                /* NEWTABLE  */
    TABLESETELEM = 290,            /* TABLESETELEM  */
    TABLEGETELEM = 291,            /* TABLEGETELEM  */
    JUMP = 292,                    /* JUMP  */
    NOP = 293,                     /* NOP  */
    COLON = 294,                   /* COLON  */
    COMMA = 295,                   /* COMMA  */
    BAR = 296,                     /* BAR  */
    NONAME = 297                   /* NONAME  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define REAL 258
#define INT 259
#define ID 260
#define TEMP 261
#define MAGIC 262
#define CODE 263
#define STRINGARRAY 264
#define NUMARRAY 265
#define LIBARRAY 266
#define USERFUNCARRAY 267
#define STRING 268
#define ASSIGN 269
#define ADD 270
#define SUB 271
#define MUL 272
#define DIV 273
#define MOD 274
#define UMINUS 275
#define AND 276
#define OR 277
#define NOT 278
#define JEQ 279
#define JNE 280
#define JLE 281
#define JGE 282
#define JLT 283
#define JGT 284
#define CALLFUNC 285
#define PUSHARG 286
#define ENTERFUNC 287
#define EXITFUNC 288
#define NEWTABLE 289
#define TABLESETELEM 290
#define TABLEGETELEM 291
#define JUMP 292
#define NOP 293
#define COLON 294
#define COMMA 295
#define BAR 296
#define NONAME 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "vm_parser.y"

     int intval;
     char* strval;
     double dblval;
     struct avm_memcell* memval;
     struct userfunc* userval;
     struct instruction* instruct;
     struct vmarg* vmargval;

#line 234 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_REAL = 3,                       /* REAL  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_TEMP = 6,                       /* TEMP  */
  YYSYMBOL_MAGIC = 7,                      /* MAGIC  */
  YYSYMBOL_CODE = 8,                       /* CODE  */
  YYSYMBOL_STRINGARRAY = 9,                /* STRINGARRAY  */
  YYSYMBOL_NUMARRAY = 10,                  /* NUMARRAY  */
  YYSYMBOL_LIBARRAY = 11,                  /* LIBARRAY  */
  YYSYMBOL_USERFUNCARRAY = 12,             /* USERFUNCARRAY  */
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_ASSIGN = 14,                    /* ASSIGN  */
  YYSYMBOL_ADD = 15,                       /* ADD  */
  YYSYMBOL_SUB = 16,                       /* SUB  */
  YYSYMBOL_MUL = 17,                       /* MUL  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_MOD = 19,                       /* MOD  */
  YYSYMBOL_UMINUS = 20,                    /* UMINUS  */
  YYSYMBOL_AND = 21,                       /* AND  */
  YYSYMBOL_OR = 22,                        /* OR  */
  YYSYMBOL_NOT = 23,                       /* NOT  */
  YYSYMBOL_JEQ = 24,                       /* JEQ  */
  YYSYMBOL_JNE = 25,                       /* JNE  */
  YYSYMBOL_JLE = 26,                       /* JLE  */
  YYSYMBOL_JGE = 27,                       /* JGE  */
  YYSYMBOL_JLT = 28,                       /* JLT  */
  YYSYMBOL_JGT = 29,                       /* JGT  */
  YYSYMBOL_CALLFUNC = 30,                  /* CALLFUNC  */
  YYSYMBOL_PUSHARG = 31,                   /* PUSHARG  */
  YYSYMBOL_ENTERFUNC = 32,                 /* ENTERFUNC  */
  YYSYMBOL_EXITFUNC = 33,                  /* EXITFUNC  */
  YYSYMBOL_NEWTABLE = 34,                  /* NEWTABLE  */
  YYSYMBOL_TABLESETELEM = 35,              /* TABLESETELEM  */
  YYSYMBOL_TABLEGETELEM = 36,              /* TABLEGETELEM  */
  YYSYMBOL_JUMP = 37,                      /* JUMP  */
  YYSYMBOL_NOP = 38,                       /* NOP  */
  YYSYMBOL_COLON = 39,                     /* COLON  */
  YYSYMBOL_COMMA = 40,                     /* COMMA  */
  YYSYMBOL_BAR = 41,                       /* BAR  */
  YYSYMBOL_NONAME = 42,                    /* NONAME  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_avmbinaryfile = 45,             /* avmbinaryfile  */
  YYSYMBOL_magicnumber = 46,               /* magicnumber  */
  YYSYMBOL_codes = 47,                     /* codes  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_instructions = 49,              /* instructions  */
  YYSYMBOL_instruction = 50,               /* instruction  */
  YYSYMBOL_opcode = 51,                    /* opcode  */
  YYSYMBOL_operand = 52,                   /* operand  */
  YYSYMBOL_arrays = 53,                    /* arrays  */
  YYSYMBOL_stringConsts = 54,              /* stringConsts  */
  YYSYMBOL_strings = 55,                   /* strings  */
  YYSYMBOL_string = 56,                    /* string  */
  YYSYMBOL_numConsts = 57,                 /* numConsts  */
  YYSYMBOL_nums = 58,                      /* nums  */
  YYSYMBOL_num = 59,                       /* num  */
  YYSYMBOL_namedLibFuncs = 60,             /* namedLibFuncs  */
  YYSYMBOL_libfuncs = 61,                  /* libfuncs  */
  YYSYMBOL_libfunc = 62,                   /* libfunc  */
  YYSYMBOL_userfuncs = 63,                 /* userfuncs  */
  YYSYMBOL_funcs = 64,                     /* funcs  */
  YYSYMBOL_func = 65                       /* func  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   89

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    54,    60,    63,    63,    65,    66,    69,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   106,   115,   122,   132,   137,
     143,   149,   153,   157,   160,   161,   164,   165,   168,   173,
     174,   177,   178,   180,   184,   185,   188,   189,   191,   195,
     196,   199,   200,   202,   210
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
  "\"end of file\"", "error", "\"invalid token\"", "REAL", "INT", "ID",
  "TEMP", "MAGIC", "CODE", "STRINGARRAY", "NUMARRAY", "LIBARRAY",
  "USERFUNCARRAY", "STRING", "ASSIGN", "ADD", "SUB", "MUL", "DIV", "MOD",
  "UMINUS", "AND", "OR", "NOT", "JEQ", "JNE", "JLE", "JGE", "JLT", "JGT",
  "CALLFUNC", "PUSHARG", "ENTERFUNC", "EXITFUNC", "NEWTABLE",
  "TABLESETELEM", "TABLEGETELEM", "JUMP", "NOP", "COLON", "COMMA", "BAR",
  "NONAME", "$accept", "program", "avmbinaryfile", "magicnumber", "codes",
  "$@1", "instructions", "instruction", "opcode", "operand", "arrays",
  "stringConsts", "strings", "string", "numConsts", "nums", "num",
  "namedLibFuncs", "libfuncs", "libfunc", "userfuncs", "funcs", "func", YY_NULLPTR
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
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
#endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,   -35,     5,   -40,     0,     3,   -40,   -30,     2,   -40,
      36,     4,   -40,    31,   -40,    38,     7,    33,    43,    44,
      45,    11,    39,    12,    43,   -40,    13,    44,   -40,    48,
      51,    17,   -40,    -2,   -40,    46,   -40,    16,    48,   -40,
      54,    56,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,    20,   -40,    59,
     -40,    22,    54,   -40,    60,    61,    20,   -40,    53,   -40,
      26,    60,   -40,    28,    20,   -40,    -4,   -40,    65,   -40,
      32,    34,    35,    66,    68,    -3,    37,    40,   -40,   -40,
     -40,   -40,   -40,    71,    73,   -40,   -40
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,     1,     0,    45,     4,
       0,     0,     3,    50,     5,     0,     0,    55,     0,     0,
       0,     0,    60,     0,     6,     7,     0,    44,    46,     0,
       0,     0,    43,     0,     8,     0,    47,     0,    49,    51,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    42,    48,     0,
      52,     0,    54,    56,     0,     0,    42,    53,     0,    57,
       0,    59,    61,    41,    42,    58,     0,    62,     0,     9,
       0,     0,    38,     0,     0,     0,     0,     0,    37,    35,
      36,    39,    40,     0,     0,    63,    64
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   -40,   -40,   -40,   -40,   -40,    57,   -40,   -39,
     -40,   -40,   -40,    55,   -40,   -40,    42,   -40,   -40,     6,
     -40,   -40,     8
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     8,    18,    24,    25,    67,    76,
      12,    13,    27,    28,    17,    38,    39,    22,    72,    73,
      32,    81,    82
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      98,    90,    99,   100,     5,     6,     1,     9,     7,    10,
     101,    11,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    84,    91,   102,
      14,    16,    19,    15,    21,    89,    20,    23,    26,    29,
      30,    31,    37,    33,    35,    40,    41,    69,    71,    68,
      74,    75,    77,    78,    80,    83,    85,    86,    88,    92,
      96,    93,    97,    94,    95,   105,   103,   106,    79,   104,
      70,    34,    36,     0,     0,     0,     0,     0,     0,    87
};

static const yytype_int8 yycheck[] =
{
       3,     5,     5,     6,    39,     0,     7,     4,     8,    39,
      13,     9,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    76,    42,    42,
       4,    10,     4,    39,    11,    84,    39,     4,     4,     4,
      39,    12,     4,    41,    41,     4,    39,    41,     4,    13,
       4,    41,     3,    41,     4,     4,    13,    41,    40,     4,
       4,    39,     4,    39,    39,     4,    39,     4,    72,    39,
      38,    24,    27,    -1,    -1,    -1,    -1,    -1,    -1,    81
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    44,    45,    46,    39,     0,     8,    47,     4,
      39,     9,    53,    54,     4,    39,    10,    57,    48,     4,
      39,    11,    60,     4,    49,    50,     4,    55,    56,     4,
      39,    12,    63,    41,    50,    41,    56,     4,    58,    59,
       4,    39,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    51,    13,    41,
      59,     4,    61,    62,     4,    41,    52,     3,    41,    62,
       4,    64,    65,     4,    52,    13,    41,    65,    40,    52,
       5,    42,     4,    39,    39,    39,     4,     4,     3,     5,
       6,    13,    42,    39,    39,     4,     4
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    46,    48,    47,    49,    49,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    53,    54,    54,    55,    55,    56,    57,
      57,    58,    58,    59,    60,    60,    61,    61,    62,    63,
      63,    64,    64,    65,    65
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     0,     5,     1,     2,     6,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     6,     6,     4,     6,
       6,     2,     0,     4,     4,     0,     1,     2,     3,     4,
       0,     1,     2,     3,     4,     0,     1,     2,     3,     4,
       0,     1,     2,     7,     7
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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


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
  case 2:
#line 51 "vm_parser.y"
                       {;}
#line 1353 "y.tab.c"
    break;

  case 3:
#line 54 "vm_parser.y"
                                        {
                    if ( (yyvsp[-2].intval) != 340200501) yyerror("WRONG MAGIC NUMBER");

               }
#line 1362 "y.tab.c"
    break;

  case 4:
#line 60 "vm_parser.y"
                               {(yyval.intval) = (yyvsp[0].intval);}
#line 1368 "y.tab.c"
    break;

  case 5:
#line 63 "vm_parser.y"
                         {init_code((yyvsp[0].intval));}
#line 1374 "y.tab.c"
    break;

  case 6:
#line 63 "vm_parser.y"
                                                      {;}
#line 1380 "y.tab.c"
    break;

  case 7:
#line 65 "vm_parser.y"
                           {;}
#line 1386 "y.tab.c"
    break;

  case 8:
#line 66 "vm_parser.y"
                                          {;}
#line 1392 "y.tab.c"
    break;

  case 9:
#line 69 "vm_parser.y"
                                                      {
                    (yyval.instruct) = (instruction*) malloc(sizeof(instruction));
                    (yyval.instruct)->opcode = (yyvsp[-3].intval);
                    (yyval.instruct)->result = *(yyvsp[-2].vmargval);
                    (yyval.instruct)->arg2 = *(yyvsp[0].vmargval);
                    (yyval.instruct)->arg1 = *(yyvsp[-1].vmargval);
                    emit_code(*(yyval.instruct));
               }
#line 1405 "y.tab.c"
    break;

  case 10:
#line 79 "vm_parser.y"
                {(yyval.intval) = 0;}
#line 1411 "y.tab.c"
    break;

  case 11:
#line 80 "vm_parser.y"
               {(yyval.intval) = 1;}
#line 1417 "y.tab.c"
    break;

  case 12:
#line 81 "vm_parser.y"
               {(yyval.intval) = 2;}
#line 1423 "y.tab.c"
    break;

  case 13:
#line 82 "vm_parser.y"
               {(yyval.intval) = 3;}
#line 1429 "y.tab.c"
    break;

  case 14:
#line 83 "vm_parser.y"
               {(yyval.intval) = 4;}
#line 1435 "y.tab.c"
    break;

  case 15:
#line 84 "vm_parser.y"
               {(yyval.intval) = 5;}
#line 1441 "y.tab.c"
    break;

  case 16:
#line 85 "vm_parser.y"
                  {(yyval.intval) = 6;}
#line 1447 "y.tab.c"
    break;

  case 17:
#line 86 "vm_parser.y"
               {(yyval.intval) = 7;}
#line 1453 "y.tab.c"
    break;

  case 18:
#line 87 "vm_parser.y"
              {(yyval.intval) = 8;}
#line 1459 "y.tab.c"
    break;

  case 19:
#line 88 "vm_parser.y"
               { (yyval.intval) = 9;}
#line 1465 "y.tab.c"
    break;

  case 20:
#line 89 "vm_parser.y"
               { (yyval.intval) = 10;}
#line 1471 "y.tab.c"
    break;

  case 21:
#line 90 "vm_parser.y"
               { (yyval.intval) = 11;}
#line 1477 "y.tab.c"
    break;

  case 22:
#line 91 "vm_parser.y"
               { (yyval.intval) = 12;}
#line 1483 "y.tab.c"
    break;

  case 23:
#line 92 "vm_parser.y"
               { (yyval.intval) = 13;}
#line 1489 "y.tab.c"
    break;

  case 24:
#line 93 "vm_parser.y"
               { (yyval.intval) = 14;}
#line 1495 "y.tab.c"
    break;

  case 25:
#line 94 "vm_parser.y"
               { (yyval.intval) = 15;}
#line 1501 "y.tab.c"
    break;

  case 26:
#line 95 "vm_parser.y"
                    { (yyval.intval) = 16;}
#line 1507 "y.tab.c"
    break;

  case 27:
#line 96 "vm_parser.y"
                   { (yyval.intval) = 17;}
#line 1513 "y.tab.c"
    break;

  case 28:
#line 97 "vm_parser.y"
                     { (yyval.intval) = 18;}
#line 1519 "y.tab.c"
    break;

  case 29:
#line 98 "vm_parser.y"
                    { (yyval.intval) = 19;}
#line 1525 "y.tab.c"
    break;

  case 30:
#line 99 "vm_parser.y"
                    { (yyval.intval) = 20;}
#line 1531 "y.tab.c"
    break;

  case 31:
#line 100 "vm_parser.y"
                        {(yyval.intval) = 21;}
#line 1537 "y.tab.c"
    break;

  case 32:
#line 101 "vm_parser.y"
                        { (yyval.intval) = 22;}
#line 1543 "y.tab.c"
    break;

  case 33:
#line 102 "vm_parser.y"
                { (yyval.intval) = 23;}
#line 1549 "y.tab.c"
    break;

  case 34:
#line 103 "vm_parser.y"
               { (yyval.intval) = 24;}
#line 1555 "y.tab.c"
    break;

  case 35:
#line 106 "vm_parser.y"
                                     {
               (yyval.vmargval) = (vmarg*) malloc(sizeof(vmarg));
               (yyval.vmargval)->val = (yyvsp[-2].intval);
               (yyval.vmargval)->id = strdup((yyvsp[0].strval));
               (yyval.vmargval)->type = (yyvsp[-4].intval);
               if ( (yyval.vmargval)->val == 1) {
                    globalSize++;
               }
          }
#line 1569 "y.tab.c"
    break;

  case 36:
#line 115 "vm_parser.y"
                                         {
               (yyval.vmargval) = (vmarg*) malloc(sizeof(vmarg));
               (yyval.vmargval)->val = (yyvsp[-2].intval);
               (yyval.vmargval)->id = strdup((yyvsp[0].strval));
               (yyval.vmargval)->type = (yyvsp[-4].intval);
               
          }
#line 1581 "y.tab.c"
    break;

  case 37:
#line 122 "vm_parser.y"
                                         {
               char* name;
               (yyval.vmargval) = (vmarg*) malloc(sizeof(vmarg));
               name = (char*) malloc(sizeof(char)*50);
               (yyval.vmargval)->val = (yyvsp[-2].intval);
               sprintf(name, "constnums_%f", (yyvsp[0].dblval));
               (yyval.vmargval)->id = strdup(name);
               (yyval.vmargval)->type = (yyvsp[-4].intval);

          }
#line 1596 "y.tab.c"
    break;

  case 38:
#line 132 "vm_parser.y"
                              {
               (yyval.vmargval) = (vmarg*) malloc(sizeof(vmarg));
               (yyval.vmargval)->val = (yyvsp[0].intval);
               (yyval.vmargval)->type = (yyvsp[-2].intval);
               }
#line 1606 "y.tab.c"
    break;

  case 39:
#line 137 "vm_parser.y"
                                           {
               (yyval.vmargval) = (vmarg*) malloc(sizeof(vmarg));
               (yyval.vmargval)->val = (yyvsp[-2].intval);
               (yyval.vmargval)->id = strdup((yyvsp[0].strval));
               (yyval.vmargval)->type = (yyvsp[-4].intval);
          }
#line 1617 "y.tab.c"
    break;

  case 40:
#line 143 "vm_parser.y"
                                           {
               (yyval.vmargval) = (vmarg*)  malloc(sizeof(vmarg));
               (yyval.vmargval)->val = (yyvsp[-2].intval);
               (yyval.vmargval)->id = strdup((yyvsp[0].strval));
               (yyval.vmargval)->type = (yyvsp[-4].intval);
          }
#line 1628 "y.tab.c"
    break;

  case 41:
#line 149 "vm_parser.y"
                    {
               (yyval.vmargval) = (vmarg*)  malloc(sizeof(vmarg));
               (yyval.vmargval)->type = (yyvsp[0].intval);
          }
#line 1637 "y.tab.c"
    break;

  case 42:
#line 153 "vm_parser.y"
            {;}
#line 1643 "y.tab.c"
    break;

  case 43:
#line 157 "vm_parser.y"
                                                         {;}
#line 1649 "y.tab.c"
    break;

  case 44:
#line 160 "vm_parser.y"
                                             {;}
#line 1655 "y.tab.c"
    break;

  case 45:
#line 161 "vm_parser.y"
                 {;}
#line 1661 "y.tab.c"
    break;

  case 46:
#line 164 "vm_parser.y"
                { (yyval.strval) = (yyvsp[0].strval);}
#line 1667 "y.tab.c"
    break;

  case 47:
#line 165 "vm_parser.y"
                           { (yyval.strval) = (yyvsp[0].strval);}
#line 1673 "y.tab.c"
    break;

  case 48:
#line 168 "vm_parser.y"
                         { 
               consts_newstring((yyvsp[0].strval));
          }
#line 1681 "y.tab.c"
    break;

  case 49:
#line 173 "vm_parser.y"
                                       {;}
#line 1687 "y.tab.c"
    break;

  case 50:
#line 174 "vm_parser.y"
                 {;}
#line 1693 "y.tab.c"
    break;

  case 51:
#line 177 "vm_parser.y"
              {;}
#line 1699 "y.tab.c"
    break;

  case 52:
#line 178 "vm_parser.y"
                    {;}
#line 1705 "y.tab.c"
    break;

  case 53:
#line 180 "vm_parser.y"
                       { 
               consts_newnumber((yyvsp[0].dblval));
          }
#line 1713 "y.tab.c"
    break;

  case 54:
#line 184 "vm_parser.y"
                                          {;}
#line 1719 "y.tab.c"
    break;

  case 55:
#line 185 "vm_parser.y"
                 {;}
#line 1725 "y.tab.c"
    break;

  case 56:
#line 188 "vm_parser.y"
                       {;}
#line 1731 "y.tab.c"
    break;

  case 57:
#line 189 "vm_parser.y"
                                  {;}
#line 1737 "y.tab.c"
    break;

  case 58:
#line 191 "vm_parser.y"
                              {
                    libfuncs_newused((yyvsp[0].strval));             
               }
#line 1745 "y.tab.c"
    break;

  case 59:
#line 195 "vm_parser.y"
                                             {;}
#line 1751 "y.tab.c"
    break;

  case 60:
#line 196 "vm_parser.y"
                 {;}
#line 1757 "y.tab.c"
    break;

  case 61:
#line 199 "vm_parser.y"
               {;}
#line 1763 "y.tab.c"
    break;

  case 62:
#line 200 "vm_parser.y"
                       {;}
#line 1769 "y.tab.c"
    break;

  case 63:
#line 202 "vm_parser.y"
                                         {
               (yyval.userval) = (userfunc*)  malloc(sizeof(userfunc));
               (yyval.userval)->id = strdup((yyvsp[-4].strval));
               (yyval.userval)->localSize = (unsigned)(yyvsp[-2].intval);
               (yyval.userval)->address = (unsigned)(yyvsp[0].intval);
               userfuncs_newfunc(*(yyval.userval));
               
          }
#line 1782 "y.tab.c"
    break;

  case 64:
#line 210 "vm_parser.y"
                                               {
               (yyval.userval) = (userfunc*)  malloc(sizeof(userfunc));
               (yyval.userval)->id = strdup((yyvsp[-4].strval));
               (yyval.userval)->localSize = (unsigned)(yyvsp[-2].intval);
               (yyval.userval)->address = (unsigned)(yyvsp[0].intval);
               userfuncs_newfunc(*(yyval.userval));
          }
#line 1794 "y.tab.c"
    break;


#line 1798 "y.tab.c"

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

#line 219 "vm_parser.y"


void yyerror(char* yaccProvidedMessage) {
     printf("%s at line %d.\n", yaccProvidedMessage, yylineno);
}

int main(int argc, char** argv){
     initMem();
     if(argc > 1){
          if(!(yyin = fopen(argv[1], "r"))){
               fprintf(stderr, "Cannot read  file: %s\n", argv[1]);
               return 1;
          }
     } else {
          yyin = stdin;
     }
     yyparse();
     avm_initstack(globalSize);
     print_code();
     execute_cycle();
     //print_stack();
     return 0;
}
