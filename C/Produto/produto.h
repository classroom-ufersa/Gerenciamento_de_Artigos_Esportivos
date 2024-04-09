#ifndef PRODUTO_H
#define PRODUTO_H

// Definição da estrutura do produto
typedef struct produto Produto;

// Definição da estrutura da lista de produtos
typedef struct lista_produto Lista_Produtos;

/**
 * @brief Adiciona um produto à lista.
 * 
 * @param lista Ponteiro para o início da lista encadeada de produtos.
 * @param nome Nome do produto a ser adicionado.
 * @param categoria Categoria do produto.
 * @param preco Preço do produto.
 * @param quantidade Quantidade do produto disponível.
 * @return Ponteiro para a lista atualizada com o novo produto.
 */
Lista_Produtos *adicionarProduto(Lista_Produtos *lista, char *nome, char *categoria, float preco, int quantidade);

/**
 * @brief Imprime os produtos da lista.
 * 
 * @param lista Ponteiro para o início da lista de produtos.
 */
void imprimirProdutos(Lista_Produtos *lista);

/**
 * @brief Remove um produto da lista pelo nome.
 * 
 * @param lista Ponteiro para a lista de produtos.
 * @param nome Nome do produto a ser removido.
 * @return Lista atualizada com o produto removido.
 */
Lista_Produtos *removerProduto(Lista_Produtos *lista, char nome[100]);

/**
 * @brief Verifica se a lista de produtos está vazia.
 * 
 * @param lista Ponteiro para a lista de produtos.
 * @return 1 se a lista estiver vazia, 0 se não estiver.
 */
int listaProdutosVazia(Lista_Produtos *lista);

/**
 * @brief Libera a memória ocupada pela lista de produtos.
 * 
 * @param lista Ponteiro para a lista de produtos.
 */
void liberarListaProdutos(Lista_Produtos *lista);

/**
 * @brief Edita um produto na lista pelo nome.
 * 
 * @param lista Ponteiro para a lista de produtos.
 * @param nome Ponteiro para uma string contendo o nome do produto a ser editado.
 * @return 1 se a edição foi bem-sucedida, 0 caso contrário.
 */
short editarProduto(Lista_Produtos *lista, char *nome);

/**
 * @brief Busca produtos na lista pelo nome.
 * 
 * @param lista Ponteiro para a lista de produtos.
 * @param nome Ponteiro para uma string contendo o nome (ou parte do nome) do produto a ser buscado.
 * @return Ponteiro para o produto encontrado, ou NULL se não encontrado.
 */
Lista_Produtos *buscarPorNome(Lista_Produtos *lista, char *nome);

/**
 * @brief Imprime as informações de um produto.
 * 
 * @param Produto Ponteiro para a estrutura do produto a ser impresso.
 */
void Imprimir_Produto(Lista_Produtos *Produto);

/**
 * @brief Escreve os produtos contidos na lista em um arquivo.
 * 
 * @param lista_produtos_var Ponteiro para a lista de produtos.
 * @param Arquivo Ponteiro para o arquivo onde os produtos serão escritos.
 * @param Numero_Produto Número do produto atual que está sendo escrito no arquivo.
 */
void Escreve_Produtos(Lista_Produtos *lista_produtos_var, FILE *Arquivo, int Numero_Produto);

/**
 * @brief Lê os produtos de um arquivo e adiciona-os à lista de produtos.
 * 
 * @param lista_produtos_var Ponteiro para a lista de produtos.
 * @param Arquivo Ponteiro para o arquivo contendo os produtos.
 * @param quantidade_produtos Quantidade total de produtos a serem lidos do arquivo.
 * @return Ponteiro para a lista de produtos atualizada.
 */
Lista_Produtos *Ler_Produtos(Lista_Produtos *lista_produtos_var, FILE *Arquivo, int quantidade_produtos);

#endif // PRODUTO_H
