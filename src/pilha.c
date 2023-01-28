#include "../include/pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializa_pilha(Pilha *p, int tamanho_estrutura_dados)
{
    p->topo = NULL;
    p->tamanho_estrutura_dados = tamanho_estrutura_dados;
    p->tamanho_pilha = 0;
    return 0;
}

int empilha(Pilha *p, void *dados)
{
    // instancia estrutura para receber elemento
    Node_Pilha *novo_node;
    novo_node = (Node_Pilha *)malloc(sizeof(Node_Pilha));
    if (novo_node == NULL)
    {
        // erro ao alocar elemento
        return 1;
    }
    novo_node->dados = malloc(p->tamanho_estrutura_dados);
    if (novo_node->dados == NULL)
    {
        // erro ao alocar dados do elemento
        free(novo_node);
        return 1;
    }
    novo_node->proximo_node = p->topo;
    // copia dados do argumento para novo node
    memcpy(novo_node->dados, dados, p->tamanho_estrutura_dados);

    // insere node no topo da pilha
    p->topo = novo_node;

    // ajusta tamanho da pilha
    p->tamanho_pilha++;
    return 0;
};

int desempilha(Pilha *p, void *valor)
{
    if (p->tamanho_pilha > 0)
    {
        // guarda endereço do node que vai ser removido
        Node_Pilha *node_removido = p->topo;

        // copia dados do node removido para ponteiro valor em argumento da função, se valor for NULL continua funcao sem copiar dados
        if (valor != NULL)
        {
            memcpy(valor, node_removido->dados, p->tamanho_estrutura_dados);
        }

        // redefine topo da pilha
        //
        p->topo = p->topo->proximo_node;


        // ajusta tamanho da pilha
        p->tamanho_pilha--;

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

int limpa_pilha(Pilha *p)
{
    int status = 0;
    while (p->tamanho_pilha > 0)
    {
        status = desempilha(p, NULL);
        if (status == 1)
        {
            return 1;
        }
    }
    return 0;
}

int retorna_tamanho_pilha(Pilha *p, int *tam)
{
    *tam = p->tamanho_pilha;
    return 0;
}