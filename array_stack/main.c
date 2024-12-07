#include "stack.h"

int main(void) {
  Stack *stack = stack_create(4);

  stack_print(stack);
  
  stack_push(stack, 1);
  stack_push(stack, 2);
  stack_push(stack, 3);
  stack_push(stack, 4);
  stack_push(stack, 5);
  stack_push(stack, 6);

  stack_print(stack);

  return 0;
}