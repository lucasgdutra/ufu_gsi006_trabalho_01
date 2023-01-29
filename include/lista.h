/* --------------------------------------------------------------------------------------
   TAD Lista_Ordenada
   Objetivo: Trabalho de disciplina Estrutura de dados (GSI006) BSI - Facom -
UFU Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/
#ifndef LISTA_H
#define LISTA_H

typedef struct node_lista {
	int pos;
	void *dados;
	struct node_lista *proximo_node;
} Node_Lista;

typedef struct lista {
	Node_Lista *primeiro;
	int tamanho_lista;
	int tamanho_estrutura_dados;
} Lista_Ordenada;

/*inicializa estrutura lista com valores iniciais, retorna 0 se não houver
 * erro*/
int inicializa_lista(Lista_Ordenada *lista, int tamanho_estrutura_dados);

/*adiciona elemento ao final da lista, retorna 0 se não houver erro*/
int adiciona_em_lista(Lista_Ordenada *lista, void *dados, int pos);

/*remove elemento do inicio da lista e retorna valor removido pra ponteiro valor
 * do argumento, retorna 0 se não houver erro*/
int remove_da_lista(Lista_Ordenada *lista, void *valor, int pos);

/*remove todos elementos da lista, retorna 0 se não houver erro*/
int limpa_lista(Lista_Ordenada *lista);

/*copia tamanho da lista para variavel tam em argumento, retorna 0 se não houver
 * erro*/
int retorna_tamanho_lista(Lista_Ordenada *lista, int *tam);

int buscar_item_lista(Lista_Ordenada *lista, int posicao, void *retorno_dados);

#endif