#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da lista
struct Node {
    int data;
    struct Node *next;
};

// Ponteiro global para o início da lista
struct Node *start = NULL;

// Função para criar um novo nó
void Create_List(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp) {
        printf("Erro de alocação de memória\n");
        return;
    }
    temp->data = data;
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        struct Node *current = start;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

// Função para adicionar um nó no início da lista
void AddAtBeg(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp) {
        printf("Erro de alocação de memória\n");
        return;
    }
    temp->data = data;
    temp->next = start;
    start = temp;
}

// Função para adicionar um nó após uma posição específica
void AddAfter(int data, int pos) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp) {
        printf("Erro de alocação de memória\n");
        return;
    }
    temp->data = data;

    struct Node *current = start;
    for (int i = 1; i < pos && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Posição inválida\n");
        free(temp);
        return;
    }

    temp->next = current->next;
    current->next = temp;
}

// Função para deletar um nó com base no valor
void Del(int data) {
    if (start == NULL) {
        printf("Lista está vazia\n");
        return;
    }

    struct Node *temp = start, *prev = NULL;

    if (start->data == data) {
        start = start->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Elemento %d não encontrado\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Função para exibir os elementos da lista
void Display() {
    if (start == NULL) {
        printf("Lista está vazia\n");
        return;
    }

    struct Node *current = start;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Função para contar o número de elementos na lista
void Count() {
    int count = 0;
    struct Node *current = start;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    printf("Número de elementos: %d\n", count);
}

// Função para reverter a lista
void Rev() {
    struct Node *prev = NULL, *current = start, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
}

// Função para buscar um elemento na lista
void Search(int data) {
    struct Node *current = start;
    int pos = 1;

    while (current != NULL) {
        if (current->data == data) {
            printf("Elemento %d encontrado na posição %d\n", data, pos);
            return;
        }
        current = current->next;
        pos++;
    }

    printf("Elemento %d não encontrado\n", data);
}

// Função principal
int main() {
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Criar Lista\n");
        printf("2. Adicionar no início\n");
        printf("3. Adicionar após posição\n");
        printf("4. Deletar elemento\n");
        printf("5. Exibir Lista\n");
        printf("6. Contar elementos\n");
        printf("7. Reverter Lista\n");
        printf("8. Buscar elemento\n");
        printf("9. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Quantos elementos deseja adicionar? ");
                int n;
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Digite o elemento %d: ", i + 1);
                    scanf("%d", &data);
                    Create_List(data);
                }
                break;

            case 2:
                printf("Digite o elemento para adicionar no início: ");
                scanf("%d", &data);
                AddAtBeg(data);
                break;

            case 3:
                printf("Digite o elemento: ");
                scanf("%d", &data);
                printf("Digite a posição: ");
                scanf("%d", &pos);
                AddAfter(data, pos);
                break;

            case 4:
                printf("Digite o elemento para deletar: ");
                scanf("%d", &data);
                Del(data);
                break;

            case 5:
                Display();
                break;

            case 6:
                Count();
                break;

            case 7:
                Rev();
                break;

            case 8:
                printf("Digite o elemento para buscar: ");
                scanf("%d", &data);
                Search(data);
                break;

            case 9:
                printf("Saindo...\n");
                exit(0);

            default:
                printf("Opção inválida\n");
        }
    }

    return 0;
}
