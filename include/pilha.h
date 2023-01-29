/* --------------------------------------------------------------------------------------
   TAD Pilha
   Objetivo: Trabalho de disciplina Estrutura de dados (GSI006) BSI - Facom - UFU
   Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/
#ifndef PILHA_H
#define PILHA_H

typedef struct node_pilha
{
    void *dados;
    struct node_pilha *proximo_node;
} Node_Pilha;

typedef struct pilha
{
    Node_Pilha *topo;
    int tamanho_pilha;
    int tamanho_estrutura_dados;
} Pilha;

/*inicializa estrutura pilha com valores iniciais, retorna 0 se não houver erro*/
int inicializa_pilha(Pilha *p, int tamanho_estrutura_dados);

/*adiciona elemento ao topo da pilha, retorna 0 se não houver erro*/
int empilha(Pilha *p, void *dados);

/*remove elemento do topo pilha e retorna valor removido pra ponteiro valor do argumento, retorna 0 se não houver erro*/
int desempilha(Pilha *p, void *valor);

/*remove todos elementos da pilha, retorna 0 se não houver erro*/
int limpa_pilha(Pilha *p);

/*copia tamanho da pilha para variavel tam em argumento, retorna 0 se não houver erro*/
int retorna_tamanho_pilha(Pilha *p, int *tam);

#endif