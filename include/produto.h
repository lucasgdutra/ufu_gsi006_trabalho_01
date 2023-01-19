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

#endif