#include "deque.h"

Deque *deque_create(int len) {
  Deque *deque = (Deque *)malloc(sizeof(Deque));

  deque->arr = (int *)malloc(len * sizeof(int));
  deque->start = 0;
  deque->end = 0;
  deque->qtd = 0;
  deque->len = len;

  return deque;
}

int deque_consult_front(Deque *deque) {
  if (deque_is_null(deque) || deque_is_empty(deque))
    return -1;
  return deque->arr[deque->start];
}

int deque_consult_back(Deque *deque) {
  if (deque_is_null(deque) || deque_is_empty(deque))
    return -1;
  return deque->arr[deque->end];
}

int deque_push_front(Deque *deque, int item) {
  if (deque_is_null(deque) || deque_is_full(deque))
    return -1;

  deque->start--;
  if (deque->start < 0)
    deque->start = deque->len - 1;
  deque->arr[deque->start] = item;
  deque->qtd++;

  return 1;
}

int deque_push_back(Deque *deque, int item) {
  if (deque_is_null(deque) || deque_is_full(deque))
    return -1;

  deque->arr[deque->end] = item;
  deque->end = (deque->end + 1) % deque->len;
  deque->qtd++;

  return 1;
}

int deque_pop_front(Deque *deque) {
  if (deque_is_null(deque) || deque_is_empty(deque))
    return -1;

  int item = deque->arr[deque->start];
  deque->start = (deque->start + 1) % deque->len;
  deque->qtd--;

  return item;
}

int deque_pop_back(Deque *deque) {
  if (deque_is_null(deque) || deque_is_empty(deque))
    return -1;

  int item = deque->arr[deque->end];
  deque->end--;
  if (deque->end < 0)
    deque->end = deque->len - 1;
  deque->qtd--;

  return item;
}

int deque_contains(Deque *deque, int item) {
  if (deque_is_null(deque) || deque_is_empty(deque))
    return -1;

  int i = deque->start < deque->end ? deque->start : deque->end;
  int j = deque->start > deque->end ? deque->start : deque->end;

  for (; i <= j; i++) {
    if (deque->arr[i] == item)
      return 1;
  }

  return -1;
}

void deque_clear(Deque *deque) {
  if (deque_is_null(deque) || deque_is_empty(deque))
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

int deque_len(Deque *deque) { return deque->len; }

int deque_is_empty(Deque *deque) { return deque->qtd == 0; }

int deque_is_null(Deque *deque) { return deque == NULL; }

int deque_is_full(Deque *deque) { return deque->qtd == deque->len; }
