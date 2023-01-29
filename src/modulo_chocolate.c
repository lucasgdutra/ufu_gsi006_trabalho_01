#include "../include/modulo_chocolate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inserir_chocolates_pilha(Pilha_Chocolate *pilha_chocolate) {
	// testa se ponteiro eh valido
	if (pilha_chocolate == NULL) {
		return 1;
	}
	Chocolate *chocolate;
	int status;

	chocolate = (Chocolate *)malloc(sizeof(Chocolate));
	char *nome;
	int tamanho_nome = 15;

	nome = (char *)malloc(sizeof(char) * tamanho_nome);
	if (nome == NULL) {
		printf("nao foi alocado..\n");
		return 1;
	}

	printf("Insira o chocolate: \n");
	if (scanf("%s", nome) != 1)
		return 1;

	status = inicializa_chocolate(chocolate, nome, tamanho_nome);
	if (status != 0) {
		printf("erro em inicializa_chocolate em funcao "
			   "inserir_chocolates_pilha\n");
		return 1;
	}
	status = empilha_chocolate(pilha_chocolate, chocolate);
	if (status != 0) {
		printf(
			"erro em empilha_chocolate em funcao inserir_chocolates_pilha\n");
		return 1;
	}
	return 0;
}

int imprime_pilha_chocolate(Pilha_Chocolate *pc) {
	// testa se ponteiro eh valido
	if (pc == NULL) {
		return 1;
	}
	// verifica se a pilha ta vazia..
	if (pc->pilha->tamanho_pilha == 0) {
		printf("Pilha de chocolates vazia\n");
	}

	// varre a pilha pelo topo e depois passa para o proximo node até chegar no
	// NULL
	Node_Pilha *current = pc->pilha->topo;
	while (current != NULL) {
		printf("%s \n", ((Chocolate *)current->dados)->nome);
		current = current->proximo_node;
	}
	printf("\n");
	return 0;
}