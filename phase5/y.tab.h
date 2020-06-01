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
    REAL = 258,
    INT = 259,
    ID = 260,
    TEMP = 261,
    MAGIC = 262,
    CODE = 263,
    STRINGARRAY = 264,
    NUMARRAY = 265,
    LIBARRAY = 266,
    USERFUNCARRAY = 267,
    STRING = 268,
    ASSIGN = 269,
    ADD = 270,
    SUB = 271,
    MUL = 272,
    DIV = 273,
    MOD = 274,
    UMINUS = 275,
    AND = 276,
    OR = 277,
    NOT = 278,
    JEQ = 279,
    JNE = 280,
    JLE = 281,
    JGE = 282,
    JLT = 283,
    JGT = 284,
    CALLFUNC = 285,
    PUSHARG = 286,
    ENTERFUNC = 287,
    EXITFUNC = 288,
    NEWTABLE = 289,
    TABLESETELEM = 290,
    TABLEGETELEM = 291,
    JUMP = 292,
    NOP = 293,
    COLON = 294,
    COMMA = 295,
    BAR = 296,
    NONAME = 297
  };
#endif
/* Tokens.  */
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
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 20 "vm_parser.y" /* yacc.c:1909  */

     int intval;
     char* strval;
     double dblval;
     struct avm_memcell* memval;
     struct userfunc* userval;
     struct instruction* instruct;
     struct vmarg* vmargval;

#line 148 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
