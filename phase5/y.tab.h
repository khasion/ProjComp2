/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    UMINUS = 259,                  /* UMINUS  */
    INT = 260,                     /* INT  */
    ID = 261,                      /* ID  */
    TEMP = 262,                    /* TEMP  */
    MAGIC = 263,                   /* MAGIC  */
    CODE = 264,                    /* CODE  */
    STRINGARRAY = 265,             /* STRINGARRAY  */
    NUMARRAY = 266,                /* NUMARRAY  */
    MINUS = 267,                   /* MINUS  */
    LIBARRAY = 268,                /* LIBARRAY  */
    USERFUNCARRAY = 269,           /* USERFUNCARRAY  */
    STRING = 270,                  /* STRING  */
    ASSIGN = 271,                  /* ASSIGN  */
    ADD = 272,                     /* ADD  */
    SUB = 273,                     /* SUB  */
    MUL = 274,                     /* MUL  */
    DIV = 275,                     /* DIV  */
    MOD = 276,                     /* MOD  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    NOT = 279,                     /* NOT  */
    JEQ = 280,                     /* JEQ  */
    JNE = 281,                     /* JNE  */
    JLE = 282,                     /* JLE  */
    JGE = 283,                     /* JGE  */
    JLT = 284,                     /* JLT  */
    JGT = 285,                     /* JGT  */
    CALLFUNC = 286,                /* CALLFUNC  */
    PUSHARG = 287,                 /* PUSHARG  */
    ENTERFUNC = 288,               /* ENTERFUNC  */
    EXITFUNC = 289,                /* EXITFUNC  */
    NEWTABLE = 290,                /* NEWTABLE  */
    TABLESETELEM = 291,            /* TABLESETELEM  */
    TABLEGETELEM = 292,            /* TABLEGETELEM  */
    JUMP = 293,                    /* JUMP  */
    NOP = 294,                     /* NOP  */
    COLON = 295,                   /* COLON  */
    COMMA = 296,                   /* COMMA  */
    BAR = 297,                     /* BAR  */
    NONAME = 298,                  /* NONAME  */
    TRUE = 299,                    /* TRUE  */
    FALSE = 300                    /* FALSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define REAL 258
#define UMINUS 259
#define INT 260
#define ID 261
#define TEMP 262
#define MAGIC 263
#define CODE 264
#define STRINGARRAY 265
#define NUMARRAY 266
#define MINUS 267
#define LIBARRAY 268
#define USERFUNCARRAY 269
#define STRING 270
#define ASSIGN 271
#define ADD 272
#define SUB 273
#define MUL 274
#define DIV 275
#define MOD 276
#define AND 277
#define OR 278
#define NOT 279
#define JEQ 280
#define JNE 281
#define JLE 282
#define JGE 283
#define JLT 284
#define JGT 285
#define CALLFUNC 286
#define PUSHARG 287
#define ENTERFUNC 288
#define EXITFUNC 289
#define NEWTABLE 290
#define TABLESETELEM 291
#define TABLEGETELEM 292
#define JUMP 293
#define NOP 294
#define COLON 295
#define COMMA 296
#define BAR 297
#define NONAME 298
#define TRUE 299
#define FALSE 300

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

#line 166 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
