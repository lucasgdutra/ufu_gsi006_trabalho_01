/* --------------------------------------------------------------------------------------
   Comanda
   Objetivo: Trabalho de disciplina Estrutura de dados (GSI006) BSI - Facom -
UFU Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/

#include "../include/comanda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializa_comanda(Comanda *comanda) {
	// testa se ponteiro eh valido
	if (comanda == NULL) {
		return 1;
	}
	Lista_Ordenada *lista;
	lista = (Lista_Ordenada *)malloc(sizeof(Lista_Ordenada));
	inicializa_lista(lista, sizeof(Produto));
	comanda->lista = lista;
	return 0;
}

int adiciona_item_comanda(Comanda *comanda, Produto *produto) {
	// testa se ponteiro eh valido
	if (comanda == NULL || produto == NULL) {
		return 1;
	}
	int status = adiciona_em_lista(comanda->lista, produto, produto->id);
	if (status != 0)
		return 1;

	return 0;
}

int remove_item_comanda(Comanda *comanda, Produto *retorno_produto, int id) {

	if (comanda == NULL || retorno_produto == NULL) {
		return 1;
	}
	int status = remove_da_lista(comanda->lista, retorno_produto, id);
	if (status != 0)
		return 1;
	return 0;
}

int soma_valor_comanda(Comanda *comanda, float *resultado) {
	// testa se ponteiro eh valido
	if (comanda == NULL || resultado == NULL) {
		return 1;
	}
	Node_Lista *node_atual = comanda->lista->primeiro;
	float soma = 0;
	while (node_atual != NULL) {
		Produto *p = (Produto *)node_atual->dados;
		soma += p->preco;
		node_atual = node_atual->proximo_node;
	}
	*resultado = soma;
	return 0;
}
