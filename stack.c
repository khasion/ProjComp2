#include "stack.h"

Stack* breakstack;
Stack* contstack;
Stack* loopcounterstack;
Stack* scopeoffsetstack;

void push(Stack** s, int val) {
     Stack* new_stack;
     new_stack = (Stack*) malloc(sizeof(Stack));
     new_stack->val = val;
     new_stack->next = NULL;
     if (*s == NULL) {
          *s = new_stack;
     }
     else {
          new_stack->next = *s;
          *s = new_stack;
     }
}

int pop(Stack** s) {
     int value = 0;
     if (*s != NULL) {
          value = (*s)->val;
          *s = (*s)->next;
     }
     return value;
}

int pop_and_top(Stack** s) {
     if (*s != NULL) {
          *s = (*s)->next;
          if (*s != NULL) return (*s)->val;
     }
     return 0;
}

void print_stack(Stack** s) {
     Stack* temp;
     int i = 0;
     temp = *s;
     while (temp) {
          printf("%d, val:%d\n", i,(*s)->val);
          temp = temp->next;
          i++;
     }
}