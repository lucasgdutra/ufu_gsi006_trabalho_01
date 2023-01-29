#include "../include/chocolate.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR_SIZE 30
int main() {
	char nome[MAX_CHAR_SIZE];
	while (scanf("%s", nome) != EOF) {
		Chocolate chocolate;
		inicializa_chocolate(&chocolate, nome, MAX_CHAR_SIZE);
		printf("nome: %s\n", chocolate.nome);
	}

	return 0;
}