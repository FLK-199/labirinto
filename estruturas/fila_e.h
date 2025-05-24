#ifndef FILA_H      // INCLUDE GUARD
#define FILA_H

#include <stdbool.h> // bool => {false, true}
#include "pilha_e.h"

// ----------- INTERFACE ----------
typedef ponto2D item;
typedef struct fila fila;

/*
Esvazia uma fila
Entrada: referência para a fila f
Saída: Não tem
*/
void fila_esvaziar(fila *f);

/*
Libera a memória da fila
Entrada: referência para a fila f
Saída: Não tem
*/
void fila_finalizar(fila *f);

/*
Inicializa uma fila
Entrada: capacidade da fila
Saída: referência para a fila criada
*/
fila* fila_inicializar();

/*
Insere um item na fila
Entrada: referência para a fila f e o item it a ser inserido
Saída: true se inserido com sucesso; false caso contrário
*/
bool fila_inserir(fila *f, item it); // enqueue

/*
Remove um item da fila
Entrada: referência para a fila f
Saída: true se removido com sucesso; false caso contrário
*/
bool fila_remover(fila *f);

/*
Informa o tamanho da fila, ou seja, o número
de iten armazenados em um dado momento
Entrada: referência para a fila f
Saída: o tamanho da fila
*/
int fila_tamanho(fila *f);

/*
Retorna o item da frente da fila
Entrada: referência para a fila f
Saída: item da frente
*/
item fila_frente(fila *f);

/*
Informa se uma fila está vazia ou não
Entrada: referência para a fila f
Saída: true se estiver vazia; false caso contrário
*/
bool fila_vazia(fila *f);

#endif // fila_H