from sessao import adicionar_sessao, remover_sessao_por_nome
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

def ler_Arquivo(lista_sessao):
    Arquivo = open("Arquivo.txt", 'r', encoding='utf-8')

    for linha in Arquivo:
            linha = linha.strip()

            if linha.startswith('Sessao'):
                nome = Arquivo.readline().strip().split('Nome: ')[1]
                descricao = Arquivo.readline().strip().split('Descricao: ')[1]
                adicionar_sessao(lista_sessao, nome, descricao)

            elif linha.startswith('Produto'):
                nome = Arquivo.readline().strip().split('Nome: ')[1]
                categoria = Arquivo.readline().strip().split('Categoria: ')[1]
                preco = Arquivo.readline().strip().split('Preco: ')[1]
                quantidade = Arquivo.readline().strip().split('Quantidade: ')[1]
                sessao_atual = lista_sessao[-1]
                adicionar_produto(sessao_atual.lista_produto, nome, categoria, preco, quantidade)

def escrever_Arquivo(lista_sessao):
    with open("Arquivo.txt", 'w', encoding='utf-8') as Arquivo:
        for sessao in lista_sessao:
            Arquivo.write("Sessao:\n")
            Arquivo.write("Nome: " + sessao.nome + "\n")
            Arquivo.write("Descricao: " + sessao.descricao + "\n\n")
            
            if len(sessao.lista_produto) == 0:
                Arquivo.write("Nao existe nenhum produto\n\n")
            else:
                for produto in sessao.lista_produto:
                    Arquivo.write("Produto:\n")
                    Arquivo.write("Nome: " + produto.nome + "\n")
                    Arquivo.write("Categoria: " + produto.categoria + "\n")
                    Arquivo.write("Preco: " + produto.preco + "\n")
                    Arquivo.write("Quantidade: " + produto.quantidade + "\n\n")

def Tratativa_para_int(string):
    nova_string = ''  
    for caractere in string:
        if caractere.isdigit():
            nova_string += caractere
    return nova_string    

def Tratativa_para_float(string):
    nova_string = ''  
    for caractere in string:
        if caractere.isdigit() or (caractere == '.' or caractere ==','):
            nova_string += caractere
    return nova_string   
    

lista_sessao = []

ler_Arquivo(lista_sessao)

while True:
    opcao_escolhida = exibir_menu()

    if opcao_escolhida == '1':
        
        
            sessao_encontrada = False
            nome_sessao = input("digite o nome da sessao que o produto vai ficar: ")
            for sessao in lista_sessao:
                if nome_sessao == sessao.nome:
                    nome = input("Digite o nome do produto: ")
                    
                    produto_com_mesmo_nome = False
                    for sessao in lista_sessao:
                        for produto in sessao.lista_produto:
                            if produto.nome == nome:
                                produto_com_mesmo_nome = True
                    
                    if not produto_com_mesmo_nome:
                        categoria = input("Digite a categoria do produto: ")
                        preco = input("Digite o preço do produto: ")
                        preco = Tratativa_para_float(preco)
                        quantidade = input("Digite a quantidade do produto: ")
                        quantidade = Tratativa_para_int(quantidade)
                        adicionar_produto(sessao.lista_produto, nome, categoria, preco, quantidade)
                        print("Produto adicionado com sucesso.")
                    else: 
                        print("produto já existente")
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
        
        sessao_com_mesmo_nome = False
        for sessao in lista_sessao:
            if nome == sessao.nome:
                sessao_com_mesmo_nome = True
        if not sessao_com_mesmo_nome:
            descricao = input("Digite a descrição da sessão: ")   
            adicionar_sessao(lista_sessao, nome, descricao)
            print("Sessão adicionada com sucesso.")
        else:
            print("sessao ja existente")
        
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
        lista_sessao.sort(key=lambda sessao: sessao.nome)
        for sessao in lista_sessao:
            sessao.lista_produto.sort(key = lambda produto: produto.nome)
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
        lista_sessao.sort(key=lambda sessao: sessao.nome)
        for sessao in lista_sessao:
            sessao.lista_produto.sort(key = lambda produto: produto.nome)
        escrever_Arquivo(lista_sessao)
        break
        
    else:
        print("Opção incorreta")
        
