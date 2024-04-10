#include "funcoes.h"

char exibirMenu() {

    char escolha[10];
    printf("\n\t\033[34m***=== Menu ===***\n");
    printf("\t   \033[1;33m1.\033[0m Adicionar produto\n");
    printf("\t   \033[1;33m2.\033[0m Remover produto\n");
    printf("\t   \033[1;33m3.\033[0m Adicionar sessão\n");
    printf("\t   \033[1;33m4.\033[0m Remover sessão\n");
    printf("\t   \033[1;33m5.\033[0m Editar informações do produto\n");
    printf("\t   \033[1;33m6.\033[0m Buscar produto por nome\n");
    printf("\t   \033[1;33m7.\033[0m Listar produtos por nome\n");
    printf("\t   \033[1;33m8.\033[0m Sair\n");
    printf("\tEscolha uma opção (\033[1;33m1-8\033[0m): ");
    scanf(" %s", escolha);
    if (escolha[1] == '\0'){
        return escolha[0];
    }
    return '0';
}

void Escrever_Arquivo(Lista_Sessao *lista_sessao_var){

    FILE *Arquivo = fopen("Arquivo.txt", "wt");
    Escrever_Sessao(lista_sessao_var, Arquivo);
    if (Arquivo == NULL)
    {
        printf("\033[1;31mErro na abertura para escrever de arquivo\033[0m\n");
        exit(1);
    }
    fclose(Arquivo);
}

int *Contador_Sessoes_e_Produtos(){
    
    FILE *Arquivo = fopen("Arquivo.txt", "rt");
    if (Arquivo == NULL)
    {
        printf("\033[1;31mErro na abertura de arquivo\033[0m\n");
        exit(1);
    }

    int *Contador = (int *)malloc(sizeof(int));
    if (Contador == NULL)
    {
        printf("\033[1;31mErro na realcacao de arquivo\033[0m\n");
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
                printf("\033[1;31mErro na realcacao de arquivo\033[0m\n");
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
    return lista_sessao_var;
}

void string_maiuscula_minuscula(char *Nome){ 
  int Contador; 
  Nome[0] = toupper(Nome[0]);  
  for (Contador = 1; Nome[Contador] != '\0'; Contador++)  { 
    if (isspace(Nome[Contador - 1]))  { 
      Nome[Contador] = toupper(Nome[Contador]);
    } else  { 
      Nome[Contador] = tolower(Nome[Contador]); 
    }
  }
}

float extrairFloat(char *str) {
    char numero_str[50];
    int j = 0;
    int i;
    int pontoEncontrado = 0;

    for(i = 0; i < strlen(str); i++) {
        if(isdigit(str[i])) {
            numero_str[j++] = str[i];
            if(pontoEncontrado){
				pontoEncontrado++;
			} 
        } else if((str[i] == '.' || str[i] == ',') && !pontoEncontrado) {
            numero_str[j++] = ',';
            pontoEncontrado = 1; 
        } else if(pontoEncontrado && isdigit(str[i]) && pontoEncontrado < 3) {
            numero_str[j++] = str[i];
            pontoEncontrado++;
        }
        if (pontoEncontrado > 3){
			break;
		}
    }
    return atof(numero_str);
}

int extrairInt(char *str){

    char numero_str[50];
    int j = 0;
    int i;
    for(i = 0; i < strlen(str); i++) {
        if(isdigit(str[i])) {
            numero_str[j++] = str[i];
		}
    }
    return atoi(numero_str);
}

void Limpar_Tela(){

    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");   
    #endif
}

void Configura_Terminal() {
    #ifdef _WIN32
        system("chcp 65001 > NUL");
    #else
        setlocale(LC_ALL, "");
    #endif
}

void Emite_Bip() {

    #ifdef _WIN32
       Beep(3000, 230);
    #else
        printf("\a");
    #endif
}
