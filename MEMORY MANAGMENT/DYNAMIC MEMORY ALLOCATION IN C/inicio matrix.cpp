#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 2, cols = 3;
    int **matrix;

    // Aloca espaço para um array de ponteiros para inteiros (linhas da matriz)
    matrix = (int **)malloc(rows * sizeof(int *));

    // Aloca espaço para os elementos de cada linha
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Preenchendo a matriz e exibindo os valores
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Liberar a memória alocada
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}