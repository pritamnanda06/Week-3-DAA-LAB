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

\[
\begin{array}{l}
\textbf{Algorithm } MaxMin(A, low, high)\\[2mm]

\textbf{Input: } \text{Array } A[low \ldots high]\\
\textbf{Output: } (\text{minimum},\text{maximum})\\[2mm]

\textbf{if } low = high \textbf{ then}\\
\qquad min \gets A[low]\\
\qquad max \gets A[low]\\
\qquad \textbf{return } (min,max)\\[2mm]

\textbf{else if } high = low + 1 \textbf{ then}\\
\qquad \textbf{if } A[low] < A[high] \textbf{ then}\\
\qquad\qquad min \gets A[low]\\
\qquad\qquad max \gets A[high]\\
\qquad \textbf{else}\\
\qquad\qquad min \gets A[high]\\
\qquad\qquad max \gets A[low]\\
\qquad \textbf{end if}\\
\qquad \textbf{return } (min,max)\\[2mm]

mid \gets \left\lfloor \frac{low+high}{2} \right\rfloor\\[2mm]

(min_1,max_1) \gets MaxMin(A,low,mid)\\
(min_2,max_2) \gets MaxMin(A,mid+1,high)\\[2mm]

min \gets \min(min_1,min_2)\\
max \gets \max(max_1,max_2)\\[2mm]

\textbf{return } (min,max)\\

\textbf{end if}
\end{array}
\]

### Number of Comparisons

For \(n=2\), only one comparison is required.

For \(n>2\), the array is divided into two halves. After recursively finding the minimum and maximum of both halves, two additional comparisons are required:

\[
T(n) = T(\lfloor n/2 \rfloor)
     + T(\lceil n/2 \rceil) + 2
\]

For \(n=2^k\),

\[
T(n)=2T(n/2)+2
\]

Solving the recurrence gives

\[
T(n)=\frac{3n}{2}-2
\]

Therefore,

\[
T(n) < \frac{3n}{2}
\]

Hence, the number of comparisons is bounded by

\[
\boxed{\frac{3n}{2}}
\]

which satisfies the requirement of the problem.
