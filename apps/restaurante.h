#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "../include/cardapio.h"
#include "../include/chocolate.h"
#include "../include/cliente.h"
#include "../include/fila.h"
#include "../include/lista.h"
#include "../include/pilha.h"
#include "../include/produto.h"

int leitura_produto(Produto *produto_retorno);
int inserir_itens_cardapio(Cardapio *cardapio);
int inserir_chocolates_pilha(Pilha_Chocolate *pilha_chocolate);
int inserir_itens_comanda(Comanda *comanda, Cardapio *cardapio);
int incluir_clientes_fila(Fila_Cliente *fila_cliente, Cardapio *cardapio);
int atender_cliente(Fila_Cliente *fila_cliente);
int imprimir_cardapio(Cardapio *cardapio);
int imprimir_fila_clientes(Fila_Cliente *fila_cliente);
int print_menu(int *opcao);
int main();

#endif