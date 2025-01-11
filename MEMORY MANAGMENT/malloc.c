//THIS IS A PROGRAM TO FIND THE SUM OF n ELEMENTS USING
//DYNAMIC MEMORY ALLOCATION
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, sum = 0;
    int *ptr;

    printf("Enter the number of elements to be added: ");
    scanf("%d", &n);

    // Alocar memória para n inteiros
    ptr = malloc(n * sizeof(int));

    // Verificar se a alocação foi bem-sucedida
    if(ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Ler os elementos
    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }

    // Calcular a soma
    for(i = 0; i < n; i++) {
        sum += ptr[i];
    }

    printf("The sum of the elements is: %d\n", sum);

    // Liberar memória alocada
    free(ptr);

    return 0;
}

