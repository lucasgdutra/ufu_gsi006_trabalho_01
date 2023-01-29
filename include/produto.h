/* --------------------------------------------------------------------------------------
   TAD Produto
   Nesse arquivo, criaremos os produtos do nosso restaurante, que constituirá o nosso 
   cardapio.
   Objetivo: Trabalho de disciplina Estrutura de dados (GSI006) BSI - Facom - UFU
   Restricoes:

   Autor: Dalmo Scalon Inacio/ Lucas Gabriel Dutra de Souza
   Disciplina: Estrutura de Dados 1
   Data da ultima atualizacao: 04/01/2023
----------------------------------------------------------------------------------------*/
#ifndef PRODUTO_H
#define PRODUTO_H

/*
    Struct Produto, temos um unsigned int indicando o id do produto, um ponteiro de char
    para indicar o nome do produto, um int para indicar o tamanho do nome e um float
    indicando o preço que será cobrado nesse produto.
*/
typedef struct produto
{
    unsigned int id;
    char *nome;
    int tam_nome;
    float preco;
} Produto;

/*
 Nome: inicializa_produto
 Entrada: Ponteiro do tipo Produto, int indicando o id, ponteiro de char caracterizando o nome
 outro int indicando o tam_nome e um float contendo o preço do produto inserido.
 Processo: Verifica validade dos ponteiros, inicia-se a struct produto com os valores recebidos
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int inicializa_produto(Produto *p, int id, char *nome, int tam_nome, float preco);

/*
 Nome: retorna_id_produto
 Entrada: Ponteiro do tipo Produto e um ponteiro de inteiro para atribuir ao id.
 Processo: Verifica validade dos ponteiros, posteriormente, copia o id do produto e envia
 para o ponteiro int *retorno_id. 
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int retorna_id_produto(Produto *p, int *retorno_id);

/*
 Nome: retorna_nome_produto
 Entrada: Ponteiro do tipo Produto, ponteiro do tipo char indicando o nome do produto.
 Processo: Verifica validade dos ponteiros, depois retorna o nome do produto passado no 
 ponteiro de char.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int retorna_nome_produto(Produto *p, char *retorno_nome);

/*
 Nome: retorna_preco_produto
 Entrada: Ponteiro do tipo Produto, ponteiro do tipo float indicando o preço do produto.
 Processo: Verifica validade dos ponteiros, depois retorna o preco do produto passado no 
 ponteiro de float.
 Saida: return 0 caso dê certo, e 1 caso dê errado.
 */
int retorna_preco_produto(Produto *p, float *retorno_preco);



#endif
