#include "produto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct sessao Sessao;
typedef struct lista_sessao Lista_Sessao;

Lista_Sessao *Cria_Lista_Sessao();
Lista_Sessao *Adicionar_Sessao(Lista_Sessao *lista_sessao_var);
short Lista_Vazia(Lista_Sessao *lista_sessao_var);
Lista_Sessao *Percorrer_Sessoes(Lista_Sessao *lista_sessao_var);
void Imprimir_Sessao(Lista_Sessao *lista_sessao_var);
Lista_Sessao *Remover_Sessao(Lista_Sessao *lista_sessao_var, char nome[100]);
Lista_Produtos *Busca_Sessao(Lista_Sessao *lista_sessao_var, char nome[100]);
Lista_Produtos *Pegar_Lista_Produtos(Lista_Sessao *lista_sessao_var);