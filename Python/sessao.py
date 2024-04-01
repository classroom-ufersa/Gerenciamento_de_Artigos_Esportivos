
class Produto:
    def __init__(dado, nome, categoria, preco, quantidade):
        
        dado.nome = nome
        dado.categoria = categoria
        dado.preco = preco
        dado.quantidade = quantidade
        
def adicionar_sessao(lista_sessao, nome, categoria, preco, quantidade):
    
    novo_no = Produto(nome, categoria, preco, quantidade)
    lista_sessao.append(novo_no)
    return lista_sessao

