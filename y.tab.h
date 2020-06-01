/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 22 "parser.y" /* yacc.c:1909  */

     int intval;
     char* strval;
     float floatval;
     struct expr* exprval;
     struct stmt_t stmtval;
     struct call callval;
     struct symbol* symval;
     struct prefix prefval;

#line 161 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
