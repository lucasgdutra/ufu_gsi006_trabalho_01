#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct produto
{
    unsigned int id;
    char *nome;
    int tam_nome;
    float preco;
} Produto;

int inicializa_produto(Produto *p, int id, char *nome, int tam_nome, float preco);

int retorna_id_produto(Produto *p, int *retorno_id);

int retorna_nome_produto(Produto *p, char *retorno_nome);

int retorna_preco_produto(Produto *p, float *retorno_preco);


#endif