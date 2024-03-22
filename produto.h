#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct {
    char nome[100];
    char categoria[100];
    float preco;
    int quantidade;
} Produto;

