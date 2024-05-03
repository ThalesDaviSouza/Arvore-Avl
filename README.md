# Implementando uma Árvore AVL

Esse projeto foi desenvolvido para implementar um tópico de programação que eu estava revendo: Árvores Binárias. <br />

A ideia de implementar a Árvore Avl veio em decorrência de ser uma árvore binária balanceada que pela teoria não aparentava ser muito complexa de ser implementada e onde a complexidade do pior caso é O(log n) para inserção, deleção e para leitura. <br />

Assim, comecei a criar esse repositório para ser tanta uma forma de estudo ativo, quanto uma biblioteca que outras pessoas possam utilizar. <br />

## 📖 Objetivos

Criar uma biblioteca que permita criar uma Árvore Avl de forma simples com código limpo e aberto, além disso, e que tenha testes unitários para as principais funcionalidades.

## 📌 As funcionalidades que a biblioteca deve implementar:
- ` Criação `
- ` Inserção `
- ` Busca `
- ` Deleção `

## 📝 As funcionalidades que faltam ser implementadas:
- ` Deleção `

## 💻 Pré-requisitos

Antes de começar, verifique se você atendeu aos seguintes requisitos:

- Você já possui `gcc ou qualquer compilador de c instalado`
- Se a sua máquina for `Windows` instale algum app que permita utilizar o comando `Make` para utilizar o Makefile (recomendo o GNU Make).


## 🚀 Instalando

Para instalar o projeto basta baixar esse repositório.


## ☕ Usando

Para usar o projeto basta adicionar a lógica que desejar no arquivo main.c. <br />
O arquivo avl_tree.h está documentado de forma explicar o que cada função faz para caso queira entender de forma mais profunda ou precise de alguma função específica. <br />
Os pontos principais que precisam ser explicados aqui para uso dessa biblioteca até o momento são:
- `node`: É o struct base do projeto. Nele temos as principais informações de cada nó (valor, nó filho à direita, nó filho à esquerda e altura).
- `addNode`: Recebe como parâmetro um valor inteiro e o nó raiz da árvore e retorna a nova raiz (caso durante a inserção e balanceamento houve a mudança do nó raiz). <br />
- `findNode`: Recebe como parâmetro um valor inteiro que será buscado na árvore e a raiz da árvore. Retorna o *nó* com o valor procurado ou *null* para caso não encontre o valor.

Para compilar basta utilizar o comando `make` <br />
Para rodar os testes unitários presentes no projeto basta utilizar o comando `make` seguindo do nome de um dos testes:
- `test-all`: Para rodar todos os testes de uma única vez.
- `test-insertion-avl-tree`: Para rodar os testes de inserção na árvore.
- `test-find-avl-tree`: Para rodar os testes de busca na árvore. 
Além disso, caso queira limpar a solução dos .exe e dos .o gerados durante a compilação: `make clean` 
