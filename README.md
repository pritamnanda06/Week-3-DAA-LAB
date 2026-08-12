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

-------------------------------------------------------------------------------

For Q5
------

# Question 5: Special-Pattern Square Matrix Multiplication (O(n^2) Divide and Conquer)

## Overview
This document outlines the divide-and-conquer algorithm for multiplying two special-pattern square matrices of size $n \times n$ (where $n = 2^k$ for some natural number $k$) in optimal $O(n^2)$ time[cite: 1]. 

Each matrix follows a recursive block structure where, when divided into four equal-sized blocks, the two diagonal blocks are identical and the two off-diagonal blocks are identical[cite: 1]:
* Matrix Format = `[[M1, M2], [M2, M1]]`

---

## Mathematical Foundation and Reduction Strategy

Given two matrices $A$ and $B$ structured as:
* Matrix $A$ = `[[A1, A2], [A2, A1]]`
* Matrix $B$ = `[[B1, B2], [B2, B1]]`

The product matrix $C = A \times B$ maintains the same structural format `[[C1, C2], [C2, C1]]`[cite: 1], where:
* $C_1 = A_1 B_1 + A_2 B_2$
* $C_2 = A_1 B_2 + A_2 B_1$

To avoid the $O(n^2 \log n)$ overhead of 4 separate recursive calls, we compute intermediate products using only **two recursive calls** via the linear combination identities:
1. $P_1 = (A_1 + A_2) \times (B_1 + B_2)$
2. $P_2 = (A_1 - A_2) \times (B_1 - B_2)$

From $P_1$ and $P_2$, the final blocks are derived via scaling:
* $C_1 = (P_1 + P_2) / 2$
* $C_2 = (P_1 - P_2) / 2$

---

## Algorithm Description

* **Base Case**: If $n = 1$, compute and return $A[0][0] \times B[0][0]$.
* **Divide Step**: For $n > 1$, split each $n \times n$ matrix into four blocks of size $k \times k$ (where $k = n / 2$) to extract $A_1, A_2$ and $B_1, B_2$[cite: 1].
* **Intermediate Computation Step**: Compute addition and subtraction matrices taking $O(n^2)$ time:
  * $\text{TempA}_1 = A_1 + A_2$, $\text{TempA}_2 = A_1 - A_2$
  * $\text{TempB}_1 = B_1 + B_2$, $\text{TempB}_2 = B_1 - B_2$
* **Conquer Step**: Perform only **2 recursive multiplications**:
  * $P_1 = \text{SpecialMultiply}(\text{TempA}_1, \text{TempB}_1, k)$
  * $P_2 = \text{SpecialMultiply}(\text{TempA}_2, \text{TempB}_2, k)$
* **Combine Step**: Calculate final blocks using scaling and assemble the result matrix $C =$ `[[C1, C2], [C2, C1]]`[cite: 1]:
  * $C_1 = (P_1 + P_2) / 2$
  * $C_2 = (P_1 - P_2) / 2$

---

## Complexity Analysis and Validation

* **Recurrence Relation**: 
  * $T(n) = 2T(n / 2) + O(n^2)$
  * This accounts for 2 recursive subproblems of size $n / 2$ combined with $O(n^2)$ matrix addition and scaling overhead at the current level[cite: 1].

* **Asymptotic Resolution**: 
  * Applying the Master Theorem where $a = 2$, $b = 2$, and $f(n) = O(n^2)$ yields:
  * $T(n) = O(n^2)$

* **Validation**: 
  * Reducing the branch factor to 2 ensures that the work satisfies the target **$O(n^2)$** time complexity constraint[cite: 1].
 
  ------------------------------------------------------------------------------------------------------------------------------

  For Q6
  ------

  Pseudocode for the Algorithm
  
  SelectionSort(A, n)
    for i = 1 to n - 1 do
        min_index = i
        for j = i + 1 to n do
            if A[j] < A[min_index] then
                min_index = j
            end if
        end for
        if min_index != i then
            swap A[i] with A[min_index]
        end if
    end for

  Loop Invariant

  Initialization: Before the first iteration ($i = 1$), the subarray $A[1 \dots i-1]$ is empty, which trivially satisfies the condition that it contains the smallest elements in sorted order.

  Maintenance: If the invariant holds true at the start of iteration $i$, the inner loop finds the absolute minimum element in the remaining unsorted subarray $A[i \dots n]$ and swaps it into position $A[i]$. This extends the sorted subarray to $A[1 \dots i]$ while ensuring all elements in it are smaller than or equal to those remaining in $A[i+1 \dots n]$.

  Termination: When the loop terminates at $i = n$, the subarray $A[1 \dots n-1]$ contains the smallest $n-1$ elements in sorted order, meaning the entire array $A[1 \dots n]$ is fully sorted.

  Why it runs for only the first $(n-1)$ elements

  When the outer loop completes its iteration for $i = n - 1$, the first $n - 1$ smallest elements have been successfully placed in their correct, sorted positions from index $1$ to $n - 1$. By default, the single remaining element at index $n$ must be the largest element and is automatically in its correct final position. Thus, running a separate iteration for the last element ($i = n$) is redundant.

  Worst-Case Running Time ($\Theta$-notation)

 The outer loop executes $n - 1$ times. For each iteration $i$, the inner loop scans the remaining unsorted elements, performing $(n - i)$ comparisons. Total comparisons sum up to an arithmetic progression:
                                         $$(n-1) + (n-2) + \dots + 2 + 1 = \frac{n(n-1)}{2} = \Theta(n^2)$$
  
Is the best-case running time any better?

No, the best-case running time is not better; it is also $\Theta(n^2)$.
