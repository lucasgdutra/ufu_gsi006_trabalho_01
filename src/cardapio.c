#include "../include/cardapio.h"
#include <stdlib.h>
#include <string.h>

int inicializa_cardapio(Cardapio *c, int tam_lista)
{
    c->lista = (Produto*) malloc(sizeof(Produto) * tam_lista);
    c->tam_cardapio = tam_lista;
    c->posicao_cardapio = 0;
    return 0;
}

int adiciona_item_cardapio(Cardapio *c, Produto *p){
    c->lista[c->posicao_cardapio] = p;
}