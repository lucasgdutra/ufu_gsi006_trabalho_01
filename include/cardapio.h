/* --------------------------------------------------------------------------------------
   Nesse arquivo temos a construçao do cardapio do nosso restaurante. NO qual
usaremos uma lista_ordenada e dinamica para ligar nossos Produtos, sendo assim,
constituindo um cardapio. Objetivo: Trabalho da disciplina Estrutura de dados
(GSI006) BSI - Facom - UFU Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/

#ifndef CARDAPIO_H
#define CARDAPIO_H

#include "./lista.h"
#include "./produto.h"

/*
	Struct Cardapio que contem o ponteiro do tipo Lista_Ordenada, indicando uma
   Lista.
*/
typedef struct cardapio {
	Lista_Ordenada *lista;
} Cardapio;

/*
 Nome: inicializa_cardapio
 Entrada: Ponteiro da struct Cardapio que contem uma lista_ordenada
 Processo: Função verifica se o cardapio passado foi alocado, em seguida aloca a
 lista na memoria e passa a lista alocada para o cardapio recebido.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int inicializa_cardapio(Cardapio *cardapio);

/*
 Nome: adiciona_item_cardapio
 Entrada:Ponteiro do tipo Cardapio e ponteiro do tipo Produto.
 Processo: verifica se cardapio ou produto está alocado, posteriormente adiciona
 na lista do cardapio um produto 
 Saida: retorna 1 em caso de erro e 0 em caso de sucesso.
 */
int adiciona_item_cardapio(Cardapio *cardapio, Produto *p);

/*
 Nome: remove_item_cardapio
 Entrada: Ponteiro do tipo Cardapio e ponteiro do tipo Produto e um inteiro
 indicando o id. Processo: Verifica se cardapio e produto existem na memória e
 posteriormente remove um elemento da lista do Cardapio atraves do ID.
 Saida: retorna 1 em caso de erro e 0 em caso de sucesso.
 */
int remove_item_cardapio(Cardapio *cardapio, Produto *retorno_produto, int id);

/*
 Nome: retorna_tamanho_cardapio
 Entrada: Ponteiro do tipo Cardapio e ponteiro de inteiro que receberá o tamanho
 retornado. Processo:Verifica se ponteiro eh valido, posteriormente, *retorno
 tamanho recebe o tamanho da lista de cardapio.
 Saida: retorna 1 em caso de erro e 0 em caso de sucesso.
 */
int retorna_tamanho_cardapio(Cardapio *cardapio, int *retorno_tamanho);

/*
 Nome: buscar_item_cardapio
 Entrada: Ponteiro de Cardapio, ponteiro do tipo Produto, e um int indicando
 posicao Processo:Primeiro os ponteiros sao testados se estao validos,
 posteriormente, eh buscado na lista atraves da posicao, e é retornado um
 Produto. 
 Saida: retorna 1 em caso de erro e 0 em caso de sucesso.
 */
int buscar_item_cardapio(Cardapio *cardapio, int posicao,
						 Produto *retorno_produto);
#endif
