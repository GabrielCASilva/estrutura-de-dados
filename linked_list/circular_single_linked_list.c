#include "circular_single_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

Cir_SList *cir_slist_create(void) { return NULL; }

Cir_SList *cir_slist_create_node(int value) {
  Cir_SList *node = (Cir_SList *)malloc(sizeof(Cir_SList));
  node->value = value;
  node->next = node; // circular aponta para ele mesmo de incio
  return node;
}

Cir_SList *cir_slist_push_head(Cir_SList **list, int value) { return NULL; }

Cir_SList *cir_slist_push_tail(Cir_SList **list, int value) {
  Cir_SList *node = cir_slist_create_node(value);

  if ((*list) == NULL) {
    *list = node;
    return node;
  }

  Cir_SList *p = *list;
  while (p->next != *list) {
    p = p->next;
  }

  p->next = node;
  node->next = *list;

  return NULL;
}

int cir_slist_pop_head(Cir_SList **list) {
  if ((*list) == NULL)
    return -1;

  Cir_SList *head = *list;
  Cir_SList *prev = *list;
  while (prev->next != *list)
    prev = prev->next;

  int value = (*list)->value;
  *list = (*list)->next;
  prev->next = *list;
  free(head);
  head = NULL;

  return value;
}

int cir_slist_remove(Cir_SList **list, int value) {
  if ((*list) == NULL)
    return -1;

  Cir_SList *prev = *list;
  while (prev->next != *list && prev->next->value != value) {
    prev = prev->next;
  }

  if (prev->next->value != value)
    return -1;

  Cir_SList *node = prev->next;
  int rm_value = node->value;

  Cir_SList *next = node->next;
  prev->next = next;
  free(node);
  node = NULL;

  return rm_value;
}

void cir_slist_free(Cir_SList **list) {
  if ((*list)->next == *list) {
    free(*list);
    return;
  }

  Cir_SList *p = (*list)->next;
  while (p != *list) {
    Cir_SList *aux = p;
    p = p->next;
    free(aux);
  }

  free(p);
}

void cir_slist_print(Cir_SList *list) {
  Cir_SList *aux;
  printf("List: {...} -> [%d] -> ", list->value);
  for (aux = list->next; aux != list; aux = aux->next) {
    printf("%d -> ", aux->value);
  }
  printf("[%d] -> {...}\n", aux->value);
}
