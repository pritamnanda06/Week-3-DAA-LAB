#include <stdio.h>

// Function to calculate the sum of coin weights in a given range (simulating a balance scale measurement)
int getWeightSum(int coins[], int left, int right) {
    int sum = 0;
    for (int i = left; i <= right; i++) {
        sum += coins[i];
    }
    return sum;
}

// Divide and Conquer function to find the defective (lighter) coin
// Returns the index of the lighter coin, or -1 if all coins are identical.
int findDefectiveCoin(int coins[], int low, int high) {
    // Base case: If only one coin is left in the search space, it is the defective coin
    if (low == high) {
        return low;
    }

    int length = high - low + 1;

    // If length is even, divide into two equal halves
    if (length % 2 == 0) {
        int mid = low + (length / 2) - 1;
        int leftSum = getWeightSum(coins, low, mid);
        int rightSum = getWeightSum(coins, mid + 1, high);

        if (leftSum < rightSum) {
            return findDefectiveCoin(coins, low, mid);
        } else if (rightSum < leftSum) {
            return findDefectiveCoin(coins, mid + 1, high);
        } else {
            // Both halves weigh the same; no lighter coin present in this range
            return -1;
        }
    } 
    // If length is odd, leave one coin out and divide the rest into two equal halves
    else {
        int mid = low + length / 2;
        int leftStart = low;
        int leftEnd = mid - 1;
        int rightStart = mid + 1;
        int rightEnd = high;

        int leftSum = getWeightSum(coins, leftStart, leftEnd);
        int rightSum = getWeightSum(coins, rightStart, rightEnd);

        if (leftSum < rightSum) {
            return findDefectiveCoin(coins, leftStart, leftEnd);
        } else if (rightSum < leftSum) {
            return findDefectiveCoin(coins, rightStart, rightEnd);
        } else {
            // The two halves balance, meaning the leftover coin (at index 'mid') must be the lighter one,
            // provided its weight is less than a known normal coin from the balanced group.
            if (coins[mid] < coins[leftStart]) {
                return mid;
            }
            return -1;
        }
    }
}

int main() {
    int n;

    printf("Enter the total number of coins (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int coins[n];
    printf("Enter the weights of the %d coins:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    int defectiveIndex = findDefectiveCoin(coins, 0, n - 1);

    printf("\n--- Defective Coin Search Results ---\n");
    if (defectiveIndex != -1) {
        printf("Lighter defective coin found at index %d (1-based position: %d) with weight %d\n", 
               defectiveIndex, defectiveIndex + 1, coins[defectiveIndex]);
    } else {
        printf("All coins have identical weights. No lighter defective coin found.\n");
    }

    return 0;
}