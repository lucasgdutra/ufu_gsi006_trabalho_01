#include "../include/modulo_cliente.h"
#include "../include/modulo_cardapio.h"
#include "../include/modulo_chocolate.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int inserir_itens_comanda(Comanda *comanda, Cardapio *cardapio) {
	// testa se ponteiro eh valido
	if (comanda == NULL || cardapio == NULL) {
		printf("ponteiro comanda ou cardapio em funcao inserir_itens_comanda "
			   "invalido");
		return 1;
	}
	int status, id;
	Produto *produto;
	produto = (Produto *)malloc(sizeof(Produto));
	imprimir_cardapio(cardapio);
	printf("Digite o ID do produto a ser incluido na comanda\n");
	scanf("%d", &id);
	status = buscar_item_cardapio(cardapio, id, produto);
	if (status != 0) {
		printf(
			"erro em buscar_item_cardapio em funcao inserir_itens_comanda\n");
	}
	status = adiciona_item_comanda(comanda, produto);
	if (status != 0) {
		printf("Erro adiciona_item_cardapio em funcao inserir_itens_comanda\n");
		return 1;
	}
	printf("item inserido na comanda..\n");

	return 0;
}

int incluir_clientes_fila(Fila_Cliente *fila_cliente, Cardapio *cardapio) {
	// testa se ponteiro eh valido
	if (fila_cliente == NULL || cardapio == NULL) {
		printf("ponteiro fila_cliente ou cardapio em funcao "
			   "incluir_clientes_fila invalido");
		return 1;
	}
	int status, tamanho_nome = 30, entrada;
	char *nome;

	Cliente *cliente;
	Comanda *comanda;

	cliente = (Cliente *)malloc(sizeof(Cliente));
	comanda = (Comanda *)malloc(sizeof(Comanda));

	nome = (char *)malloc(sizeof(char) * tamanho_nome);
	if (nome == NULL) {
		printf("Erro ao alocar nome em funcao incluir_clientes_fila\n");
		return 1;
	}

	printf("Digite o nome do cliente\n");
	scanf("%s", nome);

	status = inicializa_comanda(comanda);
	if (status != 0) {
		printf("Erro inicializa_comanda em funcao incluir_clientes_fila\n");
		return 1;
	}
	status = inserir_itens_comanda(comanda, cardapio);
	if (status != 0) {
		printf("Erro inserir_itens_comanda em funcao incluir_clientes_fila\n");
		return 1;
	}
	while (true) {
		printf("Deseja inserir mais itens na comanda?\n");
		printf("Digite 1 para Sim\n");
		printf("Digite 0 para Nao\n");
		scanf("%d", &entrada);
		if (entrada == 0) {
			break;
		}
		if (entrada == 1) {
			status = inserir_itens_comanda(comanda, cardapio);
			if (status != 0) {
				printf("Erro inserir_itens_comanda em funcao "
					   "incluir_clientes_fila\n");
				return 1;
			}
		} else {
			printf("entrada invalida, entradas aceitas 0 ou 1\n");
		}
	}
	status = inicializa_cliente(cliente, nome, tamanho_nome, comanda);
	if (status != 0) {
		printf("Erro inicializa_cliente em funcao incluir_clientes_fila\n");
		return 1;
	}
	status = adiciona_cliente_fila(fila_cliente, cliente);
	if (status != 0) {
		printf("Erro adiciona_cliente_fila em funcao incluir_clientes_fila\n");
		return 1;
	}
	printf("cliente inserido na fila..\n");

	return 0;
}

int atender_cliente(Fila_Cliente *fila_cliente,
					Pilha_Chocolate *pilha_chocolate) {
	// testa se ponteiro eh valido
	if (fila_cliente == NULL) {
		printf("ponteiro fila_cliente invalido em funcao "
			   "atender_cliente\n");
		return 1;
	}
	int status;
	if (fila_cliente->fila->tamanho_fila == 0) {
		printf("fila de clientes vazia\n");
		return 0;
	}
	Node_Fila *node_atual = fila_cliente->fila->primeiro;
	if (node_atual == NULL) {
		printf("erro ponteiro node_atual invalido em funcao "
			   "atender_cliente\n");
		return 1;
	}
	Cliente *cliente = (Cliente *)node_atual->dados;
	Comanda *comanda = cliente->comanda;
	float soma_comanda_cliente;
	soma_valor_comanda(comanda, &soma_comanda_cliente);

	printf("cliente nome: %s\n", cliente->nome);
	printf("valor total comanda cliente: %f\n", soma_comanda_cliente);
	if (pilha_chocolate != NULL) {
		Chocolate *chocolate;
		chocolate = (Chocolate *)malloc(sizeof(Chocolate));
		status = desempilha_chocolate(pilha_chocolate, chocolate);
		if (status != 0) {
			printf("erro em desempilha_chocolate em funcao atender_cliente\n");
			return 1;
		}
		printf("chocolate entregue ao cliente: %s\n", chocolate->nome);
	} else {
		printf("nao existem chocolates na pilha para entregar ao cliente\n");
	}

	return 0;
}

int imprimir_fila_clientes(Fila_Cliente *fila_cliente) {
	// testa se ponteiro eh valido
	if (fila_cliente == NULL) {
		return 1;
		printf("Ponteiro fila_cliente invalido em funcao "
			   "imprimir_fila_clientes\n");
	}
	if (fila_cliente->fila->tamanho_fila == 0) {
		printf("Fila de clientes vazia\n");
		return 0;
	}
	Node_Fila *node_atual;
	node_atual = fila_cliente->fila->primeiro;
	while (true) {
		if (node_atual == NULL) {
			break;
		}
		Cliente *cliente = (Cliente *)node_atual->dados;
		printf("cliente nome: %s\n", cliente->nome);

		Comanda *comanda = (Comanda *)cliente->comanda;
		if (comanda->lista->tamanho_lista == 0) {
			printf("Comanda do cliente %s vazia\n", cliente->nome);
		} else {
			printf("Comanda:\n");
			Node_Lista *node_atual_comanda = comanda->lista->primeiro;
			while (true) {
				if (node_atual_comanda == NULL) {
					break;
				}
				Produto *produto = (Produto *)node_atual_comanda->dados;
				printf("produto id: %d, produto nome: %s, produto preço: %f\n",
					   produto->id, produto->nome, produto->preco);
				node_atual_comanda = node_atual_comanda->proximo_node;
			}
		}

		node_atual = node_atual->proximo_node;
	}

	return 0;
}