SHELL := /bin/bash
CC = gcc
APPS=./apps
BIN=./bin
INCLUDE=./include
OBJ=./obj
SRC=./src
TEST=./test
CFLAGS+=-O0 -Wall -Wextra -lm -I $(INCLUDE) -ggdb -g3

all:	prepare compile_tads compile_app compile_test

compile_tads:	$(OBJ)/cardapio.o\
	$(OBJ)/chocolate.o\
	$(OBJ)/comanda.o\
	$(OBJ)/fila.o\
	$(OBJ)/lista.o\
	$(OBJ)/pilha.o\
	$(OBJ)/produto.o\
	$(OBJ)/cliente.o\
	$(OBJ)/modulo_cliente.o\
	$(OBJ)/modulo_cardapio.o\
	$(OBJ)/modulo_chocolate.o

$(OBJ)/%.o:	$(SRC)/%.c $(INCLUDE)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

compile_app:	clean_app\
	$(BIN)/restaurante

$(BIN)/%:	$(APPS)/%.c
	$(CC) $(CFLAGS) $< $(OBJ)/*.o -o $@


run:
	$(BIN)/restaurante

compile_test:	all\
	$(TEST)/lista.test\
	$(TEST)/fila.test\
	$(TEST)/pilha.test\
	$(TEST)/produto.test\
	$(TEST)/cardapio.test\
	$(TEST)/chocolate.test

$(TEST)/%.test:	$(TEST)/%.c
	$(CC) $(CFLAGS) $< $(OBJ)/*.o -o $@

test:	$(TEST)/lista.run_test\
	$(TEST)/fila.run_test\
	$(TEST)/pilha.run_test\
	$(TEST)/produto.run_test\
	$(TEST)/cardapio.run_test\
	$(TEST)/chocolate.run_test

$(TEST)/%.run_test:	compile_test $(TEST)/%.test $(TEST)/%.in $(TEST)/%.out
	-diff <($(word 2,$^) < $(word 3,$^))  $(word 4,$^)

clean:
	rm -rf $(BIN)/* $(OBJ)/* $(TEST)/*.test

clean_app:
	rm -rf $(BIN)/*

clean_test:
	rm -rf $(TEST)/*.test

prepare:
	mkdir -p bin obj