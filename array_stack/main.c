#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *itens;
  int len;
} Stack;

Stack* stack_create(int len);
int stack_get_item(Stack *stack, int index);
Stack* stack_copy(Stack *stack);

int main(void) {
  printf("Hello from C!\n");
  return 0;
}

Stack* stack_create(int len) {
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  stack->itens = (int*)malloc(len * sizeof(int));
  stack->len = len;
  return stack;
}

int stack_get_item(Stack *stack, int index) {
  if (index < 0 || index >= stack->len) {
    printf("Index out of bounds\n");
    exit(1);
  }

  return stack->itens[index];
}

Stack* stack_copy(Stack *stack) {
  Stack *new = stack_create(stack->len);
  for (int i = 0; i < stack->len; i++) {
    new->itens[i] = stack->itens[i];
  }

  return new;
}