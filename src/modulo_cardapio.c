#include "../include/modulo_cardapio.h"
#include "../include/cardapio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leitura_produto(Produto *produto_retorno) {
	// testa se ponteiro eh valido
	if (produto_retorno == NULL) {
		return 1;
	}
	int id, tam_nome = 15, status;
	char *nome;
	char *buffer;
	float preco;

	printf("ID do produto: \n");
	scanf("%d", &id);

	nome = (char *)malloc(sizeof(char) * tam_nome);
	buffer = (char *)malloc(sizeof(char) * (tam_nome + 1));
	if (nome == NULL) {
		printf("nao foi alocado..\n");
		return 1;
	}
	printf("Nome do produto: \n");
	getchar();
	if (fgets(buffer, tam_nome, stdin) == NULL)
		return 1;
	// remove \n da string se existir
	buffer[strcspn(buffer, "\n")] = 0;
	memcpy(nome, buffer, tam_nome);
	free(buffer);

	printf("Preco produto: \n");
	scanf("%f", &preco);

	status = inicializa_produto(produto_retorno, id, nome, tam_nome, preco);
	if (status != 0) {
		printf("Erro em inicializa_produto em funcao inserir_itens_cardapio\n");
		return 1;
	}

	return 0;
}

int inserir_itens_cardapio(Cardapio *cardapio) {
	// testa se ponteiro eh valido
	if (cardapio == NULL) {
		return 1;
	}
	int status;
	Produto *produto;
	produto = (Produto *)malloc(sizeof(Produto));
	if (produto == NULL) {
		printf("Erro ao alocar produto em funcao inserir_itens_cardapio\n");
		return 1;
	}

	leitura_produto(produto);

	status = adiciona_item_cardapio(cardapio, produto);
	if (status != 0) {
		printf(
			"Erro adiciona_item_cardapio em funcao inserir_itens_cardapio\n");
		return 1;
	}
	printf("item inserido no cardapio..\n");

	return 0;
}

int imprimir_cardapio(Cardapio *cardapio) {
	// testa se ponteiro eh valido
	if (cardapio == NULL) {
		return 1;
	}
	// verifica se está vazio o cardapio..
	if (cardapio->lista->tamanho_lista == 0) {
		printf("está vazia..\n");
	}
	Produto p;
	Node_Lista *node_atual = cardapio->lista->primeiro;
	while (node_atual != NULL) {
		memcpy(&p, node_atual->dados, cardapio->lista->tamanho_estrutura_dados);
		printf("ID: %d, Nome: %s, Preco: %.2f\n", p.id, p.nome, p.preco);
		node_atual = node_atual->proximo_node;
	}

	return 0;
}
