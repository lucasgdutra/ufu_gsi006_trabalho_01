#include "../include/produto.h"
#include <stdlib.h>
#include <string.h>

int inicializa_produto(Produto *produto, int id, char *nome, int tam_nome, float preco){
	produto->id = id;

	produto->tam_nome = tam_nome;
	produto->nome = (char *)malloc(sizeof(char) * tam_nome);
	memcpy(produto->nome, nome, produto->tam_nome);

	produto->preco = preco;

	return 0;
}

int retorna_id_produto(Produto *produto, int *retorno_id) {
	*retorno_id = produto->id;
	return 0;
}

int retorna_nome_produto(Produto *produto, char *retorno_nome) {
	memcpy(retorno_nome, produto->nome, produto->tam_nome);
	return 0;
}

int retorna_preco_produto(Produto *produto, float *retorno_preco) {
	*retorno_preco = produto->preco;
	return 0;
}

