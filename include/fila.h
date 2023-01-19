/* --------------------------------------------------------------------------------------
   TAD Fila
   Objetivo: Trabalho de disciplina Estrutura de dados (GSI006) BSI - Facom - UFU
   Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/
#ifndef FILA_H
#define FILA_H


typedef struct node_fila {
    void *dados;
    struct node_fila *proximo_node;
} Node_Fila;


typedef struct fila {
    Node_Fila *primeiro;
    Node_Fila *ultimo;
    int tamanho_fila;
    int tamanho_estrutura_dados;
} Fila;

/*inicializa estrutura fila com valores iniciais, retorna 0 se não houver erro*/
int inicializa_fila(Fila *f, int tamanho_estrutura_dados);

/*adiciona elemento ao final da fila, retorna 0 se não houver erro*/
int adiciona_final_fila(Fila *f, void *dados);

/*remove elemento do inicio da fila e retorna valor removido pra ponteiro valor do argumento, retorna 0 se não houver erro*/
int remove_inicio_fila(Fila *f, void *valor);


/*remove todos elementos da fila, retorna 0 se não houver erro*/
int limpa_fila(Fila *f);

/*copia tamanho da fila para variavel tam em argumento, retorna 0 se não houver erro*/
int retorna_tamanho_fila(Fila *f, int *tam);

#endif