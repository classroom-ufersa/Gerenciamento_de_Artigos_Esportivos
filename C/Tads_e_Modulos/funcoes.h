#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "sessao.h"
#include "produto.h"

char exibirMenu();
void Escrever_Arquivo(Lista_Sessao *lista_sessao_var);
int *Contador_Sessoes_e_Produtos();
Lista_Sessao *Ler_Arquivo(Lista_Sessao *lista_sessao_var);
void string_maiuscula_minuscula(char *Nome);
float extrairFloat(char *str);
int extrairInt(char *str);