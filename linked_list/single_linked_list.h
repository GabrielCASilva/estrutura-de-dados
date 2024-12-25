#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

struct node {
  int n;
  struct node *next;
};

typedef struct node List;

/*
 * Inicializa a lista
 */
List *list_create();

/*
 * Adiciona um novo nó a lista
 */
List *list_push(List *lst, int value);

/*
 * Retira o nó na cabeca da lista
 */
int list_pop_head(List *lst);

/*
 * Retira o nó no final da lista
 */
int list_pop_tail(List *lst);

/*
 * Retira o nó caso ache o valor na lista
 */
int list_remove(List *lst, int value);

/*
 * Libera a lista da memória
 */
void list_free(List *lst);

#endif // SINGLE_LINKED_LIST
