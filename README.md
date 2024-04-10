# Gerenciamento_de_Artigos_Esportivos
Projeto de  um sistema em Linguagem C para gerenciamento de Artigos Esportivos, que realiza a manipulação de Sessões e Produtos.  

- [Introdução](#Introdução)
- [Problemáticas](#Problemáticas)
- [Requisitos](#Requisitos)
- [Organização](#Organização)
- [Execução do projeto;](#execução-do-projeto)
- [Funções](#Funções)
___

## Desenvolvedores
> :computer:[Francisco Porfirio de Oliveira Neto](https://github.com/Porfirio24)
> 
> :computer:[Daniel Neres Vireira](https://github.com/DanielNeres)

## :football: Introdução
Em um mercado cada vez mais competitivo, a eficiência operacional e a excelência no atendimento ao cliente são diferenciais cruciais para o sucesso de qualquer negócio, especialmente no contexto de uma loja de artigos esportivos. Para enfrentar esses desafios, a adoção de um sistema de gerenciamento moderno e eficaz torna-se essencial.

Este sistema não apenas simplifica tarefas operacionais, como também aprimora a gestão de estoque, vendas e relacionamento com os clientes. No entanto, para alcançar todo o potencial dessas funcionalidades, é fundamental contar com recursos avançados de programação, como ponteiros, alocação dinâmica, structs, TADs (Tipos Abstratos de Dados), manipulação de arquivos e lista encadeada.

Ao integrar esses recursos tecnológicos, o sistema não só agiliza processos internos, mas também proporciona uma experiência mais personalizada e satisfatória para os clientes, ao mesmo tempo em que oferece ferramentas robustas para a tomada de decisões estratégicas por parte da loja.

## :scroll: Problemáticas

**Imagine uma loja de Artigos Esportivos operada manualmente, onde todas as informações sobre produtos,são registradas em papel ou em sistemas ultrapassados. Essa abordagem manual cria uma série de desafios que podem ser considerados:**

1. **Ineficiência Operacional e Perda de Tempo:** Processos manuais consomem tempo e recursos preciosos. Isso pode levar a uma redução na eficiência operacional, aumentando os custos de mão de obra e diminuindo a produtividade geral da loja.

2. **Gestão de Vendas e Transações:** Registrar vendas, e acompanhar as vendas de produtos manualmente pode ser demorado e propenso a erros. Isso pode resultar em diferença nos registros financeiros, dificultando a compreensão da lucratividade do negócio e a tomada de decisões.

3. **Controle de Estoque e Produtos:** Sem um sistema adequado, manter o controle do estoque de produtos pode ser difícil. Isso pode levar a problemas como falta de produtos em alta demanda, excesso de estoque de itens menos populares e dificuldades em identificar produtos em falta.

4. **Controle Financeiro Limitado:** Acompanhar as finanças, despesas e lucratividade, pode ser complicado e sujeito a erros quando a contabilidade é realizada manualmente.

5. **Falta de Insights e Análises:** Sem um sistema para coletar e analisar dados sobre as vendas, tendências de mercado e comportamento do cliente, a empresa pode perder oportunidades de otimização de vendas e crescimento do negócio.

Nesse cenário, a implementação de um sistema de gerenciamento de loja de artigos esportivos pode resolver esses problemas, automatizando tarefas, melhorando a gestão de estoque e vendas, oferecendo insights valiosos para a tomada de decisões e proporcionando uma melhor experiência tanto para os clientes quanto para os funcionários..

## Requisitos do projeto
O projeto teve os seguintes requisitos:

1. Adicionar Produto
2. Remover Produto
3. Adicionar Sessão
4. Remover Sessão
5. Editar a informação do Produto
6. Buscar Produto por nome
7. Listar Sessões e Produto
8. Sair

 **Observações**
- A opção de sair é a única que permite sair do programa.
- Os dados devem ser armazenados em um arquivo de texto após cada operação e quando o programa for iniciado, carregar os dados armazenados nesse arquivo de texto.
- Ordenar por ordem alfabetica as sessões e produtos a cada remoção ou adição.

## Organização
**Linguagem** <img align="center" alt="Porfirio-Neto-C" height="30" width="40" src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg">

  ```
📁 Gerenciamento_de_Artigos_Esportivos
│
├── C
│
├── Funções
│    ├── Funções.c
│    ├── Funções.h
│
├── Main.c
│       
├── Produto
│    ├── Produto.c
│    ├── Produto.h
│   
├── Sessão
│    ├── Sessão.c
│    ├── Sessão.h
│
├── .gitignore
│
└── README.md
 ```
**Linguagem** <img align="center" alt="Porfirio-Neto-Python" height="30" width="40" src="https://github.com/devicons/devicon/blob/master/icons/python/python-original.svg">

 ```
📁 Gerenciamento_de_Artigos_Esportivos
│
├── Main.py
│    
├── Produto.py
│
├── Sessão.py
│
└── .gitignore
 ```
## Execução do Projeto :gear:
-Este é um sistema em Linguagem C para gerenciamento de Artigos Esportivos, que realiza a manipulação de Sessões e Produtos.

**Compilando**
## C
```
gcc -o arquivo executavel main.c Tads_e_Modulos/produto.c Tads_e_Modulos/sessao.c Tads_e_Modulos/funcoes.c
./arquivo executavel.exe
```
## Python
```
python main.py
```
**Observação**
verifique se você possui em compilador de C instalado assim como um compilador de Python para que possa compilar o código com sucessso.

## Funções
**Adicionar Produto** <img align="center" alt="Porfirio-Neto-C" height="30" width="40" src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg">

```c
Lista_Produtos *adicionarProduto(Lista_Produtos *lista, char *nome, char *categoria, float preco, int quantidade) {
    
    Produto novo_Produto;

    
    strcpy(novo_Produto.nome, nome);
    strcpy(novo_Produto.categoria, categoria);
    novo_Produto.preco = preco;
    novo_Produto.quantidade = quantidade;

    Lista_Produtos *ordenada = lista;
    Lista_Produtos *Anterior = NULL;
    while (ordenada != NULL){
        if (strcmp(nome, ordenada->produto.nome) < 0){
            break;
        }
        Anterior = ordenada;
        ordenada = ordenada->proximo_produto;
    }
    
    Lista_Produtos *novoNo = (Lista_Produtos *)malloc(sizeof(Lista_Produtos));

    if (novoNo != NULL) {
        
        if(Anterior == NULL){
        novoNo->produto = novo_Produto;
        novoNo->proximo_produto = lista;
        return novoNo;
        } else {
            novoNo->produto = novo_Produto;
            Anterior->proximo_produto = novoNo;
            novoNo->proximo_produto = ordenada;
            return lista;
        }
    } else {
        Limpar_Tela();
        printf("\033[1;31mErro: Não foi possível adicionar o produto. Memória insuficiente.\033[0m\n");
    }
}

```
**Remover Produto**<img align="center" alt="Porfirio-Neto-C" height="30" width="40" src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg">

```c
Lista_Produtos *removerProduto(Lista_Produtos *lista, char nome[100]) {
    
    if (listaProdutosVazia(lista)) {
        Limpar_Tela();
        printf("\033[1;31mLista de produtos vazia. Nada a remover.\033[0m\n");
        return lista;
    }

    Lista_Produtos *atual = lista;
    Lista_Produtos *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->produto.nome, nome) == 0) {
            
            if (anterior == NULL) {
                lista = atual->proximo_produto;
            } else {
                anterior->proximo_produto = atual->proximo_produto;
            }
            free(atual); 
            Limpar_Tela();
            printf("\033[1;32mProduto \"%s\" removido com sucesso.\033[0m\n", nome);
            return lista;
        }
        anterior = atual;
        atual = atual->proximo_produto;
    }
    return lista;
    Limpar_Tela();
    printf("\033[1;31mProduto \"%s\" não encontrado na lista.\033[0m\n", nome);
}
```
**Adicionar Sessão**<img align="center" alt="Porfirio-Neto-C" height="30" width="40" src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg">

```c
Lista_Sessao *Adicionar_Sessao(Lista_Sessao *lista_sessao_var, char *nome, char *descricao, Lista_Produtos *lista_produto_var) {
    Lista_Sessao *Novo_No = (Lista_Sessao *)malloc(sizeof(Lista_Sessao));

    strcpy(Novo_No->sessao.nome, nome);
    strcpy(Novo_No->sessao.descricao, descricao);
    Novo_No->sessao.produto_var = lista_produto_var;

    Lista_Sessao *Posicao_Ordenada = lista_sessao_var;
    Lista_Sessao *Anterior = NULL;
    while (Posicao_Ordenada != NULL){
        if (strcmp(Novo_No->sessao.nome, Posicao_Ordenada->sessao.nome) < 0){
            break;
        }
        Anterior = Posicao_Ordenada;
        Posicao_Ordenada = Posicao_Ordenada->proxima_sessao;
    }

    if(Anterior == NULL){
        
        Novo_No->proxima_sessao = lista_sessao_var;
        return Novo_No;

    } else {
        Anterior->proxima_sessao = Novo_No;
        Novo_No->proxima_sessao = Posicao_Ordenada;
        return lista_sessao_var;
    }
    
}
```
**Remover Sessão**<img align="center" alt="Porfirio-Neto-C" height="30" width="40" src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg">

```c
Lista_Sessao *Remover_Sessao(Lista_Sessao *lista_sessao_var, char nome[100]) {
    Lista_Sessao *Atual = lista_sessao_var;
    Lista_Sessao *Anterior = NULL;

    while (Atual != NULL && strcmp(Atual->sessao.nome, nome) != 0) {
        Anterior = Atual;
        Atual = Atual->proxima_sessao;
    }

    if (Atual != NULL) {
        if (Anterior == NULL) {
            lista_sessao_var = lista_sessao_var->proxima_sessao;
            free(Atual);
            printf("Sessao removida com sucesso\n");
            return lista_sessao_var;
        } else {
            Anterior->proxima_sessao = Atual->proxima_sessao;
            free(Atual);
            printf("Sessao removida com sucesso.\n");
            return lista_sessao_var;
        }
    } else {
        printf("Objeto não encontrado.\n");
        return lista_sessao_var;
    }
}
```
**Editar informações**<img align="center" alt="Porfirio-Neto-C" height="30" width="40" src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg">

```c
void editarProduto(Lista_Produtos *lista, char *nome) {
    // Verifica se a lista está vazia
    if (listaProdutosVazia(lista)) {
        printf("Lista de produtos vazia. Nada a editar.\n");
    }

    // Percorre a lista procurando o produto com o nome especificado
    Lista_Produtos *atual = lista;
    while (atual != NULL) {
        if (strcmp(atual->produto.nome, nome) == 0) {
            // Solicita ao usuário as novas informações para o produto
            printf("Digite o novo nome do produto: ");
            scanf(" %[^\n]", atual->produto.nome);
            printf("Digite a nova categoria do produto: ");
            scanf(" %[^\n]", atual->produto.categoria);
            printf("Digite o novo preço do produto: ");
            scanf(" %f", &atual->produto.preco);
            printf("Digite a nova quantidade do produto: ");
            scanf(" %d", &atual->produto.quantidade);
            printf("Produto \"%s\" editado com sucesso.\n", nome);
            return;
        }
        atual = atual->proximo_produto;
    }

    printf("Produto \"%s\" não encontrado na lista.\n", nome);
}
```
**Buscar Produto por nome**<img align="center" alt="Porfirio-Neto-C" height="30" width="40" src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg">

```c
Lista_Produtos *buscarPorNome(Lista_Produtos *lista, char *nome) {

    // Percorre a lista procurando produtos que contenham o nome especificado
    Lista_Produtos *atual = lista;

    while (atual != NULL) {
        if (strstr(atual->produto.nome, nome) != NULL) {
            return atual;      
        }
        atual = atual->proximo_produto;
    }

    return atual;
}

void Imprimir_Produto(Lista_Produtos *Produto){

    printf("Produto encontrado:\n");
        printf("Nome: %s\n", Produto->produto.nome);
        printf("Categoria: %s\n", Produto->produto.categoria);
        printf("Preço: %.2f\n", Produto->produto.preco);
        printf("Quantidade: %d\n", Produto->produto.quantidade);
        printf("\n");
}
```
**Listar Sessão e Produto**<img align="center" alt="Porfirio-Neto-C" height="30" width="40" src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg">

```c

```
**Main**<img align="center" alt="Porfirio-Neto-C" height="30" width="40" src="https://github.com/devicons/devicon/blob/master/icons/c/c-original.svg">

```c
#include "../Funcoes/funcoes.h"

int main() {

    char opcao;
    char nome_escolhido[100];
    Lista_Sessao *lista_Sessao = Cria_Lista_Sessao();
    lista_Sessao = Ler_Arquivo(lista_Sessao);

    do {
        opcao = exibirMenu();

        switch (opcao) {
            case '1': {

                if (Lista_Vazia(lista_Sessao)){
                    printf("nenhuma sessao cadastrada\n");
                } else{ 

                    printf("Digite em qual sessao o produto vai estar\n");
                    scanf(" %[^\n]", nome_escolhido);
                    string_maiuscula_minuscula(nome_escolhido);

                    Lista_Sessao *sessao_escolhida = Busca_Sessao(lista_Sessao, nome_escolhido);

                    if (sessao_escolhida != NULL){

                        Lista_Produtos *lista_produto_Escolhida = Pegar_Lista_Produtos(sessao_escolhida);
                        char nome[100], categoria[100], preco_str[40], quantidade_str[40];
                        float preco;
                        int quantidade;
                        printf("Digite o nome do produto: ");
                        scanf(" %[^\n]", nome);
                        string_maiuscula_minuscula(nome);

                        Lista_Sessao *Auxiliar_Adicionar = lista_Sessao;
                        short produto_com_mesmo_nome = 0;
                        while(Auxiliar_Adicionar != NULL){

                            if (buscarPorNome(Pegar_Lista_Produtos(Auxiliar_Adicionar), nome) != NULL){
                                produto_com_mesmo_nome = 1;
                            }
                            Auxiliar_Adicionar = Percorrer_Sessoes(Auxiliar_Adicionar);
                        }
                        if(produto_com_mesmo_nome){
                            printf("Produto já existente");
                            break;
                        }

                        printf("Digite a categoria do produto: ");
                        scanf(" %[^\n]", categoria);
                        printf("Digite o preço do produto: ");
                        scanf(" %[^\n]", preco_str);
                        printf("Digite a quantidade do produto: ");
                        scanf(" %[^\n]", quantidade_str);

                        preco = extrairFloat(preco_str);
                        quantidade = extrairInt(quantidade_str);
                        lista_produto_Escolhida = adicionarProduto(lista_produto_Escolhida, nome, categoria, preco, quantidade);
                        sessao_escolhida = Adicionar_Produto_Sessao(lista_produto_Escolhida, sessao_escolhida);
                        printf("Produto adicionado com sucesso!\n");
                    } else {
                        printf("sessao nao existe\n");
                    }
                }
                break;
            }
            case '2': {
                printf("Digite o nome do produto a ser removido: ");
                scanf(" %[^\n]", nome_escolhido);
                string_maiuscula_minuscula(nome_escolhido);

                Lista_Sessao *Auxiliar = lista_Sessao;
                while (Auxiliar != NULL){

                    Lista_Produtos *Auxiliar_produtos = Pegar_Lista_Produtos(Auxiliar);
                    Auxiliar_produtos = removerProduto(Auxiliar_produtos, nome_escolhido);
                    Auxiliar = Percorrer_Sessoes(Auxiliar);
                }
                break;
            }
            case '3': {

                printf("\nOpcao selecionada: Adicionar sessao\n");

                char nome[100], descricao[100];
                printf("Digite o nome da sessao:\n");
                scanf(" %[^\n]", nome);
                string_maiuscula_minuscula(nome);

                if (Busca_Sessao(lista_Sessao, nome_escolhido) != NULL){
                    printf("Sessão já existente\n");
                    break;
                }
                printf("Digite a descricao da sessao:\n");
                scanf(" %[^\n]", descricao);


                lista_Sessao = Adicionar_Sessao(lista_Sessao, nome, descricao, NULL);
                break;
            }
            case '4': {
                printf("\nOpcao selecionada: Remover sessao\n");

                if(lista_Sessao == NULL){
                    printf("nenhuma lista cadastrada\n");
                    break;
                }

                printf("Digite o nome da sessao a ser removida: ");
                scanf(" %[^\n]", nome_escolhido);
                string_maiuscula_minuscula(nome_escolhido);
                lista_Sessao = Remover_Sessao(lista_Sessao, nome_escolhido);
                break;
            }
            case '5': {
                printf("Digite o nome do produto a ser editado: ");
                scanf(" %[^\n]", nome_escolhido);
                string_maiuscula_minuscula(nome_escolhido);

                Lista_Sessao *Auxiliar = lista_Sessao;
                while (Auxiliar != NULL){

                    Lista_Produtos *Auxiliar_produtos = Pegar_Lista_Produtos(Auxiliar);
                    if(editarProduto(Auxiliar_produtos, nome_escolhido)){
                        break;
                    }
                    Auxiliar = Percorrer_Sessoes(Auxiliar);
                }
                printf("Produto \"%s\" não encontrado na lista.\n", nome_escolhido);
                break;
            }
            case '6': {
                printf("Digite o nome do produto a ser buscado: ");
                scanf(" %[^\n]", nome_escolhido);
                string_maiuscula_minuscula(nome_escolhido);
                
                Lista_Sessao *Auxiliar = lista_Sessao;
                while (Auxiliar != NULL){

                    Lista_Produtos *Auxiliar_produtos = Pegar_Lista_Produtos(Auxiliar);
                    Lista_Produtos *Produto = buscarPorNome(Auxiliar_produtos, nome_escolhido);
                    if (Produto != NULL){
                        Imprimir_Produto(Produto);
                        break;
                    }
                    Auxiliar = Percorrer_Sessoes(Auxiliar);
                }
                printf("Nenhum produto com o nome: \"%s\" encontrado", nome_escolhido);
                break;
            }
            case '7': {

                Lista_Sessao *Auxiliar = lista_Sessao;
                if(!Lista_Vazia(Auxiliar)){
                while (Auxiliar != NULL)
                    {
                        Imprimir_Sessao(Auxiliar);
                        Lista_Produtos *Auxiliar_produto = Pegar_Lista_Produtos(Auxiliar);
                        imprimirProdutos(Auxiliar_produto);
                        Auxiliar = Percorrer_Sessoes(Auxiliar);
                    }
                } else {
                    printf("Nao existe nenhuma lista");
                }
                break;
            }
            case '8': {
                printf("Saindo...\n");
                Escrever_Arquivo(lista_Sessao);
                Liberar_Lista_Sessao(lista_Sessao);
                break;
            }
            default: {
                printf("Opcao invalida. Tente novamente.\n");
            }
        }
    } while (opcao != '8');
    return 0;
}

```
