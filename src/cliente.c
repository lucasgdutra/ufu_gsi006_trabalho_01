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
	c->nome = nome;
	c->tamanho_nome = tamanho_nome;
	c->comanda = comanda;
	return 0;
}

int inicializa_fila_cliente(Fila_Cliente *fc) {
	Fila *fila;
	fila = (Fila *)malloc(sizeof(Fila));
	inicializa_fila(fila, sizeof(Cliente));
	fc->fila = fila;
	return 0;
};

int adiciona_cliente_fila(Fila_Cliente *fc, Cliente *c) {
	int status = adiciona_final_fila(fc->fila,c);
	if (status != 0)
		return 1;
	return 0;
}

int remove_cliente_fila(Fila_Cliente *fc, Cliente *cliente_retorno){
	int status = remove_inicio_fila(fc->fila,cliente_retorno);
	if (status != 0)
		return 1;
	return 0;
}