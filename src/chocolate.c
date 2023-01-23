#include "../include/chocolate.h"
#include "../include/pilha.h"
#include <stdio.h>
#include <stdlib.h>

int inicializa_chocolate(Chocolate *c, char *nome, int tamanho_nome) {
    c->nome = nome;
    c->tamanho_nome = tamanho_nome;
    return 0;
};

int inicializa_pilha_chocolate(Pilha_Chocolate *pc){
    Pilha p;
    inicializa_pilha(&p, sizeof(Chocolate));

    pc->pilha = &p;
    return 0;
};


int empilha_chocolate(Pilha_Chocolate *pc, Chocolate *c){
    empilha(pc->pilha,c);
    return 0;
}

int desempilha_chocolate(Pilha_Chocolate *pc, Chocolate *choco_retorno){
    desempilha(pc->pilha,choco_retorno);
    return 0;
}