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
List *list_push(List **lst, int value);

/*
 * Retira o nó na cabeca da lista
 */
int list_pop_head(List **lst);

/*
 * Retira o nó no final da lista
 */
int list_pop_tail(List **lst);

/*
 * Retira o nó caso ache o valor na lista
 */
int list_remove(List **lst, int value);

/*
 * Libera a lista da memória
 */
void list_free(List **lst);

/*
 * Imprime os valores da lista
 */
void list_print(List *lst);

//////////////////////////
///// MÉTODOS EXTRAS /////
//////////////////////////

/*
 * Retorna o penultimo elemento da lista.
 */
List *list_second_last(List *lst);

/*
 * Reverte a lista
 */
void list_reverse(List **lst);

/*
 * Converte uma lista para string
 */
char *list_stringfy(List *lst);

/*
 * Troca o nó de uma lista com o nó da outra lista a partir de
 * determinada posição
 *
 * @return 1|0
 */
int list_swap_nodes(List *lst1, int i1, List *lst2, int i2);

/*
 * Remove a ultima ocorrencia de um item na lista
 */
char *list_rmv_last_item_occurrence(List **lst, int item);

#endif // SINGLE_LINKED_LIST
