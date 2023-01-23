#include "../include/chocolate.h"
#include "../include/pilha.h"
#include <stdio.h>
#include <stdlib.h>


int empilha_chocolate(char *nome){

    Pilha *p;
    int tam = 5;
    char *valor;

    p = (Pilha *) malloc(sizeof(Pilha));
    inicializa_pilha(p,tam);

    empilha(p, nome);
    printf("EMPILHADO\n");
    
}

