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

// TODO: esqueceu de levar em conta a condição do primeiro item da lista ser o
// trocavel
int list_swap_nodes(List *lst1, int i1, List *lst2, int i2) {
  if (lst1 == NULL || lst2 == NULL)
    return 0; // pelo menos uma das listas estão vazias

  List *ant1 = lst1;
  List *ant2 = lst2;

  int i = 0;
  while (ant1 != NULL) {
    if (i == (i1 - 1)) // cair no nó anterior ao mudado
      break;
    i++;
    ant1 = ant1->next;
  }

  if (ant1 == NULL)
    return 0; // não é possível fazer o swap

  i = 0;
  while (ant2 != NULL) {
    if (i == (i2 - 1)) // cair no nó anterior ao mudado
      break;
    i++;
    ant2 = ant2->next;
  }

  if (ant2 == NULL)
    return 0; // não é possível fazer o swap

  List *troca1 = ant1->next;
  List *troca2 = ant2->next;

  if (troca1 == NULL || troca2 == NULL)
    return 0; // não é possível trocar

  List *prox1 = troca1->next;
  List *prox2 = troca2->next;

  if (prox1 != NULL || prox2 != NULL) {
    troca1->next = prox2;
    troca2->next = prox1;
  }

  ant1->next = troca2;
  ant2->next = troca1;

  return 1;
}
