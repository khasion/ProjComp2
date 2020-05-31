%{
     #include <stdio.h>
     #include <stdlib.h>
     #include <string.h>
     #include "y.tab.h"

     #define MAX 100

%}
%option noyywrap
%option yylineno

id        [a-zA-Z][a-zA-Z_0-9]*
temp      [\^][0-9]*
integer   [0-9]*
real      [0-9]*\.[0-9](e|E)?[0-9]*
space     [\r\t \v\n]
newline   [\n]
noname    [\_][f][0-9]*

%%
_magic                 {return MAGIC;}
_code                  {return CODE;}
_stringConsts          {return STRINGARRAY;}
_numConsts             {return NUMARRAY;}
_namedLibFuncs         {return LIBARRAY;}
_userfuncs             {return USERFUNCARRAY;}
_assign                {yylval.strval = strdup(yytext); return ASSIGN;}
_add                   {yylval.strval = strdup(yytext); return ADD;}
_sub                   {yylval.strval = strdup(yytext); return SUB;}
_mul                   {yylval.strval = strdup(yytext); return MUL;}
_div                   {yylval.strval = strdup(yytext); return DIV;}
_mod                   {yylval.strval = strdup(yytext); return MOD;}
_uminus                {yylval.strval = strdup(yytext); return UMINUS;}
_and                   {yylval.strval = strdup(yytext); return AND;}
_or                    {yylval.strval = strdup(yytext); return OR;}
_not                   {yylval.strval = strdup(yytext); return NOT;}
_jeq                   {yylval.strval = strdup(yytext); return JEQ;}
_jne                   {yylval.strval = strdup(yytext); return JNE;}
_jle                   {yylval.strval = strdup(yytext); return JLE;}
_jge                   {yylval.strval = strdup(yytext); return JGE;}
_jlt                   {yylval.strval = strdup(yytext); return JLT;}
_jgt                   {yylval.strval = strdup(yytext); return JGT;}
_callfunc              {yylval.strval = strdup(yytext); return CALLFUNC;}
_pusharg               {yylval.strval = strdup(yytext); return PUSHARG;}
_enterfunc             {yylval.strval = strdup(yytext); return ENTERFUNC;}
_exitfunc              {yylval.strval = strdup(yytext); return EXITFUNC;}
_newtable              {yylval.strval = strdup(yytext); return NEWTABLE;}
_tablesetelem          {yylval.strval = strdup(yytext); return TABLESETELEM;}
_tablegetelem          {yylval.strval = strdup(yytext); return TABLEGETELEM;}
_jump                  {yylval.strval = strdup(yytext); return JUMP;}
_nop                   {yylval.strval = strdup(yytext); return NOP;}

":"                      {return COLON;}
","                      {return COMMA;}
"|"                      {return BAR;}

"\"" {
     char *str;
	int cnt = 0;
	int size = 100;
	str = (char*) malloc(sizeof(char)*size);
	int c;
	while ( (c = input()) != EOF) {
		if ( cnt >= size-2) {
			size = size*2;
			str = (char*) realloc(str, size);
		}
		if ( c == '\\') {
			c = input();
			switch(c) {
			case 'n': str[cnt++] = 10; break;
			case 'a': str[cnt++] = 7; break;
			case 'b': str[cnt++] = 8; break;
			case 'e': str[cnt++] = 27; break;
			case 'f': str[cnt++] = 12; break;
			case 'r': str[cnt++] = 13; break;
			case 't': str[cnt++] = 9; break;
			case 'v': str[cnt++] = 11; break;
			case '\\': str[cnt++] = '\\'; break;
			case '\'': str[cnt++] = '\''; break;
			case '\"': str[cnt++] = '\"'; break;
			case '\?': str[cnt++] = '\?'; break;
			default: unput(c); break;
			}
		}
		else if ( c == '\"') {
			str[cnt++] = '\0';
			break;
		}
		else {
			str[cnt++] = c;
		}
	}
     yylval.strval = strdup(str);
     return STRING;
}
{space}   {;}

{id} {
     yylval.strval = strdup(yytext);
     return ID;
}

{temp} {
     yylval.strval = strdup(yytext);
     return TEMP;
}

{integer} {
     yylval.intval = atoi(yytext);
     return INT;
}
{real}    {
  yylval.dblval = atof(yytext);
  return REAL;
}
{noname} {
     yylval.strval = strdup(yytext);
     return NONAME;
}
<<EOF>> { return -1;}
%%