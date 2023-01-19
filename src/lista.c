#include "../include/lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

    int inicializa_lista(Lista_Ordenada *l, int tamanho_estrutura_dados)
{
    l->primeiro = NULL;
    l->tamanho_estrutura_dados = tamanho_estrutura_dados;
    l->tamanho_lista = 0;
    return 0;
}

int adiciona_em_lista(Lista_Ordenada *l, void *dados, int pos)
{
    // instancia estrutura para receber elemento
    Node_Lista *novo_node;
    novo_node = (Node_Lista *)malloc(sizeof(Node_Lista));
    if (novo_node == NULL)
    {
        // erro ao alocar elemento
        return 1;
    }
    novo_node->dados = malloc(l->tamanho_estrutura_dados);
    if (novo_node->dados == NULL)
    {
        // erro ao alocar dados do elemento
        free(novo_node);
        return 1;
    }

    // copia dados do argumento para novo node
    memcpy(novo_node->dados, dados, l->tamanho_estrutura_dados);

    // insere node na lista
    Node_Lista *node_atual = l->primeiro;
    while(true){
        if(node_atual->proximo_node == NULL){
            node_atual->proximo_node = novo_node;
            novo_node->proximo_node = NULL;
            break;
        }
        if(pos >= node_atual->pos && pos < node_atual->proximo_node->pos){
            Node_Lista *proximo = node_atual->proximo_node;
            node_atual->proximo_node = novo_node;
            novo_node->proximo_node = proximo;
            break;
        }
        node_atual = node_atual->proximo_node;
    }


    // ajusta tamanho da lista
    l->tamanho_lista++;
    return 0;
};

int remove_da_lista(Lista_Ordenada *l, void *valor, int pos)
{
    if (l->tamanho_lista > 0)
    {
        // guarda endereço do node que vai ser removido
        Node_Lista *node_removido = l->primeiro;

        // copia dados do node removido para ponteiro valor em argumento da função, se valor for NULL continua funcao sem copiar dados
        if (valor != NULL)
        {
            memcpy(valor, node_removido->dados, l->tamanho_estrutura_dados);
        }

        // redefine primeiro node da lista
        if (l->tamanho_lista > 1)
        {
            l->primeiro = l->primeiro->proximo_node;
        }
        else
        {
            // se lista so tinha 1 elemento, nao vao sobrar elementos na lista apos remocao
            l->primeiro = NULL;
        }

        // ajusta tamanho da lista
        l->tamanho_lista--;

        // libera memoria de node_removido
        free(node_removido->dados);
        free(node_removido);

        return 0;
    }
    else
    {
        return 1;
    }
}

int limpa_lista(Lista_Ordenada *l)
{
    int status = 0;
    while (l->tamanho_lista > 0)
    {
        Node_Lista *node_removido = l->primeiro;
        l->primeiro = node_removido->proximo_node;
        // libera memoria de node_removido
        free(node_removido->dados);
        free(node_removido);
    }
    return 0;
}

int retorna_tamanho_lista(Lista_Ordenada *l, int *tam)
{
    *tam = l->tamanho_lista;
    return 0;
}