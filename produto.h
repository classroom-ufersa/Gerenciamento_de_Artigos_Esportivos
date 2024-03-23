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

void adicionarProduto(Lista_Produtos *lista, Produto produto);
void imprimirProdutos(Lista_Produtos *lista);
void removerProduto(Lista_Produtos *lista, const char *nome);
int listaProdutosVazia(Lista_Produtos *lista);
void liberarListaProdutos(Lista_Produtos *lista);
void editarProduto(Lista_Produtos *lista, char *nome);
void buscarPorNome(Lista_Produtos *lista, char *nome);

#endif
