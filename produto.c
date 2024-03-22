#include "produto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void adicionarProduto(Lista_Produtos *lista, Produto produto) {
    No_Produto *novoNo = (No_Produto*)malloc(sizeof(No_Produto));
    if (novoNo != NULL) {
        novoNo->produto = produto;
        novoNo->proximo = lista->primeiro;
        lista->primeiro = novoNo;
    } else {
        printf("Erro: Não foi possível adicionar o produto. Memória insuficiente.\n");
    }
}

void imprimirProdutos(Lista_Produtos *lista) {
    if (listaProdutosVazia(lista)) {
        printf("Lista de produtos vazia.\n");
        return;
    }
    printf("Produtos:\n");
    No_Produto *atual = lista->primeiro;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->produto.nome);
        printf("Categoria: %s\n", atual->produto.categoria);
        printf("Preço: %.2f\n", atual->produto.preco);
        printf("Quantidade: %d\n", atual->produto.quantidade);
        printf("\n");
        atual = atual->proximo;
    }
}
