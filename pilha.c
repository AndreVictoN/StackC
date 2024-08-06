/*
 * linha.c
 *
 *  Created on: 30 de jul de 2024
 *      Author: user
 */


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pilha.h"

TipoPilha* InicializarPilhaArr(int base, int elementos){
	TipoPilha* pilha = (TipoPilha*) malloc(sizeof(TipoPilha));

	if(pilha != NULL){
		pilha->topo = base-1;
		pilha-> base = base;

		pilha->elementos = (int*) malloc(elementos * sizeof(int));

		if(pilha->elementos == NULL)
		{
			free(pilha);
			return NULL;
		}
	}

	return pilha;
}

bool InserirPilhaArr(TipoPilha* pilha, int lim, int valor){
	if(pilha->topo < lim){
		pilha->topo++;

		pilha->elementos[pilha->topo] = valor;

		return true;
	}else{
		return false;
	}
}

bool RemoverPilhaArr(TipoPilha* pilha, int* valorRemovido){
	if(pilha->topo >= pilha->base){
		*valorRemovido = pilha-> elementos[pilha->topo];
		pilha->topo--;

		return true;
	}else{
		return false;
	}

}

bool ConsultarPilhaArr(TipoPilha* pilha, int* valor, int posicaoConsultada){
	if(posicaoConsultada == -999){
		if(pilha->topo >= pilha->base){
			*valor = pilha->elementos[pilha->topo];
			return true;
		}else{
			return false;
		}
	}else{
		if(pilha->topo >= pilha->base){
			*valor = pilha->elementos[pilha->topo - posicaoConsultada];
			return true;
		}else{
			return false;
		}
	}
}

void LiberarPilha(TipoPilha* pilha){
	free(pilha->elementos);
	free(pilha);
}
