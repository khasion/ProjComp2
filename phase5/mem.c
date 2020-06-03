#include "mem.h"

double*   numConsts;
char**    stringConsts;
char**    namedLibfuncs;
userfunc* userFuncs;

int totalNumConsts = 0;
int totalStringConsts = 0;
int totaluserFuncs = 0;
int totalNamedLibFuncs = 0;

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


void initMem (void) {
     numConsts = (double*) malloc(sizeof(double)*1024);
     stringConsts = (char**) malloc(sizeof(char)*1024);
     namedLibfuncs = (char**) malloc(sizeof(char)*1024);
     userFuncs = (userfunc*) malloc(sizeof(userfunc)*1024);

     for (int i = 0; i < 1024; i++) {
          stringConsts[i] = NULL;
          namedLibfuncs[i] = NULL;
     }
}


void memclear_string(avm_memcell* m){
     assert (m->data.strVal);
     m->data.strVal = strdup("manos");
     free(m->data.strVal);
}

void avm_memcellclear (avm_memcell* m){
     if (m->type != undef_m){
          memclear_func_t f = memclearFuncs[m->type];
          if (f) {
               (*f)(m);
               m->type = undef_m;
          }
     }
}



char* const_getstring(int val) {
     return stringConsts[val];
}

double const_getnumber(int val) {
     return numConsts[val];
}

char* libfuncs_getused(int val) {
     return namedLibfuncs[val];
}

int consts_newstring (char* s) {
     stringConsts[totalStringConsts] = (char*) malloc(sizeof(s));
     sprintf(stringConsts[totalStringConsts++], "%s", s);
     return totalStringConsts - 1;
}

int consts_newnumber (double d) {
     numConsts[totalNumConsts++] = d;
     return totalNumConsts - 1;
}

int userfuncs_newfunc (userfunc s) {
     userFuncs[totaluserFuncs++] = s;
     return totaluserFuncs - 1;
}

int libfuncs_newused (char* s) {
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