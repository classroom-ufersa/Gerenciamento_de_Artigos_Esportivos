#include "../Funcoes/funcoes.h"

struct produto {
    char nome[100];
    char categoria[100];
    float preco;
    int quantidade;
};

struct lista_produto {
    Produto produto;
    Lista_Produtos *proximo_produto;
};

Lista_Produtos *adicionarProduto(Lista_Produtos *lista, char *nome, char *categoria, float preco, int quantidade) {
    
    Produto novo_Produto;

    
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
    
    Lista_Produtos *novoNo = (Lista_Produtos *)malloc(sizeof(Lista_Produtos));

    if (novoNo != NULL) {
        
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

Lista_Produtos *removerProduto(Lista_Produtos *lista, char nome[100]) {
    
    if (listaProdutosVazia(lista)) {
        printf("Lista de produtos vazia. Nada a remover.\n");
        return lista;
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
            return lista;
        }
        anterior = atual;
        atual = atual->proximo_produto;
    }
    return lista;
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

short editarProduto(Lista_Produtos *lista, char *nome_escolhido) {
    
    if (listaProdutosVazia(lista)) {
        printf("Lista de produtos vazia. Nada a editar.\n");
    }

    
    Lista_Produtos *atual = lista;
    char nome[100], categoria[100];
    float preco;
    int quantidade;
    while (atual != NULL) {
        if (strcmp(atual->produto.nome, nome_escolhido) == 0) {
            
            printf("Digite o novo nome do produto: ");
            scanf(" %[^\n]", nome);
            printf("Digite a nova categoria do produto: ");
            scanf(" %[^\n]", categoria);
            printf("Digite o novo preço do produto: ");
            scanf(" %f", &preco);
            printf("Digite a nova quantidade do produto: ");
            scanf(" %d", &quantidade);
            removerProduto(lista, nome_escolhido);
            adicionarProduto(lista, nome, categoria, preco, quantidade);
            printf("Produto \"%s\" editado com sucesso.\n", nome);
           
            return 1;
        }
        atual = atual->proximo_produto;
    }
    return 0;
    printf("Produto \"%s\" não encontrado na lista.\n", nome);
}

Lista_Produtos *buscarPorNome(Lista_Produtos *lista, char *nome) {

    
    Lista_Produtos *atual = lista;

    while (atual != NULL) {
        if (strcmp(atual->produto.nome, nome) == 0) {
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
        string_maiuscula_minuscula(nome);
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
