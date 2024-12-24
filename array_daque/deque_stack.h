#ifndef DEQUE_STACK_H
#define DEQUE_STACK_H

#include "../array_stack/stack.h"

struct deque_stack {
  Stack *front;
  Stack *back;
};

typedef struct deque_stack Deque_stack;

Deque_stack *deque_stack_create(int len);
int deque_stack_len(Deque_stack *deque);

void deque_stack_push_front(Deque_stack *deque, int item);
int deque_stack_pop_front(Deque_stack *deque);
void deque_stack_push_back(Deque_stack *deque, int item);
int deque_stack_pop_back(Deque_stack *deque);

void deque_stack_balance(Deque_stack *deque);
int deque_stack_free(Deque_stack *deque);
int deque_stack_destroy(Deque_stack *deque);

int deque_stack_get(Deque_stack *deque, int index);
#endif // DEQUE_STACK_H
