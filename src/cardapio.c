#include "../include/cardapio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializa_cardapio(Cardapio *cardapio) {
	// testa se ponteiro eh valido
	if (cardapio == NULL) {
		return 1;
	}
	Lista_Ordenada *l;
	l = (Lista_Ordenada *)malloc(sizeof(Lista_Ordenada));
	inicializa_lista(l, sizeof(Produto));
	cardapio->lista = l;
	return 0;
}

int adiciona_item_cardapio(Cardapio *cardapio, Produto *produto) {
	// testa se ponteiro eh valido
	if (cardapio == NULL || produto == NULL) {
		return 1;
	}
	int status = adiciona_em_lista(cardapio->lista, produto, produto->id);
	if (status != 0)
		return 1;
	return 0;
}

int remove_item_cardapio(Cardapio *cardapio, Produto *retorno_produto, int id) {
	// testa se ponteiro eh valido
	if (cardapio == NULL || retorno_produto == NULL) {
		return 1;
	}
	int status = remove_da_lista(cardapio->lista, retorno_produto, id);
	if (status != 0)
		return 1;
	return 0;
}

int retorna_tamanho_cardapio(Cardapio *cardapio, int *retorno_tamanho) {
	// testa se ponteiro eh valido
	if (cardapio == NULL || retorno_tamanho == NULL) {
		return 1;
	}
	*retorno_tamanho = cardapio->lista->tamanho_lista;
	return 0;
}

int buscar_item_cardapio(Cardapio *cardapio, int posicao,
						 Produto *retorno_produto) {
	// testa se ponteiro eh valido
	if (cardapio == NULL || retorno_produto == NULL) {
		return 1;
	}
	int status;
	status = buscar_item_lista(cardapio->lista, posicao, retorno_produto);
	if (status != 0) {
		return 1;
	}
	return 0;
}