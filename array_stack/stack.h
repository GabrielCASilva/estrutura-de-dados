#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *itens;
  int len;
  int qtd;
} Stack;

Stack *stack_create(int len);    // creates a new stack
Stack *stack_copy(Stack *stack); // copies the stack into a new stack

int stack_get_item(Stack *stack, int index); // returns the item at the index
int stack_is_full(Stack *stack);             // returns 0 or 1 if is full or not
int stack_is_empty(Stack *stack); // returns 0 or 1 if is empty or not
int stack_is_not_null(
    Stack *stack); // returns 0 or 1 if the stack exists or not

void stack_resize(Stack *stack); // resizes the stack with double the size
void stack_push(Stack *stack, int item); // pushes an item into the stack
int stack_pop(Stack *stack); // returns and pops the top item from the stack
int stack_peek(
    Stack *stack); // returns the top item from the stack without removing it

// TODO: implement the following functions
int stack_search(Stack *stack, int item); // returns the index of the item
void stack_clear(Stack *stack);           // clears the stack
void stack_destroy(Stack *stack);         // destroys the stack
void stack_print(Stack *stack);           // prints the stack
void stack_trim(Stack *stack);            // trims the stack

#endif