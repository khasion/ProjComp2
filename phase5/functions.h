#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void execute_call(instruction* instr);
void execute_pusharg(instruction* instr);
void execute_funcenter(instruction* instr);
void execute_funcexit(instruction* instr);

#endif