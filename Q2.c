#include <stdio.h>
#include <stdlib.h>

// Function to get the weight sum of a range [l, r] in O(1) time using prefix sums
int getRangeSum(int pref[], int l, int r) {
    if (l > r) return 0;
    if (l == 0) return pref[r];
    return pref[r] - pref[l - 1];
}

// Divide and Conquer function to find the defective (lighter) coin
int findDefectiveCoin(int coins[], int pref[], int low, int high, int standard_weight) {
    int length = high - low + 1;

    // Base Case: Only 1 coin left in the search space
    if (length == 1) {
        if (coins[low] < standard_weight) {
            return low;
        }
        return -1;
    }

    int k = length / 2;

    // If length is even
    if (length % 2 == 0) {
        int left_low = low;
        int left_high = low + k - 1;
        int right_low = low + k;
        int right_high = high;

        int left_weight = getRangeSum(pref, left_low, left_high);
        int right_weight = getRangeSum(pref, right_low, right_high);

        if (left_weight < right_weight) {
            return findDefectiveCoin(coins, pref, left_low, left_high, standard_weight);
        } else if (right_weight < left_weight) {
            return findDefectiveCoin(coins, pref, right_low, right_high, standard_weight);
        } else {
            return -1; // Both halves balanced, no lighter coin in this range
        }
    } 
    // If length is odd
    else {
        int left_low = low;
        int left_high = low + k - 1;
        int right_low = low + k;
        int right_high = low + (2 * k) - 1;
        int leftover = high; // The extra coin left out on the scale

        int left_weight = getRangeSum(pref, left_low, left_high);
        int right_weight = getRangeSum(pref, right_low, right_high);

        if (left_weight < right_weight) {
            return findDefectiveCoin(coins, pref, left_low, left_high, standard_weight);
        } else if (right_weight < left_weight) {
            return findDefectiveCoin(coins, pref, right_low, right_high, standard_weight);
        } else {
            // Left and Right scales are balanced, check the leftover coin
            if (coins[leftover] < standard_weight) {
                return leftover;
            }
            return -1;
        }
    }
}

int main() {
    int n;
    printf("Enter the total number of coins (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of coins.\n");
        return 1;
    }

    int *coins = (int *)malloc(n * sizeof(int));
    int *pref = (int *)malloc(n * sizeof(int));

    printf("Enter the weights of the %d coins:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    // Precompute prefix sums for O(1) range weighings
    pref[0] = coins[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + coins[i];
    }

    // Robust Standard Weight Determination:
    // Since at most one coin is lighter, the standard weight is always the maximum weight in the set.
    int standard_weight = coins[0];
    for (int i = 1; i < n; i++) {
        if (coins[i] > standard_weight) {
            standard_weight = coins[i];
        }
    }

    int defective_index = findDefectiveCoin(coins, pref, 0, n - 1, standard_weight);

    printf("\n--- Defective Coin Search Results ---\n");
    if (defective_index != -1) {
        printf("Defective lighter coin found at index: %d\n", defective_index);
        printf("Weight of defective coin: %d (Standard weight: %d)\n", coins[defective_index], standard_weight);
    } else {
        printf("No lighter defective coin found. All coins have standard or identical weights[cite: 1].\n");
    }

    free(coins);
    free(pref);
    return 0;
}