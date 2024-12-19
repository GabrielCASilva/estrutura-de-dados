# Aplicação de Daque com arrays

Um daque é um tipo especial de fila, é uma estrutura que permite adição e remoção eficiente em ambas as extremidades da estrutura.
Daques também são conhecidos como Double Ended Queue, uma fila de duas saídas.

A estrutura de daque pode ser usada como um substituto de filha e pilha.

## Estrutura

```c
typedef struct {
  int *arr;
  int start;
  int end;
  int qtd;
  int len;
} Deque;
```

## Operações

```c
Deque *deque_create(int len); // cria um nova deque
int deque_consult_front(Deque *deque); // retorna o primeiro elemento
int deque_consult_back(Deque *deque); // retorna o último elemento
int deque_push_front(Deque *deque, int item); // insere um elemento no início
int deque_push_back(Deque *deque, int item); // insere um elemento no final
int deque_pop_front(Deque *deque); // remove o primeiro elemento
int deque_pop_back(Deque *deque); // remove o último elemento
int deque_contains(Deque *deque, int item); // verifica se o item está no deque
void deque_clear(Deque *deque); // remove todos os elementos
void deque_destroy(Deque *deque); // destroi o deque
int deque_len(Deque *deque); // retorna o tamanho do deque
int deque_is_empty(Deque *deque); // verifica se o deque está vazio
int deque_is_null(Deque *deque); // verifica se o deque é nulo
int deque_is_full(Deque *deque); // verifica se o deque está cheio
```

## Notação

## Rodar o programa

### Instruções

- Compilando o código:
```bash
gcc -o main daque.c main.c
```

- Executando o programa
```bash
./main
```

### Considerações
Recomenda-se fazer modificações no arquivo **main.c** para que possa experimentar as funções que foram desenvolvidos para este projeto.