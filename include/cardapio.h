#ifndef CARDAPIO_H
#define CARDAPIO_H

#include "./lista.h"
#include "./produto.h"

typedef struct cardapio {
	Lista_Ordenada *lista;
} Cardapio;

int inicializa_cardapio(Cardapio *c);

int adiciona_item_cardapio(Cardapio *c, Produto *p);

int remove_item_cardapio(Cardapio *c, Produto *retorno_produto, int id);

int mostrar_cardapio(Cardapio *c);

#endif