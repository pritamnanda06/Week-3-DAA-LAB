#include <stdio.h>

// Function to perform Binary Search and count comparisons
int binarySearch(int arr[], int n, int z, int *comparisons) {
    int low = 0, high = n - 1;
    *comparisons = 0;

    while (low <= high) {
        (*comparisons)++;
        int mid = low + (high - low) / 2;

        if (arr[mid] == z) {
            return mid;
        } else if (arr[mid] < z) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Function to perform Ternary Search and count comparisons
int ternarySearch(int arr[], int n, int z, int *comparisons) {
    int low = 0, high = n - 1;
    *comparisons = 0;

    while (low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        // Comparison for mid1 equality
        (*comparisons)++;
        if (arr[mid1] == z) {
            return mid1;
        }

        // Comparison for mid2 equality
        (*comparisons)++;
        if (arr[mid2] == z) {
            return mid2;
        }

        // Comparisons to decide which interval to search
        (*comparisons)++;
        if (z < arr[mid1]) {
            high = mid1 - 1;
        } else if (z > arr[mid2]) {
            low = mid2 + 1;
        } else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    return -1;
}

int main() {
    int n, z;

    printf("Enter the size of the sorted array: ");
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search (z): ");
    if (scanf("%d", &z) != 1) return 1;

    int bin_comp = 0, ter_comp = 0;

    int bin_index = binarySearch(arr, n, z, &bin_comp);
    int ter_index = ternarySearch(arr, n, z, &ter_comp);

    printf("\n--- Search Results & Validation ---\n");
    if (bin_index != -1)
        printf("Binary Search: Element found at index %d\n", bin_index);
    else
        printf("Binary Search: Element not found\n");
    printf("Binary Search Total Comparisons: %d\n\n", bin_comp);

    if (ter_index != -1)
        printf("Ternary Search: Element found at index %d\n", ter_index);
    else
        printf("Ternary Search: Element not found\n");
    printf("Ternary Search Total Comparisons: %d\n", ter_comp);

    return 0;
}