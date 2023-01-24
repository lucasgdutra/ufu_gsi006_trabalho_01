#include "../include/cardapio.h"
#include <stdlib.h>
#include <string.h>

int inicializa_cardapio(Cardapio *c) {
    Lista_Ordenada *l;
    l = (Lista_Ordenada*)malloc(sizeof(Lista_Ordenada));
    inicializa_lista(l, sizeof(Produto));
    c->lista = l;
    return 0;
}

int adiciona_item_cardapio(Cardapio *c, Produto *p) {
    int status = adiciona_em_lista(c->lista, p, p->id);
    if (status != 0)
        return 1;
    return 0;
}

int remove_item_cardapio(Cardapio *c, Produto *retorno_produto, int id) {
    int status = remove_da_lista(c->lista, retorno_produto, id);
    if (status != 0)
        return 1;
    return 0;
}
