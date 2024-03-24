#include "produto.h"

struct produto{
    char nome[100];
    char categoria[100];
    float preco;
    int quantidade;
};

struct lista_produto{
    Produto produto;
    Lista_Produtos *proximo_produto;
};


void adicionarProduto(Lista_Produtos *lista) {

    Produto novo_Produto;
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", novo_Produto.nome);
    printf("Digite a categoria do produto: ");
    scanf(" %[^\n]", novo_Produto.categoria);
    printf("Digite o preço do produto: ");
    scanf(" %f", &novo_Produto.preco);
    printf("Digite a quantidade do produto: ");
    scanf(" %d", &novo_Produto.quantidade);

    Lista_Produtos *novoNo = (Lista_Produtos *)malloc(sizeof(Lista_Produtos));
    if (novoNo != NULL) {
        novoNo->produto = novo_Produto;
        novoNo->proximo_produto = lista;
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
    Lista_Produtos *atual = lista;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->produto.nome);
        printf("Categoria: %s\n", atual->produto.categoria);
        printf("Preço: %.2f\n", atual->produto.preco);
        printf("Quantidade: %d\n", atual->produto.quantidade);
        printf("\n");
        atual = atual->proximo_produto;
    }
}
int listaProdutosVazia(Lista_Produtos *lista) {
    return (lista == NULL);
}

void removerProduto(Lista_Produtos *lista, char nome[100]) {
    if (listaProdutosVazia(lista)) {
        printf("Lista de produtos vazia. Nada a remover.\n");
        return;
    }

    Lista_Produtos *atual = lista;
    Lista_Produtos *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->produto.nome, nome) == 0) {
            if (anterior == NULL) {
                lista = atual->proximo_produto;
            } else {
                anterior->proximo_produto = atual->proximo_produto;
            }
            free(atual);
            printf("Produto \"%s\" removido com sucesso.\n", nome);
            return;
        }
        anterior = atual;
        atual = atual->proximo_produto;
    }

    printf("Produto \"%s\" não encontrado na lista.\n", nome);
}

void liberarListaProdutos(Lista_Produtos *lista) {
    Lista_Produtos *atual = lista;
    while (atual != NULL) {
        Lista_Produtos *proximo = atual->proximo_produto;
        free(atual);
        atual = proximo;
    }
    free(lista);
}
void editarProduto(Lista_Produtos *lista, char *nome) {
    if (listaProdutosVazia(lista)) {
        printf("Lista de produtos vazia. Nada a editar.\n");
        return;
    }

    Lista_Produtos *atual = lista;

    while (atual != NULL) {
        if (strcmp(atual->produto.nome, nome) == 0) {
            printf("Digite o novo nome do produto: ");
            scanf(" %[^\n]", atual->produto.nome);
            printf("Digite a nova categoria do produto: ");
            scanf(" %[^\n]", atual->produto.categoria);
            printf("Digite o novo preço do produto: ");
            scanf(" %f", &atual->produto.preco);
            printf("Digite a nova quantidade do produto: ");
            scanf(" %d", &atual->produto.quantidade);
            printf("Produto \"%s\" editado com sucesso.\n", nome);
            return;
        }
        atual = atual->proximo_produto;
    }

    printf("Produto \"%s\" não encontrado na lista.\n", nome);
}
void buscarPorNome(Lista_Produtos *lista, char *nome) {
    if (listaProdutosVazia(lista)) {
        printf("Lista de produtos vazia.\n");
        return;
    }

    Lista_Produtos *atual = lista;
    int encontrado = 0;

    while (atual != NULL) {
        if (strstr(atual->produto.nome, nome) != NULL) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\n", atual->produto.nome);
            printf("Categoria: %s\n", atual->produto.categoria);
            printf("Preço: %.2f\n", atual->produto.preco);
            printf("Quantidade: %d\n", atual->produto.quantidade);
            printf("\n");
            encontrado = 1;
        }
        atual = atual->proximo_produto;
    }

    if (!encontrado) {
        printf("Nenhum produto encontrado com o nome \"%s\".\n", nome);
    }
}
