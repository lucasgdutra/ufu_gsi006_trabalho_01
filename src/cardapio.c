/* --------------------------------------------------------------------------------------
   Nesse arquivo temos a construçao do cardapio do nosso restaurante.
   Objetivo: Trabalho da disciplina Estrutura de dados (GSI006) BSI - Facom -
UFU Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 29/01/2023
----------------------------------------------------------------------------------------*/

#include "../include/cardapio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 Nome: inicializa_cardapio
 Entrada: Ponteiro da struct Cardapio que contem uma lista_ordenada
 Processo: Função verifica se o cardapio passado foi alocado, em seguida aloca a
 lista na memoria e passa a lista alocada para o cardapio recebido. Saida:
 return 0 caso dê certo, e 1 caso dê errado.
 */
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

/*
 Nome: adiciona_item_cardapio
 Entrada:Ponteiro do tipo Cardapio e ponteiro do tipo Produto.
 Processo: verifica se cardapio ou produto está alocado, posteriormente adiciona
 na lista do cardapio um produto Saida: retorna 1 em caso de erro e 0 em caso de
 sucesso.
 */
int adiciona_item_cardapio(Cardapio *cardapio, Produto *produto) {

	if (cardapio == NULL || produto == NULL) {
		return 1;
	}
	int status = adiciona_em_lista(cardapio->lista, produto, produto->id);
	if (status != 0)
		return 1;
	return 0;
}

/*
 Nome: remove_item_cardapio
 Entrada: Ponteiro do tipo Cardapio e ponteiro do tipo Produto e um inteiro
 indicando o id. Processo: Verifica se cardapio e produto existem na memória e
 posteriormente remove um elemento da lista do Cardapio atraves do ID. Saida:
 retorna 1 em caso de erro e 0 em caso de sucesso.
 */
int remove_item_cardapio(Cardapio *cardapio, Produto *retorno_produto, int id) {

	if (cardapio == NULL || retorno_produto == NULL) {
		return 1;
	}
	int status = remove_da_lista(cardapio->lista, retorno_produto, id);
	if (status != 0)
		return 1;
	return 0;
}

/*
 Nome: retorna_item_cardapio
 Entrada: Ponteiro do tipo Cardapio e ponteiro de inteiro que receberá o tamanho
 retornado. Processo:Verifica se ponteiro eh valido, posteriormente, *retorno
 tamanho recebe o tamanho da lista de cardapio. Saida: retorna 1 em caso de erro
 e 0 em caso de sucesso.
 */
int retorna_tamanho_cardapio(Cardapio *cardapio, int *retorno_tamanho) {

	if (cardapio == NULL || retorno_tamanho == NULL) {
		return 1;
	}
	*retorno_tamanho = cardapio->lista->tamanho_lista;
	return 0;
}

/*
 Nome: buscar_item_cardapio
 Entrada: Ponteiro de Cardapio, ponteiro do tipo Produto, e um int indicando
 posicao Processo:Primeiro os ponteiros sao testados se estao validos,
 posteriormente, eh buscado na lista atraves da posicao, e é retornado um
 Produto. Saida: retorna 1 em caso de erro e 0 em caso de sucesso.
 */
int buscar_item_cardapio(Cardapio *cardapio, int posicao,
						 Produto *retorno_produto) {

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
