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

    
}
