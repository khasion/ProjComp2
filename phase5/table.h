#ifndef TABLE_H
#define TABLE_H
#include "conv.h"
#include "avm.h"

extern char* typeStrings[];

#define AVM_TABLE_HASHSIZE    211

typedef avm_table_bucket* (*addTable_func_t)(avm_memcell*, avm_memcell*, avm_memcell*);
typedef avm_memcell* (*getTable_func_t)(avm_memcell*, avm_memcell*);

struct avm_table*   avm_tablenew(void);
void                avm_tabledestroy (struct avm_table* t);


void  avm_tablesetelem (avm_memcell* t, avm_memcell* index, avm_memcell* content);
avm_memcell* avm_tablegetelem(avm_table* t, avm_memcell* index);

void execute_newtable(instruction* instr);
void execute_tablegetelem(instruction* instr);
void execute_tablesetelem(instruction* instr);

void avm_tableincrefcounter (avm_table* t);
void avm_tabledecrefcounter (avm_table* t);

avm_table_bucket* add_indexedNum(avm_memcell* t, avm_memcell* index, avm_memcell* content);
avm_table_bucket* add_indexedString(avm_memcell* t, avm_memcell* index, avm_memcell* content);
avm_table_bucket* add_indexedFunc(avm_memcell* t, avm_memcell* index, avm_memcell* content);
avm_table_bucket* add_indexedlibFunc(avm_memcell* t, avm_memcell* index, avm_memcell* content);
avm_table_bucket* add_indexedBool(avm_memcell* t, avm_memcell* index, avm_memcell* content);


#endif