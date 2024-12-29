#ifndef CIRCULAR_SINGLE_LINKED_LIST_H
#define CIRCULAR_SINGLE_LINKED_LIST_H

struct circular_single_node {
  int value;
  struct circular_single_node *next;
};

typedef struct circular_single_node Cir_SList;

/*
 * Criar uma lista circular vazia
 */
Cir_SList *cir_slist_create(void);

/*
 * Criar um novo nó com um valor
 */
Cir_SList *cir_slist_create_node(int value);

/*
 * Inserir valor no inicio da lista
 */
Cir_SList *cir_slist_push_head(Cir_SList **list, int value);

/*
 * Inserir o valor no final da lista
 */
Cir_SList *cir_slist_push_tail(Cir_SList **list, int value);

/*
 * Retirar o item do inicio da lista
 */
int cir_slist_pop_head(Cir_SList **list);

/*
 * Retirar o item do final da lista
 */
int cir_slist_pop_tail(Cir_SList **list);

/*
 * Remover um nó por um valor em específico caso ele exista
 */
int cir_slist_remove(Cir_SList **list, int value);

/*
 * Liberar a lista
 */
void cir_slist_free(Cir_SList **list);

/*
 * Imprimir a lista na tela
 */
void cir_slist_print(Cir_SList *list);

#endif // CIRCULAR_SINGLE_LINKED_LIST_H
