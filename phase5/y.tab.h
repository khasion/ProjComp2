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

#line 160 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
