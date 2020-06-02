#ifndef CONV_H
#define CONV_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "avm.h"

typedef double (*tonumber_func_t) (avm_memcell*);
typedef char* (*tostring_func_t)(avm_memcell*);
typedef bool (*tobool_func_t)(avm_memcell*);

extern tonumber_func_t tonumberFuncs[];
extern tostring_func_t tostringFuncs[];
extern tobool_func_t toboolFuncs[];

double number_tonumber (avm_memcell* param);
double string_tonumber (avm_memcell* param);
double bool_tonumber (avm_memcell* param);
double table_tonumber (avm_memcell* param);
double userfunc_tonumber (avm_memcell* param);
double libfunc_tonumber (avm_memcell* param);
double nil_tonumber (avm_memcell* param);
double undef_tonumber (avm_memcell* param);

char* number_tostring(avm_memcell* param);
char* string_tostring(avm_memcell* param);
char* bool_tostring(avm_memcell* param);
char* table_tostring(avm_memcell* param);
char* userfunc_tostring(avm_memcell* param);
char* libfunc_tostring(avm_memcell* param);
char* nil_tostring(avm_memcell* param);
char* undef_tostring(avm_memcell* param);

bool number_tobool (avm_memcell* m);
bool string_tobool (avm_memcell* m);
bool bool_tobool (avm_memcell* m);
bool table_tobool (avm_memcell* m);
bool userfunc_tobool (avm_memcell* m);
bool libfunc_tobool (avm_memcell* m);
bool nil_tobool (avm_memcell* m);
bool undef_tobool (avm_memcell* m);

double avm_tonumber (avm_memcell* m);
bool avm_tobool(avm_memcell* m);
char* avm_tostring(avm_memcell* m);

#endif