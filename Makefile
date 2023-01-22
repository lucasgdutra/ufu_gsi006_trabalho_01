CC = gcc
APPS=./apps
BIN=./bin
INCLUDE=./include
OBJ=./obj
SRC=./src
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

clean:	
	rm -rf $(BIN)/* $(OBJ)/*

clean_app:
	rm -rf $(BIN)/*

prepare:
	mkdir -p bin obj