#ifndef AVM_H
#define AVM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mem.h"
#include "relop.h"
#include "arith.h"
#include "functions.h"

extern unsigned pc;
extern unsigned char executionFinished;
extern avm_memcell ax;
extern avm_memcell bx;
extern avm_memcell cx;
extern avm_memcell retval;
extern unsigned totalActuals;
extern unsigned codeSize;

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

typedef struct instruction {
     vmopcode  opcode;
     vmarg     result;
     vmarg     arg1;
     vmarg     arg2;
     unsigned  label;
     unsigned  srcLine;
}instruction;

extern instruction* code;

void print_stack();
void print_code();
void emit_code(instruction t);
void init_code(unsigned size);

#define AVM_ENDING_PC codeSize
#define AVM_STACKENV_SIZE 4
#define AVM_MAX_INSTRUCTIONS (unsigned) nop_v


typedef void (*execute_func_t)(instruction*);
extern execute_func_t executeFuncs[];

avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg);

void avm_warning(char* war);
void avm_error(char* err, void* content);


void execute_cycle (void);

void avm_assign(avm_memcell* lv, avm_memcell* rv);
void avm_initialize();

void execute_assign(instruction*);
void execute_uminus(instruction*);
void execute_and(instruction*);
void execute_or(instruction*);
void execute_not(instruction*);
void execute_jeq(instruction*);
void execute_jne(instruction*);
void execute_jle(instruction*);
void execute_jge(instruction*);
void execute_jlt(instruction*);
void execute_jgt(instruction*);
void execute_newtable(instruction*);
void execute_tablegetelem(instruction*);
void execute_tablesetelem(instruction*);
void execute_nop(instruction*);


#endif
