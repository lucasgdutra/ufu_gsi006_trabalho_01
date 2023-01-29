#ifndef CARDAPIO_H
#define CARDAPIO_H

#include "./lista.h"
#include "./produto.h"

typedef struct cardapio {
	Lista_Ordenada *lista;
} Cardapio;

int inicializa_cardapio(Cardapio *cardapio);

int adiciona_item_cardapio(Cardapio *cardapio, Produto *p);

int remove_item_cardapio(Cardapio *cardapio, Produto *retorno_produto, int id);

int retorna_tamanho_cardapio(Cardapio *cardapio, int *retorno_tamanho);

int buscar_item_cardapio(Cardapio *cardapio, int posicao,
						 Produto *retorno_produto);
#endif