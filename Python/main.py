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

opcao_escolhida = exibir_menu()


    