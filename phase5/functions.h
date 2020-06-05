#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "avm.h"

#define AVM_STACKSIZE    4096
extern avm_memcell stack[AVM_STACKSIZE];
extern int top;
extern int topsp;

#define AVM_NUMACTUALS_OFFSET 4 
#define AVM_SAVEDTOP_OFFSET 2 
#define AVM_SAVEDTOPSP_OFFSET 1 
#define AVM_SAVEDPC_OFFSET 3 

typedef struct instruction instruction;

typedef void (*library_func_t)(void);
extern library_func_t libfunc_array[];

void avm_initstack();

void execute_call(instruction* instr);
void execute_pusharg(instruction* instr);
void execute_funcenter(instruction* instr);
void execute_funcexit(instruction* instr);

void avm_callsaveenviroment(void);

void avm_dec_top (void);

void avm_push_envvalue();
int avm_get_envvalue (int i);

int avm_totalactuals (void);
avm_memcell* avm_getactual (int i);

userfunc* avm_getfuncinfo(int address);
library_func_t avm_getlibraryfunc(char* id);

void avm_calllibfunc(char* funcName);
void libfunc_print(void);
void libfunc_typeof (void);
void libfunc_totalarguments(void);
void libfunc_objectmemberkeys(void);
void libfunc_objectotalmembers(void);
void libfunc_objectcopy(void);
void libfunc_argument(void);
void libfunc_strtonum(void);
void libfunc_sqrt(void);
void libfunc_cos(void);
void libfunc_sin(void);


#endif