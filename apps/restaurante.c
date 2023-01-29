/* --------------------------------------------------------------------------------------
   Programa que implementa um sistema de atendimento de um restaurante, com
cardápio, comanda e brindes de chocolates para clientes. Objetivo: Trabalho de
disciplina Estrutura de dados (GSI006) BSI - Facom - UFU Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/

#include "../include/cardapio.h"
#include "../include/chocolate.h"
#include "../include/cliente.h"
#include "../include/fila.h"
#include "../include/lista.h"
#include "../include/pilha.h"
#include "../include/produto.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int leitura_produto(Produto *produto_retorno) {
	// testa se ponteiro eh valido
	if (produto_retorno == NULL) {
		return 1;
	}
	int id, tam_nome = 15, status;
	char *nome;
	float preco;

	printf("ID do produto: \n");
	scanf("%d", &id);

	nome = (char *)malloc(sizeof(char) * tam_nome);
	if (nome == NULL) {
		printf("nao foi alocado..\n");
		return 1;
	}
	printf("Nome do produto: \n");
	if (scanf("%s", nome) != 1)
		return 1;

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

int inserir_itens_comanda(Comanda *comanda) {
	// testa se ponteiro eh valido
	if (comanda == NULL) {
		return 1;
	}
	int status;
	Produto *produto;
	produto = (Produto *)malloc(sizeof(Produto));

	status = leitura_produto(produto);
	if (status != 0) {
		printf("Erro leitura_produto em funcao inserir_itens_comanda\n");
		return 1;
	}
	status = adiciona_item_comanda(comanda, produto);
	if (status != 0) {
		printf("Erro adiciona_item_cardapio em funcao inserir_itens_comanda\n");
		return 1;
	}
	printf("item inserido na comanda..\n");

	return 0;
}

int incluir_clientes_fila(Fila_Cliente *fila_cliente) {
	// testa se ponteiro eh valido
	if (fila_cliente == NULL) {
		printf(
			"ponteiro fila_cliente em funcao incluir_clientes_fila invalido");
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
	status = inserir_itens_comanda(comanda);
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
			status = inserir_itens_comanda(comanda);
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

int atender_cliente(Fila_Cliente *fila_cliente) {
	// testa se ponteiro eh valido
	if (fila_cliente == NULL) {
		return 1;
	}
	printf("em desenvolvimento..\n");

	return 0;
}

int imprimir_cardapio(Cardapio *cardapio) {
	// testa se ponteiro eh valido
	if (cardapio == NULL) {
		return 1;
	}
	mostrar_cardapio(cardapio);

	return 0;
}

int imprimir_fila_clientes(Fila_Cliente *fila_cliente) {
	// testa se ponteiro eh valido
	if (fila_cliente == NULL) {
		return 1;
	}
	printf("em desenvolvimento..\n");
	return 0;
}

int print_menu(int *opcao) {
	// testa se ponteiro eh valido
	if (opcao == NULL) {
		return 1;
	}
	printf("\n");
	printf("Escolha uma das opções do menu\n");
	printf("0 - Sair do programa\n");
	printf("1 - Inserir itens no cardapio\n");
	printf("2 - Inserir chocolates na pilha\n");
	printf("3 - Incluir clientes na fila\n");
	printf("4 - Atender cliente na fila\n");
	printf("5 - Imprimir cardapio\n");
	printf("6 - Imprimir pilha de chocolates\n");
	printf("7 - Imprimir fila de clientes\n");
	if (scanf("%d", opcao) != 1)
		return 1;
	return 0;
}

int main() {
	Pilha_Chocolate pilha_chocolate;
	Cardapio cardapio;
	Fila_Cliente fila_cliente;

	inicializa_pilha_chocolate(&pilha_chocolate);
	inicializa_cardapio(&cardapio);
	inicializa_fila_cliente(&fila_cliente);

	int opcao;
	while (true) {
		print_menu(&opcao);
		switch (opcao) {
			case 0:
				printf("saindo...\n");
				return 0;
				break;
			case 1:
				inserir_itens_cardapio(&cardapio);
				break;
			case 2:
				inserir_chocolates_pilha(&pilha_chocolate);
				break;
			case 3:
				incluir_clientes_fila(&fila_cliente);
				break;
			case 4:
				atender_cliente(&fila_cliente);
				break;
			case 5:
				imprimir_cardapio(&cardapio);
				break;
			case 6:
				imprime_chocolate(&pilha_chocolate);
				break;
			case 7:
				imprimir_fila_clientes(&fila_cliente);
				break;
			default:
				printf("Opcao invalida\n");
				break;
		}
	}

	return 0;
}
