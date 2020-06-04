#ifndef MEM_H
#define MEM_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define AVM_TABLE_HASHSIZE    211

typedef enum avm_memcell_t {
     number_m       = 0,
     string_m       = 1,
     bool_m         = 2,
     table_m        = 3,
     userfunc_m     = 4,
     libfunc_m      = 5,
     nil_m          = 6,
     undef_m        = 7
} avm_memcell_t;

struct avm_table;
typedef struct avm_memcell {
     avm_memcell_t type;
     union {
          double              numVal;
          char*               strVal;
          bool                boolVal;
          struct avm_table*   tableVal;
          int                 funcVal;
          char*               libfuncVal;
     }data;
}avm_memcell;

typedef struct node {
     avm_memcell* cell;
     struct node* next;
}Node;

extern Node* temp_stack;

#define AVM_CONSTSIZE    1024
#define AVM_WIPEOUT(m)   memset( &(m), 0, sizeof(m))

typedef void (*memclear_func_t)(avm_memcell*);


typedef struct avm_table_bucket {
     avm_memcell              key;
     avm_memcell              value;
     struct avm_table_bucket* next;
}avm_table_bucket;


typedef struct avm_table {
     int                 refCounter;
     avm_table_bucket*   strIndexed[AVM_TABLE_HASHSIZE];
     avm_table_bucket*   numIndexed[AVM_TABLE_HASHSIZE];
     avm_table_bucket*   boolIndexed[AVM_TABLE_HASHSIZE];
     avm_table_bucket*   userFuncIndexed[AVM_TABLE_HASHSIZE];
     avm_table_bucket*   libFuncIndexed[AVM_TABLE_HASHSIZE];
     int            total;
}avm_table;

typedef struct userfunc {
     int       address;
     int       localSize;
     char*     id;
}userfunc;

typedef void (*memclear_func_t)(avm_memcell*);
extern memclear_func_t memclearFuncs[];

extern double*   numConsts;
extern int  totalNumConsts;

extern char**    stringConsts;
extern int  totalStringConsts;

extern char**    namedLibfuncs;
extern int  totalNamedLibFuncs;

extern userfunc* userFuncs;
extern int  totaluserFuncs;

void avm_memcellclear (avm_memcell* m);

void memclear_string(avm_memcell*);
void memclear_table(avm_memcell*);


double const_getnumber(int index);
char* const_getstring(int index);
char* libfuncs_getused(int index);

int consts_newstring (char* s);
int consts_newnumber (double d);
int userfuncs_newfunc (userfunc s);
int libfuncs_newused (char* s); 

void initMem();

void print_arrays();

void tempstack_push(avm_memcell* m);
avm_memcell* tempstack_pop();
void print_tempstack();

#endif