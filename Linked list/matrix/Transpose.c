#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int transpose[MAX_COLS][MAX_ROWS];
    int i, j;

    // Perform the transpose operation
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print the transpose matrix
    printf("Transpose of the matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;
    int i, j;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Original matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    transposeMatrix(matrix, rows, cols);

    return 0;
}
