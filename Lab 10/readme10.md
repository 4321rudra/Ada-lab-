# Week 10: Dynamic Programming (Matrix Chain & Multistage Graphs)

This directory contains the C++ implementations for Lab 10. The focus is on advanced Dynamic Programming techniques, specifically solving problems that require 2D table memorization (like Matrix Chain Multiplication) and state-transition graphs.

---

## Lab 10.1: Matrix Chain Multiplication
* **File:** `matrixchainmult.cpp`
* **Aim:** To find the most efficient way to multiply a given sequence of matrices by determining the optimal parenthesization that minimizes the total number of scalar multiplications.
* **Use Case:** Computer graphics (chaining 3D transformation matrices), compiler optimization, and optimizing tensor operations in Deep Learning frameworks.
* **Algorithm:**
    1. Let `d` be the array of matrix dimensions.
    2. Create a 2D DP table `m` to store the minimum multiplication costs, and a table `s` to store the optimal split points.
    3. Initialize the main diagonal of `m` to 0 (cost of multiplying one matrix is 0).
    4. **Iterate by chain length ($L$):** Loop from length 2 up to $n$.
    5. For each length, determine the start matrix $i$ and end matrix $j$.
    6. **Find optimal split ($k$):** Loop through all possible split points $k$ between $i$ and $j-1$. Calculate the cost as: `cost = m[i][k] + m[k+1][j] + d[i-1]*d[k]*d[j]`.
    7. If this `cost` is less than the current minimum in `m[i][j]`, update `m[i][j]` and record the split point $k$ in `s[i][j]`.
    8. Recursively print the optimal parentheses using the `s` table.
* **Time Complexity:** $O(n^3)$ (Due to the three nested loops for length, start position, and split point).
* **Space Complexity:** $O(n^2)$ (For the 2D DP tables).

---

## Lab 10.2: Multistage Graph (Shortest Path)
* **File:** `multistageforward.cpp`
* **Aim:** To compute the minimum cost path from the source vertex to the sink vertex in a directed multistage graph using Dynamic Programming.
* **Use Case:** Resource allocation, supply chain routing, and discrete decision-making processes over distinct chronological stages.
* **Algorithm:**
    1. Represent the graph using an Adjacency Matrix where `INF` represents no connection.
    2. Maintain a `cost` array (minimum cost from node $i$ to the sink) and a `dest` array (the next node to visit on that optimal path).
    3. **Base Case:** Set the cost of the destination node to 0.
    4. Loop backwards from the second-to-last node ($n-2$) down to the source ($0$).
    5. For each node $i$, check all valid outgoing edges to nodes $j$. 
    6. Update `cost[i]` to be the minimum of `graph[i][j] + cost[j]`. Record the chosen $j$ in `dest[i]`.
    7. Reconstruct the shortest path by following the `dest` array from the source to the sink.
* **Time Complexity:** $O(V^2)$ where $V$ is the number of vertices.

---

## Lab 10.3: Matrix Diagonal Traversal Utility
* **File:** `printdiagonal.cpp`
* **Aim:** To traverse and print a 2D matrix in a specific diagonal pattern.
* **Use Case:** This traversal pattern is a foundational building block for DP algorithms. Problems like *Matrix Chain Multiplication* or *Optimal Binary Search Tree* require filling a 2D table diagonally because the solution to a sequence of length $L$ depends on shorter sub-sequences already computed in lower diagonals.
* **Algorithm:**
    1. Loop backwards from the last row index down to 0 (`i = n-1` to `0`).
    2. For each iteration, set a temporary row tracker.
    3. Use an inner loop to print elements, decrementing the row index and incrementing the column index to move diagonally across the grid.
* **Time Complexity:** $O(n^2)$ (As it visits a subset of the $n \times n$ matrix).