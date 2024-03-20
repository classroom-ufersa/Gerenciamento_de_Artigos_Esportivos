#include "sessao.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

    Lista_Sessao *contador;
    while(contador != NULL){

        if(strcmp(Novo_No->sessao_lista.nome, contador->sessao_lista.nome)){

            break;
        }
        contador = contador->proxima_sessao;
    }

    Novo_No->sessao_lista.produto_var = NULL;
    Novo_No->proxima_sessao = contador;
    return Novo_No;
}

Lista_Sessao *Remover_Sessao(Lista_Sessao *lista_sessao_var, char nome[100]){

    Lista_Sessao *Atual = lista_sessao_var;
    Lista_Sessao *Anterior = NULL;
    
    while (Atual->sessao_lista.nome != nome && Atual != NULL) {

        Anterior = Atual;
        Atual = Atual->proxima_sessao;
    }
    if (Anterior == NULL){

        free(Atual);
        return lista_sessao_var;
    } else{
        Anterior->proxima_sessao = Atual->proxima_sessao;
        free(Atual);
        return lista_sessao_var;
    }

    printf("objeto não encontrado\n");
    return lista_sessao_var;
}

short Lista_Vazia(Lista_Sessao *lista_sessao_var){

    if (lista_sessao_var == NULL){

        return 1;
    } 
    return 0;
}

Lista_Sessao *Percorrer_Sessoes(Lista_Sessao *lista_sessao_var){

    if(Lista_Vazia(lista_sessao_var) == 1){
        
        printf("Erro: Nao existe Sessoes!!!\n\n");
    }

    Lista_Sessao *key = lista_sessao_var;
    key = key->proxima_sessao;
    return key;
}

void Imprimir_Sessao(Lista_Sessao *lista_sessao_var){

    printf("Sessao: %s", lista_sessao_var->sessao_lista.nome);
    printf("Descricao: %s", lista_sessao_var->sessao_lista.descrisao);
}
