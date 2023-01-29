#ifndef MODULO_CARDAPIO_H
#define MODULO_CARDAPIO_H

#include "./cardapio.h"

int leitura_produto(Produto *produto_retorno);
int inserir_itens_cardapio(Cardapio *cardapio);
int imprimir_cardapio(Cardapio *cardapio);

#endif