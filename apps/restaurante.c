/* --------------------------------------------------------------------------------------
   Programa que implementa um sistema de atendimento de um restaurante, com
cardápio, comanda e brindes de chocolates para clientes. Objetivo: Trabalho de
disciplina Estrutura de dados (GSI006) BSI - Facom - UFU Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/

#include "restaurante.h"
#include "../include/modulo_cardapio.h"
#include "../include/modulo_chocolate.h"
#include "../include/modulo_cliente.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
			case 3: {
				int tamanho_cardapio;
				retorna_tamanho_cardapio(&cardapio, &tamanho_cardapio);
				if (tamanho_cardapio != 0) {
					incluir_clientes_fila(&fila_cliente, &cardapio);
				} else {
					printf("Eh necessario ter itens no cardapio para incluir "
						   "clientes na fila");
				}
			}

			break;
			case 4:
				atender_cliente(&fila_cliente);
				break;
			case 5:
				imprimir_cardapio(&cardapio);
				break;
			case 6:
				imprime_pilha_chocolate(&pilha_chocolate);
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
