#include <stdio.h>

#define MAX 10   // Maximum matrix size

void inputMatrix(int r, int c, int mat[MAX][MAX]) {
    printf("Enter matrix elements:\n");
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
}

void displayMatrix(int r, int c, int mat[MAX][MAX]) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void addMatrix(int r, int c, int a[MAX][MAX], int b[MAX][MAX]) {
    int result[MAX][MAX];
    printf("\nMatrix Addition Result:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            result[i][j] = a[i][j] + b[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int r1, int c1, int r2, int c2, int a[MAX][MAX], int b[MAX][MAX]) {
    if(c1 != r2) {
        printf("\nMatrix multiplication not possible!\n");
        return;
    }

    int result[MAX][MAX] = {0};

    printf("\nMatrix Multiplication Result:\n");
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int r, int c, int mat[MAX][MAX]) {
    printf("\nTranspose of Matrix:\n");
    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++)
            printf("%d ", mat[j][i]);
        printf("\n");
    }
}

int main() {
    int r, c, choice;
    int A[MAX][MAX], B[MAX][MAX];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("\nEnter Matrix A:\n");
    inputMatrix(r, c, A);

    printf("\nEnter Matrix B:\n");
    inputMatrix(r, c, B);

    printf("\nChoose Operation:\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("3. Transpose of A\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            addMatrix(r, c, A, B);
            break;
        case 2:
            multiplyMatrix(r, c, r, c, A, B);
            break;
        case 3:
            transposeMatrix(r, c, A);
            break;
        default:
            printf("Exiting...");
    }

    return 0;
}