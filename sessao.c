#include "sessao.h"

struct sessao{
    
    char nome[100];
    char descrisao[100];
    Lista_Produtos *produto_var;
};

struct lista_sessao{

    Lista_Sessao *proxima_sessao;
    Sessao sessao_lista;
};

Lista_Sessao *Cria_Lista_Sessao(){

    Lista_Sessao *Primeiro_No = NULL;
    return Primeiro_No;
}

Lista_Sessao *Adicionar_Sessao(Lista_Sessao *lista_sessao_var){

    Lista_Sessao *Novo_No = (Lista_Sessao *)malloc(sizeof(Lista_Sessao));

    printf("Digite o nome da sessao\n");
    scanf(" %[^\n]", Novo_No->sessao_lista.nome);
    printf("Digite a descrisao da sessao\n");
    scanf(" %[^\n]", Novo_No->sessao_lista.descrisao);

    Novo_No->sessao_lista.produto_var = NULL;
    Novo_No->proxima_sessao = lista_sessao_var;
    return Novo_No;
}

Lista_Sessao *Remover_Sessao(Lista_Sessao *lista_sessao_var, char nome[100]){

    Lista_Sessao *Atual = lista_sessao_var;
    Lista_Sessao *Anterior = NULL;

    while (Atual != NULL && strcmp(lista_sessao_var->sessao_lista.nome, nome) != 0) {

        Anterior = Atual;
        Atual = Atual->proxima_sessao;
    }

    if (Atual != NULL){

        if (Anterior == NULL){

            free(Atual);
            printf("sessao removida com sucesso, lista agora vazia\n");
            return lista_sessao_var;
        } else{
            Anterior->proxima_sessao = Atual->proxima_sessao;
            free(Atual);
            printf("sessao removida com sucesso\n");
            return lista_sessao_var;
        }
    } else{
        printf("objeto não encontrado\n");
        return lista_sessao_var;
    }
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

    printf("Sessao: %s\n", lista_sessao_var->sessao_lista.nome);
    printf("Descricao: %s\n", lista_sessao_var->sessao_lista.descrisao);
}

Lista_Sessao *Busca_Sessao(Lista_Sessao *lista_sessao_var, char nome[100]){

    if (Lista_Vazia(lista_sessao_var)){
        printf("nenhuma sessao cadastrada\n");
        return NULL;
    }

    Lista_Sessao *atual = lista_sessao_var;
    while (strcmp(atual->sessao_lista.nome, nome) != 0 && atual != NULL){

        atual = atual->proxima_sessao;
    }
    
    return atual;
}

Lista_Produtos *Pegar_Lista_Produtos(Lista_Sessao *lista_sessao_var){

    return lista_sessao_var->sessao_lista.produto_var;
}

Lista_Sessao *Adicionar_Produto_Sessao(Lista_Produtos *Novo_No, Lista_Sessao  *lista_sessao_var){

    lista_sessao_var->sessao_lista.produto_var = Novo_No;
    return lista_sessao_var;
}