#ifndef SESSAO_H
#define SESSAO_H

#include "../Produto/produto.h"

/**
 * @struct Sessao
 * Estrutura que representa uma sessão.
 */
typedef struct sessao Sessao;

/**
 * @struct Lista_Sessao
 * Estrutura que representa uma lista de sessões.
 */
typedef struct lista_sessao Lista_Sessao;

/**
 * @brief Cria uma nova lista de sessões.
 * 
 * @return Ponteiro para a nova lista de sessões.
 */
Lista_Sessao *Cria_Lista_Sessao();

/**
 * @brief Adiciona uma nova sessão à lista de sessões.
 * 
 * @param lista_sessao_var Ponteiro para a lista de sessões.
 * @param nome Nome da sessão.
 * @param descricao Descrição da sessão.
 * @param lista_produto_var Ponteiro para a lista de produtos da sessão.
 * @return Ponteiro para a lista de sessões atualizada.
 */
Lista_Sessao *Adicionar_Sessao(Lista_Sessao *lista_sessao_var, char *nome, char *descricao, Lista_Produtos *lista_produto_var);

/**
 * @brief Verifica se a lista de sessões está vazia.
 * 
 * @param lista_sessao_var Ponteiro para a lista de sessões.
 * @return 1 se a lista estiver vazia, 0 caso contrário.
 */
short Lista_Vazia(Lista_Sessao *lista_sessao_var);

/**
 * @brief Percorre as sessões na lista de sessões.
 * 
 * @param lista_sessao_var Ponteiro para a lista de sessões.
 * @return Ponteiro para a próxima sessão na lista.
 */
Lista_Sessao *Percorrer_Sessoes(Lista_Sessao *lista_sessao_var);

/**
 * @brief Imprime os detalhes de uma sessão.
 * 
 * @param lista_sessao_var Ponteiro para a sessão a ser impressa.
 */
void Imprimir_Sessao(Lista_Sessao *lista_sessao_var);

/**
 * @brief Remove uma sessão da lista de sessões pelo nome.
 * 
 * @param lista_sessao_var Ponteiro para a lista de sessões.
 * @param nome Nome da sessão a ser removida.
 * @return Ponteiro para a lista de sessões atualizada.
 */
Lista_Sessao *Remover_Sessao(Lista_Sessao *lista_sessao_var, char nome[100]);

/**
 * @brief Busca uma sessão na lista de sessões pelo nome.
 * 
 * @param lista_sessao_var Ponteiro para a lista de sessões.
 * @param nome Nome da sessão a ser buscada.
 * @return Ponteiro para a sessão encontrada, ou NULL se não encontrada.
 */
Lista_Sessao *Busca_Sessao(Lista_Sessao *lista_sessao_var, char nome[100]);

/**
 * @brief Obtém a lista de produtos de uma sessão.
 * 
 * @param lista_sessao_var Ponteiro para a sessão.
 * @return Ponteiro para a lista de produtos da sessão.
 */
Lista_Produtos *Pegar_Lista_Produtos(Lista_Sessao *lista_sessao_var);

/**
 * @brief Adiciona uma lista de produtos a uma sessão.
 * 
 * @param Novo_No Ponteiro para a lista de produtos a ser adicionada.
 * @param lista_sessao_var Ponteiro para a sessão.
 * @return Ponteiro para a sessão atualizada.
 */
Lista_Sessao *Adicionar_Produto_Sessao(Lista_Produtos *Novo_No, Lista_Sessao *lista_sessao_var);

/**
 * @brief Libera a memória alocada para a lista de sessões.
 * 
 * @param lista_sessao_var Ponteiro para a lista de sessões.
 */
void *Liberar_Lista_Sessao(Lista_Sessao *lista_sessao_var);

/**
 * @brief Escreve os detalhes da sessão em um arquivo.
 * 
 * @param lista_sessao_var Ponteiro para a lista de sessões.
 * @param Arquivo Ponteiro para o arquivo onde os detalhes serão escritos.
 */
void Escrever_Sessao(Lista_Sessao *lista_sessao_var, FILE *Arquivo);

/**
 * @brief Lê as sessões de um arquivo e as adiciona à lista de sessões.
 * 
 * @param lista_sessao_var Ponteiro para a lista de sessões.
 * @param Arquivo Ponteiro para o arquivo contendo as sessões.
 * @param vetor Vetor de controle.
 * @return Ponteiro para a lista de sessões atualizada.
 */
Lista_Sessao *Ler_Sessoes(Lista_Sessao *lista_sessao_var, FILE *Arquivo, int *vetor);

#endif // SESSAO_H
