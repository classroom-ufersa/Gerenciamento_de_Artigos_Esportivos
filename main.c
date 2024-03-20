
int main() {
    int opcao;

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case 1:
                printf("\nOpção selecionada: Adicionar produto\n");
                break;
            case 2:
                printf("\nOpção selecionada: Remover produto\n");
                break;
            case 3:
                printf("\nOpção selecionada: Adicionar sessao\n");
                break;
            case 4:
                printf("\nOpção selecionada: Remover sessao\n");
                break;
            case 5:
                printf("\nOpção selecionada: Editar informações do produto\n");
                break;
            case 6:
                printf("\nOpção selecionada: Buscar produto por nome\n");
                break;
            case 7:
                printf("\nOpção selecionada: Listar produtos por nome\n");
                break;
            case 8:
                printf("\nOpção selecionada: Sair\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 8);

    printf("\nObrigado por usar o sistema!\n");

    return 0;
}