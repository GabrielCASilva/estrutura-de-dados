#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Table *Table_create(int length) {
  Table *table = (Table *)malloc(sizeof(Table));
  if (table != NULL) {
    table->table_length = length;
    table->num_elements = 0;
    table->names = (char **)malloc(sizeof(char *) * length);
    if (table->names == NULL) {
      free(table);
      return NULL;
    }
  }

  for (int i = 0; i < table->table_length; i++) {
    table->names[i] = NULL;
  }

  return table;
}

void Table_free(Table *t) {
  if (t != NULL) {
    for (int i = 0; i <= t->table_length; i++) {
      if (t->names[i] != NULL) {
        free(t->names[i]);
      }
      free(t->names);
      free(t);
    }
  }
}

int Table_insert_data_without_collision(Table *t, char *name) {
  if (t == NULL || t->num_elements == t->table_length) {
    return 0;
  }

  int key = chave_string_int(name);
  key = Table_insert_multiplication(t, key);

  t->names[key] = (char *)malloc(sizeof(char) * (strlen(name) + 1));
  if (t->names[key] == NULL) {
    return 0;
  }

  strcpy(t->names[key], name);
  t->num_elements++;
  return 1;
}

int Table_insert_multiplication(Table *t, int key) {
  float A = 0.618; // valor arbitrário --- 0 < A < 1
  float value = key * A;
  value = value - (int)value; // subtrai pegando a parte inteira
  return (int)(t->table_length * value);
}

int chave_string_int(char *str) {
  int valor = 3; // número arbitrário
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    valor = 5 * valor + (int)str[i];
  }

  return valor;
}
