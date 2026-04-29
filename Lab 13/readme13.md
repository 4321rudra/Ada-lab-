# Week 13: Backtracking Algorithms

This directory contains the C++ implementations for Lab 13. The focus this week is on the Backtracking paradigm, which incrementally builds candidates to the solutions and abandons a candidate ("backtracks") as soon as it determines that the candidate cannot possibly be completed to a valid solution.

---

## Lab 13.1: Graph Coloring (m-Coloring Problem)
* **File:** `chromatic.cpp`
* **Aim:** To determine if a graph can be colored using at most `m` colors such that no two adjacent vertices share the same color, and to print one such valid configuration.
* **Use Case:** * Register allocation in compiler optimization.
    * Map coloring (e.g., coloring countries on a map so no two bordering countries share a color).
    * Scheduling problems (e.g., avoiding exam timetable clashes for students).
* **Algorithm:**
    1. Start with the first vertex (`vertex = 0`).
    2. Try assigning all colors from `1` to `m` one by one.
    3. **Constraint Check (`isSafe`):** Before assigning a color, check if any adjacent vertex (where `graph[vertex][i] == 1`) already has the same color.
    4. If safe, assign the color and recursively call the function for `vertex + 1`.
    5. **Backtrack:** If the recursive call returns false (meaning this color choice leads to a dead end down the line), unassign the color (`color[vertex] = 0`) and try the next color.
* **Time Complexity:** O(m^V) (Where $V$ is the number of vertices and $m$ is the number of colors. In the worst case, the algorithm tries every color for every vertex).

---

## Lab 13.2: Hamiltonian Cycle
* **File:** `hamiltonian.cpp`
* **Aim:** To find a Hamiltonian Cycle in a given undirected graph—a closed loop that visits every single vertex exactly once and returns to the starting vertex.
* **Use Case:** * Foundation for the Traveling Salesperson Problem (TSP).
    * Computer graphics (polygon meshing).
    * Electronic circuit design (mapping paths on a printed circuit board).
* **Algorithm:**
    1. Initialize a `path` array with `-1` to store the cycle. Start by placing vertex `0` at `path[0]`.
    2. For the current position `pos` in the path, try all possible vertices from `1` to `n-1`.
    3. **Constraint Check (`isSafe`):** Check if there is an edge between the previous vertex `path[pos-1]` and the chosen vertex `v`. Also, ensure `v` has not already been included in the path.
    4. If safe, add `v` to the path and recurse for `pos + 1`.
    5. **Base Case Validation:** If all vertices are placed (`pos == n`), check if there is a closing edge from the last vertex `path[pos-1]` back to the start vertex `path[0]`.
    6. **Backtrack:** If a choice leads to a dead end, remove the vertex (`path[pos] = -1`) and try the next option.
* **Time Complexity:** O(N!) (Where $N$ is the number of vertices. The algorithm explores all permutations of vertices in the worst case).

---

## Lab 13.3: N-Queens Problem
* **File:** `n-queens.cpp`
* **Aim:** To place $N$ chess queens on an $N \times N$ chessboard so that no two queens threaten each other (no two queens share the same row, column, or diagonal).
* **Use Case:** * A classic benchmark for constraint satisfaction algorithms and parallel computing testing.
    * Resource allocation where resources are mutually exclusive on multiple axes.
* **Algorithm:**
    1. Start placing queens row by row, beginning at `row = 0`.
    2. Loop through every column `col` in the current row.
    3. **Constraint Check (`isSafe`):** Check if placing a queen at `board[row][col]` is safe by verifying no other 'Q' exists in the same column above it, or on its upper-left and upper-right diagonals.
    4. If safe, place the queen (`board[row][col] = 'Q'`) and recurse to `row + 1`.
    5. If all rows are successfully filled, print the board.
    6. **Backtrack:** After returning from the recursive call (or if no column is safe), remove the queen (`board[row][col] = '.'`) to explore other valid configurations.
* **Time Complexity:** O(N!) (Actually slightly better than $O(N!)$ due to pruning by `isSafe`, but it explores permutations of row/column placements).

---

## Lab 13.4: Subset Sum
* **File:** `SubsetSum.cpp`
* **Aim:** To find and print all possible subsets of a given array of integers whose elements sum exactly to a specified target value.
* **Use Case:** * Cryptography (knapsack cryptosystem).
    * Exact change problems in financial systems.
    * Loading cargo into vehicles with precise weight limits.
* **Algorithm:**
    1. Traverse the array element by element.
    2. At each element, the backtracking tree branches into two paths:
        * **Include:** Add the element to the current subset and add its value to `currentSum`. Recurse to the next index.
        * **Backtrack & Exclude:** Remove the element from the subset (backtrack) and recurse to the next index without adding its value to the sum.
    3. **Base/Pruning Cases:** * If `currentSum == target`, print the subset.
        * If `index` reaches the end of the array OR `currentSum > target` (assuming positive numbers), stop exploring this branch and return.
* **Time Complexity:** O(2^N) (Where $N$ is the number of elements. The algorithm makes a binary "Include or Exclude" choice for each element).