import sessao
import produto

def exibir_menu():
    print("\n\t=== Menu ===\n")
    print("\t1. Adicionar produto")
    print("\t2. Remover produto")
    print("\t3. Adicionar sessão")
    print("\t4. Remover sessão")
    print("\t5. Editar informações do produto")
    print("\t6. Buscar produto por nome")
    print("\t7. Listar produtos por nome")
    print("\t8. Sair")
    opcao = input("\tEscolha uma opção (1-8): ")
    return opcao

permanecer = True
while(permanecer):
    opcao_escolhida = exibir_menu()

    if opcao_escolhida == '1':
    
        print("Opção 1 selecionada.")
    elif opcao_escolhida == '2':
    
        print("Opção 2 selecionada.")
    elif opcao_escolhida == '3':

        print("Opção 3 selecionada.")
    elif opcao_escolhida == '4':

        print("Opção 4 selecionada.")
    elif opcao_escolhida == '5':

        print("Opção 5 selecionada.")
    elif opcao_escolhida == '6':

        print("Opção 6 selecionada.")
    elif opcao_escolhida == '7':

        print("Opção 7 selecionada.")
    elif opcao_escolhida == '8':

        print("Opção 8 selecionada.")
        permanecer = False
    else:
        print("Opção incorreta")
        