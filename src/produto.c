#include "../include/produto.h"
#include <stdlib.h>
#include <string.h>

int inicializa_produto(Produto *p, int id, char *nome, int tam_nome, float preco){
    p->id = id;

    p->tam_nome = tam_nome;
    p->nome = (char *)malloc(sizeof(char) * tam_nome);
    memcpy(p->nome, nome, p->tam_nome);

    p->preco = preco;
    
    return 0;
}