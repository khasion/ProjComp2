#ifndef RELOP_H
#define RELOP_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mem.h"
#include "avm.h"

typedef char* (*tostring_func_t)(avm_memcell*);
typedef unsigned char (*tobool_func_t)(avm_memcell*);

extern tostring_func_t tostringFuncs[];
extern tobool_func_t toboolFuncs[];

char* number_tostring(avm_memcell* param);
char* strng_tostring(avm_memcell* param);
char* bool_tostring(avm_memcell* param);
char* table_tostring(avm_memcell* param);
char* userfunc_tostring(avm_memcell* param);
char* libfunc_tostring(avm_memcell* param);
char* nil_tostring(avm_memcell* param);
char* undef_tostring(avm_memcell* param);

unsigned char number_tobool (avm_memcell* m);
unsigned char string_tobool (avm_memcell* m);
unsigned char bool_tobool (avm_memcell* m);
unsigned char table_tobool (avm_memcell* m);
unsigned char userfunc_tobool (avm_memcell* m);
unsigned char libfunc_tobool (avm_memcell* m);
unsigned char nil_tobool (avm_memcell* m);
unsigned char undef_tobool (avm_memcell* m);
unsigned char avm_tobool(avm_memcell* m);


char* avm_tostring(avm_memcell* m);
unsigned char avm_tobool(avm_memcell* m);

#endif
