#include "../include/lista.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    Lista_Ordenada l;
    inicializa_lista(&l, sizeof(int));

    int entrada;
    while (scanf("%d", &entrada) != EOF) {
        int s = adiciona_em_lista(&l, &entrada, entrada);
        if (s == 1)
            return 1;
    }

    while (l.tamanho_lista > 0) {

        if (l.primeiro != NULL) {
            Node_Lista *node_removido = l.primeiro;
            l.primeiro = node_removido->proximo_node;
            printf("dados:%d, pos:%d, tam_lista:%d\n",
                   *((int *)node_removido->dados), node_removido->pos,
                   l.tamanho_lista);
            free(node_removido->dados);
            free(node_removido);
            l.tamanho_lista--;
        } else {
            return 1;
        }
    }

    return 0;
}