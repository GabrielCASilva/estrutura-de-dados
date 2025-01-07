#ifndef SKIP_LIST_H
#define SKIP_LIST_H

struct node {
  int key;
  struct node **next; //< vetor de ponteiros
};

struct skipList {
  int maxLevel; //< nível máximo da lista
  int p; //< fracao dos nós, para ajudar a determinar quantos nívels terá um nó
  int level;         //< número total de níveis atuais
  struct node *init; //< primeiro nó
};

typedef struct skipList SkipList;

/*
 * Cria a struct do cabeçalho da lista
 */
SkipList *SkipList_create(int maxLevel, float p);

/*
 * Cria os nós da lista
 */
struct node *Node_create(int key, int level);

/*
 * Libera os nós da lista
 */
void SkipList_free(SkipList *sk);

/*
 * Procupa um valor na Skip List, porém só funciona caso a lista seja ordenada
 */
int SkipList_search(SkipList *sk, int key);

/*
 * Insere um novo nó na Skip List
 */
int SkipList_insert(SkipList *sk, int key);

int SkipList_drawNumber(SkipList *sk);

#endif // SKIP_LIST_H
