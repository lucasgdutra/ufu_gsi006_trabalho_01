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

int retorna_id_produto(Produto *p, int *retorno_id){
    *retorno_id = p->id;
    return 0;
}

int retorna_nome_produto(Produto *p, char *retorno_nome){
    memcpy(retorno_nome,p->nome, p->tam_nome);
    return 0;
}

int retorna_preco_produto(Produto *p, float *retorno_preco){
    *retorno_preco = p->preco;
    return 0;
}

