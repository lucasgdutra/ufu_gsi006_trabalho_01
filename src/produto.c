#include "../include/produto.h"
#include <stdlib.h>
#include <string.h>

int inicializa_produto(Produto *produto, int id, char *nome, int tam_nome,
					   float preco) {
	// testa se ponteiro eh valido
	if (produto == NULL || nome == NULL) {
		return 1;
	}
	produto->id = id;

	produto->tam_nome = tam_nome;
	produto->nome = (char *)malloc(sizeof(char) * tam_nome);
	memcpy(produto->nome, nome, produto->tam_nome);

	produto->preco = preco;

	return 0;
}

int retorna_id_produto(Produto *produto, int *retorno_id) {
	// testa se ponteiro eh valido
	if (produto == NULL || retorno_id == NULL) {
		return 1;
	}
	*retorno_id = produto->id;
	return 0;
}

int retorna_nome_produto(Produto *produto, char *retorno_nome) {
	if (produto == NULL || retorno_nome == NULL) {
		return 1;
	}
	memcpy(retorno_nome, produto->nome, produto->tam_nome);
	return 0;
}

int retorna_preco_produto(Produto *produto, float *retorno_preco) {
	if (produto == NULL || retorno_preco == NULL) {
		return 1;
	}
	*retorno_preco = produto->preco;
	return 0;
}
