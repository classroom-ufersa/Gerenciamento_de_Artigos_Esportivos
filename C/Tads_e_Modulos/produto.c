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
Lista_Produtos *adicionarProduto(Lista_Produtos *lista, char *nome, char *categoria, float preco, int quantidade) {
    // Declaração de uma variável do tipo Produto para armazenar o novo produto
    Produto novo_Produto;

    // Solicita ao usuário informações sobre o novo produto
    strcpy(novo_Produto.nome, nome);
    strcpy(novo_Produto.categoria, categoria);
    novo_Produto.preco = preco;
    novo_Produto.quantidade = quantidade;

    Lista_Produtos *ordenada = lista;
    Lista_Produtos *Anterior = NULL;
    while (ordenada != NULL){
        if (strcmp(nome, ordenada->produto.nome) < 0){
            break;
        }
        Anterior = ordenada;
        ordenada = ordenada->proximo_produto;
    }
    // Aloca memória para um novo nó da lista
    Lista_Produtos *novoNo = (Lista_Produtos *)malloc(sizeof(Lista_Produtos));
    // Verifica se a alocação foi bem-sucedida
    if (novoNo != NULL) {
        // Preenche o novo nó com o novo produto e o adiciona no início da lista
        if(Anterior == NULL){
        novoNo->produto = novo_Produto;
        novoNo->proximo_produto = lista;
        return novoNo;
        } else {
            novoNo->produto = novo_Produto;
            Anterior->proximo_produto = novoNo;
            novoNo->proximo_produto = ordenada;
            return lista;
        }
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
Lista_Produtos *buscarPorNome(Lista_Produtos *lista, char *nome) {

    // Percorre a lista procurando produtos que contenham o nome especificado
    Lista_Produtos *atual = lista;

    while (atual != NULL) {
        if (strstr(atual->produto.nome, nome) != NULL) {
            return atual;      
        }
        atual = atual->proximo_produto;
    }

    return atual;
}

void Imprimir_Produto(Lista_Produtos *Produto){

    printf("Produto encontrado:\n");
        printf("Nome: %s\n", Produto->produto.nome);
        printf("Categoria: %s\n", Produto->produto.categoria);
        printf("Preço: %.2f\n", Produto->produto.preco);
        printf("Quantidade: %d\n", Produto->produto.quantidade);
        printf("\n");
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

        char nome[100], categoria[100];
        float preco;
        int quantidade;
        char preco_str[100], quantidade_str[100];
        fscanf(Arquivo, "Produto %*d\n");
        fscanf(Arquivo, "Nome: %[^\n]\n", nome);
        fscanf(Arquivo, "categoria: %[^\n]\n", categoria);
        fscanf(Arquivo, "preco: %[^\n]\n", preco_str);
        fscanf(Arquivo, "quantidade: %[^\n]\n\n", quantidade_str);

        
        preco = extrairFloat(preco_str);
        quantidade = extrairInt(quantidade_str);

        lista_produtos_var = adicionarProduto(lista_produtos_var, nome, categoria, preco, quantidade);
        
        quantidade_produtos--;
    }
    fscanf(Arquivo, "\n");
    return lista_produtos_var;
}
