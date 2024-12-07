#include "stack.h"

Stack *stack_create(int len) {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->itens = (int *)malloc(len * sizeof(int));
  stack->qtd = 0;
  stack->len = len;
  return stack;
}

int stack_get_item(Stack *stack, int index) {
  if (!stack_is_not_null(stack)) {
    printf("Stack does not exist\n");
    exit(1);
  }

  if (index < 0 || index >= stack->len) {
    printf("Index out of bounds\n");
    exit(1);
  }

  return stack->itens[index];
}

void stack_push(Stack *stack, int item) {
  if (!stack_is_not_null(stack)) {
    printf("Stack does not exist\n");
    exit(1);
  }

  if (stack_is_full(stack)) {
    stack_resize(stack);
  }

  stack->itens[stack->qtd] = item;
  stack->qtd++;
}

int stack_pop(Stack *stack) {
  if (!stack_is_not_null(stack)) {
    printf("Stack does not exist\n");
    exit(1);
  }

  if (stack_is_empty(stack)) {
    printf("Stack is already empty\n");
    return -1;
  }

  stack->qtd--;
  return stack->itens[stack->qtd];
}

int stack_peek(Stack *stack) {
  if (!stack_is_not_null(stack)) {
    printf("Stack does not exist\n");
    exit(1);
  }

  if (stack_is_empty(stack)) {
    printf("Stack is empty\n");
    return -1;
  }

  return stack->itens[stack->qtd - 1];
}

Stack *stack_copy(Stack *stack) {
  if (!stack_is_not_null(stack)) {
    printf("Stack does not exist\n");
    exit(1);
  }

  Stack *new = stack_create(stack->len);
  for (int i = 0; i < stack->len; i++) {
    new->itens[i] = stack->itens[i];
  }

  new->qtd = stack->qtd;
  return new;
}

int stack_is_full(Stack *stack) { return stack->qtd == stack->len; }

int stack_is_empty(Stack *stack) { return stack->qtd == 0; }

void stack_resize(Stack *stack) {
  if (!stack_is_not_null(stack)) {
    printf("Stack does not exist\n");
    exit(1);
  }
  // create a new array with double the size
  int *new_itens = (int *)malloc(stack->len * 2 * sizeof(int));
  for (int i = 0; i < stack->len; i++) {
    new_itens[i] = stack->itens[i];
  }

  free(stack->itens); // free the old itens

  // point to the new itens
  stack->itens = new_itens;
  stack->len *= 2;
}

int stack_is_not_null(Stack *stack) { return stack != NULL; }
