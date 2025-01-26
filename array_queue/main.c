#include "queue.h"

int main(void) {
  Queue *queue = queue_create(4);
  queue_print(queue);

  queue_enqueue(queue, 1);
  queue_enqueue(queue, 2);
  queue_enqueue(queue, 3);
  queue_enqueue(queue, 4);
  queue_print(queue);

  queue_dequeue(queue);
  queue_print(queue);

  return 0;
}
