#include "funcoes.h"

int main() {

    char opcao;
    char nome_escolhido[100];
    Lista_Sessao *lista_Sessao = Cria_Lista_Sessao();
    lista_Sessao = Ler_Arquivo(lista_Sessao);

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case '1': {

                if (Lista_Vazia(lista_Sessao)){
                    printf("nenhuma sessao cadastrada\n");
                } else{

                    printf("Digite em qual sessao o produto vai estar\n");
                    scanf(" %[^\n]", nome_escolhido);

                    Lista_Sessao *sessao_escolhida = Busca_Sessao(lista_Sessao, nome_escolhido);

                    if (sessao_escolhida != NULL){

                        Lista_Produtos *lista_produto_Escolhida = Pegar_Lista_Produtos(sessao_escolhida);
                        lista_produto_Escolhida = adicionarProduto(lista_produto_Escolhida);
                        sessao_escolhida = Adicionar_Produto_Sessao(lista_produto_Escolhida, sessao_escolhida);
                        printf("Produto adicionado com sucesso!\n");
                    } else {
                        printf("sessao nao existe\n");
                    }
                }
                break;
            }
            case '2': {
                printf("Digite o nome do produto a ser removido: ");
                scanf(" %[^\n]", nome_escolhido);

                Lista_Sessao *Auxiliar = lista_Sessao;
                while (Auxiliar != NULL){

                    Lista_Produtos *Auxiliar_produtos = Pegar_Lista_Produtos(Auxiliar);
                    Auxiliar_produtos = removerProduto(Auxiliar_produtos, nome_escolhido);
                    Auxiliar = Percorrer_Sessoes(Auxiliar);
                }
                break;
            }
            case '3': {
                printf("\nOpcao selecionada: Adicionar sessao\n");
                lista_Sessao = Adicionar_Sessao(lista_Sessao);
                Imprimir_Sessao(lista_Sessao);
                break;
            }
            case '4': {
                printf("\nOpcao selecionada: Remover sessao\n");

                if(lista_Sessao == NULL){
                    printf("nenhuma lista cadastrada\n");
                    break;
                }

                printf("Digite o nome da sessao a ser removida: ");
                scanf(" %[^\n]", nome_escolhido);
                lista_Sessao = Remover_Sessao(lista_Sessao, nome_escolhido);
                break;
            }
            case '5': {
                printf("Digite o nome do produto a ser editado: ");
                scanf(" %[^\n]", nome_escolhido);

                Lista_Sessao *Auxiliar = lista_Sessao;
                while (Auxiliar != NULL){

                    Lista_Produtos *Auxiliar_produtos = Pegar_Lista_Produtos(Auxiliar);
                    editarProduto(Auxiliar_produtos, nome_escolhido);
                    Auxiliar = Percorrer_Sessoes(Auxiliar);
                }
                break;
            }
            case '6': {
                printf("Digite o nome do produto a ser buscado: ");
                scanf(" %[^\n]", nome_escolhido);
                
                Lista_Sessao *Auxiliar = lista_Sessao;
                while (Auxiliar != NULL){

                    Lista_Produtos *Auxiliar_produtos = Pegar_Lista_Produtos(Auxiliar);
                    buscarPorNome(Auxiliar_produtos, nome_escolhido);
                    Auxiliar = Percorrer_Sessoes(Auxiliar);
                }
                break;
            }
            case '7': {

                Lista_Sessao *Auxiliar = lista_Sessao;
                if(!Lista_Vazia(Auxiliar)){
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
                Escrever_Arquivo(lista_Sessao);
                break;
            }
            default: {
                printf("Opcao invalida. Tente novamente.\n");
            }
        }
    } while (opcao != '8');
    return 0;
}
