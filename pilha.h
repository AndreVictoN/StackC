/*
 * linha.h
 *
 *  Created on: 30 de jul de 2024
 *      Author: user
 */

#ifndef PILHA_H_
#define PILHA_H_

typedef struct tipoPilha{
	int topo;
	int base;
	int* elementos;
}TipoPilha;

TipoPilha* InicializarPilhaArr(int base, int capacidade);

bool InserirPilhaArr(TipoPilha* pilha, int lim, int valor);

bool RemoverPilhaArr(TipoPilha* pilha, int* valorRemovido);

bool ConsultarPilhaArr(TipoPilha* pilha, int* valor, int posicaoConsultada);

void LiberarPilha(TipoPilha* pilha);

#endif /* PILHA_H_ */
