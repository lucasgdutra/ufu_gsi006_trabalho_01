#include "../include/chocolate.h"
#include "../include/pilha.h"
#include <stdio.h>
#include <stdlib.h>

int inicializa_chocolate(Chocolate *c, char *nome, int tamanho_nome) {
	// testa se ponteiro eh valido
	if (c == NULL || nome == NULL) {
		return 1;
	}
	c->nome = nome;
	c->tamanho_nome = tamanho_nome;
	return 0;
};

int inicializa_pilha_chocolate(Pilha_Chocolate *pc) {
	// testa se ponteiro eh valido
	if (pc == NULL) {
		return 1;
	}
	Pilha *p;
	p = malloc(sizeof(Pilha));
	inicializa_pilha(p, sizeof(Chocolate));
	pc->pilha = p;
	return 0;
};

int empilha_chocolate(Pilha_Chocolate *pc, Chocolate *c) {
	// testa se ponteiro eh valido
	if (pc == NULL || c == NULL) {
		return 1;
	}
	empilha(pc->pilha, c);
	return 0;
}

int desempilha_chocolate(Pilha_Chocolate *pc, Chocolate *choco_retorno) {
	// testa se ponteiro eh valido
	if (pc == NULL || choco_retorno == NULL) {
		return 1;
	}
	desempilha(pc->pilha, choco_retorno);
	return 0;
}

int imprime_chocolate(Pilha_Chocolate *pc) {
	// testa se ponteiro eh valido
	if (pc == NULL) {
		return 1;
	}
	// verifica se a pilha ta vazia..
	if (pc->pilha->tamanho_pilha == 0) {
		printf("Pilha vazia...\n");
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
