#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

// Estrutura para representar a pilha
typedef struct stack {
    int stack[MAXSIZE];
    int top;
} NODE;

// Função para inserir um elemento no topo da pilha
void push(NODE *ps) {
    int item;
    if (ps->top == MAXSIZE - 1) {
        printf("\nA Pilha está cheia (Overflow)");
    } else {
        printf("\nDigite o elemento a ser inserido: ");
        scanf("%d", &item);
        ps->stack[++ps->top] = item;
        printf("\nElemento %d inserido com sucesso", item);
    }
}

// Função para remover um elemento do topo da pilha
void pop(NODE *ps) {
    if (ps->top == -1) {
        printf("\nA Pilha está vazia (Underflow)");
    } else {
        int item = ps->stack[ps->top--];
        printf("\nElemento removido: %d", item);
    }
}

// Função para exibir todos os elementos da pilha
void traverse(NODE *ps) {
    if (ps->top == -1) {
        printf("\nA Pilha está vazia");
    } else {
        printf("\nElementos na pilha:");
        for (int i = ps->top; i >= 0; i--) {
            printf("\n%d", ps->stack[i]);
        }
    }
}

int main() {
    NODE stack;
    stack.top = -1;
    int choice;
    char ch;

    do {
        printf("\n\nOperações de Pilha:");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. TRAVERSAR");
        printf("\nEscolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(&stack);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                traverse(&stack);
                break;
            default:
                printf("\nOpção inválida");
                break;
        }

        printf("\n\nDeseja continuar? (Y/y para sim): ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
