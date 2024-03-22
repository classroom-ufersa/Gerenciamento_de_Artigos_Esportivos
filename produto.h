#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    char nome[100];
    char categoria[100];
    float preco;
    int quantidade;
} Produto;

typedef struct No_Produto {
    Produto produto;
    struct No_Produto *proximo;
} No_Produto;

typedef struct {
    No_Produto *primeiro;
} Lista_Produtos;
