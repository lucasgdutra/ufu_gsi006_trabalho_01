SHELL := /bin/bash
CC = gcc
APPS=./apps
BIN=./bin
INCLUDE=./include
OBJ=./obj
SRC=./src
TEST=./test
CFLAGS+=-O3 -Wall -Wextra -lm -I $(INCLUDE)

all:	prepare compile_tads compile_app

compile_tads:	$(OBJ)/cardapio.o\
	$(OBJ)/chocolate.o\
	$(OBJ)/comanda.o\
	$(OBJ)/fila.o\
	$(OBJ)/lista.o\
	$(OBJ)/pilha.o\
	$(OBJ)/produto.o

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
	$(TEST)/fila.test
	
$(TEST)/%.test:	$(TEST)/%.c
	$(CC) $(CFLAGS) $< $(OBJ)/*.o -o $@ 

test:	$(TEST)/lista.run_test\
	$(TEST)/fila.run_test

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