
// Definição da estrutura Sessao
typedef struct sessao Sessao;

// Definição da estrutura Lista_Sessao
typedef struct lista_sessao Lista_Sessao;

// Função para criar uma lista de sessões
Lista_Sessao *Cria_Lista_Sessao();

// Função para adicionar uma nova sessão à lista de sessões
Lista_Sessao *Adicionar_Sessao(Lista_Sessao *lista_sessao_var);

// Função para verificar se a lista de sessões está vazia
short Lista_Vazia(Lista_Sessao *lista_sessao_var);

// Função para percorrer as sessões na lista de sessões
Lista_Sessao *Percorrer_Sessoes(Lista_Sessao *lista_sessao_var);

// Função para imprimir uma sessão
void Imprimir_Sessao(Lista_Sessao *lista_sessao_var);

// Função para remover uma sessão da lista de sessões pelo nome
Lista_Sessao *Remover_Sessao(Lista_Sessao *lista_sessao_var, char nome[100]);

// Função para buscar uma sessão na lista de sessões pelo nome
Lista_Sessao *Busca_Sessao(Lista_Sessao *lista_sessao_var, char nome[100]);

// Função para obter a lista de produtos de uma sessão
Lista_Produtos *Pegar_Lista_Produtos(Lista_Sessao *lista_sessao_var);

// Função para adicionar uma lista de produtos a uma sessão
Lista_Sessao *Adicionar_Produto_Sessao(Lista_Produtos *Novo_No, Lista_Sessao *lista_sessao_var);

void Escrever_Sessao(Lista_Sessao *lista_sessao_var, FILE *Arquivo);
