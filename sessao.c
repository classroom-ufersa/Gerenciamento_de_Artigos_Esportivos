#include "sessao.h"

struct sessao{
    
    char nome[100];
    char descrisao[100];
    Produto *produto_var;
};

struct lista_sessao{

    Sessao *proxima_sessao;
    Sessao sessao_lista;
};

Sessao *Adicionar_Sessao(Sessao sessao_var){

    
}
