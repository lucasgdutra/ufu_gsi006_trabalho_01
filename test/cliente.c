#include "../include/cliente.h"
#include "../include/comanda.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR_SIZE 100
int main() {
	Cliente cliente;
	Comanda comanda;
	inicializa_comanda(&comanda);

	int id;
	float preco;
	char nome[MAX_CHAR_SIZE];
	char nome_cliente[MAX_CHAR_SIZE];
	scanf("%s", nome_cliente);
	inicializa_cliente(&cliente, nome_cliente, MAX_CHAR_SIZE, &comanda);
	while (fscanf(stdin, "%d %s %f", &id, nome, &preco) != EOF) {
		Produto *produto;
		produto = (Produto *)malloc(sizeof(Produto));
		inicializa_produto(produto, id, nome, MAX_CHAR_SIZE, preco);
		adiciona_item_comanda(&comanda, produto);
	}
	printf("nome cliente:%s\n", cliente.nome);
	while (cliente.comanda->lista->tamanho_lista != 0) {
		Produto produtoRetorno;
		remove_item_comanda(&comanda, &produtoRetorno,
							comanda.lista->primeiro->pos);

		int id_retorno;
		retorna_id_produto(&produtoRetorno, &id_retorno);

		char nome_retorno[MAX_CHAR_SIZE];
		retorna_nome_produto(&produtoRetorno, nome_retorno);

		float preco_retorno;
		retorna_preco_produto(&produtoRetorno, &preco_retorno);

		printf("Id: %d, nome:%s, preco:%.2f\n", id_retorno, nome_retorno,
			   preco_retorno);
	}

	return 0;
}