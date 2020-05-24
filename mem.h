#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "table.h"
#include "quads.h"

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
          unsigned char       boolVal;
          struct avm_table*   table_val;
          unsigned            funcVal;
          char*               libfuncVal;
     } data;
} avm_memcell;

#define AVM_CONSTSIZE    1024
#define AVM_STACKSIZE    4096
#define AVM_WIPEOUT(m)   memset( &(m), 0, sizeof(m))

extern avm_memcell stack[AVM_STACKSIZE];

struct avm_table*   avm_tablenew(void);
void                avm_tabledestroy (struct avm_table* t);
avm_memcell*        avm_tablegetelem (avm_memcell* key);
void                avm_tablesetelem (avm_memcell* key, avm_memcell* value);

#define AVM_TABLE_HASHSIZE    211

typedef struct avm_table_bucket {
     avm_memcell              key;
     avm_memcell              value;
     struct avm_table_bucket* next;
}avm_table_bucket;

typedef struct avm_table {
     unsigned            refCounter;
     avm_table_bucket*   strIndexed[AVM_TABLE_HASHSIZE];
     avm_table_bucket*   numIndexed[AVM_TABLE_HASHSIZE];
     avm_table_bucket*   boolIndexed[AVM_TABLE_HASHSIZE];
     avm_table_bucket*   userFuncIndexed[AVM_TABLE_HASHSIZE];
     avm_table_bucket*   libFuncIndexed[AVM_TABLE_HASHSIZE];
     unsigned            total;
}avm_table;

typedef struct userfunc {
     unsigned  address;
     unsigned  localSize;
     char*     id;
}userfunc;

extern double*   numConsts;
extern unsigned  totalNumConsts;

extern char**    stringConsts;
extern unsigned  totalStringConsts;

extern char**    namedLibfuncs;
extern unsigned  totalNamedLibFuncs;

extern userfunc* userFuncs;
extern unsigned  totaluserFuncs;