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
#include "../include/cardapio.h"
#include <stdio.h>

int main()
{
    Fila f;
    int valor;
    inicializa_fila(&f, sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        adiciona_final_fila(&f, &i);
    }
    for (int i = 0; i < 10; i++)
    {
        remove_inicio_fila(&f, &valor);
        printf("%d\n", valor);
    }

    return 0;
}