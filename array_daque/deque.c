#include "deque.h"

Deque* deque_create(int len) {
  Deque* deque = (Deque*)malloc(sizeof(Deque));
  
  deque->arr = (int*)malloc(len * sizeof(int));
  deque->start = 0;
  deque->end = 0;
  deque->qtd = 0;
  deque->len = len;

  return deque;
}

int deque_consult_front(Deque *deque) {
  if (deque_is_null(deque) || deque_is_empty(deque)) return -1;
  return deque->arr[deque->start];
}

int deque_consult_back(Deque *deque) {
  if (deque_is_null(deque) || deque_is_empty(deque)) return -1;
  return deque->arr[deque->end];
}

int deque_push_front(Deque *deque, int item) {
  if (deque_is_null(deque) || deque_is_full(deque)) return -1;

  deque->start = (deque->start - 1 + deque->len) % deque->len;
  deque->arr[deque->start] = item;
  deque->qtd++;

  return 1;
}

int deque_push_back(Deque *deque, int item); // insere um elemento no final
int deque_pop_front(Deque *deque); // remove o primeiro elemento
int deque_pop_back(Deque *deque); // remove o último elemento
int deque_contains(Deque *deque, int item); // verifica se o item está no deque

void deque_clear(Deque *deque) {
  if (deque_is_null(deque))
    return;

  deque->start = 0;
  deque->end = 0;
  deque->qtd = 0;
}

void deque_destroy(Deque *deque) {
  if (deque_is_null(deque))
    return;

  free(deque->arr);
  free(deque);
}

int deque_len(Deque *deque) {
  return deque->len;
}

int deque_is_empty(Deque *deque) {
  return deque->qtd == 0;
}

int deque_is_null(Deque *deque) {
  return deque == NULL;
}

int deque_is_full(Deque *deque) {
  return deque->qtd == deque->len;
}