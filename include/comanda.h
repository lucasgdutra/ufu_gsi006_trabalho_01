/* --------------------------------------------------------------------------------------
 Nesse arquivo temos o foco na criaçao da comanda. Portanto, deve ser permitido,
adicionar item a comanda, somar o valor da comanda. Objetivo: Trabalho da
disciplina Estrutura de dados (GSI006) BSI - Facom - UFU Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/
#ifndef COMANDA_H
#define COMANDA_H

#include "./lista.h"
#include "./produto.h"

/*
	Struct Comanda possui uma Lista_Ordenada.
*/
typedef struct comanda {
	Lista_Ordenada *lista;
} Comanda;

/*
 Nome: inicializa_comanda
 Entrada: Ponteiro do tipo Comanda.
 Processo: testa validadade do ponteiro, depois aloca memoria da lista, e faz
 ela apontar pra struct comanda 
 Saida: return 0 caso dê certo, e 1 caso dê
 errado.
 */
int inicializa_comanda(Comanda *comanda);

/*
 Nome: adiciona_item_comanda
 Entrada: Ponteiro do tipo Comanda e o ponteiro do Produto que sera adicionado.
 Processo: Testa validadade dos ponteiros, posteriormente, adiciona na lista o
 Produto recebido 
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int adiciona_item_comanda(Comanda *comanda, Produto *p);

/*
 Nome: soma_valor_comanda
 Entrada: Ponteiro do tipo Comanda e ponteiro do tipo float para devolver o
 resultado. Processo: testa validadade dos ponteiros, e como estamos tratando
 uma lista encadeada, criamos um node e apontamos para o primemiro node, e
 varremos até que o proximo node seja NULO, condi- ção de parada para sair do
 laço, enquanto isso, o valor vai sendo acumulado na variavel soma que dps é
 atribuido para o ponteiro resultado. 
 Saida: return 0 caso dê certo, e 1 caso dê
 errado.
 */
int soma_valor_comanda(Comanda *comanda, float *resultado);

#endif
