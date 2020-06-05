#include "functions.h"
#include "table.h"

library_func_t libfunc_array[] = {
     libfunc_print,
     libfunc_typeof,
     libfunc_totalarguments,
     libfunc_objectmemberkeys,
     libfunc_objectotalmembers,
     libfunc_objectcopy,
     libfunc_argument,
     libfunc_strtonum,
     libfunc_sqrt,
     libfunc_cos,
     libfunc_sin
};

int top = 4096;
int topsp = 4095;
int savedtop = 0;
avm_memcell stack[AVM_STACKSIZE];

void avm_initstack (int n) {
     for (int i=0; i < AVM_STACKSIZE; i++) {
          AVM_WIPEOUT(stack[i]);
          stack[i].type = undef_m;
     }
     top = topsp = AVM_STACKSIZE - n;
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

void avm_pusharg (instruction* instr, int n) {
     avm_memcell* arg;
     if (n==1) {
          while ( (arg = tempstack_pop()) ) {
               avm_assign(&stack[savedtop], arg);
               savedtop--;
          }
     }
     else {
          arg = avm_translate_operand(&instr->arg1, &ax);
          assert(arg);
          tempstack_push(arg);
          if (!savedtop) savedtop = top;
          avm_dec_top();
          ++totalActuals;
     }
}

void execute_pusharg(instruction* instr){
     avm_pusharg(instr, 0);
}

void execute_funcexit (instruction* unused) {
     int oldTop = top;
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
     else if (strcmp(id, "objectmemberkey") == 0) {
          return libfunc_array[3];
     }
     else if (strcmp(id, "objectotalmembers") == 0) {
          return libfunc_array[4];
     }
     else if (strcmp(id, "objectcopy") == 0) {
          return libfunc_array[5];
     }
     else if (strcmp(id, "argument") == 0) {
          return libfunc_array[6];
     }
     else if (strcmp(id, "strtonum") == 0) {
          return libfunc_array[7];
     }
     else if (strcmp(id, "sqrt") == 0) {
          return libfunc_array[8];
     }
     else if (strcmp(id, "cos") == 0) {
          return libfunc_array[9];
     }
     else if (strcmp(id, "sin") == 0) {
          return libfunc_array[10];
     }else{
          return NULL;
     }
     
}

void avm_calllibfunc (char* id) {  
     library_func_t f = avm_getlibraryfunc(id);
     if (!f) {
          avm_error("unsupported lib func 's' called!" , id);
          executionFinished = 1;
     }
     else {/*Notice that enter function and exit function are called manually!*/
          topsp = top;
          (*f)();
          if (!executionFinished) execute_funcexit((instruction*) 0);
     }
}

void libfunc_print(void) {
     unsigned n = avm_totalactuals();
     for (unsigned i = 0; i < n; ++i) {
          char* s = strdup(avm_tostring(avm_getactual(i)) );
          fputs(s, stdout);
          free(s);
     }
}

int avm_totalactuals (void) {
  return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual (int i) {
  assert(i < avm_totalactuals());
  return &stack[topsp + AVM_STACKENV_SIZE +1 +i];
}

void libfunc_typeof (void) {
     int n = avm_totalactuals();
     if(n !=1) avm_error ("one argument (not %d) expected in 'typeof'!", &n);
     else {
          avm_memcellclear(&retval);
          retval.type = string_m;
          retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
     }
}

void libfunc_totalarguments(){
     int p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
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

void libfunc_objectmemberkeys(){}
void libfunc_objectotalmembers(void){
     int n = avm_totalactuals();
     if(n !=1) avm_error ("one argument (not %d) expected in 'objectotalmembers'!", &n);
     else {
          avm_memcellclear(&retval);
          retval.type = number_m;
          retval.data.numVal = avm_getactual(0)->data.tableVal->total;
     }

}
void libfunc_objectcopy(void){
     int n = avm_totalactuals();
     if(n !=1) avm_error ("one argument (not %d) expected in 'objectcopy'!", &n);
     else {
          avm_memcellclear(&retval);
          memcpy(&retval, avm_getactual(0), sizeof(avm_memcell));
     }
}
void libfunc_argument(void){
}
void libfunc_strtonum(void){
     int n = avm_totalactuals();
     if(n !=1) avm_error ("one argument (not %d) expected in 'strtonum'!", &n);
     else {
          avm_memcellclear(&retval);
          retval.type = string_m;
          retval.data.numVal = string_tonumber(avm_getactual(0));
     }
}
void libfunc_sqrt(void) {
     int n = avm_totalactuals();
     if(n !=1) avm_error ("one argument (not %d) expected in 'sqrt'!", &n);
     else {
          avm_memcellclear(&retval);
          retval.type = number_m;
          retval.data.numVal = sqrt(avm_getactual(0)->data.numVal);
     }
}
void libfunc_cos(void) {
     int n = avm_totalactuals();
     if(n !=1) avm_error ("one argument (not %d) expected in 'cos'!", &n);
     else {
          avm_memcellclear(&retval);
          retval.type = number_m;
          retval.data.numVal = cos(avm_getactual(0)->data.numVal);
     }
}
void libfunc_sin(void){
     int n = avm_totalactuals();
     if(n !=1) avm_error ("one argument (not %d) expected in 'sin'!", &n);
     else {
          avm_memcellclear(&retval);
          retval.type = number_m;
          retval.data.numVal = sin(avm_getactual(0)->data.numVal);
     }
}

void avm_dec_top (void){
    // printf("top\n");
     if(!top){ /*stack overflow*/
          avm_error("stack overflow", "");
          executionFinished = 1;
     }
     else --top;
}

void avm_push_envvalue (int val) {
     //printf("PUSH\n");
     stack[top].type = number_m;
     stack[top].data.numVal = val;
     avm_dec_top();
}

int avm_get_envvalue (int i ){
     assert(stack[i].type == number_m);
     int  val = (int) stack[i].data.numVal;
     //printf("GET %d\n", val);
     assert((stack[i].data.numVal) == ((double) val));
     return val;
}

userfunc* avm_getfuncinfo (int addr) {
     userfunc* temp;
     temp = (userfunc*) malloc(sizeof(userfunc));
     temp->address = pc;
     temp->id = strdup(userFuncs[code[addr].result.val].id);
     temp->localSize = userFuncs[code[addr].result.val].localSize;
     return temp;
}

void execute_call (instruction* instr) {
     avm_memcell* func = avm_translate_operand(&instr->arg1 , &ax);
     avm_pusharg(NULL, 1);
     assert(func);
     avm_callsaveenviroment();
     switch (func->type) {
          case userfunc_m: {
               pc=func->data.funcVal;
               assert(pc < AVM_ENDING_PC);
               assert(code[pc].opcode == funcenter_v);
               break;
          }
          case string_m: avm_calllibfunc(func->data.strVal); break;
          case libfunc_m: avm_calllibfunc(func->data.libfuncVal);break;
          default: {
               char* s = avm_tostring(func);
               avm_error("call: cannot bind '%s' to function!" , s);
               free(s);
               executionFinished=1;
          }
     }
     totalActuals = 0;
     savedtop = 0;
}
