#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

struct dnode {
  int value;
  struct dnode *next;
  struct dnode *prev;
};

typedef struct dnode DList;

/*
 * Inicializa a lista
 */
DList *dlist_create(void);

/*
 * Criar um novo nó com um valor
 */
DList *dlist_create_node(int value);

/*
 * Inserir valor no inicio da lista
 */
DList *dlist_push_head(DList **list, int value);

/*
 * Inserir o valor no final da lista
 */
DList *dlist_push_tail(DList **list, int value);

/*
 * Retirar o item do inicio da lista
 */
int dlist_pop_head(DList **list);

/*
 * Retirar o item do final da lista
 */
int dlist_pop_tail(DList **list);

/*
 * Remover um nó por um valor em específico caso ele exista
 */
int dlist_remove(DList **list, int value);

/*
 * Liberar a lista
 */
void dlist_free(DList **list);

/*
 * Imprimir a lista na tela
 */
void dlist_print(DList *list);

#endif // DOUBLE_LINKED_LIST_H
