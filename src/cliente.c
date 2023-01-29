/* --------------------------------------------------------------------------------------
   Comanda
   Objetivo: Trabalho de disciplina Estrutura de dados (GSI006) BSI - Facom -
UFU Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/

#include "../include/cliente.h"
#include "../include/fila.h"
#include <stdlib.h>

int inicializa_cliente(Cliente *c, char *nome, int tamanho_nome,
					   Comanda *comanda) {
	// testa se ponteiro eh valido
	if (c == NULL || comanda == NULL) {
		return 1;
	}
	c->nome = nome;
	c->tamanho_nome = tamanho_nome;
	c->comanda = comanda;
	return 0;
}

int inicializa_fila_cliente(Fila_Cliente *fila_cliente) {
	// testa se ponteiro eh valido
	if (fila_cliente == NULL) {
		return 1;
	}
	Fila *fila;
	fila = (Fila *)malloc(sizeof(Fila));
	inicializa_fila(fila, sizeof(Cliente));
	fila_cliente->fila = fila;
	return 0;
};

int adiciona_cliente_fila(Fila_Cliente *fila_cliente, Cliente *c) {
	// testa se ponteiro eh valido
	if (fila_cliente == NULL || c == NULL) {
		return 1;
	}
	int status = adiciona_final_fila(fila_cliente->fila, c);
	if (status != 0)
		return 1;
	return 0;
}

int remove_cliente_fila(Fila_Cliente *fila_cliente, Cliente *cliente_retorno) {
	// testa se ponteiro eh valido
	if (fila_cliente == NULL || cliente_retorno == NULL) {
		return 1;
	}
	int status = remove_inicio_fila(fila_cliente->fila, cliente_retorno);
	if (status != 0)
		return 1;
	return 0;
}