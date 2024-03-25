#include <stdio.h>
#include "produto.h"
#include "funcoes.h"
#include "sessao.h"

int main() {

    char opcao;
    Lista_Sessao *lista_Sessao = Cria_Lista_Sessao();

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case '1': {

                if (Lista_Vazia(lista_Sessao)){
                    printf("nenhuma sessao cadastrada\n");
                } else{
                    char nome_teste[100];
                    printf("estou aqui 1\n");
                    printf("Digite em qual sessao o produto vai estar\n");
                    printf("estou aqui 2\n");
                    scanf(" %[^\n]", nome_teste);
                    printf("estou aqui 3\n");

                    Lista_Sessao *sessao_escolhida = Busca_Sessao(lista_Sessao, nome_teste);
                    Lista_Produtos *lista_produto_Escolhida = Pegar_Lista_Produtos(sessao_escolhida);

                    if (sessao_escolhida != NULL){
                        lista_produto_Escolhida = adicionarProduto(lista_produto_Escolhida);
                        printf("Produto adicionado com sucesso!\n");
                    } else {
                        printf("sessao nao existe\n");
                    }
                }
                break;
            }
            case '2': {
                char nome[100];
                printf("Digite o nome do produto a ser removido: ");
                scanf(" %[^\n]", nome);

                Lista_Sessao *Auxiliar = lista_Sessao;
                while (Auxiliar != NULL){

                    Lista_Produtos *Auxiliar_produtos = Pegar_Lista_Produtos(Auxiliar);
                    Auxiliar_produtos = removerProduto(Auxiliar_produtos, nome);
                    Auxiliar = Percorrer_Sessoes(Auxiliar);
                }
                break;
            }
            case '3': {
                printf("\nOpcao selecionada: Adicionar sessao\n");
                lista_Sessao = Adicionar_Sessao(lista_Sessao);
                break;
            }
            case '4': {
                char nome[100];
                printf("\nOpcao selecionada: Remover sessao\n");

                printf("Digite o nome da sessao a ser removida: ");
                scanf(" %[^\n]", nome);
                lista_Sessao = Remover_Sessao(lista_Sessao, nome);
                break;
            }
            case '5': {
                char nome[100];
                printf("Digite o nome do produto a ser editado: ");
                scanf(" %[^\n]", nome);

                Lista_Sessao *Auxiliar = lista_Sessao;
                while (Auxiliar != NULL){

                    Lista_Produtos *Auxiliar_produtos = Pegar_Lista_Produtos(Auxiliar);
                    editarProduto(Auxiliar_produtos, nome);
                    Auxiliar = Percorrer_Sessoes(Auxiliar);
                }
                break;
            }
            case '6': {
                char nome[100];
                printf("Digite o nome do produto a ser buscado: ");
                scanf(" %[^\n]", nome);
                
                Lista_Sessao *Auxiliar = lista_Sessao;
                while (Auxiliar != NULL){

                    Lista_Produtos *Auxiliar_produtos = Pegar_Lista_Produtos(Auxiliar);
                    buscarPorNome(Auxiliar_produtos, nome);
                    Auxiliar = Percorrer_Sessoes(Auxiliar);
                }
                break;
            }
            case '7': {

                Lista_Sessao *Auxiliar = lista_Sessao;
                if(Lista_Vazia(Auxiliar)){
                while (Auxiliar != NULL)
                    {
                        Imprimir_Sessao(Auxiliar);
                        Lista_Produtos *Auxiliar_produto = Pegar_Lista_Produtos(Auxiliar);
                        imprimirProdutos(Auxiliar_produto);
                        Auxiliar = Percorrer_Sessoes(Auxiliar);
                    }
                } else {
                    printf("Nao existe nenhuma lista");
                }
                break;
            }
            case '8': {
                printf("Saindo...\n");
                break;
            }
            default: {
                printf("Opcao invalida. Tente novamente.\n");
            }
        }
    } while (opcao != '8');
    return 0;
}
