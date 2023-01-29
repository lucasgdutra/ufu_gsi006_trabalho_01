/* --------------------------------------------------------------------------------------
   TAD Pilha
   Outra Estrutura de Dados que utilizaremos será as Pilhas, que usaremos para montar nossa
   pilha de Chocolate que será distribuido como brinde.
   Objetivo: Trabalho de disciplina Estrutura de dados (GSI006) BSI - Facom - UFU
   Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/
#ifndef PILHA_H
#define PILHA_H

/*
    Struct node_pilha, terá como atributo, um ponteiro do tipo void para generalizar o tipo
    de dados que essa pilha aceita, e uma struct node_pilha indicando o proximo node.
*/
typedef struct node_pilha
{
    void *dados;
    struct node_pilha *proximo_node;
} Node_Pilha;

/*
    Struct pilha, terá um ponteiro do tipo Node_Pilha indicando o topo, um inteiro indicando
    o tamanho da Pilha, e outro inteiro para indicar o tamanho da estrutura que será alocada.
*/
typedef struct pilha
{
    Node_Pilha *topo;
    int tamanho_pilha;
    int tamanho_estrutura_dados;
} Pilha;

/*
 Nome: inicializa_pilha
 Entrada: Ponteiro do tipo Pilha e um int indicando o tamanho da estrutura.
 Processo: Verifica validade do ponteiro, inicializa a pilha com os valores iniciais.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int inicializa_pilha(Pilha *p, int tamanho_estrutura_dados);

/*
 Nome: empilha
 Entrada: Ponteiro do tipo Pilha e ponteiro do tipo void indicando o dado que será empilhado
 Processo: Verifica validade dos ponteiros, empilha os dados no topo da pilha. 
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int empilha(Pilha *p, void *dados);

/*
 Nome: desempilha
 Entrada: Ponteiro do tipo Pilha e um ponteiro do tipo void indicando o dado que sera retornado.
 Processo: Verifica validade dos ponteiros, caso seja possivel desempilhar, retira-se do topo
 e atribui o valor retirado a *valor e libera da memória o node removido. 
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int desempilha(Pilha *p, void *valor);

/*
 Nome: limpa_pilha
 Entrada: Ponteiro do tipo Pilha.
 Processo: Verifica validade do ponteiro, e remove todos elementos da Pilha.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int limpa_pilha(Pilha *p);

/*
 Nome: retorna_tamanho_pilha
 Entrada: Ponteiro do tipo Pilha e um ponteiro do tipo int indicando o tamanho que será retornado.
 Processo: Verifica validade dos ponteiros, copia o tamanho da pilha e atribui a variavel *tam
 que será alterada com o tamanho atual da Pilha. 
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int retorna_tamanho_pilha(Pilha *p, int *tam);

#endif
