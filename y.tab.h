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

#line 173 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
