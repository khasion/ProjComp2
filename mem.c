#include "mem.h"

avm_memcell stack[AVM_STACKSIZE];
unsigned top = 4095;

double*   numConsts;
unsigned  totalNumConsts;

char**    stringConsts;
unsigned  totalStringConsts;

char**    namedLibfuncs;
unsigned  totalNamedLibFuncs;

userfunc* userFuncs;
unsigned  totaluserFuncs;

static void avm_initstack (void) {
     unsigned i;
     for (i=0; i<AVM_STACKSIZE; ++i) {
          AVM_WIPEOUT(stack[i]);
          stack[i].type = undef_m;
     }
}

void initMem (void) {
     avm_initstack();
     numConsts = (double*) malloc(sizeof(double)*1024);
     stringConsts = (char**) malloc(sizeof(char)*1024);
     namedLibfuncs = (char**) malloc(sizeof(char)*1024);
     userFuncs = (userfunc*) malloc(sizeof(userfunc)*1024);
}

unsigned consts_newstring (char* s) {
     stringConsts[totalStringConsts++] = s;
     return totalStringConsts - 1;
}

unsigned consts_newnumber (double d) {
     numConsts[totalNumConsts++] = d;
     return totalNumConsts - 1;
}

unsigned userfuncs_newfunc (Symbol* s) {
     userFuncs[totaluserFuncs].address = s->taddress;
     userFuncs[totaluserFuncs].localSize = s->totalLocals;
     userFuncs[totaluserFuncs++].id = s->name;
     return totaluserFuncs - 1;
}

unsigned libfuncs_newused (char* s) {
     namedLibfuncs[totalNamedLibFuncs++] = s;
     return totalNamedLibFuncs - 1;
}

void stack_push(avm_memcell* stack, Symbol* sym) {
     stack[top].type = userfunc_m;
     stack[top--].data.symVal = sym;
}

Symbol* stack_top(avm_memcell* stack) {
     return stack[top+1].data.symVal;
}

Symbol* stack_pop(avm_memcell* stack) {
     Symbol* data;
     data = stack[top+1].data.symVal;
     top++;
     return data;
}

