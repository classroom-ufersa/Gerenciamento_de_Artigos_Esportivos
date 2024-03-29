#include "funcoes.h"

char exibirMenu() {

    setlocale(LC_ALL, "Portuguese");
    char escolha;
    printf("\n\t\033[34m=== Menu ===\n");
    printf("\t\033[1;33m1.\033[0m Adicionar produto\n");
    printf("\t\033[1;33m2.\033[0m Remover produto\n");
    printf("\t\033[1;33m3.\033[0m Adicionar sess�o\n");
    printf("\t\033[1;33m4.\033[0m Remover sess�o\n");
    printf("\t\033[1;33m5.\033[0m Editar informa��es do produto\n");
    printf("\t\033[1;33m6.\033[0m Buscar produto por nome\n");
    printf("\t\033[1;33m7.\033[0m Listar produtos por nome\n");
    printf("\t\033[1;33m8.\033[0m Sair\n");
    printf("\tEscolha uma op��o (\033[1;33m1-8\033[0m): ");
    scanf(" %c", &escolha);
    return escolha;
}


void Escrever_Arquivo(Lista_Sessao *lista_sessao_var){

    FILE *Arquivo = fopen("Arquivo.txt", "wt");
    Escrever_Sessao(lista_sessao_var, Arquivo);
    fclose(Arquivo);
}
