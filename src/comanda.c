/* --------------------------------------------------------------------------------------
   Comanda
   Objetivo: Trabalho de disciplina Estrutura de dados (GSI006) BSI - Facom - UFU
   Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/

#include "../include/comanda.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int inicializa_comanda(Comanda *comanda){

    Lista_Ordenada *l;
    l = (Lista_Ordenada*)malloc(sizeof(Lista_Ordenada));
    inicializa_lista(l, sizeof(Produto));
    comanda->lista = l;
    return 0;

}

int adiciona_item_comanda(Comanda *comanda, Produto *p)
{

    int status = adiciona_em_lista(comanda->lista, p, p->id);
    if (status != 0)
       return 1;

    return 0;
}

int soma_valor_comanda(Comanda *comanda, float *resultado) {
    Node_Lista *no = comanda->lista->primeiro;
    float soma = 0;
    while (no != NULL) {
        Produto *p = (Produto*)no->dados;
        soma += p->preco;
        no = no->proximo_node;
    }
    *resultado = soma;
    return 0;
}

