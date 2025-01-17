#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack* Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, int i);
int pop(Stack s);

void printStack(Stack s, char* n);

#endif