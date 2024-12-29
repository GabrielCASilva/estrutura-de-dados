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

DList *dlist_push_tail(DList **list, int value) {
  DList *node = dlist_create_node(value);

  if ((*list) == NULL) {
    *list = node;
  } else {
    DList *p = *list;
    while (p->next != NULL) {
      p = p->next;
    }

    p->next = node;
    node->prev = p;
  }

  return node;
}

int dlist_pop_head(DList **list) {
  if ((*list) == NULL)
    return -1;

  int removedValue = (*list)->value;
  DList *p = *list;
  *list = (*list)->next;
  free(p);
  p = NULL;
  (*list)->prev = p;

  return removedValue;
}

int dlist_pop_tail(DList **list) {
  if ((*list) == NULL)
    return -1;

  DList *p = *list;
  while (p->next != NULL) {
    p = p->next;
  }

  DList *tail = p->prev;
  int removedValue = p->value;
  free(p);
  p = NULL;
  tail->next = p;

  return removedValue;
}

int dlist_remove(DList **list, int value) {
  if ((*list) == NULL)
    return -1;

  DList *p = *list;
  while (p->next != NULL && p->value != value) {
    p = p->next;
  }

  if (p->value != value)
    return -1;

  DList *prev = p->prev;
  DList *next = p->next;

  free(p);
  p = NULL;

  if (prev != NULL && next != NULL) {
    prev->next = next;
    next->prev = prev;
  } else if (prev != NULL) {
    next->prev = p;
  } else if (next != NULL) {
    prev->next = p;
  }

  return value;
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
