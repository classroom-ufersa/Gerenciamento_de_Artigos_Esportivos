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
    if (Arquivo == NULL)
    {
        printf("errp na abertura para escrever de arquivo\n");
        exit(1);
    }
    fclose(Arquivo);
}

int *Contador_Sessoes_e_Produtos(){
    
    FILE *Arquivo = fopen("Arquivo.txt", "rt");
    if (Arquivo == NULL)
    {
        printf("errp na abertura de arquivo\n");
        exit(1);
    }

    int *Contador = (int *)malloc(sizeof(int));
    if (Contador == NULL)
    {
        printf("errp na realcacao de arquivo\n");
        exit(1);
    }
    int index = -1;
    char linha[200];

    while(fscanf(Arquivo, "%[^\n]\n", linha) != EOF){

        if(strstr(linha, "Sessao") != NULL){
            index++;
            Contador = (int *)realloc(Contador, (index + 1) * sizeof(int));
            if (Contador == NULL)
            {
                printf("errp na realcacao de arquivo\n");
                exit(1);
            }
            Contador[index] = 0;
        }
        if(strstr(linha, "quantidade") != NULL){
            Contador[index]++;
        }
    }
    Contador = (int *)realloc(Contador, (index + 2) * sizeof(int));
    Contador[index + 1] = -1;
    fclose(Arquivo);
    return Contador;
}

Lista_Sessao *Ler_Arquivo(Lista_Sessao *lista_sessao_var){

    int *vetor_sessoes = Contador_Sessoes_e_Produtos();
    FILE *Arquivo = fopen("Arquivo.txt", "rt");
    lista_sessao_var = Ler_Sessoes(lista_sessao_var, Arquivo, vetor_sessoes);
    fclose(Arquivo);
}