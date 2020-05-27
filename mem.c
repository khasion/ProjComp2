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
     for (unsigned i=0; i<AVM_STACKSIZE; ++i) {
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

     for (int i = 0; i < 1024; i++) {
          stringConsts[i] = NULL;
          namedLibfuncs[i] = NULL;
     }
}

void avm_tableincrefcounter (avm_table* t) {
     ++t->refCounter;
}

void avm_tabledecrefcounter (avm_table* t) {
     assert(t->refCounter > 0);
     if (!--t->refCounter) {
          avm_tabledestroy(t);
     }
}

void avm_tablebucketsinit (avm_table_bucket** p) {
     for (unsigned i=0; i < AVM_TABLE_HASHSIZE; ++i) {
          p[i] = (avm_table_bucket*) 0;
     }
}

avm_table* avm_tablenew (void) {
     avm_table* t = (avm_table* ) malloc(sizeof(avm_table));
     AVM_WIPEOUT(*t);

     t->refCounter = t->total = 0;
     avm_tablebucketsinit(t->numIndexed);
     avm_tablebucketsinit(t->strIndexed);
     avm_tablebucketsinit(t->boolIndexed);
     avm_tablebucketsinit(t->userFuncIndexed);
     avm_tablebucketsinit(t->libFuncIndexed);

     return t;
}

void avm_memcellclear (avm_memcell* m) {
 
}

void avm_tablebucketsdestroy (avm_table_bucket** p) {
     for (unsigned i=0; i<AVM_TABLE_HASHSIZE; ++i, ++p) {
          for (avm_table_bucket* b = *p; b;) {
               avm_table_bucket* del = b;
               b = b->next;
               avm_memcellclear(&del->key);
               avm_memcellclear(&del->value);
               free(del);
          }
          p[i] = (avm_table_bucket*) 0;
     }
}

void avm_tabledestroy (avm_table* t) {
     avm_tablebucketsdestroy(t->strIndexed);
     avm_tablebucketsdestroy(t->numIndexed);
     avm_tablebucketsdestroy(t->boolIndexed);
     avm_tablebucketsdestroy(t->userFuncIndexed);
     avm_tablebucketsdestroy(t->libFuncIndexed);
     free(t);
}

unsigned consts_newstring (char* s) {
     stringConsts[totalStringConsts] = (char*) malloc(sizeof(s));
     sprintf(stringConsts[totalStringConsts++], "%s", s);
     return totalStringConsts - 1;
}

unsigned consts_newnumber (double d) {
     numConsts[totalNumConsts++] = d;
     return totalNumConsts - 1;
}

unsigned userfuncs_newfunc (Symbol* s) {
     printf("ASD\n");
     userFuncs[totaluserFuncs].address = s->taddress;
     userFuncs[totaluserFuncs].localSize = s->totalLocals;
     userFuncs[totaluserFuncs++].id = strdup(s->name);
     return totaluserFuncs - 1;
}

unsigned libfuncs_newused (char* s) {
     namedLibfuncs[totalNamedLibFuncs] = (char*) malloc(sizeof(s));
     sprintf(namedLibfuncs[totalNamedLibFuncs++], "%s", s);
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

retList* append(retList* returnList, unsigned label) {
     retList* new_ret;
     new_ret = (retList*) malloc(sizeof(retList));
     new_ret->retVal = label;
     new_ret->next = returnList;
     returnList = new_ret;
     return returnList;
}