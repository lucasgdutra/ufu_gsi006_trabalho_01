/* --------------------------------------------------------------------------------------
   TAD Lista_Ordenada
   Também usaremos como estrutura de dados para nos dar suporte no projeto, as Listas, e
   usaremos Listas Encadeadas e Ordenadas.
   Objetivo: Trabalho de disciplina Estrutura de dados (GSI006) BSI - Facom -
UFU Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/
#ifndef LISTA_H
#define LISTA_H

/*
	Struct Node_Lista, que contem um inteiro indicando posicao, os dados que é um ponteiro
	do tipo void, para comportar qualquer tipo de dado e teremos mais um node indicando o
	proximo_node.

*/
typedef struct node_lista {
	int pos;
	void *dados;
	struct node_lista *proximo_node;
} Node_Lista;

/*
	Struct Lista, contem um Node_Lista indicando a primeira posicao da lista, int indicando
	o tamanho da lista, outro int pra receber o tamanho da estrutura.
*/
typedef struct lista {
	Node_Lista *primeiro;
	int tamanho_lista;
	int tamanho_estrutura_dados;
} Lista_Ordenada;

/*
 Nome: inicializa_lista
 Entrada: Ponteiro do tipo Lista e um int indicando o tamanho da estrutura.
 Processo: Verifica validade do ponteiro, e inicializa o primeiro com NULL,
 tamanho da lista com 0, e o tamanho da estrutura.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int inicializa_lista(Lista_Ordenada *lista, int tamanho_estrutura_dados);

/*
 Nome: adiciona_em_lista
 Entrada: Ponteiro do tipo Lista, ponteiro do tipo void passando os dados, e um int indicando
 a posicao
 Processo: Verifica validade dos ponteiros, e adiciona elemento no final da lista
 Saida: return 0 caso dê certo, e 1 caso dê errado.
*/
int adiciona_em_lista(Lista_Ordenada *lista, void *dados, int pos);

/*
 Nome: remove_da_lista
 Entrada: Ponteiro do tipo Lista, ponteiro do tipo void passando o valor retirado
 e um int indicando a posicao
 Processo: Verifica validade dos ponteiros, e remove elemento do inicio da lista e passa
 o elemento removido para *valor.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
*/
int remove_da_lista(Lista_Ordenada *lista, void *valor, int pos);

/*
 Nome: limpa_lista
 Entrada: Ponteiro do tipo Lista.
 Processo: Verifica validade do ponteiro, e remove todos elementos da lista passada.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
*/
int limpa_lista(Lista_Ordenada *lista);


/*
 Nome: retorna_tamanho_lista
 Entrada: Ponteiro do tipo Lista, ponteiro de inteiro indicando o tamanho da lista
 Processo: Verifica validade dos ponteiros, e passa o tamanho da lista para a variavel
 recebida na função.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int retorna_tamanho_lista(Lista_Ordenada *lista, int *tam);

/*
 Nome: buscar_item_lista
 Entrada: Ponteiro do tipo Lista, ponteiro de inteiro indicando a posicao, e ponteiro do tipo
 void indicando os dados que serão retornados.
 Processo: Verifica validade dos ponteiros, procura na lista comparando por posicao,
 se encontrado posiçoes iguais, retornará os dados.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int buscar_item_lista(Lista_Ordenada *lista, int posicao, void *retorno_dados);

#endif
