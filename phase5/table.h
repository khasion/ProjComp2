#ifndef TABLE_H
#define TABLE_H
#include "avm.h"
#include "mem.h"

void execute_newtable(instruction* instr);
void execute_tablegetelem(instruction* instr);
void execute_tablesetelem(instruction* instr);

#endif