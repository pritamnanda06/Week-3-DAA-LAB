#include <stdio.h>

// Divide and Conquer function to find Max and Min
void findMaxMin(int arr[], int low, int high, int *max, int *min, int *comparisons) {
    // Base Case 1: Only one element
    if (low == high) {
        *max = arr[low];
        *min = arr[low];
        return;
    }

    // Base Case 2: Two elements
    if (high == low + 1) {
        (*comparisons)++; // Comparison between the two elements
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    // Recursive Step: Divide the array into two halves
    int mid = low + (high - low) / 2;
    int max1, min1, max2, min2;

    findMaxMin(arr, low, mid, &max1, &min1, comparisons);
    findMaxMin(arr, mid + 1, high, &max2, &min2, comparisons);

    // Combine Step: Compare results from both halves
    (*comparisons)++; // Comparison for max
    if (max1 > max2) {
        *max = max1;
    } else {
        *max = max2;
    }

    (*comparisons)++; // Comparison for min
    if (min1 < min2) {
        *min = min1;
    } else {
        *min = min2;
    }
}

int main() {
    int n;

    printf("Enter the size of the array (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max, min;
    int comparisons = 0;

    findMaxMin(arr, 0, n - 1, &max, &min, &comparisons);

    printf("\n--- Max and Min Results ---\n");
    printf("Maximum Element: %d\n", max);
    printf("Minimum Element: %d\n", min);
    printf("Total Comparisons Made: %d\n", comparisons);
    printf("Theoretical Bound (3n/2): %.2f\n", (1.5 * n));

    if (comparisons <= (1.5 * n)) {
        printf("Validation Successful: Number of comparisons is bounded by 3n/2[cite: 1].\n");
    } else {
        printf("Validation Failed: Comparisons exceeded the limit.\n");
    }

    return 0;
}