#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
  int *arr;
  int start;
  int end;
  int qtd;
} Queue;

Queue *queue_create(int len); // cria uma nova fila
void queue_enqueue(Queue *queue, int item); // adiciona um elemento
int queue_dequeue(Queue *queue); // remove o próximo elemento e o retorna
int queue_peek(Queue *queue); // retorna o próximo elemento que será removido
void queue_contains(Queue *queue, int item); // verifica se o item está na fila
void queue_clear(Queue *queue); // remove todos os elementos
void queue_destroy(Queue *queue); // destroi a fila
int queue_len(Queue *queue); // retorna o tamanho da fila
void queue_resize(Queue *queue); // redimensiona a fila para o doubro do tamanho original

#endif