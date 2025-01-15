#include "skip_list.h"
#include "stdio.h"
#include "stdlib.h"

SkipList *SkipList_create(int maxLevel, float p) {
  SkipList *sk = (SkipList *)malloc(sizeof(SkipList));
  if (sk != NULL) {
    sk->maxLevel = maxLevel;
    sk->p = p;
    sk->level = 0;
    sk->init = NULL;
  }
  return sk;
}

struct node *Node_create(int key, int level) {
  struct node *newNode = malloc(sizeof(struct node));
  if (newNode != NULL) {
    newNode->key = key;
    newNode->next = malloc((level + 1) * sizeof(struct node));
    for (int i = 0; i < (level + 1); i++)
      newNode->next[i] = NULL;
  }
  return newNode;
}

void SkipList_free(SkipList *sk) {
  if (sk == NULL)
    return;

  struct node *n, *current;
  current = sk->init->next[0];
  while (current != NULL) {
    n = current;
    current = current->next[0];
    free(n->next);
    free(n);
  }

  free(sk->init);
  free(sk);
}

int SkipList_search(SkipList *sk, int key) {
  if (sk == NULL)
    return 0;

  struct node *current = sk->init;

  // busca a chave a partir do ponto mais alto
  for (int i = sk->level; i >= 0; i--) {
    while (current->next[i] != NULL && current->next[i]->key < key)
      current = current->next[i];
  }

  // Acessa o nível 0 do próximo, porque é a localização da chave
  current = current->next[0];
  if (current != NULL && current->key == key)
    return 1;

  return 0;
}

int SkipList_insert(SkipList *sk, int key) {
  if (sk == NULL)
    return 0;

  int i = 0;
  struct node *current = sk->init;

  // criacao de um array de nós auxiliar
  struct node **aux = malloc((sk->maxLevel + 1) * sizeof(struct node *));
  for (; i <= sk->maxLevel; i++)
    aux[i] = NULL;

  // processo de busca para encontrar o ponto de inserção
  for (i = sk->level; i >= 0; i--) {
    while (current->next[i] != NULL && current->next[i]->key < key)
      current = current->next[i];
    aux[i] = current;
  }

  current = current->next[0];

  if (current == NULL || current->key != key) {
    int new_level = SkipList_drawNumber(sk);

    struct node *new_node = Node_create(key, new_level);
    if (new_node == NULL) {
      free(aux);
      return 0;
    }

    if (new_level > sk->level) {
      for (i = sk->level + 1; i <= new_level; i++)
        aux[i] = sk->init;

      sk->level = new_level;
    }

    for (i = 0; i <= new_level; i++) {
      new_node->next[i] = aux[i]->next[i];
      aux[i]->next[i] = new_node;
    }

    free(aux);
    return 1;
  }

  return 0;
}

int SkipList_drawNumber(SkipList *sk) {
  float r = (float)rand() / RAND_MAX;
  int level = 0;
  while (r < sk->p && level < sk->maxLevel) {
    level++;
    r = (float)rand() / RAND_MAX;
  }

  return level;
}

int SkipList_remove(SkipList *sk, int key) {
  if (sk == NULL)
    return 0;

  struct node *current = sk->init;
  struct node **aux = malloc((sk->maxLevel + 1) * sizeof(struct node *));
  int i = 0;
  for (; i <= sk->maxLevel + 1; i++)
    aux[i] = NULL;

  for (i = sk->level; i >= 0; i--) {
    while (current->next[i] != NULL && current->next[i]->key < key)
      current = current->next[i];
    aux[i] = current;
  }

  current = current->next[0];

  if (current != NULL && current->key == key) {
    for (i = 0; i <= sk->level; i++) {
      if (aux[i]->next[i] != current)
        break;

      aux[i]->next[i] = current->next[i];
    }

    while (sk->level > 0 && sk->init->next[sk->level] == NULL)
      sk->level--;

    free(current->next);
    free(current);
    free(aux);
    return 1;
  }

  free(aux);
  return 0;
}
