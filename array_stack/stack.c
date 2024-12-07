#include "stack.h"

Stack *stack_create(int len) {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->itens = (int *)malloc(len * sizeof(int));
  stack->qtd = 0;
  stack->len = len;
  return stack;
}

void stack_push(Stack *stack, int item) {
  if (stack == NULL) {
    printf("Stack does not exist\n");
    return;
  }

  if (stack->qtd == stack->len) {
    stack_resize(stack);
  }

  stack->itens[stack->qtd] = item;
  stack->qtd++;
}

int stack_pop(Stack *stack) {
  if (stack == NULL) {
    printf("Stack does not exist\n");
    return -1;
  }

  if (stack->qtd == 0) {
    printf("Stack is empty\n");
    return -1;
  }

  stack->qtd--;
  return stack->itens[stack->qtd];
}

int stack_peek(Stack *stack) {
  if (stack == NULL) {
    printf("Stack does not exist\n");
    return -1;
  }

  if (stack->qtd == 0) {
    printf("Stack is empty\n");
    return -1;
  }

  return stack->itens[stack->qtd - 1];
}

Stack *stack_copy(Stack *stack) {
  if (stack == NULL) {
    printf("Stack does not exist\n");
    return NULL;
  }

  Stack *new = stack_create(stack->len);
  for (int i = 0; i < stack->len; i++) {
    new->itens[i] = stack->itens[i];
  }

  new->qtd = stack->qtd;
  return new;
}

void stack_resize(Stack *stack) {
  if (stack == NULL) {
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

void stack_print(Stack *stack) {
  if (stack == NULL) {
    printf("Stack does not exist\n");
    exit(1);
  }

  if (stack->qtd == 0) {
    printf("Stack is empty\n");
    return;
  }

  for (int i = 0; i < stack->qtd; i++) {
    printf("%d ", stack->itens[i]);
  }
  printf("\n");
}

int stack_search(Stack *stack, int item) {
  if (stack == NULL) {
    printf("Stack does not exist\n");
    return -1;
  }

  if (stack->qtd == 0) {
    printf("Stack is empty\n");
    return -1;
  }

  for (int i = 0; i < stack->qtd; i++) {
    if (stack->itens[i] == item) {
      return i;
    }
  }

  return -1;
}

void stack_trim(Stack *stack) {
  if (stack == NULL || stack->itens == NULL) {
    printf("Stack does not exist\n");
    return;
  }

  int size = stack->len - stack->qtd;
  if ( size == 0 || size < 5 ) {
    printf("Stack is already trimmed or the size difference is not too big\n");
    return;
  }

  //// stack->itens = (int*)realloc(stack->itens, stack->qtd * sizeof(int));
  int *new_itens = (int *)malloc(stack->qtd * sizeof(int));
  for (int i = 0; i < stack->qtd; i++) {
    new_itens[i] = stack->itens[i];
  }

  free(stack->itens);
  stack->itens = new_itens;
  stack->len = stack->qtd;
}

void stack_destroy(Stack *stack) {
  if (stack == NULL || stack->itens == NULL) {
    printf("Stack does not exist\n");
    return;
  }

  free(stack->itens);
  stack->itens = NULL;

  free(stack);
  stack = NULL;
}

void stack_clear(Stack *stack) {
  if (stack == NULL || stack->itens == NULL) {
    return;
  }

  free(stack->itens);
  stack->qtd = 0; 
}
