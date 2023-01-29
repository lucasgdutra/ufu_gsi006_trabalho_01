#include "../include/pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializa_pilha(Pilha *pilha, int tamanho_estrutura_dados) {
	pilha->topo = NULL;
	pilha->tamanho_estrutura_dados = tamanho_estrutura_dados;
	pilha->tamanho_pilha = 0;
    return 0;
}

int empilha(Pilha *pilha, void *dados) {
    // instancia estrutura para receber elemento
    Node_Pilha *novo_node;
    novo_node = (Node_Pilha *)malloc(sizeof(Node_Pilha));
	if (novo_node == NULL) {
        // erro ao alocar elemento
        return 1;
    }
	novo_node->dados = malloc(pilha->tamanho_estrutura_dados);
        // erro ao alocar dados do elemento
        free(novo_node);
        return 1;
    }
	novo_node->proximo_node = pilha->topo;
    // copia dados do argumento para novo node
	memcpy(novo_node->dados, dados, pilha->tamanho_estrutura_dados);

    // insere node no topo da pilha
	pilha->topo = novo_node;

    // ajusta tamanho da pilha
	pilha->tamanho_pilha++;
    return 0;
};

int desempilha(Pilha *pilha, void *valor) {
	if (pilha->tamanho_pilha > 0) {
        // guarda endereço do node que vai ser removido
		Node_Pilha *node_removido = pilha->topo;

		// copia dados do node removido para ponteiro valor em argumento da
		// função, se valor for NULL continua funcao sem copiar dados
		if (valor != NULL) {
			memcpy(valor, node_removido->dados, pilha->tamanho_estrutura_dados);
        }

        // redefine topo da pilha
        //
		pilha->topo = pilha->topo->proximo_node;

        // ajusta tamanho da pilha
		pilha->tamanho_pilha--;

        // libera memoria de node_removido
        free(node_removido->dados);
        free(node_removido);

        return 0;
	} else {
        return 1;
    }
}

int limpa_pilha(Pilha *pilha) {
    int status = 0;
	while (pilha->tamanho_pilha > 0) {
		status = desempilha(pilha, NULL);
		if (status == 1) {
            return 1;
        }
    }
    return 0;
}

int retorna_tamanho_pilha(Pilha *pilha, int *tam) {
	*tam = pilha->tamanho_pilha;
    return 0;
}