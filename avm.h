#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mem.h"

#ifndef AVM_H
#define AVM_H

unsigned consts_newstring(char* s);
unsigned consts_newnumber(double d);
unsigned userfuncs_newfunc(Symbol* s);
unsigned libfuncs_newused(char* s);

typedef void (*generator_func_t)(Quad*);
extern generator_func_t generators[];

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

extern instruction* instructions;

typedef struct incomplete_jump {
     unsigned                 instrNo;  // The jump instruction number .
     unsigned                 iaddress; // The i-code jump-target address.
     struct incomplete_jump*  next;     // A trivial linked list.
}incomplete_jump;

extern incomplete_jump*    ij_head;
extern unsigned            ij_total;

unsigned nextinstructionlabel();

void instructions_emit(instruction i);

void make_numberoperand (vmarg* arg, double val);
void make_booloperand (vmarg* arg , bool val);
void make_retvaloperand (vmarg* arg);
void reset_operand (vmarg* arg);

unsigned currprocessedquad();

extern void generate_ADD (Quad*);
extern void generate_SUB (Quad*);
extern void generate_MUL (Quad*);
extern void generate_DIV (Quad*);
extern void generate_MOD (Quad*);
extern void generate_NEWTABLE (Quad*);
extern void generate_TABLEGETELEM (Quad*);
extern void generate_TABLESETELEM (Quad*);
extern void generate_ASSIGN (Quad*);
extern void generate_NOP ();
extern void generate_JUMP (Quad*);
extern void generate_IF_EQ (Quad*);
extern void generate_IF_NOTEQ (Quad*);
extern void generate_IF_GREATER (Quad*);
extern void generate_IF_GREATEREQ (Quad*);
extern void generate_IF_LESS (Quad*);
extern void generate_IF_LESSEQ (Quad*);
extern void generate_UMINUS (Quad*);
extern void generate_NOT (Quad*);
extern void generate_AND (Quad*);
extern void generate_OR (Quad*);
extern void generate_PARAM (Quad*);
extern void generate_CALL (Quad*);
extern void generate_GETRETVAL (Quad*);

extern void generate_FUNCSTART (Quad*);
extern void generate_RETURN (Quad*);
extern void generate_FUNCEND (Quad*);

void generate1();


void print_instructions();

#endif