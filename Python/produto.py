

class Produto:
    def __init__(dado, nome, categoria, preco, quantidade):
        
        dado.nome = nome
        dado.categoria = categoria
        dado.preco = preco
        dado.quantidade = quantidade
        
def adicionar_produto(lista_produto, nome, categoria, preco, quantidade):
    
    novo_no = Produto(nome, categoria, preco, quantidade)
    lista_produto.append(novo_no)
    return lista_produto

def remover_produto(lista_produto, nome):
    for sessao in lista_produto:
        if sessao.nome == nome:
            lista_produto.remove(sessao)
            return lista_produto
    return "Pessoa não encontrada."