#include "../include/fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializa_fila(Fila *fila, int tamanho_estrutura_dados) {
	// testa se ponteiro eh valido
	if (fila == NULL) {
		return 1;
	}
	fila->primeiro = NULL;
	fila->ultimo = NULL;
	fila->tamanho_estrutura_dados = tamanho_estrutura_dados;
	fila->tamanho_fila = 0;
	return 0;
}

int adiciona_final_fila(Fila *fila, void *dados) {
	// testa se ponteiro eh valido
	if (fila == NULL || dados == NULL) {
		return 1;
	}
	// instancia estrutura para receber elemento
	Node_Fila *novo_node;
	novo_node = (Node_Fila *)malloc(sizeof(Node_Fila));
	if (novo_node == NULL) {
		// erro ao alocar elemento
		return 1;
	}
	novo_node->dados = malloc(fila->tamanho_estrutura_dados);
	if (novo_node->dados == NULL) {
		// erro ao alocar dados do elemento
		free(novo_node);
		return 1;
	}
	novo_node->proximo_node = NULL;
	// copia dados do argumento para novo node
	memcpy(novo_node->dados, dados, fila->tamanho_estrutura_dados);

	// insere node na fila
	if (fila->tamanho_fila == 0) {
		fila->primeiro = novo_node;
		fila->ultimo = novo_node;
	} else {
		// ultimo node atual recebe novo node como proximo
		fila->ultimo->proximo_node = novo_node;
		// ultimo node redefinido como novo node
		fila->ultimo = novo_node;
	}
	// ajusta tamanho da fila
	fila->tamanho_fila++;
	return 0;
};

int remove_inicio_fila(Fila *fila, void *valor) {
	// testa se ponteiro eh valido
	if (fila == NULL) {
		return 1;
	}
	if (fila->tamanho_fila > 0) {
		// guarda endereço do node que vai ser removido
		Node_Fila *node_removido = fila->primeiro;

		// copia dados do node removido para ponteiro valor em argumento da
		// função, se valor for NULL continua funcao sem copiar dados
		if (valor != NULL) {
			memcpy(valor, node_removido->dados, fila->tamanho_estrutura_dados);
		}

		// redefine primeiro node da lista
		if (fila->tamanho_fila > 1) {
			fila->primeiro = fila->primeiro->proximo_node;
		} else {
			// se lista so tinha 1 elemento, nao vao sobrar elementos na lista
			// apos remocao
			fila->primeiro = NULL;
			fila->ultimo = NULL;
		}

		// ajusta tamanho da fila
		fila->tamanho_fila--;

		// libera memoria de node_removido
		free(node_removido->dados);
		free(node_removido);

		return 0;
	} else {
		return 1;
	}
}

int limpa_fila(Fila *fila) {
	// testa se ponteiro eh valido
	if (fila == NULL) {
		return 1;
	}
	int status = 0;
	while (fila->tamanho_fila > 0) {
		status = remove_inicio_fila(fila, NULL);
		if (status == 1) {
			return 1;
		}
	}
	return 0;
}

int retorna_tamanho_fila(Fila *fila, int *tam) {
	// testa se ponteiro eh valido
	if (fila == NULL || tam == NULL) {
		return 1;
	}
	*tam = fila->tamanho_fila;
	return 0;
}