#include "funcoes.h"
#include <stdio.h>

char exibirMenu() {
    char escolha;
    printf("\nMenu:\n");
    printf("1. Adicionar produto\n");
    printf("2. Remover produto\n");
    printf("3. Adicionar sessão\n");
    printf("4. Remover sessão\n");
    printf("5. Editar informações do produto\n");
    printf("6. Buscar produto por nome\n");
    printf("7. Listar produtos por nome\n");
    printf("8. Sair\n");
    printf("Escolha uma opção (1-8): ");
    scanf("%c", &escolha);
    return escolha;
}



void menu(){

    char escolha = exibirMenu();

    switch (escolha)
    {
    case '1':
        /* code */
        break;
    
    default:
        break;
    }
}