%{
     #include <stdio.h>
     #include <unistd.h>
     #include <stdlib.h>
     #include <string.h>
     #include "mem.h"
     #include "avm.h"

     #define  YY_DECL int alpha_yylex (void* yylval)
     void yyerror (char* yaccProvidedMessage);
     int yylex();
     extern int yylineno;
     extern char* yytext;
     extern FILE* yyin;
%}

%start program

%union {
     int intval;
     char* strval;
     double dblval;
     struct avm_memcell* memval;
     struct userfunc* userval;
     struct instruction* instruct;
     struct vmarg* vmargval;
}
%token <dblval>     REAL
%token <intval>     INT
%token <strval>     ID TEMP MAGIC CODE STRINGARRAY NUMARRAY 
%token <strval>     LIBARRAY USERFUNCARRAY STRING
%token <strval>     OPCODE
%token <strval>     COLON COMMA BAR NONAME 

%type <intval> avmbinaryfile magicnumber codes arrays
%type <intval> stringConsts numConsts namedLibFuncs userfuncs 

%type <instruct> instructions instruction

%type <strval> libfunc libfuncs string strings 

%type <memval> num nums 
%type <userval> func funcs 

%type <vmargval> operand


%%
program:  avmbinaryfile{;}
          ;

avmbinaryfile: magicnumber codes arrays {
                    if ( $1 != 340200501) yyerror("WRONG MAGIC NUMBER");

               }
               ;
     
magicnumber:   MAGIC COLON INT {$$ = $3;}
               ;

codes:     CODE COLON INT{init_code($3+1);} instructions{ }; 

instructions:  instruction {;}
               | instructions instruction {;}
               ;

instruction:   INT BAR OPCODE operand operand operand {
                    $$ = (instruction*) malloc(sizeof(instruction));
                    $$->opcode = atoi($3);
                    $$->result = *$4;
                    $$->arg2 = *$6;
                    $$->arg1 = *$5;
                    emit_code(*$$);
               ;}
               ;

operand:  BAR INT COMMA INT COLON ID {
               $$ = (vmarg*) malloc(sizeof(vmarg));
               $$->val = $4;
               $$->id = $6;
               $$->type = $2;
          }
          | BAR INT COMMA INT COLON TEMP {
               $$ = (vmarg*) malloc(sizeof(vmarg));
               $$->val = $4;
               $$->id = $6;
               $$->type = $2;
               
          }
          | BAR INT COMMA INT COLON REAL {
               char*name;
               $$ = (vmarg*) malloc(sizeof(vmarg));
               name = (char*) malloc(sizeof(char)*50);
               $$->val = $4;
               sprintf(name, "constnums_", $6);
               $$->id = name;
               $$->type = $2;

          }
          | BAR INT COMMA INT {
               $$ = (vmarg*) malloc(sizeof(vmarg));
               $$->val = $4;
               $$->type = $2;
               }
          | BAR INT COMMA INT COLON STRING {
               $$ = (vmarg*) malloc(sizeof(vmarg));
               $$->val = $4;
               $$->id = $6;
               $$->type = $2;
          }
          | BAR INT COMMA INT COLON NONAME {
               $$ = (vmarg*)  malloc(sizeof(vmarg));
               $$->val = $4;
               $$->id = $6;
               $$->type = $2;
          }
          | BAR INT {
               $$ = (vmarg*)  malloc(sizeof(vmarg));
               $$->type = $2;
          }
          | {;}
          ;


arrays:   stringConsts numConsts namedLibFuncs userfuncs {;}
          ;

stringConsts:  STRINGARRAY COLON INT strings {;}
               ;

strings:  string{ $$ = $1;}
          | strings string { $$ = $2;}
          ;

string:   INT BAR STRING { 
               consts_newstring($3);
          }
          ;

numConsts:     NUMARRAY COLON INT nums {;}
               ;

nums:     num {;}
          | nums num{;};

num:      INT BAR REAL { 
               consts_newnumber($3);
          };

namedLibFuncs: LIBARRAY COLON INT libfuncs{;}
               ;

libfuncs:      libfunc {;}
               | libfuncs libfunc {;}

libfunc:       INT BAR STRING {
                    libfuncs_newused($3);             
               }

userfuncs:     USERFUNCARRAY COLON INT funcs {;}
               ;

funcs:    func {;}
          | funcs func {;};

func:     INT BAR ID COLON INT COLON INT {
               $$ = (userfunc*)  malloc(sizeof(userfunc));
               $$->id = strdup($3);
               $$->localSize = (unsigned)$5;
               $$->address = (unsigned)$7;
               userfuncs_newfunc(*$$);
               
          }
          | INT BAR NONAME COLON INT COLON INT {
               $$ = (userfunc*)  malloc(sizeof(userfunc));
               $$->id = strdup($3);
               $$->localSize = (unsigned)$5;
               $$->address = (unsigned)$7;
               userfuncs_newfunc(*$$);
          }


%%

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
     print_arrays();
     print_code();
     return 0;
}