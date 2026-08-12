#include <stdio.h>
#include <stdlib.h>

// Function to allocate a square matrix of size n x n
int** createMatrix(int n) {
    int** mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = (int*)calloc(n, sizeof(int));
    }
    return mat;
}

// Function to free a square matrix
void freeMatrix(int** mat, int n) {
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

// Function to add two matrices: C = A + B
void addMatrix(int n, int** A, int** B, int** C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices: C = A - B
void subMatrix(int n, int** A, int** B, int** C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to scale a matrix by dividing all elements by 2
void scaleMatrix(int n, int** A) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] /= 2;
        }
    }
}

// O(n^2) Divide and Conquer multiplication for special-pattern matrices[cite: 1]
void specialMatrixMultiply(int n, int** A, int** B, int** C) {
    // Base Case: 1x1 matrix
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    // Allocate sub-blocks and temporary matrices
    int** A1 = createMatrix(k);
    int** A2 = createMatrix(k);
    int** B1 = createMatrix(k);
    int** B2 = createMatrix(k);

    int** TempA1 = createMatrix(k);
    int** TempA2 = createMatrix(k);
    int** TempB1 = createMatrix(k);
    int** TempB2 = createMatrix(k);

    int** P1 = createMatrix(k);
    int** P2 = createMatrix(k);
    int** C1 = createMatrix(k);
    int** C2 = createMatrix(k);

    // Extract blocks A1, A2 from A and B1, B2 from B[cite: 1]
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + k];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + k];
        }
    }

    // Compute intermediate matrices: TempA1 = A1 + A2, TempA2 = A1 - A2
    addMatrix(k, A1, A2, TempA1);
    subMatrix(k, A1, A2, TempA2);

    // TempB1 = B1 + B2, TempB2 = B1 - B2
    addMatrix(k, B1, B2, TempB1);
    subMatrix(k, B1, B2, TempB2);

    // Recursive multiplications (only 2 calls to maintain O(n^2) complexity)[cite: 1]
    specialMatrixMultiply(k, TempA1, TempB1, P1);
    specialMatrixMultiply(k, TempA2, TempB2, P2);

    // Combine step: C1 = (P1 + P2) / 2, C2 = (P1 - P2) / 2
    addMatrix(k, P1, P2, C1);
    scaleMatrix(k, C1);

    subMatrix(k, P1, P2, C2);
    scaleMatrix(k, C2);

    // Assemble result matrix C into the recursive block pattern [[C1, C2], [C2, C1]][cite: 1]
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C1[i][j];
            C[i][j + k] = C2[i][j];
            C[i + k][j] = C2[i][j];
            C[i + k][j + k] = C1[i][j];
        }
    }

    // Free allocated memory
    freeMatrix(A1, k); freeMatrix(A2, k);
    freeMatrix(B1, k); freeMatrix(B2, k);
    freeMatrix(TempA1, k); freeMatrix(TempA2, k);
    freeMatrix(TempB1, k); freeMatrix(TempB2, k);
    freeMatrix(P1, k); freeMatrix(P2, k);
    freeMatrix(C1, k); freeMatrix(C2, k);
}

int main() {
    int n;
    printf("Enter the size of the matrix n (must be a power of 2)[cite: 1]: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    int** A = createMatrix(n);
    int** B = createMatrix(n);
    int** C = createMatrix(n);

    printf("Enter elements of Matrix A (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of Matrix B (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    specialMatrixMultiply(n, A, B, C);

    printf("\n--- Resultant Special-Pattern Matrix C (A * B) ---\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d \t", C[i][j]);
        }
        printf("\n");
    }

    // Clean up main matrices
    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);

    return 0;
}