# Programa em C com Lista Encadeada

Este programa foi desenvolvido em C utilizando o Visual Studio e demonstra o funcionamento de uma lista encadeada para manipulação de objetos do tipo "Cargo".

## Estrutura Cargo

A estrutura "Cargo" é definida no arquivo "Cargo.h" e possui os seguintes campos:

- "code": um inteiro que representa o código do cargo.
- "name": uma cadeia de caracteres de comprimento máximo 255 que representa o nome do cargo.
- "price": um número real (double) que representa o preço do cargo.
- "ToString": um ponteiro para uma função que recebe um ponteiro para um objeto do tipo "Cargo" e não retorna nada.

A função apontada pelo campo "ToString" é responsável por imprimir uma representação em texto do objeto "Cargo". Essa função recebe um ponteiro para um objeto "Cargo" e não retorna nada, ou seja, ela é do tipo void.

## Lista Encadeada

A lista encadeada é uma lista simples com inclusão e listagem.

- "cargo": um ponteiro para um objeto do tipo "Cargo".
- "next": um ponteiro para o próximo nó da lista.


## Como executar o programa

O programa pode ser executado a partir do Visual Studio. Para isso, basta abrir o projeto "Strings.sln" e pressionar F5. Isso irá compilar e executar o programa.


