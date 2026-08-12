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

Objective
---------
Find the maximum and minimum elements in an array $A[1 \dots n]$ using the divide and conquer approach, with a comparison bound of $\frac{3n}{2}$.

Function Signature
------------------
FindMaxMin(A, low, high, max, min)

Steps
-----

1. Base Case 1 (Single Element)
   
 If $\text{low} == \text{high}$, then:$\text{max} = A[\text{low}]
$$\text{min} = A[\text{low}]$(Comparisons = 0)

2. Base Case 2
3. 
   (Two Elements)If $\text{high} == \text{low} + 1$, then:
   If $A[\text{low}] > A[\text{high}]$, then $\text{max} = A[\text{low}]$, $\text{min} = A[\text{high}]$
   Else, $\text{max} = A[\text{high}]$, $\text{min} = A[\text{low}]$(Comparisons = 1)

   3. Recursive Step
   4. 
      ($n > 2$)Find the midpoint:$$\text{mid} = \lfloor(\text{low} + \text{high}) / 2\rfloor
      $$Divide and Conquer: Recursively find the max and min for both halves:
      FindMaxMin(A, low, mid, max1, min1)
      FindMaxMin(A, mid + 1, high, max2, min2)
      Combine Step: Compare the results of the two halves to find the overall maximum and minimum:
      If $\text{max1} > \text{max2}$, then $\text{max} = \text{max1}$, else $\text{max} = \text{max2}$
      If $\text{min1} < \text{min2}$, then $\text{min} = \text{min1}$, else $\text{min} = \text{min2}$(Comparisons = 2 per combination level)

      Complexity & Comparison Analysis
      
      Recurrence Relation:
      $$T(n) = 2T(n/2) + 2 \quad \text{for } n > 2
      $$Total Comparisons:
      The recurrence resolves to approximately $\frac{3n}{2} - 2$ comparisons in the worst case, which strictly satisfies the requirement of being bounded by $\frac{3n}{2}$.
