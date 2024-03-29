#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "sessao.h"
#include "produto.h"

char exibirMenu();
void Escrever_Arquivo(Lista_Sessao *lista_sessao_var);
int *Contador_Sessoes_e_Produtos(FILE *Arquivo);