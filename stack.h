#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
     int            val;
     struct stack*  next;
}Stack;

extern Stack* breakstack;
extern Stack* contstack;
extern Stack* loopcounterstack;
extern Stack* scopeoffsetstack;

void      push(Stack** s, int val);
int       pop(Stack** s);
int       pop_and_top(Stack** s);
void      print_stack(Stack** s);

#endif