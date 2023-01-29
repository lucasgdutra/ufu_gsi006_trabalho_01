/* --------------------------------------------------------------------------------------
 Nesse arquivo temos o foco no cliente. E temos o objetivo de permitir o
cliente ser adicionado/removido da fila, e feito o cadastro do mesmo no
restaurante.
   Objetivo: Trabalho da disciplina Estrutura de dados (GSI006) BSI -
Facom - UFU Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/
#ifndef CLIENTE_H
#define CLIENTE_H

#include "./comanda.h"
#include "./fila.h"

/*
	Struct Cliente, tem como atributo um ponteiro de char indicando nome, int
   para tam_nome e uma Struct Comanda, indicando a Comanda do cliente.
*/
typedef struct cliente {
	char *nome;
	int tamanho_nome;
	Comanda *comanda;
} Cliente;

/*
 Nome: inicializa_cliente
 Entrada: Ponteiro para Cliente, ponteiro do tipo char indicando nome , int
 tam_nome e um ponteiro do tipo Comanda. Processo: testa validadade dos
 ponteiros, e aloca na struct Cliente, os valores passados. Saida: return 0 caso
 dê certo, e 1 caso dê errado.
 */
int inicializa_cliente(Cliente *c, char *nome, int tamanho_nome,
					   Comanda *comanda);

/*
	Struct Fila_Cliente, indicando que existira uma Fila de CLientes.
*/
typedef struct fila_cliente {
	Fila *fila;
} Fila_Cliente;

/*
 Nome: inicializa_fila_cliente
 Entrada: Ponteiro do tipo Fila_Cliente
 Processo: Testa validade dos ponteiros, aloca a Fila e atribui a fila alocada
 para Fila_cliente. Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int inicializa_fila_cliente(Fila_Cliente *fc);

/*
 Nome: adiciona_cliente_fila
 Entrada: Ponteiro do tipo Fila_Cliente e um ponteiro do tipo Cliente.
 Processo: Testa validade dos ponteiros,e adiciona ao final da fila o Cliente
 passado. Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int adiciona_cliente_fila(Fila_Cliente *fc, Cliente *c);

/*
 Nome: remove_cliente_fila
 Entrada: Ponteiro do tipo Fila_Cliente e um ponteiro do tipo Cliente.
 Processo: Testa validade dos ponteiros,e retira o cliente da fila atraves da
 primeira posicao, sendo assim, respeitando o conceito FIFO das filas. Saida:
 return 0 caso dê certo, e 1 caso dê errado.
 */
int remove_cliente_fila(Fila_Cliente *fc, Cliente *cliente_retorno);

#endif
