#include "sessao.h"
#include <stdlib.h>
#include <stdio.h>

struct sessao{
    
    char nome[100];
    char descrisao[100];
    Produto *produto_var;
};

struct lista_sessao{

    Sessao *proxima_sessao;
    Sessao sessao_lista;
};

Lista_Sessao *Cria_Lista(){

    Lista_Sessao *Primeiro_No = NULL;
    return Primeiro_No;
}

Lista_Sessao *Adicionar_Sessao(Lista_Sessao *lista_sessao_var){

    Lista_Sessao *Novo_No = (Lista_Sessao *)malloc(sizeof(Lista_Sessao));

    printf("Digite o nome da sessao\n");
    scanf("%[^\n]", Novo_No->sessao_lista.nome);
    printf("Digite a descrisao da sessao\n");
    scanf("%[^\n]", Novo_No->sessao_lista.descrisao);

    Novo_No->sessao_lista.produto_var = NULL;
    Novo_No->proxima_sessao = lista_sessao_var;
    return Novo_No;
}

short Lista_Vazia(Lista_Sessao *lista_sessao_var){

    if (lista_sessao_var == NULL){

        return 1;
    }
    return 0;
}

void Percorrer_Sessoes(){
    if(Lista_Vazia == 1){
        
        printf("Erro: Nao existe Sessoes!!!");

    }
}
