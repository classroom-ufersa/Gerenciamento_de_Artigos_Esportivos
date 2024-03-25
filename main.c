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

                char nome_sessao[100];
                printf("Digite em qual sessao o produto vai estar\n");
                scanf("%[^\n]", nome_sessao);

                Lista_Produtos *sessao_escolhida = Busca_Sessao(lista_Sessao, nome_sessao);

                if (sessao_escolhida != NULL){
                    sessao_escolhida = adicionarProduto(sessao_escolhida);
                    printf("Produto adicionado com sucesso!\n");
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
                printf("\nOpção selecionada: Adicionar sessao\n");
                lista_Sessao = Adicionar_Sessao(lista_Sessao);
                break;
            }
            case '4': {
                char nome[100];
                printf("\nOpção selecionada: Remover sessao\n");

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
                printf("Opção inválida. Tente novamente.\n");
            }
        }
    } while (opcao != '8');
    return 0;
}
