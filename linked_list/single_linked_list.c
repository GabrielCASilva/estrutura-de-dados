#include "single_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

List *list_create() { return NULL; }

List *list_push(List **lst, int value) {
  List *node = (List *)malloc(sizeof(List));
  node->n = value;
  node->next = NULL;

  if (*lst == NULL) {
    *lst = node;
    return node;
  }

  List *aux = *lst;
  while (aux->next != NULL) {
    aux = aux->next;
  }

  aux->next = node;
  return node;
}

int list_pop_head(List **lst) {
  if (lst == NULL)
    return -1;
  int value = (*lst)->n;

  List *head = *lst;
  *lst = (*lst)->next;

  free(head);
  head = NULL;

  return value;
}

int list_pop_tail(List **lst) {
  if (*lst == NULL)
    return -1;
  if ((*lst)->next == NULL)
    return list_pop_head(lst);

  List *aux = NULL;
  List *tail = *lst;
  while (tail->next != NULL) {
    aux = tail;
    tail = tail->next;
  }

  aux->next = NULL;
  free(tail);
  tail = NULL;

  return aux->n;
}

int list_remove(List **lst, int value) {
  if ((*lst) == NULL)
    return -1;

  List *aux = NULL;
  List *node = *lst;
  while (node != NULL && value != node->n) {
    aux = node;
    node = node->next;
  }

  if (node == NULL)
    return -1;

  aux->next = node->next;
  free(node);
  node = NULL;

  return aux->n;
}

void list_free(List **lst) {
  if ((*lst) == NULL)
    return;

  List *aux = *lst;
  while (aux != NULL) {
    List *p = aux->next;
    free(aux);
    aux = p;
  }
}

void list_print(List *lst) {
  List *aux;
  printf("List: ");
  for (aux = lst; aux != NULL; aux = aux->next) {
    printf("%d -> ", aux->n);
  }
  printf("NULL\n");
}

//////////////////////////
///// MÉTODOS EXTRAS /////
//////////////////////////

List *list_second_last(List *lst) {
  if (lst == NULL && lst->next == NULL)
    return NULL;

  List *p = lst;
  while (p != NULL && p->next->next != NULL)
    p = p->next;

  return p;
}

void list_reverse(List **lst) {
  if (*lst == NULL)
    return;

  // chegar no final da lista
  List *tail = *lst;
  while (tail->next != NULL)
    tail = tail->next;

  List *head = *lst;
  while (head != tail) {
    if (head == *lst) {
      tail->next = head;
      head = head->next;
      tail->next->next = NULL;
    } else {
      List *aux = head;
      head = head->next;
      aux->next = tail->next;
      tail->next = aux;
    }
  }

  *lst = tail;
}

char *list_stringfy(List *lst) {
  List *aux = lst;
  int len = 0;
  for (; aux != NULL; aux = aux->next)
    len++;

  char *text = (char *)malloc(len * sizeof(char));

  aux = lst;
  int i = 0;
  for (; aux != NULL; aux = aux->next) {
    sprintf(&text[i], "%d", aux->n);
    i++;
  }

  return text;
}
