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

\documentclass{article}
\usepackage{amsmath}
\usepackage{amssymb}
\usepackage{geometry}
\geometry{margin=1in}

\begin{document}

\section*{Algorithm: Divide and Conquer Max and Min}

\textbf{Objective:} Find the maximum and minimum elements in an array $A[1 \dots n]$ using the divide and conquer approach, with a comparison bound of $\frac{3n}{2}$.  

\textbf{Function Signature:}
\[ \text{FindMaxMin}(A, \text{low}, \text{high}, \text{max}, \text{min}) \]

\subsection*{Steps}

\begin{enumerate}
    \item \textbf{Base Case 1 (Single Element):} \\
    If $\text{low} == \text{high}$, then:
    \begin{align*}
    \text{max} &= A[\text{low}] \\
    \text{min} &= A[\text{low}]
    \end{align*}
    (Comparisons $= 0$)

    \item \textbf{Base Case 2 (Two Elements):} \\
    If $\text{high} == \text{low} + 1$, then:
    \begin{itemize}
        \item If $A[\text{low}] > A[\text{high}]$, then $\text{max} = A[\text{low}]$, $\text{min} = A[\text{high}]$
        \item Else, $\text{max} = A[\text{high}]$, $\text{min} = A[\text{low}]$
    \end{itemize}
    (Comparisons $= 1$)

    \item \textbf{Recursive Step ($n > 2$):}
    \begin{enumerate}
        \item \textbf{Find the midpoint:}
        \[ \text{mid} = \lfloor(\text{low} + \text{high}) / 2\rfloor \]
        \item \textbf{Divide the array into two halves and recursively find the max and min for both halves:}
        \begin{align*}
        &\text{Call FindMaxMin}(A, \text{low}, \text{mid}, \text{max1}, \text{min1}) \\
        &\text{Call FindMaxMin}(A, \text{mid} + 1, \text{high}, \text{max2}, \text{min2})
        \end{align*}
        \item \textbf{Combine Step:} Compare the results of the two halves to find the overall maximum and minimum:
        \begin{align*}
        &\text{If } \text{max1} > \text{max2}, \text{ then } \text{max} = \text{max1}, \text{ else } \text{max} = \text{max2} \\
        &\text{If } \text{min1} < \text{min2}, \text{ then } \text{min} = \text{min1}, \text{ else } \text{min} = \text{min2}
        \end{align*}
        (Comparisons $= 2$ per combination level)
    \end{enumerate}
\end{enumerate}

\section*{Complexity \& Comparison Analysis}

\textbf{Recurrence Relation:}
\[ T(n) = 2T(n/2) + 2 \quad \text{for } n > 2 \]

\textbf{Total Comparisons:}
The recurrence resolves to approximately $\frac{3n}{2} - 2$ comparisons in the worst case, which strictly satisfies the requirement of being bounded by $\frac{3n}{2}$.

\end{document}
