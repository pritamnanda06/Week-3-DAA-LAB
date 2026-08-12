#include <stdio.h>

// Selection Sort function running for the first n - 1 elements
void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        
        // Find the index of the smallest element in the remaining unsorted array
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }
        
        // Exchange the found minimum element with the first element of the unsorted portion
        if (min_index != i) {
            int temp = A[i];
            A[i] = A[min_index];
            A[min_index] = temp;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input size.\n");
        return 1;
    }

    int A[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Perform sorting
    selectionSort(A, n);

    printf("\n--- Sorted Array Result ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}