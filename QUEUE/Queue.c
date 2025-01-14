/*
Movimento dos Elementos na Fila:

Embora na vida real as pessoas na fila "andem" fisicamente, em arrays os índices front e rear mudam 
para simular essa movimentação.
Nenhum valor realmente é deslocado dentro do array; apenas os ponteiros front e rear controlam onde 
começa e termina a fila.

*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue_arr[MAX];  // Array que representa a fila
int rear = -1;       // Final da fila
int front = -1;      // Início da fila

// Função para inserir um elemento na fila
void insert() {
    int added_item;
    
    if (rear == MAX - 1) {  // Verifica se a fila está cheia
        printf("\nQueue Overflow\n");
        return;
    }

    if (front == -1)  // Se a fila estava inicialmente vazia
        front = 0;

    printf("Input the element to be added to the queue: ");
    scanf("%d", &added_item);

    rear++;
    queue_arr[rear] = added_item;  // Insere o elemento no final da fila
}

// Função para remover um elemento da fila
void del() {
    if (front == -1 || front > rear) {  // Verifica se a fila está vazia
        printf("\nQueue Underflow\n");
        return;
    }

    printf("\nElement deleted from the queue: %d\n", queue_arr[front]);
    front++;  // Move o ponteiro `front` para o próximo elemento
}

// Função para exibir os elementos da fila
void display() {
    if (front == -1 || front > rear) {  // Verifica se a fila está vazia
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nQueue elements are:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue_arr[i]);
    }
    printf("\n");
}

// Função principal para controle do menu
int main() {
    int choice;

    while (1) {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong choice\n");
        }
    }

    return 0;
}

/*

Melhorias Potenciais
Fila Circular: Uma implementação mais eficiente, onde o array se comporta como se
 estivesse em um loop, reaproveitando o espaço livre.
Listas Ligadas: Podem ser usadas para evitar limites fixos de tamanho.



Filas circulares:

#RACIOCINIO
ok, front=0 e rear = 5. fila cheia.... depois volta para front=0 e rear=0
(mas continua dizendo que esta cheia e nao aceita introduzir elementos), 
so quando front eh: 1(informando que saiu um da frente, pode-se adicionar algo no rear), ne? 
*/
