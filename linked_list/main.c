#include "double_linked_list.h"
#include "single_linked_list.h"
#include <string.h>

void single_linked_list_app(void);
void double_linked_list_app(void);

int main(int argc, char *argv[]) {
  if (strcmp(argv[1], "single") == 0) {
    single_linked_list_app();
  } else if (strcmp(argv[1], "double") == 0) {
    double_linked_list_app();
  }

  return 0;
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
  list_push(&list, 8);

  list_print(list);

  list_remove(&list, 10);

  list_print(list);

  list_free(&list);
}
