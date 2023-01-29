#include "../include/lista.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializa_lista(Lista_Ordenada *lista, int tamanho_estrutura_dados) {
	// testa se ponteiro eh valido
	if (lista == NULL) {
		return 1;
	}
	lista->primeiro = NULL;
	lista->tamanho_estrutura_dados = tamanho_estrutura_dados;
	lista->tamanho_lista = 0;
	return 0;
}

int adiciona_em_lista(Lista_Ordenada *lista, void *dados, int pos) {
	// testa se ponteiro eh valido
	if (lista == NULL || dados == NULL) {
		return 1;
	}
	// instancia estrutura para receber elemento
	Node_Lista *novo_node;
	novo_node = (Node_Lista *)malloc(sizeof(Node_Lista));
	if (novo_node == NULL) {
		// erro ao alocar elemento
		return 1;
	}
	novo_node->dados = malloc(lista->tamanho_estrutura_dados);
	if (novo_node->dados == NULL) {
		// erro ao alocar dados do elemento
		free(novo_node);
		return 1;
	}

	// define propriedades do nodo
	memcpy(novo_node->dados, dados, lista->tamanho_estrutura_dados);
	novo_node->pos = pos;
	novo_node->proximo_node = NULL;

	// insere node na lista
	if (lista->primeiro == NULL) {
		// se lista vazia insere na primeira posição
		lista->primeiro = novo_node;
	} else {
		Node_Lista *node_anterior = NULL;
		Node_Lista *node_atual = lista->primeiro;

		while (true) {

			if (node_atual == NULL) {

				// inserir na ultima posicao
				node_anterior->proximo_node = novo_node;
				break;
			} else if (node_anterior == NULL) {
				// inserir na primeira posição
				if (pos < node_atual->pos) {
					lista->primeiro = novo_node;
					novo_node->proximo_node = node_atual;
					break;
				}
			} else if (pos >= node_anterior->pos && pos < node_atual->pos) {
				// inserir no meio
				node_anterior->proximo_node = novo_node;

				novo_node->proximo_node = node_atual;
				break;
			}

			node_anterior = node_atual;
			node_atual = node_atual->proximo_node;
		}
	}

	// ajusta tamanho da lista
	lista->tamanho_lista++;
	return 0;
};

int remove_da_lista(Lista_Ordenada *lista, void *valor, int pos) {
	// testa se ponteiro eh valido
	if (lista == NULL) {
		return 1;
	}
	if (lista->tamanho_lista > 0) {
		Node_Lista *node_anterior = NULL;
		Node_Lista *node_atual = lista->primeiro;
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
						   lista->tamanho_estrutura_dados);
				}
				// ajusta apontamento do node anterior para proximo node
				if (node_anterior == NULL) {
					// removendo primeiro elemento
					lista->primeiro = node_atual->proximo_node;
				} else {
					node_anterior->proximo_node = node_atual->proximo_node;
				}

				// libera memoria de node_removido
				free(node_removido->dados);
				free(node_removido);

				// ajusta tamanho da lista
				lista->tamanho_lista--;
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

int limpa_lista(Lista_Ordenada *lista) {
	// testa se ponteiro eh valido
	if (lista == NULL) {
		return 1;
	}
	while (lista->tamanho_lista > 0) {
		Node_Lista *node_removido = lista->primeiro;
		lista->primeiro = node_removido->proximo_node;
		// libera memoria de node_removido
		free(node_removido->dados);
		free(node_removido);
		lista->tamanho_lista--;
	}
	return 0;
}

int retorna_tamanho_lista(Lista_Ordenada *lista, int *tam) {
	// testa se ponteiro eh valido
	if (lista == NULL || tam == NULL) {
		return 1;
	}
	*tam = lista->tamanho_lista;
	return 0;
}

int buscar_item_lista(Lista_Ordenada *lista, int posicao, void *retorno_dados) {
	// testa se ponteiro eh valido
	if (lista == NULL || retorno_dados == NULL) {
		return 1;
	}
	Node_Lista *node_atual = lista->primeiro;
	if (node_atual == NULL) {
		// lista vazia
		return 1;
	}
	while (true) {
		if (node_atual == NULL) {
			// node_atual chegou ao final da lista, item nao encontrado
			return 1;
		}
		if (node_atual->pos == posicao) {
			memcpy(retorno_dados, node_atual->dados,
				   lista->tamanho_estrutura_dados);
			return 0;
		}
		if (posicao < node_atual->pos) {
			// como a lista eh ordenada, se a posicao da busca for menor que a
			// posicao atual entao a posicao da busca já passou e nao existe
			return 1;
		}
		node_atual = node_atual->proximo_node;
	}
	return 0;
}