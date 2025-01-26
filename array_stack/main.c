#include "stack.h"
#include <stdio.h>

int main(void) {
  Stack *stack = stack_create(4);

  stack_print(stack);

  stack_push(stack, 1);
  stack_push(stack, 2);
  stack_push(stack, 3);
  stack_push(stack, 4);
  stack_push(stack, 5);
  stack_push(stack, 6);

  printf("Pilha: ");
  stack_print(stack);

  Stack *stack_cp = stack_copy(stack);
  stack_pop(stack);
  stack_pop(stack);

  printf("Pilha depois do pop: ");
  stack_print(stack);

  printf("Copia da stack antes dos 2 pops: ");
  stack_print(stack_cp);

  return 0;
}
