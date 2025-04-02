#include "hash_table.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // ideal fazer uma tabela que o tamanho seja primo, porque da menos chance de
  // ocorrer colisões
  int len = 13;
  Table *tabela = Table_create(len);

  Table_insert_data_without_collision(tabela, "cachorro");
  Table_insert_data_without_collision(tabela, "cavalo");

  for (int i = 0; i < tabela->table_length; i++) {
    if (tabela->names[i] != NULL) {
      printf("[%d] - %s\n", i, tabela->names[i]);
    }
  }

  Table_free(tabela);
  return 0;
}
