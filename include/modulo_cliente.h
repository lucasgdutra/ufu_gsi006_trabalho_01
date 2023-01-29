#ifndef MODULO_CLIENTE_H
#define MODULO_CLIENTE_H
#include "./cardapio.h"
#include "./cliente.h"
#include "./comanda.h"

int inserir_itens_comanda(Comanda *comanda, Cardapio *cardapio);
int incluir_clientes_fila(Fila_Cliente *fila_cliente, Cardapio *cardapio);
int atender_cliente(Fila_Cliente *fila_cliente);
int imprimir_fila_clientes(Fila_Cliente *fila_cliente);

#endif