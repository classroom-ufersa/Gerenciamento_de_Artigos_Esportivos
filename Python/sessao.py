import produto

class Sessao:
    
    def __init__(self, nome, descricao, lista_produto):
        self.nome = nome
        self.descricao = descricao
        self.lista_produto = lista_produto

def adicionar_sessao(lista_sessao, nome, descricao):
    
    lista_produto = []
    novo_no = Sessao(nome, descricao, lista_produto)
    lista_sessao.append(novo_no)
    return lista_sessao

def remover_sessao_por_nome(lista_sessao, nome):

    for sessao in lista_sessao:
        if sessao.nome == nome:
            lista_sessao.remove(sessao)
            return lista_sessao
    return "Sessao não encontrada."
