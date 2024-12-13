# Aplicação de Fila com arrays

Uma fila é uma estrutura FIFO (First-in, First-out), em que o primeiro elemento a entrar é o primeiro a sair.

## Estrutura

A fila ultilizada de exemplo foi definida com um array de inteiros alocado dinamicamente. 

```c
typedef struct {
  int *arr; // array de inteiros
  int start; // indice do elemento inicial da fila
  int end; // indice do elemento ao final da fila
  int qtd; // quantidade de elementos na fila
  int len; // tamanho máximo do array
} Queue;
```

## Operações

```c
Queue *queue_create(int len); // cria uma nova fila
int queue_enqueue(Queue *queue, int item); // adiciona um elemento
int queue_dequeue(Queue *queue); // remove o próximo elemento e o retorna
int queue_peek(Queue *queue); // retorna o próximo elemento que será removido
int queue_contains(Queue *queue, int item); // verifica se o item está na fila
void queue_clear(Queue *queue); // remove todos os elementos
void queue_destroy(Queue *queue); // destroi a fila
int queue_len(Queue *queue); // retorna o tamanho da fila
void queue_resize(Queue *queue); // redimensiona a fila para o doubro do tamanho original
int queue_is_null(Queue *queue); // verifica se a fila é nula
int queue_is_empty(Queue *queue); // verifica se a fila está vazia
int queue_is_null_and_is_empty(Queue *queue); // verifica se a fila é nula e se está vazia
```

## Notação

## Rodar o programa

### Instruções

- Compilando o código:
```bash
gcc -o main queue.c main.c
```

- Executando o programa
```bash
./main
```

### Considerações
Recomenda-se fazer modificações no arquivo **main.c** para que possa experimentar as funções que foram desenvolvidos para este projeto.