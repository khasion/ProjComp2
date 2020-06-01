#include "functions.h"
#include "table.h"

library_func_t libfunc_array[] = {
     libfunc_print,
     libfunc_typeof,
     libfunc_totalarguments
};

unsigned top = 4095;
unsigned topsp = 4095;
avm_memcell stack[AVM_STACKSIZE];

void avm_initstack (unsigned n) {
     for (unsigned i=0; i < AVM_STACKSIZE; ++i) {
          AVM_WIPEOUT(stack[i]);
          stack[i].type = undef_m;
     }
     for (int i = 0; i < codeSize; i++) {
          if ( code[i].result.type == global_a) {
               stack[top--] = *avm_translate_operand(&code[i].result, (avm_memcell*) 0);
          }
     }
     topsp = AVM_STACKSIZE - n;
}

void avm_callsaveenviroment (void) {
     avm_push_envvalue(totalActuals);
     avm_push_envvalue(pc+1);
     avm_push_envvalue(top + totalActuals +2);
     avm_push_envvalue (topsp);
}

void execute_funcenter(instruction* instr){
     userfunc* funcInfo = avm_getfuncinfo(pc);
     topsp = top;
     top = top - funcInfo->localSize;
}

void execute_pusharg(instruction* instr){
     avm_memcell* arg = avm_translate_operand(&instr->arg1, &ax);
     assert(arg);
     avm_assign(&stack[top], arg);
     ++totalActuals; 
     avm_dec_top();
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

library_func_t avm_getlibraryfunc(char* id) {

     if ( strcmp(id, "print") == 0) {
          return libfunc_array[0];
     }
     else if (strcmp(id, "typeof") == 0){
          return libfunc_array[1];
     } 
     else if (strcmp(id, "totalarguments") == 0) {
          return libfunc_array[2];
     }
     return NULL;
}

void avm_calllibfunc (char* id){
     library_func_t f = avm_getlibraryfunc(id);
     if (!f) {
          avm_error("unsupported lib func 's' called!" , id);
          executionFinished = 1;
     }
     else {/*Notice that enter function and exit function are called manually!*/
          topsp = top;
          totalActuals = 0;
          (*f)();
          if (!executionFinished) execute_funcexit((instruction*) 0);
     }
}

void libfunc_print(void) {
     unsigned n = avm_totalactuals();
     for (unsigned i = 0; i < n; ++i) {
          char* s = avm_tostring(avm_getactual(i));
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
     if(n !=1) avm_error ("one argument (not %d) expected in 'typeof'!", &n);
     else {
          avm_memcellclear(&retval);
          retval.type = string_m;
          retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
     }
}

void libfunc_totalarguments(){
     unsigned p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
     avm_memcellclear(&retval);
     if(!p_topsp) {
          avm_error("'totalarguments' called outside a function!", "");
          retval.type = nil_m;
     }
     else {
          retval.type = number_m;
          retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
     }
}

void avm_dec_top (void){
    // printf("top\n");
     if(!top){/*stack overflow*/
          avm_error("stack overflow", "");
          executionFinished = 1;
     }
     else --top;
}

void avm_push_envvalue (unsigned val) {
     //printf("PUSH\n");
     stack[top].type = number_m;
     stack[top].data.numVal = val;
     avm_dec_top();
}

unsigned avm_get_envvalue (unsigned i ){
     assert(stack[i].type == number_m);
     unsigned  val = (unsigned) stack[i].data.numVal;
     //printf("GET %d\n", val);
     assert((stack[i].data.numVal) == ((double) val));
     return val;
}

userfunc* avm_getfuncinfo (unsigned addr) {
     userfunc* temp;
     temp = (userfunc*) malloc(sizeof(userfunc));
     temp->address = pc;
     temp->id = strdup(userFuncs[code[addr].result.val].id);
     temp->localSize = userFuncs[code[addr].result.val].localSize;
     return temp;
}

void execute_call (instruction* instr) {
     avm_memcell* func = avm_translate_operand(&instr->arg1 , &ax);
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
