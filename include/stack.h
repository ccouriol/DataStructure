#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

#define STACK_MAX_SIZE 100

typedef struct
{
    float data[STACK_MAX_SIZE];
    int index;
} Stack;

#endif /* STACK_H */

void init_stack(Stack *s);
void push_stack(Stack *s, float value);
float pop_stack(Stack *s);
bool is_stack_empty(Stack *s);
float peek_stack(Stack *s); // aka top or front
void dup(Stack *s);
void swap(Stack *s);
void clear_stack(Stack *s);
