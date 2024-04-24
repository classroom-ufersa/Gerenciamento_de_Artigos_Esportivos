class Produto:
    def __init__(self, nome, categoria, preco, quantidade):
        self.nome = nome
        self.categoria = categoria
        self.preco = preco
        self.quantidade = quantidade

def adicionar_produto(lista_produto, nome, categoria, preco, quantidade):
    novo_produto = Produto(nome, categoria, preco, quantidade)
    lista_produto.append(novo_produto)
    return lista_produto

def remover_produto(lista_sessao, nome):
    for sessao in lista_sessao:
        for produto in sessao.lista_produto:
            if produto.nome == nome:
                sessao.lista_produto.remove(produto)
                return sessao.lista_produto
    raise ValueError("Produto não encontrado.")

def editar_produto(lista_produto, nome):
    for produto in lista_produto:
        if produto.nome == nome:
            opcao = input("Deseja editar o nome? Digite 'y' para sim: ")
            if opcao.lower() == 'y':
                novo_nome = input("Digite o novo nome do produto: ")
                produto.nome = novo_nome
            return lista_produto
    raise ValueError("Produto não encontrado.")
