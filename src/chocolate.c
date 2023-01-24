#include "../include/chocolate.h"
#include "../include/pilha.h"
#include <stdio.h>
#include <stdlib.h>

int inicializa_chocolate(Chocolate *c, char *nome, int tamanho_nome)
{
    c->nome = nome;
    c->tamanho_nome = tamanho_nome;
    return 0;
};

int inicializa_pilha_chocolate(Pilha_Chocolate *pc)
{
    Pilha *p;
    p = malloc(sizeof(Pilha));
    inicializa_pilha(p, sizeof(Chocolate));
    pc->pilha = p;
    return 0;
};

int empilha_chocolate(Pilha_Chocolate *pc, Chocolate *c)
{
    empilha(pc->pilha, c);
    return 0;
}

int desempilha_chocolate(Pilha_Chocolate *pc, Chocolate *choco_retorno)
{
    desempilha(pc->pilha, choco_retorno);
    return 0;
}

void imprime_chocolate(Pilha_Chocolate *pc)
{

    // verifica se a pilha ta vazia..
    if (pc->pilha->tamanho_pilha == 0)
    {
        printf("Pilha vazia...\n");
    }

    // varre a pilha pelo topo e depois passa para o proximo node até chegar no NULL
    Node_Pilha *current = pc->pilha->topo;
    while (current != NULL)
    {
        printf("%s \n", ((Chocolate *)current->dados)->nome);
        current = current->proximo_node;
    }
    printf("\n");
}
