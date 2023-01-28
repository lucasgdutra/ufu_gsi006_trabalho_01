#include "../include/cardapio.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR_SIZE 100
int main() {
    Cardapio c;
    inicializa_cardapio(&c);
    int id;
    float preco;
    char nome[MAX_CHAR_SIZE];
    while (fscanf(stdin, "%d %s %f", &id, nome, &preco) != EOF) {
        Produto *p;
        p = (Produto *)malloc(sizeof(Produto));
        inicializa_produto(p, id, nome, MAX_CHAR_SIZE, preco);
        adiciona_item_cardapio(&c, p);
    }
    while(c.lista->tamanho_lista != 0){
        Produto  produtoRetorno;
        remove_item_cardapio(&c, &produtoRetorno, c.lista->primeiro->pos);

        int id_retorno;
        retorna_id_produto(&produtoRetorno, &id_retorno);

        char nome_retorno[MAX_CHAR_SIZE];
        retorna_nome_produto(&produtoRetorno, nome_retorno);

        float preco_retorno;
        retorna_preco_produto(&produtoRetorno, &preco_retorno);

        printf("Id: %d, nome:%s, preco:%.2f\n", id_retorno, nome_retorno,
               preco_retorno);
    }

    return 0;
}