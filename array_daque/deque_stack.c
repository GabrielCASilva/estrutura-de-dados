#include "deque_stack.h"

Deque_stack *deque_stack_create(int len) {
  Deque_stack *deque = (Deque_stack *)malloc(sizeof(Deque_stack));
  deque->front = stack_create(len / 2);
  deque->back = stack_create(len / 2);
  return deque;
}

int deque_stack_len(Deque_stack *deque) {
  return deque->front->len + deque->back->len;
}

void deque_stack_push_front(Deque_stack *deque, int item) {
  stack_push(deque->front, item);
}

int deque_stack_pop_front(Deque_stack *deque) {
  return stack_pop(deque->front);
}

void deque_stack_push_back(Deque_stack *deque, int item) {
  stack_push(deque->back, item);
}

int deque_stack_pop_back(Deque_stack *deque) { return stack_pop(deque->back); }

void deque_stack_balance(Deque_stack *deque) {
  int len = deque_stack_len(deque);
  int mid = len / 2;
  int f_qtd = deque->front->qtd;
  int b_qtd = deque->back->qtd;
  if (2 * f_qtd < b_qtd) {
    Stack *s1 = stack_create(mid);
    Stack *s2 = stack_create(mid);

    for (int i = 0; i < (b_qtd / 2 + 1); i++)
      stack_push(s1, deque->back->itens[i]);

    for (int i = 0; i < f_qtd; i++)
      stack_push(s1, deque->front->itens[i]);

    for (int i = b_qtd / 2 + 1; i <= b_qtd; i++)
      stack_push(s2, deque->back->itens[i]);

    deque_stack_free(deque);
    deque->front = s1;
    deque->back = s2;

  } else if (2 * f_qtd > b_qtd) {
    Stack *s1 = stack_create(mid);
    Stack *s2 = stack_create(mid);

    for (int i = 0; i < (f_qtd / 2 + 1); i++)
      stack_push(s2, deque->front->itens[i]);

    for (int i = 0; i < b_qtd; i++)
      stack_push(s2, deque->back->itens[i]);

    for (int i = f_qtd / 2 + 1; i <= f_qtd; i++)
      stack_push(s1, deque->front->itens[i]);

    deque_stack_free(deque);
    deque->front = s1;
    deque->back = s2;
  }
}

int deque_stack_free(Deque_stack *deque) {
  stack_destroy(deque->front);
  stack_destroy(deque->back);
  return 1;
}
int deque_stack_destroy(Deque_stack *deque) {
  stack_destroy(deque->front);
  stack_destroy(deque->front);

  free(deque);
  return 1;
}

///
int deque_stack_get(Deque_stack *deque, int index) {
  if (index < deque->front->len) {
    int i = deque->front->len - index - 1;
    return deque->front->itens[i];
  }

  int i = index - deque->back->len - 1;
  return deque->back->itens[i];
}
