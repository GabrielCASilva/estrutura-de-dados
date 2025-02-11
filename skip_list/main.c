#include "skip_list.h"

int main(void) {
  SkipList *sk = SkipList_create(10, 5);
  SkipList_insert(sk, 10);

  return 0;
}
