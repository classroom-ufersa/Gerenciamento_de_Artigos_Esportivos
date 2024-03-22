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
