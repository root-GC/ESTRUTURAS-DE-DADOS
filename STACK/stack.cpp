#include <iostream>
using namespace std;

// Definindo o tamanho máximo da pilha
#define MAXSIZE 100

// Classe para implementação da pilha com array
class STACK_ARRAY {
    int stack[MAXSIZE];
    int Top;

public:
    // Construtor inicializando Top como -1
    STACK_ARRAY() {
        Top = -1;
    }

    void push();
    void pop();
    void traverse();
};

// Função para inserir um elemento no topo da pilha
void STACK_ARRAY::push() {
    int item;

    // Verifica se a pilha está cheia (Overflow)
    if (Top == MAXSIZE - 1) {
        cout << "\nA Pilha Está Cheia (Overflow)";
    } else {
        cout << "\nDigite o Elemento a Ser Inserido: ";
        cin >> item;
        stack[++Top] = item;
        cout << "Elemento Inserido com Sucesso!";
    }
}

// Função para remover o elemento do topo da pilha
void STACK_ARRAY::pop() {
    if (Top == -1) {
        cout << "\nA Pilha Está Vazia (Underflow)";
    } else {
        int item = stack[Top--];
        cout << "\nElemento Removido: " << item;
    }
}

// Função para percorrer e exibir os elementos da pilha
void STACK_ARRAY::traverse() {
    if (Top == -1) {
        cout << "\nA Pilha Está Vazia";
    } else {
        cout << "\nElementos na Pilha:";
        for (int i = Top; i >= 0; i--) {
            cout << "\n" << stack[i];
        }
    }
}

int main() {
    STACK_ARRAY ps;
    int choice;
    char ch;

    do {
        // Menu de operações da pilha
        cout << "\n\n1. PUSH";
        cout << "\n2. POP";
        cout << "\n3. TRAVERSE";
        cout << "\nDigite Sua Escolha: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ps.push();
                break;
            case 2:
                ps.pop();
                break;
            case 3:
                ps.traverse();
                break;
            default:
                cout << "\nEscolha Inválida!";
        }

        cout << "\n\nPressione (Y/y) Para Continuar: ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
