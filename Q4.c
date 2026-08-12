#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices of size n x n
void add(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices of size n x n
void sub(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Strassen's recursive function for matrix multiplication
void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
    // Base case: 1x1 matrix
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    int A11[k][k], A12[k][k], A21[k][k], A22[k][k];
    int B11[k][k], B12[k][k], B21[k][k], B22[k][k];
    int M1[k][k], M2[k][k], M3[k][k], M4[k][k], M5[k][k], M6[k][k], M7[k][k];
    int TEMP1[k][k], TEMP2[k][k];

    // Divide matrices into 4 sub-matrices
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Step 1: Compute M1 to M7 using formulas
    // M1 = (A11 + A22) * (B11 + B22)
    add(k, A11, A22, TEMP1);
    add(k, B11, B22, TEMP2);
    strassen(k, TEMP1, TEMP2, M1);

    // M2 = (A21 + A22) * B11
    add(k, A21, A22, TEMP1);
    strassen(k, TEMP1, B11, M2);

    // M3 = A11 * (B12 - B22)
    sub(k, B12, B22, TEMP2);
    strassen(k, A11, TEMP2, M3);

    // M4 = A22 * (B21 - B11)
    sub(k, B21, B11, TEMP2);
    strassen(k, A22, TEMP2, M4);

    // M5 = (A11 + A12) * B22
    add(k, A11, A12, TEMP1);
    strassen(k, TEMP1, B22, M5);

    // M6 = (A21 - A11) * (B11 + B12)
    sub(k, A21, A11, TEMP1);
    add(k, B11, B12, TEMP2);
    strassen(k, TEMP1, TEMP2, M6);

    // M7 = (A12 - A22) * (B21 + B22)
    sub(k, A12, A22, TEMP1);
    add(k, B21, B22, TEMP2);
    strassen(k, TEMP1, TEMP2, M7);

    // Step 2: Compute result sub-matrices C11, C12, C21, C22
    // C11 = M1 + M4 - M5 + M7
    add(k, M1, M4, TEMP1);
    sub(k, TEMP1, M5, TEMP2);
    add(k, TEMP2, M7, A11); // Reusing A11 as temporary block

    // C12 = M3 + M5
    add(k, M3, M5, A12);

    // C21 = M2 + M4
    add(k, M2, M4, A21);

    // C22 = M1 - M2 + M3 + M6
    sub(k, M1, M2, TEMP1);
    add(k, TEMP1, M3, TEMP2);
    add(k, TEMP2, M6, A22);

    // Step 3: Gather results back into output matrix C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = A11[i][j];
            C[i][j + k] = A12[i][j];
            C[i + k][j] = A21[i][j];
            C[i + k][j + k] = A22[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the square matrix (n, must be a power of 2): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    int A[n][n], B[n][n], C[n][n];

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

    // Perform Strassen's Matrix Multiplication
    strassen(n, A, B, C);

    printf("\n--- Resultant Matrix C (A * B) using Strassen's Method ---\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d \t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}