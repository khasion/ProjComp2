#include "mem.h"

avm_memcell stack[AVM_STACKSIZE];
unsigned top = 4095;
unsigned topsp = 4095;

double*   numConsts;
char**    stringConsts;
char**    namedLibfuncs;
userfunc* userFuncs;

unsigned totalNumConsts = 0;
unsigned totalStringConsts = 0;
unsigned totaluserFuncs = 0;
unsigned totalNamedLibFuncs = 0;

memclear_func_t (memclearFuncs[]) = {
     0,
     memclear_string,
     0,
     memclear_table,
     0,
     0,
     0,
     0
};

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

void memclear_string(avm_memcell* m){
     assert (m->data.strVal);
     free(m->data.strVal);
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

void memclear_table (avm_memcell* m){
     assert (m->data.tableVal);
     avm_tabledecrefcounter(m->data.tableVal);
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

char* const_getstring(unsigned val) {
     return stringConsts[val];
}

char* libfuncs_getused(unsigned val) {
     return namedLibfuncs[val];
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

unsigned userfuncs_newfunc (userfunc s) {
     userFuncs[totaluserFuncs++] = s;
     return totaluserFuncs - 1;
}

unsigned libfuncs_newused (char* s) {
     namedLibfuncs[totalNamedLibFuncs] = (char*) malloc(sizeof(s));
     sprintf(namedLibfuncs[totalNamedLibFuncs++], "%s", s);
     return totalNamedLibFuncs - 1;
}

void print_arrays() {
     for (int i = 0; i < totalStringConsts; i++) {
          printf("%d |%s\n", i, stringConsts[i]);
     }

     for (int i = 0; i < totalNumConsts ; i++){
          printf("%d |%f\n", i, numConsts[i]);
     }

    for (int i = 0; i < totalNamedLibFuncs; i++) {
         printf("%d |%s\n", i, namedLibfuncs[i]);
    } 

    for(int i = 0; i < totaluserFuncs; i++){
         printf("%d |%s\n",i, userFuncs[i].id);
    }
}