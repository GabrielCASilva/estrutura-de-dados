#include "double_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

DList *dlist_create(void) { return NULL; }

DList *dlist_create_node(int value) {
  DList *node = (DList *)malloc(sizeof(DList));
  node->value = value;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

DList *dlist_push_head(DList **list, int value) {
  DList *node = dlist_create_node(value);

  if ((*list) == NULL) {
    *list = node;
    return node;
  }

  node->next = *list;
  (*list)->prev = node;
  *list = node;
  return node;
}

void dlist_free(DList **list) {
  if ((*list) == NULL)
    return;

  DList *aux = NULL;
  while ((*list) != NULL) {
    aux = *list;
    *list = (*list)->next;
    free(aux);
    aux = NULL;
  }
}

void dlist_print(DList *list) {
  DList *aux;
  printf("List: NULL <- ");
  for (aux = list; aux != NULL; aux = aux->next) {
    if (aux->next != NULL)
      printf("%d <-> ", aux->value);
    else
      printf("%d -> ", aux->value);
  }
  printf("NULL\n");
}
