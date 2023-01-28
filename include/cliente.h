#ifndef CLIENTE_H
#define CLIENTE_H

#include "./comanda.h"
#include "./fila.h"

typedef struct cliente
{
    char *nome;
    int tamanho_nome;
    Comanda *comanda;
} Cliente;

int inicializa_cliente(Cliente *c, char *nome, int tamanho_nome,
                       Comanda *comanda);

typedef struct fila_cliente
{
    Fila *fila;
} Fila_Cliente;

int inicializa_fila_cliente(Fila_Cliente *fc);

int adiciona_cliente_fila(Fila_Cliente *fc, Cliente *c);

int remove_cliente_fila(Fila_Cliente *fc, Cliente *cliente_retorno);


#endif
