#ifndef PRODUTO_H
#define PRODUTO_H


// Definição da estrutura do produto
typedef struct produto Produto;

// Definição da estrutura da lista de produtos
typedef struct lista_produto Lista_Produtos;

// Função para adicionar um produto à lista
Lista_Produtos *adicionarProduto(Lista_Produtos *lista, char *nome, char *categoria, float preco, int quantidade);

// Função para imprimir os produtos da lista
void imprimirProdutos(Lista_Produtos *lista);

// Função para remover um produto da lista pelo nome
Lista_Produtos *removerProduto(Lista_Produtos *lista, char nome[100]);

// Função para verificar se a lista de produtos está vazia
int listaProdutosVazia(Lista_Produtos *lista);

// Função para liberar a memória ocupada pela lista de produtos
void liberarListaProdutos(Lista_Produtos *lista);

// Função para editar um produto na lista pelo nome
void editarProduto(Lista_Produtos *lista, char *nome);

// Função para buscar produtos na lista pelo nome
Lista_Produtos *buscarPorNome(Lista_Produtos *lista, char *nome);

void Imprimir_Produto(Lista_Produtos *Produto);

void Escreve_Produtos(Lista_Produtos *lista_produtos_var, FILE *Arquivo, int Numero_Produto);

Lista_Produtos *Ler_Produtos(Lista_Produtos *lista_produtos_var, FILE *Arquivo, int quantidade_produtos);

float extrairFloat(char *str);

int extrairInt(char *str);

#endif // PRODUTO_H
