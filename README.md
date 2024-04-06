# Gerenciamento_de_Artigos_Esportivos
Projeto de  um sistema em Linguagem C para gerenciamento de Artigos Esportivos, que realiza a manipulação de Sessões e Produtos.  

- [Introdução](#introduçao)
- [Problemáticas](#Problemáticas)
- [Requisitos](#Requisitos)
- [Organização](#Organização)
- [Execução do projeto;](#execução-do-projeto)
___

## Desenvolvedores
> :computer:[Francisco Porfirio de Oliveira Neto](https://github.com/Porfirio24)
> 
> :computer:[Daniel Neres Vireira](https://github.com/DanielNeres)
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
├── .gitignore
│
├── Funções
│   ├── Funções.c
│   ├── Funções.h
│   └── Funções.o
│    
├── Arquivo.txt
│
├── Main
│   ├── Main.c
│   ├── Main.exe
│   └── Main.o
│
├── Produto
│   ├── Produto.c        
│   ├── Produto.h
│   └── Produto.o
│
├── Sessão
│   ├── Sessão.c
│   ├── Sessão.h
│   └── Sessão.o
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
gcc -c /Produto.c /Sessão.c /Main.c /Funcões.c
gcc -o main /Produto.c /Sessão.c /Main.c /Funcões.c
```

