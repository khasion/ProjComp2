#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "avm.h"


execute_func_t executeFuncs[] = {
    execute_assign,
    execute_add,
    execute_sub,
    execute_mul,
    execute_div,
    execute_mod,
    execute_uminus,
    execute_and,
    execute_or,
    execute_not,
    execute_jeq,
    execute_jne,
    execute_jle,
    execute_jge,
    execute_jlt,
    execute_jgt,
    execute_call,
    execute_pusharg,
    execute_funcenter,
    execute_funcexit,
    execute_newtable,
    execute_tablegetelem,
    execute_tablesetelem,
    execute_nop
};

memclear_func_t memclearFuncs[] = {
  0,
  memclear_string,
  0,
  memclear_table,
  0,
  0,
  0,
  0
};


avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg){
  switch(arg->type){
    /*Variables*/
    case global_a: return &stack[AVM_STACKSIZE-1-arg->val];
    case local_a: return &stack[topsp-arg->val];
    case formal_a: return &stack[topsp+AVM_STACKENV_SIZE+1+arg->val];
    case retval_a: return &retval;
    case number_a: {
      reg->type = number_m;
      reg->data.numVal = consts_getnumber(arg->val);
      return reg;
    }
    case string_a: {
      reg->type = string_m;
      reg->data.strVal = strdup(consts_getstring(arg->val));
      return reg;
    }
    case bool_a: {
      reg->type = bool_m;
      reg->data.boolVal = arg->val;
      return reg;
    }
    case nil_a: reg->type = nil_m; return reg;
    case userfunc_a: {
      reg->type = userfunc_m;
      reg->data.funcVal = arg->val; /*Address already stored*/
      return reg;
    }
    case libfunc_a: {
      reg->type = libfunc_m;
      reg->data.libfuncVal = libfuncs_getused(arg->val);
      return reg;
    }
    default: assert (0);
  }
}

void execute_cycle(void) {
  if(executionFinished) return;
  else if(pc == AVM_ENDING_PC){
      executionFinished = 1;
      return;
    }
    else{
      assert(pc< AVM_ENDING_PC);
      instruction* instr = code + pc;
      assert(instr->opcode >= 0 && instr->opcode <= AVM_MAX_INSTRUCTIONS);
      if (instr-> srcLine) currLine = instr->srcLine;
      unsigned oldPC = pc;
      (*executeFuncs[instr->opcode])(instr);
      if (pc == olsPC) ++pc;
    }
  }

void avm_memcellclear (avm_memcell* m){
  if (m->type != undef_m){
    memclear_func_t f = memclearFuncs[m->type];
    if (f){
      (*f)(m);
      m->type = undef_m;
    }
  }
}

extern void memclear_string(avm_memcell* m){
  assert (m->data.strVal);
  free(m->data.strVal);
}

extern void memclear_table (avm_memcell* m){
  assert (m->data.tableVal);
  avm_tabledecrefcounter(m->data.tableVal);
}

void avm_dec_top (void){
  if(!top){/*stack overflow*/
    avm_error("stack overflow");
    executionFinished = 1;
  }
  else --top;
}

void avm_push_envvalue (unsigned val){
  stack[top].type = number_m;
  stack[top].data.numVal = val;
  avm_dec_top();
}


unsigned avm_get_envvalue (unsigned i ){
  assert(stack[i].type = number_m);
  unsigned val = (unsigned) stack[i].data.numVal;
  assert (stack[i].data.numVal) == ((double) val);
  return val;
}

void execute_pusharg(instruction* instr){
  avm_memcell* arg = avm_translate_operand(&instr->arg1, &ax);
  assert(arg);
  avm_assign(&stack[top], arg);
  ++totalActuals;
  avm_dec_top();
}

unsigned char avm_tobool (avm_memcell* m){
  assert(m->type >= 0 && m->type < undef_m);
  return (*toboolFuncs[m->type]) (m);
}

void avm_warning(char* war){
  printf("Warning: %s", war);
}

void avm_error(char* err){
  printf("Error: %s", err)
}

void avm_initialize(){
  avm_initstack();
  avm_registerlibfunc("print", libfunc_print);
  avm_registerlibfunc("input", libfunc_input);
  avm_registerlibfunc("objectmemberkyes", libfunc_objectmemberkyes);
  avm_registerlibfunc("objectotslmembers", libfunc_objectotslmembers);
  avm_registerlibfunc("objectcopy", libfunc_objectcopy);
  avm_registerlibfunc("totalarguments", libfunc_totalarguments);
  avm_registerlibfunc("argument", libfunc_argument);
  avm_registerlibfunc("typeof", libfunc_typeof);
  avm_registerlibfunc("strtonum", libfunc_strtonum);
  avm_registerlibfunc("sqrt", libfunc_sqrt);
  avm_registerlibfunc("cos", libfunc_cos);
  avm_registerlibfunc("sin", libfunc_sin);
}


