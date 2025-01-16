
else {
        struct Node *current = start;
        while (current->next != NULL) {
            current = current->next;//Aponta para o proximo nó
        }
        current->next = temp;
 }

/*

Essa forma de percorrer é uma abordagem baseada em loops controlados por condição, 
que é uma técnica comum em C++ (e outras linguagens) para percorrer estruturas de dados
 dinâmicas, como listas encadeadas, ou para processar dados sequenciais, 
como leitura de arquivos.

*/

while (current->next != NULL)

/*
O loop continua enquanto o próximo nó (current->next) não for NULL.
Como o último nó de uma lista encadeada tem next igual a NULL, isso 
é um indicador de que chegamos ao final da lista.
*/

current = current->next;

/*
A cada iteração, current é atualizado para apontar para o próximo nó.
Isso permite que o loop "caminhe" pela lista nó por nó.

#Parada
O loop para quando current->next é NULL, ou seja, quando current está no último nó da lista.


#Por que usar o while aqui?
Essa forma de percorrer é ideal para estruturas dinâmicas como listas encadeadas, porque 
o tamanho da lista geralmente não é conhecido de antemão.
Diferente de um array, onde podemos usar um loop for baseado em índices 
(como for (int i = 0; i < tamanho; i++)), listas 
encadeadas não têm índices. Em vez disso, precisamos seguir os ponteiros de nó para nó.
*/

for (int i = 0; i < tamanho; i++) {
    // Percorrer elementos de um array, por exemplo
}

for (Node *current = start; current != NULL; current = current->next) {
    // Percorrer os nós da lista
}//Mas isto eh equivalente ao while, entao eh melhor utilizar while
