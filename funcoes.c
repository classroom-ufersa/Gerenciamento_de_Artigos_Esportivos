#include "funcoes.h"
#include <stdio.h>

char exibirMenu() {
    char escolha;
    printf("\n\t\033[34m=== Menu ===\n");
    printf("\t\033[1;33m1.\033[0m Adicionar produto\n");
    printf("\t\033[1;33m2.\033[0m Remover produto\n");
    printf("\t\033[1;33m3.\033[0m Adicionar sessão\n");
    printf("\t\033[1;33m4.\033[0m Remover sessão\n");
    printf("\t\033[1;33m5.\033[0m Editar informações do produto\n");
    printf("\t\033[1;33m6.\033[0m Buscar produto por nome\n");
    printf("\t\033[1;33m7.\033[0m Listar produtos por nome\n");
    printf("\t\033[1;33m8.\033[0m Sair\n");
    printf("\tEscolha uma opção (\033[1;33m1-8\033[0m): ");
    scanf(" %c", &escolha);
    return escolha;
}

