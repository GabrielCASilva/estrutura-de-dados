#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *itens;
  int len;
  int qtd;
} Stack;

Stack* stack_create(int len); // creates a new stack
Stack* stack_copy(Stack *stack); // copies the stack into a new stack

int stack_get_item(Stack *stack, int index); // returns the item at the index
int stack_is_full(Stack *stack); // returns 0 or 1 if is full or not
int stack_is_empty(Stack *stack); // returns 0 or 1 if is empty or not
int stack_is_exist(Stack *stack); // returns 0 or 1 if the stack exists or not

void stack_resize(Stack *stack); // resizes the stack with double the size
void stack_push(Stack *stack, int item); // pushes an item into the stack
int stack_pop(Stack *stack); // returns and pops the top item from the stack
int stack_peek(Stack *stack); // returns the top item from the stack without removing it

// TODO: implement the following functions
void stack_insert_element_at(Stack *stack, int index, int item); // inserts an item at the index
int stack_remove_element_at(Stack *stack, int index); // removes an item at the index
int stack_search(Stack *stack, int item); // returns the index of the item
void stack_clear(Stack *stack); // clears the stack
void stack_destroy(Stack *stack); // destroys the stack
void stack_print(Stack *stack); // prints the stack
void stack_trim(Stack *stack); // trims the stack

int main(void) {
  printf("Hello from C!\n");
  return 0;
}

Stack* stack_create(int len) {
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  stack->itens = (int*)malloc(len * sizeof(int));
  stack->qtd = 0;
  stack->len = len;
  return stack;
}

int stack_get_item(Stack *stack, int index) {
  if(!stack_is_exist(stack)) {
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
  if(!stack_is_exist(stack)) {
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
  if(!stack_is_exist(stack)) {
    printf("Stack does not exist\n");
    exit(1);
  }

  if(stack_is_empty(stack)) {
    printf("Stack is already empty\n");
    return;
  }

  stack->qtd--;
  return stack->itens[stack->qtd];
}

int stack_peek(Stack *stack) {
  if(!stack_is_exist(stack)) {
    printf("Stack does not exist\n");
    exit(1);
  }

  if(stack_is_empty(stack)) {
    printf("Stack is empty\n");
    return;
  }

  return stack->itens[stack->qtd - 1];
}

Stack* stack_copy(Stack *stack) {
  if(!stack_is_exist(stack)) {
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

int stack_is_full(Stack *stack) {
  return stack->qtd == stack->len;
}

int stack_is_empty(Stack *stack) {
  return stack->qtd == 0;
}

void stack_resize(Stack *stack) {
  if(!stack_is_exist(stack)) {
    printf("Stack does not exist\n");
    exit(1);
  }
  // create a new array with double the size
  int *new_itens = (int*)malloc(stack->len * 2 * sizeof(int));
  for (int i = 0; i < stack->len; i++) {
    new_itens[i] = stack->itens[i];
  }

  free(stack->itens); // free the old itens

  // point to the new itens
  stack->itens = new_itens;
  stack->len *= 2;
}

int stack_is_exist(Stack *stack) {
  return stack != NULL;
}