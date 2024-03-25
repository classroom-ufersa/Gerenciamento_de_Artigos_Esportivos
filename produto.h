#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct produto Produto;
typedef struct lista_produto Lista_Produtos;


Lista_Produtos *adicionarProduto(Lista_Produtos *lista);
void imprimirProdutos(Lista_Produtos *lista);
Lista_Produtos *removerProduto(Lista_Produtos *lista, char nome[100]);
int listaProdutosVazia(Lista_Produtos *lista);
void liberarListaProdutos(Lista_Produtos *lista);
void editarProduto(Lista_Produtos *lista, char *nome);
void buscarPorNome(Lista_Produtos *lista, char *nome);

#endif
