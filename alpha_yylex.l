%{
  #include "quads.h"
  #include "y.tab.h"
  #define MAX 100

  char* buffer;
  int string_count;
  int buffer_count;
  int tokens = 0;

  char Enum_array[44][10]= {"IF","ELSE","WHILE","FOR","FUNC","RETURN","BREAK","CONTINUE","AND","OR","NOT","LOCAL","TRUE","FALSE","NIL","ASSIGN","PLUS",
    "MINUS","MUL","DIV","MOD","EQ","NOT_EQ","D_PLUS","D_MINUS","LESS","GREATER","LESS_EQ","GREATER_EQ","LC_BRA","RC_BRA",
    "L_BRA","R_BRA","L_PAR","R_PAR","SEMI","COMMA","COLON","D_COLON","DOT","D_DOT","INT","REAL","ID"};

  typedef struct node node;

  struct node {
    int line_num;
    int token_num;
    char* content;
    char* type;
    char* charvalue;
    float numbervalue;
    node *next;
  };

node *head = NULL;
void insert_list(int numline, int numtoken, char* content, char* type, char* charvalue, float numbervalue);
void print_list(node *head);
char* search_name(char* name);
%}
%option noyywrap
%option yylineno

id      [a-zA-Z][a-zA-Z_0-9]*
integer (0[xX][0-9A-Fa-f]+)|([0-9]+)
real    [0-9]*\.[0-9](e|E)?[0-9]*
space   [\r\t \v\n]
linecomment "//".*
illegal ([\$ \~ \? \# \&\& \|\| \!]*)|(\_[a-zA-Z]*)|([0-9][a-zA-Z]*)

%%

if        {return IF;}
else      {return ELSE;}
while     {return WHILE;}
for       {return FOR;}
function  {return FUNC;}
return    {return RETURN;}
break     {return BREAK;}
continue  {return CONTINUE;}
and       {return AND;}
or        {return OR;}
not       {return NOT;}
local     {return LOCAL;}
true      {return TRUE;}
false     {return FALSE;}
nil       {return NIL;}

"="       {return ASSIGN;}
"+"       {return PLUS;}
"-"       {return MINUS;}
"*"       {return MUL;}
"/"       {return DIV;}
"%"       {return MOD;}
"=="      {return EQ;}
"!="      {return NOT_EQ; }
"++"      {return D_PLUS;}
"--"      {return D_MINUS;}
"<"       {return LESS;}
">"       {return GREATER;}
">="      {return LESS_EQ;}
"<="      {return GREATER_EQ;}

"{"       {return LC_BRA;}
"}"       {return RC_BRA;}
"["       {return L_BRA;}
"]"       {return R_BRA;}
"("       {return L_PAR;}
")"       {return R_PAR;}
";"       {return SEMI;}
","       {return COMMA;}
":"       {return COLON;}
"::"      {return D_COLON;}
"."       {return DOT;}
".."      {return D_DOT;}

{integer} {
  yylval.intval = atoi(yytext);
  return INT;
}
{real}    {
  yylval.floatval = atof(yytext);
  return REAL;
}
{id}      {
  yylval.strval = (char*) malloc(sizeof(char)*strlen(yytext));
  sprintf(yylval.strval, "%s", yytext);
  return ID;
}
{space}   {;}

"\"" 			{
      char *str;
			int cnt = 0;
			int size = 1000;
			int c;
			str = (char*) malloc(sizeof(char)*size);
			while ( (c = input()) != EOF) {
				if ( cnt >= size-2) {
					size = size + 2;
					str = (char*) realloc(str, size+1);
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
      str[cnt++] = '\0';
			/*insert_list(yylineno, tokens++, str, "STRING", str, atoi(yytext));*/
      yylval.strval = (char*) malloc(sizeof(char)*cnt+1);
      sprintf(yylval.strval, "%s", str);
    return STRING;
  }


"/*"  {
  int c;
  int comm_counter = 1;
  int line_counter = 0;
  char cr_buffer[16];
  while((c = input()) != EOF){
    if(c == '\n'){
      line_counter++;
    }
    if(c == '/'){
      c = input();
      if(c == '*'){
        comm_counter++;
      } else { unput(c); }
    } else if(c == '*'){
      c = input();
      if(c == '/'){
        comm_counter--;
      } else { unput(c); }
    }

    if(comm_counter == 0) break;
  }
  if(comm_counter != 0){
    printf("ERROR: OPEN COMMENT\n");
  } else{
    sprintf(cr_buffer,"%d %c %d",yylineno, '-', yylineno + line_counter);
     /*insert_list(yylineno, tokens++, cr_buffer, "COMMENT BLOCK_COMMENT", "", atoi(yytext));*/}
}

{linecomment} {
  int c;
  while ((c = input()) != '\n' && c != EOF);
  /*insert_list(yylineno, tokens++, "", "COMMENT LINE_COMMENT", "", atoi(yytext));*/
}

{illegal} {/*insert_list(yylineno,tokens++, yytext, "ILLIGAL CHAR","", atoi(yytext));*/
}
<<EOF>> { return -1;}

%%

 char* search_name(char* name){
    char* name1 = name;
    if ( strcmp(name, "IF") == 0 || strcmp(name, "ELSE") == 0 || strcmp(name, "WHILE") == 0 || strcmp(name , "FOR") ==0 || strcmp(name,"FUNC")==0 || strcmp(name , "RETURN") == 0 ||
      strcmp(name, "BREAK") == 0 || strcmp(name, "CONTINUE") == 0|| strcmp(name , "AND") == 0 || strcmp(name , "NOT") == 0|| strcmp(name , "OR") == 0 || strcmp(name , "LOCAL") == 0|| strcmp(name , "TRUE") == 0 ||
      strcmp(name , "FALSE") == 0 || strcmp(name , "NIL") == 0 )
      {
          name1 = "KEYWORD";
      }
     else if( strcmp(name, "ASSIGN") == 0 || strcmp(name, "PLUS") == 0 || strcmp(name, "MINUS") == 0 || strcmp(name, "MUL") == 0 || strcmp(name, "DIV") == 0 ||
        strcmp(name, "MOD") == 0 || strcmp(name, "EQ") == 0 || strcmp(name, "NOT_EQ") == 0 || strcmp(name, "D_PLUS") == 0 || strcmp(name, "D_MINUS") == 0 ||
       strcmp(name, "LESS") == 0 || strcmp(name, "GREATER") == 0 || strcmp(name, "LESS_EQ") == 0 || strcmp(name, "GREATER_EQ") == 0)
      {
         name1 = "OPERATOR";

      }

     else if (strcmp(name , "LC_BRA") == 0 || strcmp(name , "RC_BRA") == 0 || strcmp(name , "L_BRA") == 0 || strcmp(name , "R_BRA") == 0 || strcmp(name , "L_PAR") == 0 ||
        strcmp(name ,"R_PAR") == 0 || strcmp(name , "SEMI") == 0 || strcmp(name , "COMMA") == 0 || strcmp(name , "COLON") == 0 || strcmp(name , "D_COLON") == 0
        || strcmp(name , "DOT") == 0 || strcmp(name , "D_DOT") == 0)
       {
         name1 = "PUNCTUATION";

       }
     else if (strcmp(name,"INT") == 0)
     {
       name1 = "INTEGER";

     }
     else if (strcmp(name , "REAL") == 0 )
     {
       name1 = "REAL";

     }
     else if (strcmp(name,"ID") == 0)
     {
       name1 = "ID";

     }
     return name1;
}

void print_list(node *head){
  node *tmp = head;
  printf("----------------------------------------------------- Lexical Analysis ----------------------------------------------------- \n");
  while(tmp){

    tmp = tmp->next;
  }
  return;
}

void insert_list(int line_num, int token_num, char* content, char* type, char* charvalue, float numbervalue)
{
 node *newnode, *tmp;
 newnode = (node*)malloc(sizeof(node));
 tmp = head;
 if(head == NULL){
   newnode->line_num = line_num;
   newnode->token_num = token_num;

   newnode->content = (char*) malloc(sizeof(content));
   sprintf(newnode->content, "%s", content);

   newnode->type = type;

   newnode->charvalue = (char*) malloc(sizeof(charvalue));
   sprintf(newnode->charvalue, "%s", charvalue);

   newnode->numbervalue = numbervalue;
   newnode->next = NULL;
   head = newnode;
 } else{
   while(tmp->next){
     tmp = tmp->next;
   }
   newnode->line_num = line_num;
   newnode->token_num = token_num;

   newnode->content = (char*) malloc(sizeof(char)*strlen(content));
   sprintf(newnode->content, "%s", content);

   newnode->type = type;


   newnode->charvalue = (char*) malloc(sizeof(char)*strlen(charvalue));
   sprintf(newnode->charvalue, "%s", charvalue);

   newnode->numbervalue = numbervalue;
   newnode->next = NULL;
   tmp->next = newnode;
 }
 return;
}
