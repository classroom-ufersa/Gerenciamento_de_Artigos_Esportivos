#include <stdio.h>
#include "produto.h"
#include "funcoes.h"
#include "sessao.h"

int main() {
    Lista_Produtos *listaProdutos = criarListaProdutos();
    if (listaProdutos == NULL) {
        printf("Erro: Falha ao criar lista de produtos.\n");
        return 1;
    }

    char opcao;
    Lista_Sessao *listaSessao = Cria_Lista();

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case '1': {
                Produto novoProduto;
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]", novoProduto.nome);
                printf("Digite a categoria do produto: ");
                scanf(" %[^\n]", novoProduto.categoria);
                printf("Digite o preço do produto: ");
                scanf(" %f", &novoProduto.preco);
                printf("Digite a quantidade do produto: ");
                scanf(" %d", &novoProduto.quantidade);
                adicionarProduto(listaProdutos, novoProduto);
                printf("Produto adicionado com sucesso!\n");
                break;
            }
            case '2': {
                char nome[100];
                printf("Digite o nome do produto a ser removido: ");
                scanf(" %[^\n]", nome);
                removerProduto(listaProdutos, nome);
                break;
            }
            case '3': {
                printf("\nOpção selecionada: Adicionar sessao\n");
                listaSessao = Adicionar_Sessao(listaSessao);
                break;
            }
            case '4': {
                printf("\nOpção selecionada: Remover sessao\n");
                // Implemente a remoção de sessão aqui
                break;
            }
            case '5': {
                char nome[100];
                printf("Digite o nome do produto a ser editado: ");
                scanf(" %[^\n]", nome);
                editarProduto(listaProdutos, nome);
                break;
            }
            case '6': {
                char nome[100];
                printf("Digite o nome do produto a ser buscado: ");
                scanf(" %[^\n]", nome);
                buscarPorNome(listaProdutos, nome);
                break;
            }
            case '7': {
                // Implemente a listagem de produtos por nome aqui
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

    liberarListaProdutos(listaProdutos);
    liberarListaSessao(listaSessao);

    return 0;
}
