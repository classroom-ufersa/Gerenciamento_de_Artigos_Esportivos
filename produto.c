#include "funcoes.h"

// Definição da estrutura Produto
struct produto {
    char nome[100];
    char categoria[100];
    float preco;
    int quantidade;
};

// Definição da estrutura Lista_Produtos
struct lista_produto {
    Produto produto;
    Lista_Produtos *proximo_produto;
};

// Função para adicionar um novo produto à lista
Lista_Produtos *adicionarProduto(Lista_Produtos *lista) {
    // Declaração de uma variável do tipo Produto para armazenar o novo produto
    Produto novo_Produto;

    // Solicita ao usuário informações sobre o novo produto
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", novo_Produto.nome);
    printf("Digite a categoria do produto: ");
    scanf(" %[^\n]", novo_Produto.categoria);
    printf("Digite o preço do produto: ");
    scanf("%f", &novo_Produto.preco);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &novo_Produto.quantidade);

    // Aloca memória para um novo nó da lista
    Lista_Produtos *novoNo = (Lista_Produtos *)malloc(sizeof(Lista_Produtos));
    // Verifica se a alocação foi bem-sucedida
    if (novoNo != NULL) {
        // Preenche o novo nó com o novo produto e o adiciona no início da lista
        novoNo->produto = novo_Produto;
        novoNo->proximo_produto = lista;
        return novoNo;
    } else {
        printf("Erro: Não foi possível adicionar o produto. Memória insuficiente.\n");
    }
}

// Função para imprimir todos os produtos na lista
void imprimirProdutos(Lista_Produtos *lista) {
    // Verifica se a lista está vazia
    if (listaProdutosVazia(lista)) {
        printf("Lista de produtos vazia.\n");
        return;
    }
    printf("Produtos:\n");
    Lista_Produtos *atual = lista;
    // Percorre a lista e imprime cada produto
    while (atual != NULL) {
        printf("Nome: %s\n", atual->produto.nome);
        printf("Categoria: %s\n", atual->produto.categoria);
        printf("Preço: %.2f\n", atual->produto.preco);
        printf("Quantidade: %d\n", atual->produto.quantidade);
        printf("\n");
        atual = atual->proximo_produto;
    }
}

// Função para verificar se a lista de produtos está vazia
int listaProdutosVazia(Lista_Produtos *lista) {
    return (lista == NULL);
}

// Função para remover um produto da lista pelo nome
Lista_Produtos *removerProduto(Lista_Produtos *lista, char nome[100]) {
    // Verifica se a lista está vazia
    if (listaProdutosVazia(lista)) {
        printf("Lista de produtos vazia. Nada a remover.\n");
        return lista;
    }

    // Declaração de ponteiros para percorrer a lista
    Lista_Produtos *atual = lista;
    Lista_Produtos *anterior = NULL;

    // Percorre a lista procurando o produto com o nome especificado
    while (atual != NULL) {
        if (strcmp(atual->produto.nome, nome) == 0) {
            // Remove o nó correspondente ao produto encontrado
            if (anterior == NULL) {
                lista = atual->proximo_produto;
            } else {
                anterior->proximo_produto = atual->proximo_produto;
            }
            free(atual); // Libera a memória do nó removido
            printf("Produto \"%s\" removido com sucesso.\n", nome);
            return lista;
        }
        anterior = atual;
        atual = atual->proximo_produto;
    }
    return lista;
    printf("Produto \"%s\" não encontrado na lista.\n", nome); // Essa linha nunca será executada
}

// Função para liberar a memória ocupada pela lista de produtos
void liberarListaProdutos(Lista_Produtos *lista) {
    Lista_Produtos *atual = lista;
    while (atual != NULL) {
        Lista_Produtos *proximo = atual->proximo_produto;
        free(atual);
        atual = proximo;
    }
    free(lista);
}

// Função para editar um produto na lista pelo nome
void editarProduto(Lista_Produtos *lista, char *nome) {
    // Verifica se a lista está vazia
    if (listaProdutosVazia(lista)) {
        printf("Lista de produtos vazia. Nada a editar.\n");
    }

    // Percorre a lista procurando o produto com o nome especificado
    Lista_Produtos *atual = lista;
    while (atual != NULL) {
        if (strcmp(atual->produto.nome, nome) == 0) {
            // Solicita ao usuário as novas informações para o produto
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

// Função para buscar produtos na lista pelo nome
void buscarPorNome(Lista_Produtos *lista, char *nome) {
    // Verifica se a lista está vazia
    if (listaProdutosVazia(lista)) {
        printf("Lista de produtos vazia.\n");
    }

    // Percorre a lista procurando produtos que contenham o nome especificado
    Lista_Produtos *atual = lista;
    int encontrado = 0;
    while (atual != NULL) {
        if (strstr(atual->produto.nome, nome) != NULL) {
            // Imprime as informações do produto encontrado
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

void Escreve_Produtos(Lista_Produtos *lista_produtos_var, FILE *Arquivo, int Numero_Produto){

    Lista_Produtos *Atual = lista_produtos_var;
    if(lista_produtos_var == NULL){

        fprintf(Arquivo, "\n");
        return;
    } else {

        fprintf(Arquivo, "Produto %d\n", Numero_Produto);
        fprintf(Arquivo, "Nome: %s\n", lista_produtos_var->produto.nome);
        fprintf(Arquivo, "categoria: %s\n", lista_produtos_var->produto.categoria);
        fprintf(Arquivo, "preco: %.2f\n", lista_produtos_var->produto.preco);
        fprintf(Arquivo, "quantidade: %d\n", lista_produtos_var->produto.quantidade);
        fprintf(Arquivo, "\n");
        Numero_Produto++;
    }
    Escreve_Produtos(Atual->proximo_produto, Arquivo, Numero_Produto);
}

Lista_Produtos *Ler_Produtos(Lista_Produtos *lista_produtos_var, FILE *Arquivo, int quantidade_produtos){

    while(quantidade_produtos > 0){

        Lista_Produtos *Novo_No = (Lista_Produtos *)malloc(sizeof(Lista_Produtos));
        if (Arquivo == NULL)
        {
            printf("errp na alocacao de produtos\n");
            exit(1);
        }

        
        fscanf(Arquivo, "Produto %*d\n");
        fscanf(Arquivo, "Nome: %s\n", Novo_No->produto.nome);
        fscanf(Arquivo, "categoria: %s\n", Novo_No->produto.categoria);
        fscanf(Arquivo, "preco: %.2f\n", Novo_No->produto.preco);
        fscanf(Arquivo, "quantidade: %d\n\n", Novo_No->produto.quantidade);

        Novo_No->proximo_produto = lista_produtos_var;
        lista_produtos_var = Novo_No;
        quantidade_produtos--;
    }
    fscanf(Arquivo, "\n");
    return lista_produtos_var;
}