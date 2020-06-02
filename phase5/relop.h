#ifndef RELOP_H
#define RELOP_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "conv.h"
#include "avm.h"

#define execute_jeq execute_relop
#define execute_jne execute_relop
#define execute_jle execute_relop
#define execute_jge execute_relop
#define execute_jlt execute_relop
#define execute_jgt execute_relop

typedef bool (*cmp_func_t)(avm_memcell*, avm_memcell*);

extern cmp_func_t cmpFuncs[];


bool avm_eq(avm_memcell* arg1, avm_memcell* arg2);
bool avm_neq(avm_memcell* arg1, avm_memcell* arg2);
bool avm_lt(avm_memcell* arg1, avm_memcell* arg2);
bool avm_gt(avm_memcell* arg1, avm_memcell* arg2);
bool avm_gte(avm_memcell* arg1, avm_memcell* arg2);
bool avm_lte(avm_memcell* arg1, avm_memcell* arg2);

#endif
