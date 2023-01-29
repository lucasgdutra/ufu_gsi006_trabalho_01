/* --------------------------------------------------------------------------------------
   TAD Fila
   Na construção do nosso restaurante, precisaremos de algumas Estruturas de Dados, e a Fila
   será uma delas, optamos por trabalhar com ela dinamicamente.
   Objetivo: Trabalho de disciplina Estrutura de dados (GSI006) BSI - Facom - UFU
   Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/
#ifndef FILA_H
#define FILA_H


/*
    Struct node_fila , onde teremos os dados do tipo void, para poder receber qualquer tipo
    de dado, e uma struct node_fila, indicando o proximo node.
*/
typedef struct node_fila {
    void *dados;
    struct node_fila *proximo_node;
} Node_Fila;


/*
Struct Fila, teremos o ponteiro do tipo Node_Fila indicando o primeiro elemento e o ultimo,
teremos também dois inteiros, indicando o tamanho da fila e o tamanho da estrutura. 
*/
typedef struct fila {
    Node_Fila *primeiro;
    Node_Fila *ultimo;
    int tamanho_fila;
    int tamanho_estrutura_dados;
} Fila;


/*
 Nome: inicializa_fila
 Entrada: Ponteiro do tipo Fila e um int indicando o tamanho da estrutura.
 Processo: Verifica validade do ponteiro, e inicializa o primeiro e ultimo node com NULL,
 tamanho da fila com 0, e o tamanho da estrutura.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int inicializa_fila(Fila *f, int tamanho_estrutura_dados);

/*
 Nome: adiciona_final_fila
 Entrada: Ponteiro do tipo Fila e ponteiro do tipo Void dados, podendo indicar qualquer tipo
 de dados.
 Processo: Verifica validade de ponteiros, e adiciona o Cliente ao final da fila.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int adiciona_final_fila(Fila *f, void *dados);

/*
 Nome: remove_inicio_fila
 Entrada: Ponteiro do tipo Fila e ponteiro do tipo Void valor, podendo indicar qualquer tipo
 de dados.
 Processo: Verifica validade de ponteiros, e remove do inicio da fila. 
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int remove_inicio_fila(Fila *f, void *valor);

/*
 Nome:  limpa_fila
 Entrada: Ponteiro do tipo Fila.
 Processo: Limpa todos os elementos da fila.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int limpa_fila(Fila *f);

/*
 Nome:  retorna_tamanho_fila
 Entrada: Ponteiro do tipo Fila e um ponteiro de inteiro indicando o tamanho.
 Processo: Atribui a *tam o tamanho da fila.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int retorna_tamanho_fila(Fila *f, int *tam);

#endif
