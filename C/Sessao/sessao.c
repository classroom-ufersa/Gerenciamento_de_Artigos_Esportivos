#include "../Funcoes/funcoes.h"

struct sessao {
    char nome[100];
    char descricao[100];
    Lista_Produtos *produto_var;
};

struct lista_sessao {
    Lista_Sessao *proxima_sessao;
    Sessao sessao;
};

Lista_Sessao *Cria_Lista_Sessao() {
    Lista_Sessao *Primeiro_No = NULL;
    return Primeiro_No;
}

Lista_Sessao *Adicionar_Sessao(Lista_Sessao *lista_sessao_var, char *nome, char *descricao, Lista_Produtos *lista_produto_var) {
    Lista_Sessao *Novo_No = (Lista_Sessao *)malloc(sizeof(Lista_Sessao));

    strcpy(Novo_No->sessao.nome, nome);
    strcpy(Novo_No->sessao.descricao, descricao);
    Novo_No->sessao.produto_var = lista_produto_var;

    Lista_Sessao *Posicao_Ordenada = lista_sessao_var;
    Lista_Sessao *Anterior = NULL;
    while (Posicao_Ordenada != NULL){
        if (strcmp(Novo_No->sessao.nome, Posicao_Ordenada->sessao.nome) < 0){
            break;
        }
        Anterior = Posicao_Ordenada;
        Posicao_Ordenada = Posicao_Ordenada->proxima_sessao;
    }

    if(Anterior == NULL){
        
        Novo_No->proxima_sessao = lista_sessao_var;
        return Novo_No;

    } else {
        Anterior->proxima_sessao = Novo_No;
        Novo_No->proxima_sessao = Posicao_Ordenada;
        return lista_sessao_var;
    }
    
}

Lista_Sessao *Remover_Sessao(Lista_Sessao *lista_sessao_var, char nome[100]) {
    Lista_Sessao *Atual = lista_sessao_var;
    Lista_Sessao *Anterior = NULL;

    while (Atual != NULL && strcmp(Atual->sessao.nome, nome) != 0) {
        Anterior = Atual;
        Atual = Atual->proxima_sessao;
    }

    if (Atual != NULL) {
        if (Anterior == NULL) {
            lista_sessao_var = lista_sessao_var->proxima_sessao;
            free(Atual);
            Limpar_Tela();
            printf("\033[1;32mSessao removida com sucesso\033[0m\n");
            return lista_sessao_var;
        } else {
            Anterior->proxima_sessao = Atual->proxima_sessao;
            free(Atual);
            Limpar_Tela();
            printf("\033[1;32mSessao removida com sucesso.\033[0m\n");
            return lista_sessao_var;
        }
    } else {
        Limpar_Tela();
        printf("\033[1;31 sessao não encontrado.\033[0m\n");
        return lista_sessao_var;
    }
}

short Lista_Vazia(Lista_Sessao *lista_sessao_var) {
    if (lista_sessao_var == NULL) {
        return 1;
    } 
    return 0;
}

Lista_Sessao *Percorrer_Sessoes(Lista_Sessao *lista_sessao_var) {
    if (Lista_Vazia(lista_sessao_var) == 1) {
        Limpar_Tela();
        printf("\033[1;31mErro: Nao existe sessoes!!!\033[0m\n\n");
    }

    Lista_Sessao *key = lista_sessao_var;
    key = key->proxima_sessao;
    return key;
}

void Imprimir_Sessao(Lista_Sessao *lista_sessao_var) {
    printf("Sessao: %s\n", lista_sessao_var->sessao.nome);
    printf("Descricao: %s\n", lista_sessao_var->sessao.descricao); 
}

Lista_Sessao *Busca_Sessao(Lista_Sessao *lista_sessao_var, char nome[100]) {

    Lista_Sessao *atual = lista_sessao_var;
    
    if (Lista_Vazia(atual)){
        return NULL;
    } else if (strcmp(atual->sessao.nome, nome) == 0){
        return atual;
    }
    Busca_Sessao(atual->proxima_sessao, nome);
}

Lista_Produtos *Pegar_Lista_Produtos(Lista_Sessao *lista_sessao_var) {
    return lista_sessao_var->sessao.produto_var;
}

Lista_Sessao *Adicionar_Produto_Sessao(Lista_Produtos *Novo_No, Lista_Sessao *lista_sessao_var) {
    lista_sessao_var->sessao.produto_var = Novo_No;
    return lista_sessao_var;
}

void *Liberar_Lista_Sessao(Lista_Sessao *lista_sessao_var){

    Lista_Sessao *atual = lista_sessao_var;
    while (atual != NULL) {
        Lista_Sessao *proximo = atual->proxima_sessao;
        liberarListaProdutos(atual->sessao.produto_var);
        free(atual);
        atual = proximo;
    }
    free(lista_sessao_var);

}

void Escrever_Sessao(Lista_Sessao *lista_sessao_var, FILE *Arquivo){

    Lista_Sessao *Atual = lista_sessao_var;

    if (Lista_Vazia(Atual)){

        return;
    } else{

        fprintf(Arquivo, "Sessao\n");

        fprintf(Arquivo, "Nome: %s\n", Atual->sessao.nome);
        fprintf(Arquivo, "Descrição: %s\n", Atual->sessao.descricao);
        fprintf(Arquivo, "\n");

        if (Atual->sessao.produto_var == NULL){
            fprintf(Arquivo, "Nenhum produto cadastrado\n\n");
        } else{

            Escreve_Produtos(Atual->sessao.produto_var, Arquivo, 1);
        }
    }

    Escrever_Sessao(Atual->proxima_sessao, Arquivo);
}

Lista_Sessao *Ler_Sessoes(Lista_Sessao *lista_sessao_var, FILE *Arquivo, int *vetor_sessoes){
    
    int index = 0;

    while(vetor_sessoes[index] != -1){

        Lista_Sessao *Novo_No = (Lista_Sessao *)malloc(sizeof(Lista_Sessao));
        if (Arquivo == NULL)
        {
            Limpar_Tela();
            printf("\033[1;31mErro na alocacao da sessao\033[0m\n");
            exit(1);
        }
        char nome[100], descricao[100];
        fscanf(Arquivo, "Sessao\n");
        fscanf(Arquivo, "Nome: %[^\n]\n", nome);
        string_maiuscula_minuscula(nome);
        fscanf(Arquivo, "Descrição: %[^\n]\n\n", descricao);
        if(vetor_sessoes[index] == 0){

            fscanf(Arquivo, "Nenhum produto cadastrado\n\n");
        } else{
            Novo_No->sessao.produto_var = NULL;
            Novo_No->sessao.produto_var = Ler_Produtos(Novo_No->sessao.produto_var, Arquivo, vetor_sessoes[index]);
        }
        lista_sessao_var = Adicionar_Sessao(lista_sessao_var, nome, descricao, Novo_No->sessao.produto_var);
        index++;
    }
    return lista_sessao_var;
}