#include "../include/produto.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR_SIZE 100
int main() {
    int id;
    float preco;
    char nome[MAX_CHAR_SIZE];
    while (fscanf(stdin, "%d %s %f", &id, nome, &preco) != EOF) {
        Produto p;
        inicializa_produto(&p, id, nome, MAX_CHAR_SIZE, preco);

        int id_retorno;
        retorna_id_produto(&p,&id_retorno);

        char nome_retorno[MAX_CHAR_SIZE];
        retorna_nome_produto(&p, nome_retorno);

        float preco_retorno;
        retorna_preco_produto(&p, &preco_retorno);

        printf("Id: %d, nome:%s, preco:%.2f\n", id_retorno, nome_retorno, preco_retorno);
    }

    return 0;
}