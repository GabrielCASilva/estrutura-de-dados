#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define MAX_LEN_NAMES 100

// A tabela guarda os elementos de maneira não ordenada e espalhada
// Ela tem o principio de associação: chave e valor.
typedef struct {
  int num_elements;
  int table_length;
  char **names; // array de strings
} Table;

Table *Table_create(int length);
void Table_free(Table *t);

// Método de inserção de um elemento na tabela
// A função retorna a posição em que o elemento deve ser inserido na tabela
int Table_insert_multiplication(Table *t, int key);

// Função insere uma string na tabela, mas sem levar em consideração que ocorreu
// uma colisão
int Table_insert_data_without_collision(Table *t, char *name);

// Essa função existe porque se usar a conversão direta de algumas strings,
// mesmo elas sendo diferentes, podem dar o mesmo valor
int chave_string_int(char *str);

#endif // !HASH_TABLE_H
