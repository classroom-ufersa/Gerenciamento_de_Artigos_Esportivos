#include "funcoes.h"

// Definição da estrutura Sessao
struct sessao {
    char nome[100];
    char descricao[100];
    Lista_Produtos *produto_var;
};

// Definição da estrutura Lista_Sessao
struct lista_sessao {
    Lista_Sessao *proxima_sessao;
    Sessao sessao_lista;
};

// Função para criar uma lista de sessões
Lista_Sessao *Cria_Lista_Sessao() {
    Lista_Sessao *Primeiro_No = NULL;
    return Primeiro_No;
}

// Função para adicionar uma nova sessão à lista de sessões
Lista_Sessao *Adicionar_Sessao(Lista_Sessao *lista_sessao_var) {
    Lista_Sessao *Novo_No = (Lista_Sessao *)malloc(sizeof(Lista_Sessao));

    printf("Digite o nome da sessao:\n");
    scanf(" %[^\n]", Novo_No->sessao_lista.nome);
    printf("Digite a descricao da sessao:\n");
    scanf(" %[^\n]", Novo_No->sessao_lista.descricao);

    Novo_No->sessao_lista.produto_var = NULL;
    Novo_No->proxima_sessao = lista_sessao_var;
    return Novo_No;
}

// Função para remover uma sessão da lista de sessões pelo nome
Lista_Sessao *Remover_Sessao(Lista_Sessao *lista_sessao_var, char nome[100]) {
    Lista_Sessao *Atual = lista_sessao_var;
    Lista_Sessao *Anterior = NULL;

    while (Atual != NULL && strcmp(Atual->sessao_lista.nome, nome) != 0) {
        Anterior = Atual;
        Atual = Atual->proxima_sessao;
    }

    if (Atual != NULL) {
        if (Anterior == NULL) {
            lista_sessao_var = lista_sessao_var->proxima_sessao;
            free(Atual);
            printf("Sessao removida com sucesso\n");
            return lista_sessao_var;
        } else {
            Anterior->proxima_sessao = Atual->proxima_sessao;
            free(Atual);
            printf("Sessao removida com sucesso.\n");
            return lista_sessao_var;
        }
    } else {
        printf("Objeto não encontrado.\n");
        return lista_sessao_var;
    }
}

// Função para verificar se a lista de sessões está vazia
short Lista_Vazia(Lista_Sessao *lista_sessao_var) {
    if (lista_sessao_var == NULL) {
        return 1;
    } 
    return 0;
}

// Função para percorrer as sessões na lista de sessões
Lista_Sessao *Percorrer_Sessoes(Lista_Sessao *lista_sessao_var) {
    if (Lista_Vazia(lista_sessao_var) == 1) {
        printf("Erro: Nao existe sessoes!!!\n\n");
    }

    Lista_Sessao *key = lista_sessao_var;
    key = key->proxima_sessao;
    return key;
}

// Função para imprimir uma sessão
void Imprimir_Sessao(Lista_Sessao *lista_sessao_var) {
    printf("Sessao: %s\n", lista_sessao_var->sessao_lista.nome);
    printf("Descricao: %s\n", lista_sessao_var->sessao_lista.descricao);
}

// Função para buscar uma sessão na lista de sessões pelo nome
Lista_Sessao *Busca_Sessao(Lista_Sessao *lista_sessao_var, char nome[100]) {

    Lista_Sessao *atual = lista_sessao_var;
    
    if (Lista_Vazia(atual)){
        return NULL;
    } else if (strcmp(atual->sessao_lista.nome, nome) == 0){
        return atual;
    }
    Busca_Sessao(atual->proxima_sessao, nome);
}

// Função para obter a lista de produtos de uma sessão
Lista_Produtos *Pegar_Lista_Produtos(Lista_Sessao *lista_sessao_var) {
    return lista_sessao_var->sessao_lista.produto_var;
}

// Função para adicionar uma lista de produtos a uma sessão
Lista_Sessao *Adicionar_Produto_Sessao(Lista_Produtos *Novo_No, Lista_Sessao *lista_sessao_var) {
    lista_sessao_var->sessao_lista.produto_var = Novo_No;
    return lista_sessao_var;
}

void Escrever_Sessao(Lista_Sessao *lista_sessao_var, FILE *Arquivo){

    Lista_Sessao *Atual = lista_sessao_var;

    if (Lista_Vazia(Atual)){

        return;
    } else{

        fprintf(Arquivo, "Sessao\n");

        fprintf(Arquivo, "Nome: %s\n", Atual->sessao_lista.nome);
        fprintf(Arquivo, "Descrição: %s\n", Atual->sessao_lista.descricao);
        fprintf(Arquivo, "\n");

        if (Atual->sessao_lista.produto_var == NULL){

            fprintf(Arquivo, "Nenhum produto cadastrado\n\n");
        } else{

            Escreve_Produtos(Atual->sessao_lista.produto_var, Arquivo, 1);
        }
    }

    Escrever_Sessao(Atual->proxima_sessao, Arquivo);
}

Lista_Sessao *Ler_Sessoes(Lista_Sessao *lista_sessao_var, FILE *Arquivo, int *vetor_sessoes){
    
    int index = 0;

    while(vetor_sessoes[index] != NULL){

        Lista_Sessao *Novo_No = (Lista_Sessao *)malloc(sizeof(Lista_Sessao));

        fscanf(Arquivo, "Sessao\n");
        fscanf(Arquivo, "Nome: %[^\n]\n", Novo_No->sessao_lista.nome);
        fscanf(Arquivo, "Descrição: %[^\n]\n\n", Novo_No->sessao_lista.descricao);

        if(vetor_sessoes[index] == 0){

            fprintf(Arquivo, "Nenhum produto cadastrado\n\n");
            Novo_No->sessao_lista.produto_var = NULL;
        } else{

            lista_sessao_var->sessao_lista.produto_var = Ler_Produtos(Pegar_Lista_Produtos(lista_sessao_var), Arquivo, vetor_sessoes[index]);
        }
        Novo_No->proxima_sessao = lista_sessao_var;
        lista_sessao_var = Novo_No;
        index++;
    }
    return lista_sessao_var;
}