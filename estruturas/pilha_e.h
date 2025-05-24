#ifndef PILHA_H      // INCLUDE GUARD
#define PILHA_H

#include <stdbool.h> // bool => {false, true}
#include "ponto.h"

// ----------- INTERFACE ----------
typedef ponto2D item;
typedef struct pilha pilha;

#define ERRO -9999

/*
Esvazia uma pilha
Entrada: referência para a pilha p
Saída: Não tem
*/
void pilha_esvaziar(pilha *p);

/*
Libera a memória da pilha
Entrada: referência para a pilha p
Saída: Não tem
*/
void pilha_finalizar(pilha *p);

/*
Cria uma pilha
Entrada: Não tem
Saída: referência para a pilha criada
*/
pilha* pilha_inicializar();

/*
Insere um item na pilha
Entrada: referência para a pilha p e o item it a ser inserido
Saída: true se inserido com sucesso; false caso contrário
*/
bool pilha_inserir(pilha *p, item it);

/*
Remove um item da pilha
Entrada: referência para a pilha p
Saída: true se removido com sucesso; false caso contrário
*/
bool pilha_remover(pilha *p);

/*
Informa o tamanho da pilha, ou seja, o número
de iten armazenados em um dado momento
Entrada: referência para a pilha p
Saída: o tamanho da pilha
*/
int pilha_tamanho(pilha *p);

/*
Retorna o item do topo da pilha
Entrada: referência para a pilha p
Saída: item do topo ou comportamento inesperado caso pilha vazia

*/
item pilha_topo(pilha *p);

/*
Informa se uma pilha está vazia ou não
Entrada: referência para a pilha p
Saída: true se estiver vazia; false caso contrário
*/
bool pilha_vazia(pilha *p);

#endif // PILHA_H