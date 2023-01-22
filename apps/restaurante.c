/* --------------------------------------------------------------------------------------
   Programa que implementa um sistema de atendimento de um restaurante, com cardápio, comanda e brindes de chocolates para clientes.
   Objetivo: Trabalho de disciplina Estrutura de dados (GSI006) BSI - Facom - UFU
   Restricoes: 

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/

#include "../include/fila.h"
#include "../include/pilha.h"
#include "../include/lista.h"
#include "../include/cardapio.h"
#include "../include/produto.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  
  Produto p,p1;
  Cardapio *c;

  c = (Cardapio*) malloc(sizeof(Cardapio)*2);
  
  inicializa_cardapio(c,2);
  inicializa_produto(&p, 1, "macarrao", 8, 22.50);
  adiciona_item_cardapio(c, &p);
  inicializa_produto(&p1, 2, "feijoada", 8, 30.00);
  adiciona_item_cardapio(c, &p1);

    
  //listar cardapio para cliente...
  for(int i=0; i < c->tam_cardapio; i++){
    printf("%s\n", c->lista[i]->nome);
  }


    return 0;
}
