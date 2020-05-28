#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "functions.h"

void execute_call (instruction* instr){
  avm_memcell* func = avm_translate_operand(&instr->result , &ax);
  assert(func);
  avm_callsaveenviroment();
  switch (func->type) {
    case userfunc_m: {
      pc=func->data.funcVal;
      assert(pc < AVM_ENDING_PC);
      assert (code[pc].opcode == funcenter_v);
      break;
    }
    case string_m: avm_calllibfunc(func->data.strVal); break;
    case libfunc_m: avm_calllibfunc(func->data.libfuncVal); break;
    default: {
      char* s = avm_tostring(func);
      avm_error("call: cannot bind '%s' to function!" , s);
      free(s);
      executionFinished=1;
    }
  }
}


void avm_callsaveenviroment (void) {
  avm_push_envvalue(totalActuals);
  avm_push_envvalue(pc+1);
  avm_push_envvalue(top + totalActuals +2);
  avm_push_envvalue (topsp);
}

void execute_funcenter(instruction* instr){
  avm_memcell* funcInfo = avm_getfuncinfo(pc);
  topsp = top;
  top = top - funcInfo->localSize;
}

void execute_funcexit (instruction* unused) {
  unsigned oldTop = top;
  top = avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
  pc = avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
  topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

  while (++oldTop <= top){ /*Intetionally ignoring first*/
    avm_memcellclear(&stack[oldTop]);
  }
}


void avm_calllibfunc (char* id){
  library_func_t f = avm_getlibraryfunc(id);
  if (!if) {
    avm_error("unsupported lib func 's' called!" , id);
    executionFinished=1;
  }
  else{/*Notice that enter function and exit function are called manually!*/
    topsp = top;
    totalActuals = 0;
    (*f)();
    if (!executionFinished) execute_funcexit((instruction*) 0);
  }
}

void libfunc_print(void){
  unsigned n= avm_totalactuals();
  for (unsigned i = 0; i < n; ++i) {
    char* s=avm_tostring(avm_getactual(i));
    puts(s);
    free(s);
  }
}

unsigned avm_totalactuals (void) {
  return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual (unsigned i) {
  assert(i < avm_totalactuals());
  return &stack[topsp + AVM_STACKENV_SIZE +1 +i];
}

void libfunc_typeof (void) {
    unsigned n = avm_totalactuals();
    if(n !=1) avm_error ("one argument (not %d) expected in 'typeof'!", n);
    else {
      avm_memcellclear(&retval);
      retval.type = string_m;
      retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
    }
}

void libfunc_totalarguments(){
  unsigned p_topsp = avm_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
  avm_memcellclear(&retval);
  if(!p_topsp){
    avm_error("'totalarguments' called outside a function!");
    retval.type = nil_m;
  }else{
    retval.type = number_m;
    retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
  }
}