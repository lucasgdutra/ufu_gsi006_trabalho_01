#include "../include/fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializa_fila(Fila *f, int tamanho_estrutura_dados){
    f->primeiro=NULL;
    f->ultimo=NULL;
    f->tamanho_estrutura_dados = tamanho_estrutura_dados;
    f->tamanho_fila = 0;
    return 0;
}

int adiciona_final_fila(Fila *f, void *dados){
    //instancia estrutura para receber elemento
    Node_Fila *novo_node;
    novo_node = (Node_Fila *) malloc(sizeof(Node_Fila));
    if(novo_node == NULL){
        //erro ao alocar elemento
        return 1;
    }
    novo_node->dados = malloc(f->tamanho_estrutura_dados);
    if(novo_node->dados == NULL){
        //erro ao alocar dados do elemento
        free(novo_node);
        return 1;
    }
    novo_node->proximo_node = NULL;
    //copia dados do argumento para novo node
    memcpy(novo_node->dados, dados, f->tamanho_estrutura_dados);

    //insere node na fila
    if(f->tamanho_fila == 0){
        f->primeiro = novo_node;
        f->ultimo = novo_node;
    }else{
        //ultimo node atual recebe novo node como proximo
        f->ultimo->proximo_node = novo_node;
        //ultimo node redefinido como novo node
        f->ultimo = novo_node;
    }
    //ajusta tamanho da fila
    f->tamanho_fila++;
    return 0;

};

int remove_inicio_fila(Fila *f, void *valor){
    if(f->tamanho_fila > 0){
        //guarda endereço do node que vai ser removido
        Node_Fila *node_removido = f->primeiro;

        //copia dados do node removido para ponteiro valor em argumento da função, se valor for NULL continua funcao sem copiar dados
        if(valor != NULL){
            memcpy(valor,node_removido->dados,f->tamanho_estrutura_dados);
        }

        //redefine primeiro node da lista
        if(f->tamanho_fila > 1){
            f->primeiro = f->primeiro->proximo_node;
        }else{
            //se lista so tinha 1 elemento, nao vao sobrar elementos na lista apos remocao
            f->primeiro = NULL;
            f->ultimo = NULL;
        }

        //ajusta tamanho da fila
        f->tamanho_fila--;

        //libera memoria de node_removido
        free(node_removido->dados);
        free(node_removido);

        return 0;
    }else{
        return 1;
    }
}

int limpa_fila(Fila *f){
    int status = 0;
    while(f->tamanho_fila > 0){
        status = remove_inicio_fila(f, NULL);
        if(status == 1){
            return 1;
        }
    }
    return 0;
}

int retorna_tamanho_fila(Fila *f, int *tam){
    *tam = f->tamanho_fila;
    return 0;
}