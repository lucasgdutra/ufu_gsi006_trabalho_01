#include "../include/fila.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Fila f;
    inicializa_fila(&f, sizeof(int));

    int entrada;
    while (scanf("%d", &entrada) != EOF) {
        int s = adiciona_final_fila(&f, &entrada);
        if (s == 1)
            return 1;
    }

    while (f.tamanho_fila > 0) {
        int v;
        remove_inicio_fila(&f,&v);
        printf("valor: %d\n",v);
    }

    return 0;
}