#include "../Funcoes/funcoes.h"

int main() {

    Configura_Terminal();
    char opcao;
    char nome_escolhido[100];
    Lista_Sessao *lista_Sessao = Cria_Lista_Sessao();
    lista_Sessao = Ler_Arquivo(lista_Sessao);

    do {

        Emite_Bip();
        opcao = exibirMenu();
        Limpar_Tela();
        
        switch (opcao) {
            case '1': {
                Emite_Bip();
                if (Lista_Vazia(lista_Sessao)){
                    Limpar_Tela();
                    printf("\033[1;31mnenhuma sessao cadastrada\033[0m\n");
                } else{ 

                    printf("Digite em qual sessao o produto vai estar\n");
                    scanf(" %[^\n]", nome_escolhido);
                    string_maiuscula_minuscula(nome_escolhido);

                    Lista_Sessao *sessao_escolhida = Busca_Sessao(lista_Sessao, nome_escolhido);

                    if (sessao_escolhida != NULL){

                        Lista_Produtos *lista_produto_Escolhida = Pegar_Lista_Produtos(sessao_escolhida);
                        char nome[100], categoria[100], preco_str[40], quantidade_str[40];
                        float preco;
                        int quantidade;
                        printf("Digite o nome do produto: ");
                        scanf(" %[^\n]", nome);
                        string_maiuscula_minuscula(nome);

                        Lista_Sessao *Auxiliar_Adicionar = lista_Sessao;
                        short produto_com_mesmo_nome = 0;
                        while(Auxiliar_Adicionar != NULL){

                            if (buscarPorNome(Pegar_Lista_Produtos(Auxiliar_Adicionar), nome) != NULL){
                                produto_com_mesmo_nome = 1;
                            }
                            Auxiliar_Adicionar = Percorrer_Sessoes(Auxiliar_Adicionar);
                        }
                        if(produto_com_mesmo_nome){
                            Limpar_Tela();
                            printf("\033[1;31mProduto já existente\033[0m");
                            break;
                        }

                        printf("Digite a categoria do produto: ");
                        scanf(" %[^\n]", categoria);
                        printf("Digite o preço do produto: ");
                        scanf(" %[^\n]", preco_str);
                        printf("Digite a quantidade do produto: ");
                        scanf(" %[^\n]", quantidade_str);

                        preco = extrairFloat(preco_str);
                        quantidade = extrairInt(quantidade_str);
                        lista_produto_Escolhida = adicionarProduto(lista_produto_Escolhida, nome, categoria, preco, quantidade);
                        sessao_escolhida = Adicionar_Produto_Sessao(lista_produto_Escolhida, sessao_escolhida);
                        Limpar_Tela();
                        printf("\033[1;32mProduto adicionado com sucesso!\033[0m\n");
                    } else {
                        Limpar_Tela();
                        printf("\033[1;31msessao nao existe\033[0m\n");
                    }
                }
                break;
            }
            case '2': {
                Emite_Bip();
                short produto_encontrado = 0;
                printf("Digite o nome do produto a ser removido: ");
                scanf(" %[^\n]", nome_escolhido);
                string_maiuscula_minuscula(nome_escolhido);

                Lista_Sessao *Auxiliar = lista_Sessao;
                while (Auxiliar != NULL){

                    Lista_Produtos *Auxiliar_produtos = Pegar_Lista_Produtos(Auxiliar);
                    if (buscarPorNome(Auxiliar_produtos, nome_escolhido) != NULL){
                        produto_encontrado = 1;
                        break;
                    }
                    Auxiliar = Percorrer_Sessoes(Auxiliar);
                }
                if(produto_encontrado == 0){
                    Limpar_Tela();
                    printf("\033[1;31mProduto \"%s\" não encontrado na lista.\033[0m\n", nome_escolhido);
                    break;
                }


                Auxiliar = lista_Sessao;
                while (Auxiliar != NULL){

                    Lista_Produtos *Auxiliar_produtos = Pegar_Lista_Produtos(Auxiliar);
                    Lista_Produtos *Nova_Lista_Produtos = removerProduto(Auxiliar_produtos, nome_escolhido);
                    
                    
                    Auxiliar = Adicionar_Produto_Sessao(Nova_Lista_Produtos, Auxiliar);
                                                      
                    
                    Auxiliar = Percorrer_Sessoes(Auxiliar);
                }
                break;
            }

            case '3': {
                Emite_Bip();
                printf("\nOpcao selecionada: Adicionar sessao\n");

                char nome[100], descricao[100];
                printf("Digite o nome da sessao:\n");
                scanf(" %[^\n]", nome);
                string_maiuscula_minuscula(nome);

                string_maiuscula_minuscula(nome);
                if(Busca_Sessao(lista_Sessao, nome) != NULL){
                    printf("\033[1;31mSessão já existente.\033[0m\n");
                    break;
                }
                printf("Digite a descricao da sessao:\n");
                scanf(" %[^\n]", descricao);

                lista_Sessao = Adicionar_Sessao(lista_Sessao, nome, descricao, NULL);
                break;
            }
            case '4': {
                Emite_Bip();
                printf("\nOpcao selecionada: Remover sessao\n");

                if(lista_Sessao == NULL){
                    Limpar_Tela();
                    printf("\033[1;31nenhuma lista cadastrada\033[0m\n");
                    break;
                }

                printf("Digite o nome da sessao a ser removida: ");
                scanf(" %[^\n]", nome_escolhido);
                string_maiuscula_minuscula(nome_escolhido);
                lista_Sessao = Remover_Sessao(lista_Sessao, nome_escolhido);
                break;
            }
            case '5': {
                Emite_Bip();
                short produto_encontrado = 0;
                printf("Digite o nome do produto a ser editado: ");
                scanf(" %[^\n]", nome_escolhido);
                string_maiuscula_minuscula(nome_escolhido);

                Lista_Sessao *Auxiliar = lista_Sessao;
                while (Auxiliar != NULL){

                    Lista_Produtos *Auxiliar_produtos = Pegar_Lista_Produtos(Auxiliar);
                    if (buscarPorNome(Auxiliar_produtos, nome_escolhido) != NULL){
                        produto_encontrado = 1;
                        break;
                    }
                    Auxiliar = Percorrer_Sessoes(Auxiliar);
                }
                if(produto_encontrado == 0){
                    Limpar_Tela();
                    printf("\033[1;31mProduto \"%s\" não encontrado na lista.\033[0m\n", nome_escolhido);
                    break;
                }

                Auxiliar = lista_Sessao;
                while (Auxiliar != NULL){

                    Lista_Produtos *Auxiliar_produtos = Pegar_Lista_Produtos(Auxiliar);
                    Auxiliar_produtos = editarProduto(Auxiliar_produtos, nome_escolhido);
                    Adicionar_Produto_Sessao(Auxiliar_produtos, Auxiliar);
                    Auxiliar = Percorrer_Sessoes(Auxiliar);
                }

                break;
            }

            case '6': {
                Emite_Bip();
                printf("Digite o nome do produto a ser buscado: ");
                scanf(" %[^\n]", nome_escolhido);
                string_maiuscula_minuscula(nome_escolhido);
                short produto_encontrado = 0;
                Lista_Sessao *Auxiliar = lista_Sessao;
                while (Auxiliar != NULL){

                    Lista_Produtos *Auxiliar_produtos = Pegar_Lista_Produtos(Auxiliar);
                    Lista_Produtos *Produto = buscarPorNome(Auxiliar_produtos, nome_escolhido);
                    if (Produto != NULL){
                        Imprimir_Produto(Produto);
                        produto_encontrado = 1;
                        break;
                    }
                    Auxiliar = Percorrer_Sessoes(Auxiliar);
                }
                if (!(produto_encontrado)){
                    Limpar_Tela();
                    printf("\033[1;31mNenhum produto com o nome: \"%s\" encontrado\033[0m", nome_escolhido);
                }
                break;
            }
            case '7': {
                Emite_Bip();
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
                    Limpar_Tela();
                    printf("\033[1;31mNao existe nenhuma lista\033[0m\n");
                }
                break;
            }
            case '8': {
                Emite_Bip();
                printf("Saindo...\n");
                Escrever_Arquivo(lista_Sessao);
                Liberar_Lista_Sessao(lista_Sessao);
                break;
            }
            default: {
                Limpar_Tela();
                printf("\033[1;31mOpcao invalida. Tente novamente.\033[0m\n");
            }
        }
    } while (opcao != '8');
    return 0;
}
