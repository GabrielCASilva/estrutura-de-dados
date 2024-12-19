#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @file deque.h
 * @brief Declarações e definições para a estrutura de dados Deque.
 *
 * Este arquivo contém a definição da estrutura `Deque` e as declarações
 * das funções para manipulação de um deque. A estrutura
 * `Deque` utiliza um array para armazenar os elementos e mantém índices
 * para o início e final do deque, além de acompanhar a quantidade
 * atual de elementos.
 *
 * @see Deque
 */

/**
 * @struct Deque
 * @brief Estrutura que representa um deque.
 *
 * A estrutura Deque utiliza um array para armazenar os elementos e mantém
 * índices para o início e final do deque, além de acompanhar a quantidade
 * atual de elementos.
 */
typedef struct Deque {
    int *arr;   /**< Ponteiro para um array que armazena os elementos do deque. */
    int start;  /**< Índice do início do deque. */
    int end;    /**< Índice do final do deque. */
    int qtd;    /**< Quantidade de elementos atualmente no deque. */
    int len;    /**< Capacidade máxima do deque. */
} Deque;

/**
 * @brief Cria um novo deque.
 * 
 * Aloca memória para um deque com a capacidade especificada.
 * 
 * @param len Tamanho inicial do deque.
 * @return Deque* Ponteiro para o deque criado.
 */
Deque* deque_create(int len);

/**
 * @brief Consulta o primeiro elemento do deque.
 * 
 * Retorna o elemento no início do deque sem removê-lo.
 * 
 * @param deque Ponteiro para o deque.
 * @return int O primeiro elemento do deque.
 */
int deque_consult_front(Deque *deque);

/**
 * @brief Consulta o último elemento do deque.
 * 
 * Retorna o elemento no final do deque sem removê-lo.
 * 
 * @param deque Ponteiro para o deque.
 * @return int O último elemento do deque.
 */
int deque_consult_back(Deque *deque);

/**
 * @brief Insere um elemento no início do deque.
 * 
 * Adiciona um novo elemento no início do deque, ajustando os índices conforme necessário.
 * 
 * @param deque Ponteiro para o deque.
 * @param item Elemento a ser inserido.
 * @return int 0 se a inserção foi bem-sucedida, -1 caso contrário.
 */
int deque_push_front(Deque *deque, int item);

/**
 * @brief Insere um elemento no final do deque.
 * 
 * Adiciona um novo elemento no final do deque, ajustando os índices conforme necessário.
 * 
 * @param deque Ponteiro para o deque.
 * @param item Elemento a ser inserido.
 * @return int 0 se a inserção foi bem-sucedida, -1 caso contrário.
 */
int deque_push_back(Deque *deque, int item);

/**
 * @brief Remove o primeiro elemento do deque.
 * 
 * Remove e retorna o elemento no início do deque.
 * 
 * @param deque Ponteiro para o deque.
 * @return int O elemento removido.
 */
int deque_pop_front(Deque *deque);

/**
 * @brief Remove o último elemento do deque.
 * 
 * Remove e retorna o elemento no final do deque.
 * 
 * @param deque Ponteiro para o deque.
 * @return int O elemento removido.
 */
int deque_pop_back(Deque *deque);

/**
 * @brief Verifica se o item está no deque.
 * 
 * Percorre o deque para verificar a presença de um elemento específico.
 * 
 * @param deque Ponteiro para o deque.
 * @param item Elemento a ser verificado.
 * @return int 1 se o item está no deque, 0 caso contrário.
 */
int deque_contains(Deque *deque, int item);

/**
 * @brief Remove todos os elementos do deque.
 * 
 * Reseta os índices e a quantidade de elementos, efetivamente esvaziando o deque.
 * 
 * @param deque Ponteiro para o deque.
 */
void deque_clear(Deque *deque);

/**
 * @brief Destroi o deque e libera a memória.
 * 
 * Libera a memória alocada para o array interno e para a estrutura Deque.
 * 
 * @param deque Ponteiro para o deque.
 */
void deque_destroy(Deque *deque);

/**
 * @brief Retorna o tamanho do deque.
 * 
 * Obtém a quantidade atual de elementos armazenados no deque.
 * 
 * @param deque Ponteiro para o deque.
 * @return int O tamanho do deque.
 */
int deque_len(Deque *deque);

/**
 * @brief Verifica se o deque está vazio.
 * 
 * Determina se o deque contém ou não elementos.
 * 
 * @param deque Ponteiro para o deque.
 * @return int 1 se o deque está vazio, 0 caso contrário.
 */
int deque_is_empty(Deque *deque);

/**
 * @brief Verifica se o deque é nulo.
 * 
 * Determina se o ponteiro para o deque é nulo.
 * 
 * @param deque Ponteiro para o deque.
 * @return int 1 se o deque é nulo, 0 caso contrário.
 */
int deque_is_null(Deque *deque);

/**
 * @brief Verifica se o deque está cheio.
 * 
 * Determina se o deque atingiu sua capacidade máxima.
 * 
 * @param deque Ponteiro para o deque.
 * @return int 1 se o deque está cheio, 0 caso contrário.
 */
int deque_is_full(Deque *deque);

#endif // DEQUE_H