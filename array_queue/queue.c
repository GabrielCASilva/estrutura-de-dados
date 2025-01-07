#include "queue.h"

Queue *queue_create(int len) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->arr = (int *)malloc(len * sizeof(int));

  queue->start = 0;
  queue->end = 0;
  queue->qtd = 0;
  queue->len = len;

  return queue;
}

int queue_enqueue(Queue *queue, int item) {
  if (queue_is_null(queue))
    return -1;

  if (queue->qtd == queue->len)
    queue_resize(queue);

  queue->arr[queue->end] = item;
  queue->end = (queue->end + 1) % queue->len;
  queue->qtd++;
  return 1;
}

int queue_dequeue(Queue *queue) {
  if (queue_is_null_and_is_empty(queue))
    return -1;

  queue->start = (queue->start + 1) % queue->len;
  queue->qtd--;
  return 1;
}

int queue_peek(Queue *queue) {
  if (queue_is_null_and_is_empty(queue))
    return -1;

  return queue->arr[queue->start];
}

int queue_contains(Queue *queue, int item) {
  if (queue_is_null_and_is_empty(queue))
    return -1;

  for (int i = 0; i < queue->qtd; i++) {
    if (queue->arr[i] == item)
      return 1;
  }

  return -1;
}

void queue_clear(Queue *queue) {
  if (queue_is_null_and_is_empty(queue))
    return;

  queue->start = 0;
  queue->end = 0;
  queue->qtd = 0;
}

void queue_destroy(Queue *queue) {
  free(queue->arr);
  free(queue);
}

int queue_len(Queue *queue) {
  if (queue_is_null(queue))
    return -1;

  return queue->qtd;
}

void queue_resize(Queue *queue) {
  if (queue_is_null_and_is_empty(queue))
    return;

  int *new_arr = (int *)malloc(queue->len * 2 * sizeof(int));
  for (int i = 0; i < queue->qtd; i++)
    new_arr[i] = queue->arr[i];

  free(queue->arr);
  queue->arr = new_arr;
  queue->len = queue->len * 2;
}

int queue_is_null(Queue *queue) {
  if (queue != NULL)
    return 0;

  printf("Queue does not exist\n");
  return 1;
}

int queue_is_empty(Queue *queue) {
  if (queue->qtd != 0)
    return 0;

  printf("Queue is empty\n");
  return 1;
}

int queue_is_null_and_is_empty(Queue *queue) {
  if (queue_is_null(queue) || queue_is_empty(queue))
    return 1;

  return 0;
}
