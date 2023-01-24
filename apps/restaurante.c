/* --------------------------------------------------------------------------------------
   Programa que implementa um sistema de atendimento de um restaurante, com
cardápio, comanda e brindes de chocolates para clientes. Objetivo: Trabalho de
disciplina Estrutura de dados (GSI006) BSI - Facom - UFU Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/

#include "../include/cardapio.h"
#include "../include/chocolate.h"
#include "../include/fila.h"
#include "../include/lista.h"
#include "../include/pilha.h"
#include "../include/produto.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int inserir_itens_cardapio() {
    printf("Em desenvolvimento\n");
    return 0;
}

int inserir_chocolates_pilha(Pilha_Chocolate *pc) {
    Chocolate c;
    char *nome;
    int tamanho_nome = 15;

    nome = (char *)malloc(sizeof(char) * tamanho_nome);
    if (nome == NULL) {
        printf("nao foi alocado..\n");
        return 1;
    }

    printf("Insira o chocolate: \n");
    if (scanf("%s", nome) != 1)
        return 1;

    inicializa_chocolate(&c, nome, tamanho_nome);
    empilha_chocolate(pc, &c);

    return 0;
}

int incluir_clientes_fila() {
    printf("em desenvolvimento..\n");
    return 0;
}

int atender_cliente() {
    printf("em desenvolvimento..\n");
    return 0;
}

int imprimir_cardapio() {
    printf("em desenvolvimento..\n");
    return 0;
}


int imprimir_fila_clientes() {
    printf("em desenvolvimento..\n");
    return 0;
}

int print_menu(int *opcao) {
    printf("\n");
    printf("Escolha uma das opções do menu\n");
    printf("0 - Sair do programa\n");
    printf("1 - Inserir itens no cardapio\n");
    printf("2 - Inserir chocolates na pilha\n");
    printf("3 - Incluir clientes na fila\n");
    printf("4 - Atender cliente na fila\n");
    printf("5 - Imprimir cardapio\n");
    printf("6 - Imprimir pilha de chocolates\n");
    printf("7 - Imprimir fila de clientes\n");
    if (scanf("%d", opcao) == 1)
        return 0;
    return 1;
}

int main() {
    Pilha_Chocolate pc;

    inicializa_pilha_chocolate(&pc);

    int opcao;
    while (true) {
        print_menu(&opcao);
        switch (opcao) {
        case 0:
            printf("saindo...\n");
            return 0;
            break;
        case 1:
            inserir_itens_cardapio();
            break;
        case 2:
            inserir_chocolates_pilha(&pc);
            break;
        case 3:
            incluir_clientes_fila();
            break;
        case 4:
            atender_cliente();
            break;
        case 5:
            imprimir_cardapio();
            break;
        case 6:
            imprime_chocolate(&pc);
            break;
        case 7:
            imprimir_fila_clientes();
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    }

    return 0;
}
