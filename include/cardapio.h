#ifndef CARDAPIO_H
#define CARDAPIO_H

#include "./produto.h"


typedef struct cardapio{
    Produto **lista;
    int tam_cardapio;
    int posicao_cardapio;
} Cardapio;

int inicializa_cardapio(Cardapio *c, int tam_lista);

int adiciona_item_cardapio(Cardapio *c, Produto *p);

#endif