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
#line 1 "parser.y"

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

#line 90 "y.tab.c"

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
    ASSIGN = 258,                  /* ASSIGN  */
    OR = 259,                      /* OR  */
    AND = 260,                     /* AND  */
    EQ = 261,                      /* EQ  */
    NOT_EQ = 262,                  /* NOT_EQ  */
    GREATER = 263,                 /* GREATER  */
    GREATER_EQ = 264,              /* GREATER_EQ  */
    LESS = 265,                    /* LESS  */
    LESS_EQ = 266,                 /* LESS_EQ  */
    PLUS = 267,                    /* PLUS  */
    MINUS = 268,                   /* MINUS  */
    MUL = 269,                     /* MUL  */
    DIV = 270,                     /* DIV  */
    MOD = 271,                     /* MOD  */
    NOT = 272,                     /* NOT  */
    D_PLUS = 273,                  /* D_PLUS  */
    D_MINUS = 274,                 /* D_MINUS  */
    UMINUS = 275,                  /* UMINUS  */
    DOT = 276,                     /* DOT  */
    D_DOT = 277,                   /* D_DOT  */
    L_BRA = 278,                   /* L_BRA  */
    R_BRA = 279,                   /* R_BRA  */
    L_PAR = 280,                   /* L_PAR  */
    R_PAR = 281,                   /* R_PAR  */
    INT = 282,                     /* INT  */
    REAL = 283,                    /* REAL  */
    ID = 284,                      /* ID  */
    STRING = 285,                  /* STRING  */
    IF = 286,                      /* IF  */
    ELSE = 287,                    /* ELSE  */
    WHILE = 288,                   /* WHILE  */
    FOR = 289,                     /* FOR  */
    FUNC = 290,                    /* FUNC  */
    RETURN = 291,                  /* RETURN  */
    BREAK = 292,                   /* BREAK  */
    CONTINUE = 293,                /* CONTINUE  */
    LOCAL = 294,                   /* LOCAL  */
    TRUE = 295,                    /* TRUE  */
    FALSE = 296,                   /* FALSE  */
    NIL = 297,                     /* NIL  */
    LC_BRA = 298,                  /* LC_BRA  */
    RC_BRA = 299,                  /* RC_BRA  */
    SEMI = 300,                    /* SEMI  */
    COMMA = 301,                   /* COMMA  */
    COLON = 302,                   /* COLON  */
    D_COLON = 303                  /* D_COLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
union YYSTYPE
{
#line 22 "parser.y"

     int intval;
     char* strval;
     float floatval;
     struct expr* exprval;
     struct stmt_t stmtval;
     struct call callval;
     struct symbol* symval;
     struct prefix prefval;

#line 249 "y.tab.c"

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
  YYSYMBOL_ASSIGN = 3,                     /* ASSIGN  */
  YYSYMBOL_OR = 4,                         /* OR  */
  YYSYMBOL_AND = 5,                        /* AND  */
  YYSYMBOL_EQ = 6,                         /* EQ  */
  YYSYMBOL_NOT_EQ = 7,                     /* NOT_EQ  */
  YYSYMBOL_GREATER = 8,                    /* GREATER  */
  YYSYMBOL_GREATER_EQ = 9,                 /* GREATER_EQ  */
  YYSYMBOL_LESS = 10,                      /* LESS  */
  YYSYMBOL_LESS_EQ = 11,                   /* LESS_EQ  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_MUL = 14,                       /* MUL  */
  YYSYMBOL_DIV = 15,                       /* DIV  */
  YYSYMBOL_MOD = 16,                       /* MOD  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_D_PLUS = 18,                    /* D_PLUS  */
  YYSYMBOL_D_MINUS = 19,                   /* D_MINUS  */
  YYSYMBOL_UMINUS = 20,                    /* UMINUS  */
  YYSYMBOL_DOT = 21,                       /* DOT  */
  YYSYMBOL_D_DOT = 22,                     /* D_DOT  */
  YYSYMBOL_L_BRA = 23,                     /* L_BRA  */
  YYSYMBOL_R_BRA = 24,                     /* R_BRA  */
  YYSYMBOL_L_PAR = 25,                     /* L_PAR  */
  YYSYMBOL_R_PAR = 26,                     /* R_PAR  */
  YYSYMBOL_INT = 27,                       /* INT  */
  YYSYMBOL_REAL = 28,                      /* REAL  */
  YYSYMBOL_ID = 29,                        /* ID  */
  YYSYMBOL_STRING = 30,                    /* STRING  */
  YYSYMBOL_IF = 31,                        /* IF  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_WHILE = 33,                     /* WHILE  */
  YYSYMBOL_FOR = 34,                       /* FOR  */
  YYSYMBOL_FUNC = 35,                      /* FUNC  */
  YYSYMBOL_RETURN = 36,                    /* RETURN  */
  YYSYMBOL_BREAK = 37,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 38,                  /* CONTINUE  */
  YYSYMBOL_LOCAL = 39,                     /* LOCAL  */
  YYSYMBOL_TRUE = 40,                      /* TRUE  */
  YYSYMBOL_FALSE = 41,                     /* FALSE  */
  YYSYMBOL_NIL = 42,                       /* NIL  */
  YYSYMBOL_LC_BRA = 43,                    /* LC_BRA  */
  YYSYMBOL_RC_BRA = 44,                    /* RC_BRA  */
  YYSYMBOL_SEMI = 45,                      /* SEMI  */
  YYSYMBOL_COMMA = 46,                     /* COMMA  */
  YYSYMBOL_COLON = 47,                     /* COLON  */
  YYSYMBOL_D_COLON = 48,                   /* D_COLON  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_stmts = 51,                     /* stmts  */
  YYSYMBOL_stmt = 52,                      /* stmt  */
  YYSYMBOL_expr = 53,                      /* expr  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_term = 56,                      /* term  */
  YYSYMBOL_assignexpr = 57,                /* assignexpr  */
  YYSYMBOL_primary = 58,                   /* primary  */
  YYSYMBOL_lvalue = 59,                    /* lvalue  */
  YYSYMBOL_member = 60,                    /* member  */
  YYSYMBOL_call = 61,                      /* call  */
  YYSYMBOL_callsuffix = 62,                /* callsuffix  */
  YYSYMBOL_normcall = 63,                  /* normcall  */
  YYSYMBOL_methodcall = 64,                /* methodcall  */
  YYSYMBOL_elist = 65,                     /* elist  */
  YYSYMBOL_comma_elist = 66,               /* comma_elist  */
  YYSYMBOL_objectdef = 67,                 /* objectdef  */
  YYSYMBOL_indexed = 68,                   /* indexed  */
  YYSYMBOL_indexed_tmp = 69,               /* indexed_tmp  */
  YYSYMBOL_indexedelem = 70,               /* indexedelem  */
  YYSYMBOL_rec_stmt = 71,                  /* rec_stmt  */
  YYSYMBOL_block = 72,                     /* block  */
  YYSYMBOL_73_3 = 73,                      /* $@3  */
  YYSYMBOL_funcname = 74,                  /* funcname  */
  YYSYMBOL_funcprefix = 75,                /* funcprefix  */
  YYSYMBOL_funcargs = 76,                  /* funcargs  */
  YYSYMBOL_funcbody = 77,                  /* funcbody  */
  YYSYMBOL_funcblockstart = 78,            /* funcblockstart  */
  YYSYMBOL_funcblockend = 79,              /* funcblockend  */
  YYSYMBOL_funcdef = 80,                   /* funcdef  */
  YYSYMBOL_const = 81,                     /* const  */
  YYSYMBOL_idlist = 82,                    /* idlist  */
  YYSYMBOL_ifprefix = 83,                  /* ifprefix  */
  YYSYMBOL_elseprefix = 84,                /* elseprefix  */
  YYSYMBOL_ifstmt = 85,                    /* ifstmt  */
  YYSYMBOL_whilestart = 86,                /* whilestart  */
  YYSYMBOL_whilecond = 87,                 /* whilecond  */
  YYSYMBOL_whilestmt = 88,                 /* whilestmt  */
  YYSYMBOL_N = 89,                         /* N  */
  YYSYMBOL_M = 90,                         /* M  */
  YYSYMBOL_forprefix = 91,                 /* forprefix  */
  YYSYMBOL_92_4 = 92,                      /* $@4  */
  YYSYMBOL_forstmt = 93,                   /* forstmt  */
  YYSYMBOL_94_5 = 94,                      /* $@5  */
  YYSYMBOL_break = 95,                     /* break  */
  YYSYMBOL_continue = 96,                  /* continue  */
  YYSYMBOL_returnstmt = 97                 /* returnstmt  */
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

#define YYMAXUTOK   303


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
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
  "\"end of file\"", "error", "\"invalid token\"", "ASSIGN", "OR", "AND",
  "EQ", "NOT_EQ", "GREATER", "GREATER_EQ", "LESS", "LESS_EQ", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "NOT", "D_PLUS", "D_MINUS", "UMINUS",
  "DOT", "D_DOT", "L_BRA", "R_BRA", "L_PAR", "R_PAR", "INT", "REAL", "ID",
  "STRING", "IF", "ELSE", "WHILE", "FOR", "FUNC", "RETURN", "BREAK",
  "CONTINUE", "LOCAL", "TRUE", "FALSE", "NIL", "LC_BRA", "RC_BRA", "SEMI",
  "COMMA", "COLON", "D_COLON", "$accept", "program", "stmts", "stmt",
  "expr", "$@1", "$@2", "term", "assignexpr", "primary", "lvalue",
  "member", "call", "callsuffix", "normcall", "methodcall", "elist",
  "comma_elist", "objectdef", "indexed", "indexed_tmp", "indexedelem",
  "rec_stmt", "block", "$@3", "funcname", "funcprefix", "funcargs",
  "funcbody", "funcblockstart", "funcblockend", "funcdef", "const",
  "idlist", "ifprefix", "elseprefix", "ifstmt", "whilestart", "whilecond",
  "whilestmt", "N", "M", "forprefix", "$@4", "forstmt", "$@5", "break",
  "continue", "returnstmt", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
#endif

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
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

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
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

  /* YYPGOTONTERM-NUM.  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,   -16,    -1,  -166,  -166,  -166,  -166,  -166,
      42,  -166,    46,  -166,  -166,  -166,   -90,   -45,  -166,  -166,
     -42,     2,  -166,     1,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,     0,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -165,  -121,  -166,  -166,  -166,  -166,  -166,  -166,  -166
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,   123,   122,    29,    30,    31,
      32,    33,    34,    94,    95,    96,    57,   111,    35,    58,
     115,    59,   121,    36,    69,    65,    37,   101,   170,   145,
     183,    38,    39,   144,    40,   147,    41,    42,   104,    43,
     105,   160,    44,    63,    45,   191,    46,    47,    48
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
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

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
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

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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
#line 71 "parser.y"
                     {;}
#line 1551 "y.tab.c"
    break;

  case 3:
#line 74 "parser.y"
             {
               (yyval.stmtval) = (yyvsp[0].stmtval);
          }
#line 1559 "y.tab.c"
    break;

  case 4:
#line 77 "parser.y"
                      {
               (yyval.stmtval).breaklist = mergelist((yyvsp[-1].stmtval).breaklist, (yyvsp[0].stmtval).breaklist); 
               (yyval.stmtval).contlist = mergelist((yyvsp[-1].stmtval).contlist, (yyvsp[0].stmtval).contlist);
          }
#line 1568 "y.tab.c"
    break;

  case 5:
#line 83 "parser.y"
                    {
               make_stmt(&(yyval.stmtval));
               resettemp();
               if ((yyvsp[-1].exprval)->type == 5) {
                    patchboolean((yyvsp[-1].exprval), yylineno);
               }
          }
#line 1580 "y.tab.c"
    break;

  case 6:
#line 90 "parser.y"
                   { make_stmt(&(yyval.stmtval));}
#line 1586 "y.tab.c"
    break;

  case 7:
#line 91 "parser.y"
                      { make_stmt(&(yyval.stmtval));}
#line 1592 "y.tab.c"
    break;

  case 8:
#line 92 "parser.y"
                    { make_stmt(&(yyval.stmtval));}
#line 1598 "y.tab.c"
    break;

  case 9:
#line 93 "parser.y"
                       { make_stmt(&(yyval.stmtval));}
#line 1604 "y.tab.c"
    break;

  case 10:
#line 94 "parser.y"
                       {
               make_stmt(&(yyval.stmtval));
               (yyval.stmtval).breaklist = (yyvsp[-1].stmtval).breaklist;
               (yyval.stmtval).contlist = (yyvsp[-1].stmtval).contlist;
               if (loopcounter == 0) Error(3, yytext, yylineno);
          }
#line 1615 "y.tab.c"
    break;

  case 11:
#line 100 "parser.y"
                          {
               make_stmt(&(yyval.stmtval));
               (yyval.stmtval).breaklist = (yyvsp[-1].stmtval).breaklist;
               (yyval.stmtval).contlist = (yyvsp[-1].stmtval).contlist;
               if (loopcounter == 0) Error(4, yytext, yylineno);
          }
#line 1626 "y.tab.c"
    break;

  case 12:
#line 106 "parser.y"
                  { (yyval.stmtval) = (yyvsp[0].stmtval);}
#line 1632 "y.tab.c"
    break;

  case 13:
#line 107 "parser.y"
                    { make_stmt(&(yyval.stmtval));}
#line 1638 "y.tab.c"
    break;

  case 14:
#line 108 "parser.y"
                 { make_stmt(&(yyval.stmtval));}
#line 1644 "y.tab.c"
    break;

  case 15:
#line 114 "parser.y"
                   { (yyval.exprval) = (yyvsp[0].exprval);}
#line 1650 "y.tab.c"
    break;

  case 16:
#line 115 "parser.y"
                           {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_add, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1660 "y.tab.c"
    break;

  case 17:
#line 120 "parser.y"
                            {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_sub, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1670 "y.tab.c"
    break;

  case 18:
#line 125 "parser.y"
                          {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_mul, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1680 "y.tab.c"
    break;

  case 19:
#line 130 "parser.y"
                          {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_div, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1690 "y.tab.c"
    break;

  case 20:
#line 135 "parser.y"
                          {
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = newtemp();
               emit(op_mod, (yyvsp[-2].exprval), (yyvsp[0].exprval), (yyval.exprval), nextquad() + 1, yylineno);
          }
#line 1700 "y.tab.c"
    break;

  case 21:
#line 140 "parser.y"
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
#line 1715 "y.tab.c"
    break;

  case 22:
#line 150 "parser.y"
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
#line 1730 "y.tab.c"
    break;

  case 23:
#line 160 "parser.y"
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
#line 1745 "y.tab.c"
    break;

  case 24:
#line 170 "parser.y"
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
#line 1762 "y.tab.c"
    break;

  case 25:
#line 182 "parser.y"
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
#line 1777 "y.tab.c"
    break;

  case 26:
#line 192 "parser.y"
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
#line 1792 "y.tab.c"
    break;

  case 27:
#line 202 "parser.y"
                     {
               if( (yyvsp[-1].exprval) && (yyvsp[-1].exprval)->type != 5){
                    (yyvsp[-1].exprval)->truelist = newlist(nextquad());
                    (yyvsp[-1].exprval)->falselist = newlist(nextquad()+1);
                    emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, 0, yylineno);
                    emit(jump, NULL, NULL, NULL , 0, yylineno);
              
               }
          }
#line 1806 "y.tab.c"
    break;

  case 28:
#line 210 "parser.y"
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
#line 1826 "y.tab.c"
    break;

  case 29:
#line 225 "parser.y"
                    {
               if((yyvsp[-1].exprval) && (yyvsp[-1].exprval)->type != 5){
                    (yyvsp[-1].exprval)->truelist = newlist(nextquad());
                    (yyvsp[-1].exprval)->falselist = newlist(nextquad()+1);
                    emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, 0, yylineno);
                    emit(jump, NULL, NULL, NULL , 0, yylineno);
               }
          }
#line 1839 "y.tab.c"
    break;

  case 30:
#line 232 "parser.y"
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
#line 1859 "y.tab.c"
    break;

  case 31:
#line 247 "parser.y"
                 {(yyval.exprval) = (yyvsp[0].exprval);}
#line 1865 "y.tab.c"
    break;

  case 32:
#line 250 "parser.y"
                         {(yyval.exprval) = (yyvsp[-1].exprval);}
#line 1871 "y.tab.c"
    break;

  case 33:
#line 251 "parser.y"
                                    {
               check_arith((yyvsp[0].exprval), (yyvsp[0].exprval)->sym->name);
               (yyval.exprval) = newexpr(arithexpr_e);
               (yyval.exprval)->sym = istempexpr((yyvsp[0].exprval)) ? (yyvsp[0].exprval)->sym : newtemp();
               emit(uminus, (yyvsp[0].exprval), NULL, (yyval.exprval), nextquad() + 1,yylineno); 
          }
#line 1882 "y.tab.c"
    break;

  case 34:
#line 257 "parser.y"
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
#line 1904 "y.tab.c"
    break;

  case 35:
#line 274 "parser.y"
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
#line 1925 "y.tab.c"
    break;

  case 36:
#line 290 "parser.y"
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
#line 1947 "y.tab.c"
    break;

  case 37:
#line 307 "parser.y"
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
#line 1968 "y.tab.c"
    break;

  case 38:
#line 323 "parser.y"
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
#line 1994 "y.tab.c"
    break;

  case 39:
#line 344 "parser.y"
                    {(yyval.exprval) = (yyvsp[0].exprval);}
#line 2000 "y.tab.c"
    break;

  case 40:
#line 347 "parser.y"
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
#line 2023 "y.tab.c"
    break;

  case 41:
#line 367 "parser.y"
                       { (yyval.exprval) = emit_iftableitem((yyvsp[0].exprval), yylineno);}
#line 2029 "y.tab.c"
    break;

  case 42:
#line 368 "parser.y"
                 {;}
#line 2035 "y.tab.c"
    break;

  case 43:
#line 369 "parser.y"
                      {;}
#line 2041 "y.tab.c"
    break;

  case 44:
#line 370 "parser.y"
                                {
               (yyval.exprval) = newexpr(programfunc_e);
               (yyval.exprval)->sym = (yyvsp[-1].symval);
          }
#line 2050 "y.tab.c"
    break;

  case 45:
#line 374 "parser.y"
                  { (yyval.exprval) = (yyvsp[0].exprval);}
#line 2056 "y.tab.c"
    break;

  case 46:
#line 377 "parser.y"
                   {
               Symbol* item = lvalue_id(yytext, yylineno);
               (yyval.exprval) = lvalue_expr(item);
          }
#line 2065 "y.tab.c"
    break;

  case 47:
#line 381 "parser.y"
                     {
               Symbol* item = lvalue_localid(yytext, yylineno);
               if ( item && item->type == programfunc_s) {
                    fprintf(stderr, "Warning  :  %s is a function.", yytext);
               }
               (yyval.exprval) = lvalue_expr(item);
          }
#line 2077 "y.tab.c"
    break;

  case 48:
#line 388 "parser.y"
                       {
               Symbol* item = lvalue_dcolonid(yytext, yylineno);
               (yyval.exprval) = lvalue_expr(item);
          }
#line 2086 "y.tab.c"
    break;

  case 49:
#line 392 "parser.y"
                   {(yyval.exprval) = (yyvsp[0].exprval);}
#line 2092 "y.tab.c"
    break;

  case 50:
#line 395 "parser.y"
                              {(yyval.exprval) = member_item((yyvsp[-2].exprval), yytext,yylineno);}
#line 2098 "y.tab.c"
    break;

  case 51:
#line 396 "parser.y"
                                    {
               (yyvsp[-3].exprval) = emit_iftableitem((yyvsp[-3].exprval), yylineno);
               (yyval.exprval) = newexpr(tableitem_e);
               (yyval.exprval)->sym = (yyvsp[-3].exprval)->sym;
               (yyval.exprval)->index = (yyvsp[-1].exprval);
          }
#line 2109 "y.tab.c"
    break;

  case 52:
#line 402 "parser.y"
                        {;}
#line 2115 "y.tab.c"
    break;

  case 53:
#line 403 "parser.y"
                                  {;}
#line 2121 "y.tab.c"
    break;

  case 54:
#line 406 "parser.y"
                               { (yyval.exprval) = make_call((yyval.exprval), (yyvsp[-1].exprval),yylineno);}
#line 2127 "y.tab.c"
    break;

  case 55:
#line 407 "parser.y"
                              {
               (yyvsp[-1].exprval) = emit_iftableitem((yyvsp[-1].exprval), yylineno);
               if ((yyvsp[0].callval).method){
                    Expr* t = (yyvsp[-1].exprval);
                    (yyvsp[-1].exprval) = emit_iftableitem(member_item(t, (yyvsp[0].callval).name,yylineno), yylineno);
                    (yyvsp[0].callval).elist->next = t;
               }
               (yyval.exprval) = make_call((yyvsp[-1].exprval), (yyvsp[0].callval).elist,yylineno);
          }
#line 2141 "y.tab.c"
    break;

  case 56:
#line 416 "parser.y"
                                                  {
               Expr* func = newexpr(programfunc_e);
               func->sym = (yyvsp[-4].symval);
               (yyval.exprval) = make_call(func, (yyvsp[-1].exprval),yylineno);
          }
#line 2151 "y.tab.c"
    break;

  case 57:
#line 423 "parser.y"
                         { (yyval.callval) = (yyvsp[0].callval); }
#line 2157 "y.tab.c"
    break;

  case 58:
#line 424 "parser.y"
                            {(yyval.callval) = (yyvsp[0].callval);}
#line 2163 "y.tab.c"
    break;

  case 59:
#line 427 "parser.y"
                                  {
                    (yyval.callval).elist = (yyvsp[-1].exprval);
                    (yyval.callval).method = 0;
                    (yyval.callval).name = NULL;
               }
#line 2173 "y.tab.c"
    break;

  case 60:
#line 433 "parser.y"
                                       {
               (yyval.callval).elist = (yyvsp[-1].exprval);
               (yyval.callval).method = 1;
               (yyval.callval).name = (yyvsp[-3].strval);
          }
#line 2183 "y.tab.c"
    break;

  case 61:
#line 439 "parser.y"
                         {
               if ( (yyvsp[-1].exprval)->type == boolexpr_e) {
                    patchboolean((yyvsp[-1].exprval), yylineno);
               }
               (yyval.exprval) = (yyvsp[-1].exprval);
               (yyval.exprval)->next = (yyvsp[0].exprval);
          }
#line 2195 "y.tab.c"
    break;

  case 62:
#line 446 "parser.y"
            {(yyval.exprval) = NULL;}
#line 2201 "y.tab.c"
    break;

  case 63:
#line 448 "parser.y"
                                      {
                    (yyval.exprval) = (yyvsp[-1].exprval);
                    (yyval.exprval)->next = (yyvsp[0].exprval);
               }
#line 2210 "y.tab.c"
    break;

  case 64:
#line 452 "parser.y"
                 {(yyval.exprval) = NULL;}
#line 2216 "y.tab.c"
    break;

  case 65:
#line 455 "parser.y"
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
#line 2232 "y.tab.c"
    break;

  case 66:
#line 466 "parser.y"
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
#line 2252 "y.tab.c"
    break;

  case 67:
#line 483 "parser.y"
                                               {
                    (yyval.exprval) = (yyvsp[-1].exprval);
                    (yyval.exprval)->next=(yyvsp[0].exprval);
               }
#line 2261 "y.tab.c"
    break;

  case 68:
#line 489 "parser.y"
                                            {
                    (yyval.exprval) = (yyvsp[-1].exprval);
                    (yyval.exprval)->next = (yyvsp[0].exprval);
               }
#line 2270 "y.tab.c"
    break;

  case 69:
#line 493 "parser.y"
                 {(yyval.exprval)=NULL;}
#line 2276 "y.tab.c"
    break;

  case 70:
#line 496 "parser.y"
                                              {
                    (yyval.exprval)=(yyvsp[-3].exprval);
                    (yyval.exprval)->index = (yyvsp[-1].exprval); 
               }
#line 2285 "y.tab.c"
    break;

  case 71:
#line 503 "parser.y"
                             { (yyval.stmtval) = (yyvsp[0].stmtval);}
#line 2291 "y.tab.c"
    break;

  case 72:
#line 504 "parser.y"
                 {;}
#line 2297 "y.tab.c"
    break;

  case 73:
#line 507 "parser.y"
                       { nextscope();}
#line 2303 "y.tab.c"
    break;

  case 74:
#line 507 "parser.y"
                                                       { (yyval.stmtval) = (yyvsp[-1].stmtval); hide(currscope()); exitscope();}
#line 2309 "y.tab.c"
    break;

  case 75:
#line 510 "parser.y"
                           {
                    funcname_id(yytext, yylineno);
                    (yyval.strval) = (yyvsp[0].strval);
               }
#line 2318 "y.tab.c"
    break;

  case 76:
#line 514 "parser.y"
                 {
                    Symbol* temp;
                    temp = funcname_noname(yytext, yylineno);
                    (yyval.strval) = temp->name;
               }
#line 2328 "y.tab.c"
    break;

  case 77:
#line 520 "parser.y"
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
#line 2344 "y.tab.c"
    break;

  case 78:
#line 533 "parser.y"
                                   {
                    enterfuncscope();
                    enterscopespace();
                    resetfunctionlocaloffset();
               }
#line 2354 "y.tab.c"
    break;

  case 79:
#line 539 "parser.y"
                      {
                    exitfuncscope();
                    (yyval.intval) = currscopespaceoffset();
                    exitscopespace();
               }
#line 2364 "y.tab.c"
    break;

  case 80:
#line 546 "parser.y"
               { push(&loopcounterstack, loopcounter); loopcounter=0;}
#line 2370 "y.tab.c"
    break;

  case 81:
#line 547 "parser.y"
                { loopcounter = pop(&loopcounterstack); }
#line 2376 "y.tab.c"
    break;

  case 82:
#line 549 "parser.y"
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
#line 2396 "y.tab.c"
    break;

  case 83:
#line 566 "parser.y"
            { (yyval.exprval) = newexpr_constnum((yyvsp[0].intval));}
#line 2402 "y.tab.c"
    break;

  case 84:
#line 567 "parser.y"
                 {(yyval.exprval) = newexpr_constnum((yyvsp[0].floatval));}
#line 2408 "y.tab.c"
    break;

  case 85:
#line 568 "parser.y"
                   { (yyval.exprval) = newexpr_conststring((yyvsp[0].strval));}
#line 2414 "y.tab.c"
    break;

  case 86:
#line 569 "parser.y"
                { (yyval.exprval) = newexpr(nil_e);}
#line 2420 "y.tab.c"
    break;

  case 87:
#line 570 "parser.y"
                 { (yyval.exprval) = newexpr_constbool(1);}
#line 2426 "y.tab.c"
    break;

  case 88:
#line 571 "parser.y"
                  { (yyval.exprval) = newexpr_constbool(0);}
#line 2432 "y.tab.c"
    break;

  case 89:
#line 574 "parser.y"
           { idlist_id(yytext, yylineno);}
#line 2438 "y.tab.c"
    break;

  case 90:
#line 575 "parser.y"
                            { idlist_commaid(yytext, yylineno);}
#line 2444 "y.tab.c"
    break;

  case 91:
#line 576 "parser.y"
            {;}
#line 2450 "y.tab.c"
    break;

  case 92:
#line 579 "parser.y"
                                    {
               if ((yyvsp[-1].exprval) && (yyvsp[-1].exprval)->type == 5) {
                    patchboolean((yyvsp[-1].exprval), yylineno);
               }
               emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, nextquad() + 2, yylineno);
               (yyval.intval) = nextquad();
               emit(jump, NULL , NULL, NULL, 0, yylineno);
          }
#line 2463 "y.tab.c"
    break;

  case 93:
#line 589 "parser.y"
                     {
                    (yyval.intval) = nextquad();
                    emit(jump, NULL, NULL, NULL, 0, yylineno);
               }
#line 2472 "y.tab.c"
    break;

  case 94:
#line 595 "parser.y"
                                     {
                    patchlabel((yyvsp[-1].intval), nextquad());
               }
#line 2480 "y.tab.c"
    break;

  case 95:
#line 598 "parser.y"
                                               {
                    patchlabel((yyvsp[-3].intval), ((yyvsp[-1].intval))+1);
                    patchlabel((yyvsp[-1].intval), nextquad());
               }
#line 2489 "y.tab.c"
    break;

  case 96:
#line 604 "parser.y"
                      {
                    loopcounter++;
                    (yyval.intval) = nextquad();
               }
#line 2498 "y.tab.c"
    break;

  case 97:
#line 610 "parser.y"
                                 {
                    if ( (yyvsp[-1].exprval)->type == 5) {
                         patchboolean((yyvsp[-1].exprval), yylineno);
                    }
                    emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, nextquad()+2, yylineno);
                    (yyval.intval) = nextquad();
                    emit(jump, NULL, NULL, NULL, 0, yylineno);
               }
#line 2511 "y.tab.c"
    break;

  case 98:
#line 619 "parser.y"
                                          {
                    loopcounter--;
                    emit(jump, NULL, NULL, NULL, (yyvsp[-2].intval), yylineno);
                    patchlabel((yyvsp[-1].intval), nextquad());

                    patchlist(pop(&breakstack), nextquad());
                    patchlist(pop(&contstack), (yyvsp[-2].intval));
               }
#line 2524 "y.tab.c"
    break;

  case 99:
#line 628 "parser.y"
        {
          (yyval.intval) = nextquad();
          emit(jump, NULL, NULL, NULL, 0, yylineno);
     }
#line 2533 "y.tab.c"
    break;

  case 100:
#line 633 "parser.y"
     {(yyval.intval) = nextquad();}
#line 2539 "y.tab.c"
    break;

  case 101:
#line 636 "parser.y"
                    {loopcounter++;}
#line 2545 "y.tab.c"
    break;

  case 102:
#line 636 "parser.y"
                                                                   {
                    if ( (yyvsp[-1].exprval)->type == 5) {
                         patchboolean((yyvsp[-1].exprval), yylineno);
                    }
                    (yyval.prefval).test = (yyvsp[-2].intval);
                    (yyval.prefval).enter = nextquad();
                    emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(1), NULL, 0, yylineno);
               }
#line 2558 "y.tab.c"
    break;

  case 103:
#line 646 "parser.y"
                                               {loopcounter--;}
#line 2564 "y.tab.c"
    break;

  case 104:
#line 646 "parser.y"
                                                                   {
               patchlabel((yyvsp[-7].prefval).enter, (yyvsp[-3].intval)+1);
               patchlabel((yyvsp[-6].intval), nextquad());
               patchlabel((yyvsp[-3].intval), (yyvsp[-7].prefval).test);
               patchlabel((yyvsp[0].intval), (yyvsp[-6].intval)+1);

               patchlist(pop(&breakstack), nextquad());
               patchlist(pop(&contstack), (yyvsp[-6].intval)+1);
          }
#line 2578 "y.tab.c"
    break;

  case 105:
#line 656 "parser.y"
                {
               make_stmt(&(yyval.stmtval));
               (yyval.stmtval).breaklist = newlist(nextquad());
               emit(jump, NULL, NULL, NULL, 0, yylineno);
               push(&breakstack, (yyval.stmtval).breaklist);
          }
#line 2589 "y.tab.c"
    break;

  case 106:
#line 664 "parser.y"
                   {
               make_stmt(&(yyval.stmtval));
               (yyval.stmtval).contlist = newlist(nextquad());
               emit(jump, NULL, NULL, NULL, 0, yylineno);
               push(&contstack, (yyval.stmtval).contlist);
          }
#line 2600 "y.tab.c"
    break;

  case 107:
#line 673 "parser.y"
                            {
                    if (currfuncscope() == 0) Error(2, yytext, yylineno);
                    else {
                         emit(ret, NULL, NULL, NULL, nextquad() + 1, yylineno);
                         retaddr = nextquad();
                         emit(jump, NULL, NULL, NULL, 0, yylineno);
                    }
               }
#line 2613 "y.tab.c"
    break;

  case 108:
#line 681 "parser.y"
                                  {
                    if (currfuncscope() == 0) Error(2, yytext, yylineno);
                    else {
                         emit(ret, (yyvsp[-1].exprval), NULL, NULL, nextquad() + 1, yylineno);
                         retaddr = nextquad();
                         emit(jump, NULL, NULL, NULL, 0, yylineno);
                    }
               }
#line 2626 "y.tab.c"
    break;


#line 2630 "y.tab.c"

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

#line 691 "parser.y"


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
