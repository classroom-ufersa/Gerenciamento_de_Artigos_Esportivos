#ifndef PRODUTO_H
#define PRODUTO_H


// Definição da estrutura do produto
typedef struct produto Produto;

// Definição da estrutura da lista de produtos
typedef struct lista_produto Lista_Produtos;

/*
 *Função de adicionar produto a lista.
 * Parâmetro: Recebe um ponteiro pro começo da lista encadeada 
 *@return: Retorna a lista atualizada com o novo produto
*/
Lista_Produtos *adicionarProduto(Lista_Produtos *lista, char *nome, char *categoria, float preco, int quantidade);

/**Função para imprimir os produtos da lista
 * Parâmetro: Recebe um ponteiro pro começo da lista de produto
 * Retorno: imprime os produtos na saida padrão
 */
void imprimirProdutos(Lista_Produtos *lista);

/**Função para remover um produto da lista pelo nome
 * Parâmetro: recebe o ponteiro para a lista de produto e um array de caractere
 * Retorno: lista atualizada com o produto removido
*/
Lista_Produtos *removerProduto(Lista_Produtos *lista, char nome[100]);

/**Função para verificar se a lista de produtos está vazia
 * Parâmetro: Recebe um ponteiro pro começo da lista de produto
 * Retorno: Retorna 1 se a lista tiver fazia e 0 se não estiver
*/
int listaProdutosVazia(Lista_Produtos *lista);

/**Função para liberar a memória ocupada pela lista de produtos
 * Parâmetro: ponteiro para lista de produtos que será liberado a memoria
 * Retorno: nada
*/
void liberarListaProdutos(Lista_Produtos *lista);

/**Função para editar um produto na lista pelo nome
 * Parâmetro: ponteiro para a lista de produto e Um ponteiro para uma string que contém o nome do produto que será editado.
 * Retorno: retorna a lista com o produto editado
*/
short editarProduto(Lista_Produtos *lista, char *nome);

/**Função para buscar produtos na lista pelo nome
 * Parâmetro:Um ponteiro para uma string que contém o nome (ou parte do nome) do produto que está sendo buscado.
 * Retorno: retorna o produto encontrado
*/
Lista_Produtos *buscarPorNome(Lista_Produtos *lista, char *nome);

/**
 * Parâmetro: recebe a struct do produto
 * Retorno: retorna as informações do produto
*/
void Imprimir_Produto(Lista_Produtos *Produto);
/**
 * Parâmetro:um inteiro que representa o número do produto atual que está sendo escrito no arquivo.
 * Retorno: escreve os produtos contidos na lista no arquivo
*/
void Escreve_Produtos(Lista_Produtos *lista_produtos_var, FILE *Arquivo, int Numero_Produto);
/**
 * Parâmetro: Um inteiro que representa a quantidade total de produtos a serem lidos do arquivo.
 * Retorno: retorna a lista de produto atualizada
*/
Lista_Produtos *Ler_Produtos(Lista_Produtos *lista_produtos_var, FILE *Arquivo, int quantidade_produtos);

#endif // PRODUTO_H
