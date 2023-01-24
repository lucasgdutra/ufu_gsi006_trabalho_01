#include "../include/chocolate.h"
#include "../include/pilha.h"
#include <stdio.h>
#include <stdlib.h>

int inicializa_chocolate(Chocolate *c, char *nome, int tamanho_nome) {
    c->nome = nome;
    c->tamanho_nome = tamanho_nome;
    return 0;
};

int inicializa_pilha_chocolate(Pilha_Chocolate *pc) {
    Pilha *p;
    p = malloc(sizeof(Pilha));
    inicializa_pilha(p, sizeof(Chocolate));
    pc->pilha = p;
    return 0;
};

int empilha_chocolate(Pilha_Chocolate *pc, Chocolate *c) {
    int s = empilha(pc->pilha, c);
    if(s != 0){
        return 1;
    }
    return 0;
}

int desempilha_chocolate(Pilha_Chocolate *pc, Chocolate *choco_retorno) {
    desempilha(pc->pilha, choco_retorno);
    return 0;
}