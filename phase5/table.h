#ifndef TABLE_H
#define TABLE_H
#include "conv.h"
#include "avm.h"

extern char* typeStrings[];

void execute_newtable(instruction* instr);
void execute_tablegetelem(instruction* instr);
void execute_tablesetelem(instruction* instr);

#endif