#ifndef CHOCOLATE_H
#define CHOCOLATE_H

#include "./pilha.h"

typedef struct chocolate {
	char *nome;
	int tamanho_nome;
} Chocolate;

int inicializa_chocolate(Chocolate *chocolate, char *nome, int tamanho_nome);

typedef struct pilha_chocolate {
	Pilha *pilha;
} Pilha_Chocolate;

int inicializa_pilha_chocolate(Pilha_Chocolate *pilha_chocolate);

int empilha_chocolate(Pilha_Chocolate *pilha_chocolate, Chocolate *chocolate);

int desempilha_chocolate(Pilha_Chocolate *pilha_chocolate,
						 Chocolate *retorno_chocolate);

#endif
