#include "single_linked_list.h"
#include <stdlib.h>

List *list_create() { return NULL; }

List *list_push(List *lst, int value) {
  List *node = (List *)malloc(sizeof(List));
  node->n = value;
  node->next = NULL;

  if (lst == NULL) {
    lst = node;
  } else {
    lst->next = node;
  }

  return node;
}

int list_pop_head(List *lst) {
  if (lst == NULL)
    return -1;
  int value = lst->n;

  List *head = lst;
  lst = lst->next;

  free(head);
  head = NULL;

  return value;
}

int list_pop_tail(List *lst) {
  if (lst == NULL)
    return -1;
  if (lst->next == NULL)
    return list_pop_head(lst);

  List *aux = NULL;
  List *tail = lst;
  while (tail->next != NULL) {
    aux = tail;
    tail = tail->next;
  }

  aux->next = NULL;
  free(tail);
  tail = NULL;

  return aux->n;
}

int list_remove(List *lst, int value) {
  if (lst == NULL)
    return -1;

  List *aux = NULL;
  List *node = lst;
  while (node != NULL) {
    if (value == node->n)
      break;
    aux = node;
    node = node->next;
  }

  if (node == NULL || value != node->n)
    return -1;

  aux->next = node->next;
  free(node);
  node = NULL;

  return aux->n;
}

void list_free(List *lst) {
  if (lst == NULL)
    return;

  List *aux = lst;
  while (aux != NULL) {
    List *p = aux->next;
    free(aux);
    aux = p->next;
  }
}

void list_print(List *lst) {}