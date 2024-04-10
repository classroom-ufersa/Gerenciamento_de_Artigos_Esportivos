#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "../Sessao/sessao.h"
#include "../Produto/produto.h"

/**
 * @brief Exibe o menu e retorna a opção escolhida pelo usuário.
 * 
 * @return Caractere representando a opção escolhida pelo usuário.
 */
char exibirMenu();

/**
 * @brief Escreve os detalhes das sessões em um arquivo.
 * 
 * @param lista_sessao_var Ponteiro para a lista de sessões.
 */
void Escrever_Arquivo(Lista_Sessao *lista_sessao_var);

/**
 * @brief Conta o número de sessões e produtos.
 * 
 * @return Um array de inteiros contendo o número de sessões e produtos, respectivamente.
 */
int *Contador_Sessoes_e_Produtos();

/**
 * @brief Lê os detalhes das sessões de um arquivo e as adiciona à lista de sessões.
 * 
 * @param lista_sessao_var Ponteiro para a lista de sessões.
 * @return Ponteiro para a lista de sessões atualizada.
 */
Lista_Sessao *Ler_Arquivo(Lista_Sessao *lista_sessao_var);

/**
 * @brief Converte uma string para maiúsculas ou minúsculas.
 * 
 * @param Nome Ponteiro para a string a ser convertida.
 */
void string_maiuscula_minuscula(char *Nome);

/**
 * @brief Extrai um número float de uma string.
 * 
 * @param str Ponteiro para a string contendo o número float.
 * @return O número float extraído da string.
 */
float extrairFloat(char *str);

/**
 * @brief Extrai um número inteiro de uma string.
 * 
 * @param str Ponteiro para a string contendo o número inteiro.
 * @return O número inteiro extraído da string.
 */
int extrairInt(char *str);

/**
 * @brief Limpa o conteúdo da tela do terminal.
 */
void Limpar_Tela();

/**
 * @brief Configura as definições do terminal para a execução do programa.
 */
void Configura_Terminal();

/**
 * @brief Emite um sinal sonoro (bip) no terminal.
 */
void Emite_Bip();
