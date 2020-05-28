#ifndef AVM_H
#define AVM_H

#define AVM_ENDING_PC 10
#define AVM_STACKENV_SIZE 4
#define AVM_MAX_INSTRUCTIONS (unsigned) nop_v
#include "mem.h"

avm_memcell ax, bx, cx;
avm_memcell retval;
unsigned top, topsp;

struct avm_table;
typedef void (*memclear_func_t)(avm_memcell*);
extern memclear_func_t memclearFuncs[];

typedef enum vmopcode {
     assign_v,           add_v,              sub_v,
     mul_v,              div_v,              mod_v,
     uminus_v,           and_v,              or_v,
     not_v,              jeq_v,              jne_v,
     jle_v,              jge_v,              jlt_v,
     jqt_v,              call_v,             pusharg_v,
     funcenter_v,        funcexit_v,         newtable_v,
     tablegetelem_v,     tablesetelem_v,     jump_v,
     nop_v
}vmopcode;

typedef enum vmarg_t {
     label_a        = 0,
     global_a       = 1,
     formal_a       = 2,
     local_a        = 3,
     number_a       = 4,
     string_a       = 5,
     bool_a         = 6,
     nil_a          = 7,
     userfunc_a     = 8,
     libfunc_a      = 9,
     retval_a       = 10
}vmarg_t;


typedef struct vmarg {
     vmarg_t   type;
     char*     id;
     unsigned  val;
}vmarg;

typedef struct Instruction {
     vmopcode  opcode;
     vmarg     result;
     vmarg     arg1;
     vmarg     arg2;
     unsigned  label;
     unsigned  srcLine;
}instruction;

typedef void (*execute_func_t)(instruction*);
extern execute_func_t executeFuncs[];



double const_getnumber(unsigned index);
char* consts_getstring(unsigned index);
char* libfuncs_getused(unsigned index);
extern void avm_warning(char* war);
extern void avm_error(char* err);
extern char* avm_tostring(avm_memcell*);
extern void avm_calllibfunc(char* funcName);
extern void avm_callsaveenviroment(void);
extern userfunc* avm_getfuncinfo(unsigned address);
typedef void (*library_func_t)(void);
library_func_t avm_getlibraryfunc(char* id);
extern void avm_assign(avm_memcell* lv, avm_memcell* rv);
void avm_initialize();
#endif
