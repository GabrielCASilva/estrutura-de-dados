#include "single_linked_list.h"
#include <string.h>

void single_linked_list_app(void);

int main(int argc, char *argv[]) {
  if (strcmp(argv[1], "single") == 0) {
    single_linked_list_app();
  }

  return 0;
}

void single_linked_list_app(void) {
  List *list = list_create();

  list_push(&list, 2);
  list_push(&list, 5);
  list_push(&list, 7);
  list_print(list);

  /* list_pop_head(&list); */
  /* list_print(list); */

  list_free(&list);
}
