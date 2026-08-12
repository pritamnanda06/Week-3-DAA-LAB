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

Find Maximum and Minimum Using Divide and Conquer
Algorithm

Function: FindMaxMin(A, low, high, max, min)

If low == high

Set max = min = A[low].
Comparisons: 0

If high == low + 1

Compare A[low] and A[high].
Set the larger as max and the smaller as min.
Comparisons: 1

Otherwise

Find the midpoint:

𝑚
𝑖
𝑑
=
⌊
(
𝑙
𝑜
𝑤
+
ℎ
𝑖
𝑔
ℎ
)
/
2
⌋
Recursively find maximum and minimum in both halves.
Compare the two maximums to get the overall maximum.
Compare the two minimums to get the overall minimum.
Comparisons for combining: 2
Complexity

The recurrence is:

𝑇
(
𝑛
)
=
2
𝑇
(
𝑛
/
2
)
+
2

which gives:

𝑇
(
𝑛
)
=
3
𝑛
2
−
2

Therefore, the number of comparisons is bounded by:

3
𝑛
2

Time Complexity: O(n)
Space Complexity: O(log n) due to recursion.
