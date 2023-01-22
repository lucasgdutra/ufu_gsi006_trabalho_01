#include "../include/lista.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializa_lista(Lista_Ordenada *l, int tamanho_estrutura_dados) {
    l->primeiro = NULL;
    l->tamanho_estrutura_dados = tamanho_estrutura_dados;
    l->tamanho_lista = 0;
    return 0;
}

int adiciona_em_lista(Lista_Ordenada *l, void *dados, int pos) {

    // instancia estrutura para receber elemento
    Node_Lista *novo_node;
    novo_node = (Node_Lista *)malloc(sizeof(Node_Lista));
    if (novo_node == NULL) {
        // erro ao alocar elemento
        return 1;
    }
    novo_node->dados = malloc(l->tamanho_estrutura_dados);
    if (novo_node->dados == NULL) {
        // erro ao alocar dados do elemento
        free(novo_node);
        return 1;
    }

    // define propriedades do nodo
    memcpy(novo_node->dados, dados, l->tamanho_estrutura_dados);
    novo_node->pos = pos;
    novo_node->proximo_node = NULL;

    // insere node na lista
    if (l->primeiro == NULL) {
        // se lista vazia insere na primeira posição
        l->primeiro = novo_node;
    } else {
        Node_Lista *node_anterior = NULL;
        Node_Lista *node_atual = l->primeiro;

        while (true) {

            if (node_atual == NULL) {

                // inserir na ultima posicao
                node_anterior->proximo_node = novo_node;
                break;
            }
            if (node_anterior == NULL && pos < node_atual->pos) {

                // inserir na primeira posição
                l->primeiro = novo_node;

                novo_node->proximo_node = node_atual;
                break;
            }
            if (pos >= node_anterior->pos && pos < node_atual->pos) {

                node_anterior->proximo_node = novo_node;

                novo_node->proximo_node = node_atual;
                break;
            }

            node_anterior = node_atual;
            node_atual = node_atual->proximo_node;
        }
    }

    // ajusta tamanho da lista
    l->tamanho_lista++;
    return 0;
};

int remove_da_lista(Lista_Ordenada *l, void *valor, int pos) {
    if (l->tamanho_lista > 0) {
        Node_Lista *node_anterior = NULL;
        Node_Lista *node_atual = l->primeiro;
        while (true) {
            if (node_atual == NULL) {
                return 1;
            }
            if (node_atual->pos == pos) {
                // guarda endereço do node que vai ser removido
                Node_Lista *node_removido = node_atual;

                // copia dados do node removido para ponteiro valor em argumento
                // da função, se valor for NULL continua funcao sem copiar dados
                if (valor != NULL) {
                    memcpy(valor, node_removido->dados,
                           l->tamanho_estrutura_dados);
                }
                // ajusta apontamento do node anterior para proximo node
                if (node_anterior == NULL) {
                    // removendo primeiro elemento
                    l->primeiro = node_atual->proximo_node;
                } else {
                    node_anterior->proximo_node = node_atual->proximo_node;
                }

                // libera memoria de node_removido
                free(node_removido->dados);
                free(node_removido);

                // ajusta tamanho da lista
                l->tamanho_lista--;
                break;
            }
            node_anterior = node_atual;
            node_atual = node_atual->proximo_node;
        }

        return 0;
    } else {
        return 1;
    }
}

int limpa_lista(Lista_Ordenada *l) {
    while (l->tamanho_lista > 0) {
        Node_Lista *node_removido = l->primeiro;
        l->primeiro = node_removido->proximo_node;
        // libera memoria de node_removido
        free(node_removido->dados);
        free(node_removido);
        l->tamanho_lista--;
    }
    return 0;
}

int retorna_tamanho_lista(Lista_Ordenada *l, int *tam) {
    *tam = l->tamanho_lista;
    return 0;
}