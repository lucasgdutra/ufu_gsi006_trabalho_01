#ifndef COMANDA_H
#define COMANDA_H

#include "./produto.h"
#include "./lista.h"

typedef struct comanda
{
    Lista_Ordenada *lista;
} Comanda;



int inicializa_comanda(Comanda *comanda);

int adiciona_item_comanda(Comanda *comanda, Produto *p);



#endif
