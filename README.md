For Q1
------
Overview & Justification
------------------------
Binary Search: Divides the search space into $2$ nearly equal halves at each step and requires $1$ comparison per iteration to determine the branch. Its worst-case time complexity is proportional to $\log_2 n$.

Ternary Search: Divides the search space into $3$ parts using two midpoints, requiring $2$ comparisons per iteration. While its number of steps is $\log_3 n$, the total number of comparisons is roughly $2 \log_3 n \approx 1.26 \log_2 n$.

Validation: Because ternary search performs more comparisons per level ($2$ comparisons instead of $1$), its total operation count is higher than binary search, making binary search more efficient for 1D array searching.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

For Q2
------
Algorithm Overview & Complexity
-------------------------------
Divide and Conquer Strategy: The array of coins is divided into two equal halves at each recursive step, simulating a balance weighing scale.

Time Complexity: By utilizing prefix sums for $O(1)$ range weight calculations, each recursive step runs in constant time, yielding an optimal time complexity of $O(\log_2 n + c)$ (where $\log_2 n$ represents the number of scale weighings and $c$ handles the constant-time overhead).

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

For Q3
------

## Algorithm: Maximum and Minimum using Divide and Conquer

### Pseudocode

**Algorithm:** `MaxMin(A, low, high)`

**Input:** Array $A[low \ldots high]$
**Output:** Minimum and maximum elements

1. If $low = high$:

   * `min = A[low]`
   * `max = A[low]`
   * Return `(min, max)`

2. Else if $high = low + 1$:

   * Compare $A[low]$ and $A[high]$
   * If $A[low] < A[high]$:

     * `min = A[low]`
     * `max = A[high]`
   * Else:

     * `min = A[high]`
     * `max = A[low]`
   * Return `(min, max)`

3. Find the middle index:

$$
mid = \left\lfloor \frac{low + high}{2} \right\rfloor
$$

4. Recursively find minimum and maximum in the left half:

$$
(min_1, max_1) = MaxMin(A, low, mid)
$$

5. Recursively find minimum and maximum in the right half:

$$
(min_2, max_2) = MaxMin(A, mid+1, high)
$$

6. Combine the results:

   * `min = min(min₁, min₂)`
   * `max = max(max₁, max₂)`

7. Return `(min, max)`.

### Number of Comparisons

For $n = 2$, only one comparison is required.

For $n > 2$, the array is divided into two halves and two additional comparisons are required to combine the results.

$$
T(n) = T(\lfloor n/2 \rfloor) + T(\lceil n/2 \rceil) + 2
$$

For $n = 2^k$:

$$
T(n) = 2T(n/2) + 2
$$

Solving the recurrence:

$$
T(n) = \frac{3n}{2} - 2
$$

Therefore,

$$
T(n) < \frac{3n}{2}
$$

Hence, the number of comparisons is bounded by:

$$
\boxed{\frac{3n}{2}}
$$

Thus, the divide-and-conquer algorithm satisfies the required comparison bound.

