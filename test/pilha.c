#include "../include/pilha.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Pilha p;
    inicializa_pilha(&p, sizeof(int));

    int entrada;
    while (scanf("%d", &entrada) != EOF) {
        int s = empilha(&p,&entrada);
        if (s == 1) return 1;
    }

    while (p.tamanho_pilha > 0) {
        int v;
        desempilha(&p,&v);
        printf("valor: %d\n",v);
    }

    return 0;
}