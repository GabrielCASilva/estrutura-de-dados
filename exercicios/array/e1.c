/*
  Exercício 1. Modifique a implementação do ArrayDeque de modo que o operador mod (%) não seja utilizado. 
  Dica: dados dois números inteiros a e b, se b é uma potência de 2, vale a igualdade:
  a % b == a & (b - 1)
  (& é o operador bitwise-and).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Deque {
  int *arr;
  int start;
  int end;
  int qtd;
  int len;
} Deque;

Deque* deque_create(int len);
int deque_consult_front(Deque *deque);
int deque_consult_back(Deque *deque);
int deque_push_front(Deque *deque, int item);
int deque_push_back(Deque *deque, int item);
int deque_pop_front(Deque *deque);
int deque_pop_back(Deque *deque);
void deque_clear(Deque *deque);
void deque_destroy(Deque *deque);
int deque_len(Deque *deque);
int deque_is_empty(Deque *deque);
int deque_is_null(Deque *deque);
int deque_is_full(Deque *deque);

int main(void) {
  return 0;
}

Deque* deque_create(int len) {
  Deque* deque = (Deque*)malloc(sizeof(Deque));
  deque->arr = (int*)malloc(len * sizeof(int));

  deque->start;
  deque->end;
  deque->qtd;
  deque->len = len;

  return deque;
}

int deque_consult_front(Deque *deque);
int deque_consult_back(Deque *deque);
int deque_push_front(Deque *deque, int item);
int deque_push_back(Deque *deque, int item);
int deque_pop_front(Deque *deque);
int deque_pop_back(Deque *deque);
void deque_clear(Deque *deque);
void deque_destroy(Deque *deque);

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