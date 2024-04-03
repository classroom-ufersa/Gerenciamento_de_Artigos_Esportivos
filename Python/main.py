from sessao import adicionar_sessao, remover_sessao_por_nome, Sessao
from produto import adicionar_produto, remover_produto, editar_produto

def exibir_menu():
    print("\n\t***=== Menu ===***\n")
    print("1. Adicionar produto")
    print("2. Remover produto")
    print("3. Adicionar sessão")
    print("4. Remover sessão")
    print("5. Editar informações do produto")
    print("6. Buscar produto por nome")
    print("7. Listar produtos por nome")
    print("8. Sair")
    opcao = input("Escolha uma opção (1-8): ")
    return opcao

lista_sessao = []

while True:
    opcao_escolhida = exibir_menu()

    if opcao_escolhida == '1':
        
        sessao_encontrada = False
        nome_sessao = input("digite o nome da sessao que o produto vai ficar: ")
        for sessao in lista_sessao:
            if nome_sessao == sessao.nome:
                nome = input("Digite o nome do produto: ")
                categoria = input("Digite a categoria do produto: ")
                preco = float(input("Digite o preço do produto: "))
                quantidade = int(input("Digite a quantidade do produto: "))
                adicionar_produto(sessao.lista_produto, nome, categoria, preco, quantidade)
                print("Produto adicionado com sucesso.")
                sessao_encontrada = True
        if not sessao_encontrada:
            print("sessao nao encontrada")
            
            
    elif opcao_escolhida == '2':
        nome_produto = input("Digite o nome do produto que deseja remover: ")
        try:
            remover_produto(lista_sessao, nome_produto)
            print("Produto removido com sucesso.")
        except ValueError as e:
            print(e)
            
    elif opcao_escolhida == '3':
        nome = input("Digite o nome da sessão: ")      
        descricao = input("Digite a descrição da sessão: ")   
        adicionar_sessao(lista_sessao, nome, descricao)
        print("Sessão adicionada com sucesso.")
        
    elif opcao_escolhida == '4':
        nome_sessao = input("Digite o nome da sessão que deseja remover: ")
        try:
            remover_sessao_por_nome(lista_sessao, nome_sessao)
            print("Sessão removida com sucesso.")
        except ValueError as e:
            print(e)
            
    elif opcao_escolhida == '5':
        nome_produto = input("Digite o nome do produto que deseja editar: ")
        try:
            editar_produto(lista_sessao, nome_produto)
            print("Produto editado com sucesso.")
        except ValueError as e:
            print(e)
            
    elif opcao_escolhida == '6':
        
        print("Opção 6 selecionada.")
        nome_produto_escolhido = input("digite o nome do produto: ")
        for sessao in lista_sessao:
            for produto in sessao.lista_produto:
                if produto.nome == nome_produto_escolhido:
                    print("Sessoa:")
                    print("Nome: ", sessao.nome)
                    print("descricao: ", sessao.descricao, "\n")
                    print("Produto:")
                    print("Nome: ", produto.nome)
                    print("Categoria: ", produto.categoria)
                    print("Preco: ", produto.preco)
                    print("Quantidade: ", produto.quantidade)
                    
                
        
    elif opcao_escolhida == '7':
        
        print("Opção 7 selecionada.")
        for sessao in lista_sessao:
            print("Sessoa:")
            print("Nome: ", sessao.nome)
            print("descricao: ", sessao.descricao, "\n")
            for produto in sessao.lista_produto:
                print("Produto:")
                print("Nome: ", produto.nome)
                print("Categoria: ", produto.categoria)
                print("Preco: ", produto.preco)
                print("Quantidade: ", produto.quantidade)
            print("\n") 
        
        
    elif opcao_escolhida == '8':
        print("Opção 8 selecionada. Saindo...")
        break
        
    else:
        print("Opção incorreta")
