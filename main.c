/*
 * linha.c
 *
 *  Created on: 30 de jul de 2024
 *      Author: user
 */


#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char **argv) {
	setlocale(LC_ALL, "Portuguese");
	setbuf(stdout, NULL);

	TipoPilha *pilha;
	bool sucesso;
	int topo, posicaoConsultada, valorConsultado, valorRemovido;

	pilha = InicializarPilhaArr(0, 9);

	for(int i = 0; i < 9; i++)
	{
		sucesso = InserirPilhaArr(pilha, 8, i);

		if(sucesso){
			printf("Valor inserido: %d\n", i);
		}
	}

	sucesso = ConsultarPilhaArr(pilha, &topo, -999);

	if(sucesso){
		printf("\nO valor no topo da pilha é: %d\n", topo);
	}

	printf("\nQual posição da pilha deseja consultar?\n");
	scanf("%d", &posicaoConsultada);

	if(posicaoConsultada <= pilha->topo && posicaoConsultada >= 0){
		for(int i = 0; i <= pilha->topo; i++){
			if(pilha->topo - i == posicaoConsultada){
				sucesso = ConsultarPilhaArr(pilha, &valorConsultado, i);
				if(sucesso){
					printf("\nO valor na posição %d da pilha é: %d\n", posicaoConsultada, valorConsultado);
				}
			}
		}
	}else{
		printf("Valor inválido\n");

		return 0;
	}

	RemoverPilhaArr(pilha, &valorRemovido);

	printf("\nO valor removido do topo é: %d", valorRemovido);

	LiberarPilha(pilha);

	return 0;
}
