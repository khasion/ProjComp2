#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "avm.h"

#define AVM_STACKSIZE    4096
extern avm_memcell stack[AVM_STACKSIZE];
extern unsigned top;
extern unsigned topsp;

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
unsigned avm_get_envvalue (unsigned i);

unsigned avm_totalactuals (void);
avm_memcell* avm_getactual (unsigned i);

userfunc* avm_getfuncinfo(unsigned address);
library_func_t avm_getlibraryfunc(char* id);

void avm_calllibfunc(char* funcName);
void libfunc_print(void);
void libfunc_typeof (void);
void libfunc_totalarguments();

#endif