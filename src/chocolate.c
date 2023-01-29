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
	int status;
	p = malloc(sizeof(Pilha));
	status = inicializa_pilha(p, sizeof(Chocolate));
	if (status != 0) {
		return 1;
	}
	pc->pilha = p;
	return 0;
};

int empilha_chocolate(Pilha_Chocolate *pc, Chocolate *c) {
	// testa se ponteiro eh valido
	if (pc == NULL || c == NULL) {
		return 1;
	}
	int status;
	status = empilha(pc->pilha, c);
	if (status != 0) {
		return 1;
	}
	return 0;
}

int desempilha_chocolate(Pilha_Chocolate *pc, Chocolate *choco_retorno) {
	// testa se ponteiro eh valido
	if (pc == NULL || choco_retorno == NULL) {
		return 1;
	}
	int status;
	status = desempilha(pc->pilha, choco_retorno);
	if (status != 0) {
		return 1;
	}
	return 0;
}
