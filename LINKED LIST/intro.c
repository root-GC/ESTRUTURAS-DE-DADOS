
//#LINKED LIST 

/*
O que é uma lista ligada?

Uma lista ligada é uma estrutura de dados composta por uma sequência de "nós" (nodes) conectados por ponteiros.
Cada nó armazena duas informações:

Data (dado): o valor que o nó contém (por exemplo, um número inteiro).

Next (próximo): um ponteiro para o próximo nó da lista.

O último nó aponta para NULL, indicando o fim da lista.
*/

struct Node {
    int DATA; // Armazena o dado (por exemplo, um número inteiro)
    struct Node *Next;  // Ponteiro para o próximo nó na lista
};

typedef struct Node *NODE; // Define 'NODE' como um ponteiro para 'struct Node',  declaramos um ponteiro para a struct Node


NODE head = NULL; == struct Node *head = NULL; //Usamos aquele typedef para evitar andar a escrever struct

/*
Exemplo Prático
Aqui está uma representação simples de uma lista com 3 nós contendo os valores 10, 20 e 30:
[10 | Next] -> [20 | Next] -> [30 | NULL]
*/
//#CODIGO EM C
NODE head = (NODE)malloc(sizeof(struct Node));
head->DATA = 10;
head->Next = (NODE)malloc(sizeof(struct Node));
head->Next->DATA = 20;
head->Next->Next = (NODE)malloc(sizeof(struct Node));
head->Next->Next->DATA = 30;
head->Next->Next->Next = NULL;

/*

Resumo
Uma lista ligada é uma sequência de nós conectados por ponteiros.
Cada nó tem um dado e o endereço do próximo nó.
O último nó sempre aponta para NULL.
A estrutura struct Node permite criar essa lista, e o ponteiro Next conecta os nós.

*/


/*   #VANTAGENS E DESVANTAGENS DAS LISTAS LIGADAS

#VANTAGENS

Estrutura de Dados Dinâmica:
As listas ligadas podem crescer ou diminuir durante a execução de um programa, permitindo flexibilidade na alocação de memória.

Utilização Eficiente de Memória:

A memória não é pré-alocada.
A memória é alocada conforme necessário e liberada quando não é mais utilizada.
Facilidade na Inserção e Remoção:

Inserir ou remover itens em posições específicas é mais simples e eficiente em comparação a estruturas como arrays.
Aplicações Complexas:

Estruturas complexas podem ser implementadas de forma mais fácil usando listas ligadas.

#DESVANTAGENS:

Maior Consumo de Memória:

Cada nó armazena não apenas os dados, mas também o endereço do próximo nó, aumentando o uso de memória.
Acesso Mais Lento:

O acesso direto a um item específico é mais demorado e complexo, já que é necessário percorrer a lista desde o início até encontrar o elemento desejado.

*/

/*
#   TIPOS DE LISTA LIGADA

1. Singly linked list
2. Doubly linked list
3. Circular linked list

*/