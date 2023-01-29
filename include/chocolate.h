/* --------------------------------------------------------------------------------------
   Nesse arquivo temos o header da parte do chocolate, haja vista que teremos uma pilha
   de chocolate que será distruibida como brinde no nosso restaurante. Portanto, é preciso 
   que eu consiga ter uma pilha de chocolate e aloca-los nessa estrutura.
   Objetivo: Trabalho da disciplina Estrutura de dados (GSI006) BSI - Facom -
UFU Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/
#ifndef CHOCOLATE_H
#define CHOCOLATE_H

#include "./pilha.h"

/*
	Struct chamada Chocolate, que contem um ponteiro pra char indicando nome e
   um int indicando tamanho desse nome.
*/
typedef struct chocolate {
	char *nome;
	int tamanho_nome;
} Chocolate;

/*
 Nome: inicializa_chocolate
 Entrada: Ponteiro do tipo Chocolate, ponteiro do tipo char indicando nome, e
 int tam_nome Processo:  Valida os ponteiros recebidos, e atribui nome e
 tamanho_nome para a struct Chocolate recebida
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int inicializa_chocolate(Chocolate *chocolate, char *nome, int tamanho_nome);

/*
	Struct Pilha_Chocolate que contem um ponteiro do tipo Pilha, para
   possibilitar criarmos nossa Pilha de Chocolate.
*/
typedef struct pilha_chocolate {
	Pilha *pilha;
} Pilha_Chocolate;

/*
 Nome: inicializa_pilha_chocolate
 Entrada: A função recebe um ponteiro do tipo Pilha_Chocolate.
 Processo: Função verifica se os ponteiros sao validos, posteriormente aloca a
 Pilha e passa a pilha alocada para pc. 
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int inicializa_pilha_chocolate(Pilha_Chocolate *pilha_chocolate);

/*
 Nome: empilha_chocolate
 Entrada: A função recebe um ponteiro do tipo Pilha_Chocolate e um ponteiro do
 tipo Chocolate Processo: Função verifica se os ponteiros sao validos, empilha o
 chocolate que é passado pra função. 
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int empilha_chocolate(Pilha_Chocolate *pilha_chocolate, Chocolate *chocolate);

/*
 Nome: desempilha_chocolate
 Entrada: A função recebe um ponteiro do tipo Pilha_Chocolate e um ponteiro do
 tipo Chocolate Processo: Função verifica se os ponteiros sao validos,
 desempilha o chocolate caso seja possivel e passa o ponteiro choco_retorno para
 caso desempilhar, receber o elemento desempilhado.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int desempilha_chocolate(Pilha_Chocolate *pilha_chocolate,
						 Chocolate *retorno_chocolate);

#endif
