#include "circular_single_linked_list.h"
#include "double_linked_list.h"
#include "single_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void single_linked_list_app(void);
void double_linked_list_app(void);
void circular_single_linked_list_app(void);
void exercises_test(void);

int main(int argc, char *argv[]) {
  if (strcmp(argv[1], "single") == 0) {
    single_linked_list_app();
  } else if (strcmp(argv[1], "double") == 0) {
    double_linked_list_app();
  } else if (strcmp(argv[1], "circular_single") == 0) {
    circular_single_linked_list_app();
  } else if (strcmp(argv[1], "exercises") == 0) {
    exercises_test();
  } else {
    printf("Comando inválido ou inexistênte");
  }

  return 0;
}

void exercises_test(void) {
  printf("Testes dos exercícios: \n");
  printf("Exercicio 1: \n");

  List *list = list_create();
  list_push(&list, 2);
  list_push(&list, 5);
  list_push(&list, 3);

  char *stringfyed = list_stringfy(list);

  List *aux = list;
  int i = 0;
  for (; aux != NULL; aux = aux->next) {
    printf("%c -> ", stringfyed[i]);
    i++;
  }
  printf("NULL\n");
  free(stringfyed);
  list_free(&list);
  list = NULL;

  printf("\nExercicio 2: \n");
  List *lst1 = list_create();
  List *lst2 = list_create();

  list_push(&lst1, 1);
  list_push(&lst1, 2);
  list_push(&lst1, 3);
  list_push(&lst1, 4);

  list_push(&lst2, 9);
  list_push(&lst2, 8);
  list_push(&lst2, 7);

  list_print(lst1);
  list_print(lst2);

  list_swap_nodes(lst1, 3, lst2, 1); // TODO: rever
  printf("\nAltera el pos 3 com el pos 1...\n");

  printf("\n");
  list_print(lst1);
  list_print(lst2);
  printf("\nExercicio 3: \n");
  DList *dlist = dlist_create();

  dlist_push_tail(&dlist, 4);
  dlist_push_tail(&dlist, 3);
  dlist_push_tail(&dlist, 2);
  dlist_push_tail(&dlist, 1);
  dlist_print(dlist);

  printf("\ninvertendo a lista duplamente encadeada...\n");
  dlist_reverse(&dlist);
  dlist_print(dlist);

  printf("\nExercicio 4 e 5: \n");

  list = list_create();
  list_push(&list, 1);
  list_push(&list, 2);
  list_push(&list, 3);
  list_push(&list, 1);
  list_push(&list, 4);

  list_print(list);
  char *retorno = list_rmv_last_item_occurrence(&list, 5);

  printf("Resposta [%s]\n", retorno);
  list_print(list);
}

void circular_single_linked_list_app(void) {
  Cir_SList *list = cir_slist_create();

  cir_slist_push_tail(&list, 10);
  cir_slist_push_tail(&list, 9);
  cir_slist_print(list);

  cir_slist_push_tail(&list, 8);
  cir_slist_push_tail(&list, 7);
  cir_slist_print(list);

  cir_slist_pop_head(&list);
  cir_slist_print(list);

  cir_slist_push_tail(&list, 2);
  cir_slist_push_tail(&list, 22);
  cir_slist_push_tail(&list, 10);
  cir_slist_push_tail(&list, 20);
  cir_slist_print(list);

  cir_slist_remove(&list, 22);
  cir_slist_print(list);

  cir_slist_free(&list);
}

void double_linked_list_app(void) {
  DList *list = dlist_create();

  dlist_push_head(&list, 3);
  dlist_push_head(&list, 2);
  dlist_push_head(&list, 1);
  dlist_push_head(&list, 0);
  dlist_print(list);

  dlist_push_tail(&list, 10);
  dlist_print(list);

  dlist_pop_head(&list);
  dlist_print(list);

  dlist_pop_tail(&list);
  dlist_print(list);

  dlist_remove(&list, 2);
  dlist_print(list);

  dlist_free(&list);
}

void single_linked_list_app(void) {
  List *list = list_create();

  list_push(&list, 2);
  list_push(&list, 5);
  list_push(&list, 7);

  list_print(list);

  list_pop_head(&list);
  list_print(list);

  list_pop_tail(&list);
  list_print(list);

  list_push(&list, 10);
  list_push(&list, 5);
  list_push(&list, 7);
  list_push(&list, 9);
  list_push(&list, 29);
  list_push(&list, 23);
  list_push(&list, 14);

  list_print(list);

  list_remove(&list, 10);
  list_print(list);

  list_reverse(&list);
  list_print(list);

  list_free(&list);
}
