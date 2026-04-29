# Week 12: Traveling Salesperson Problem (DP & Bitmasking)

This directory contains the C++ implementation for Lab 12. The focus this week is on solving the classic Traveling Salesperson Problem (TSP) using Dynamic Programming optimized with Bitmasking to track visited states efficiently.

---

## Lab 12.1: Traveling Salesperson Problem (TSP)
* **File:** `tsp.cpp`
* **Aim:** To find the absolute shortest possible route that visits every given city exactly once and returns to the starting origin city.
* **Use Case:** * Logistics, supply chain, and delivery routing (e.g., Amazon, FedEx optimizing driver routes).
    * Manufacturing (e.g., optimizing the movement of a drill over a printed circuit board).
    * DNA sequencing and astronomy (telescope scheduling).
* **Algorithm:**
    1. **State Representation (Bitmasking):** Use an integer `mask` to represent the set of visited cities using binary bits (e.g., if $n=4$, a mask of `0101` in binary means cities 0 and 2 have been visited).
    2. **Memorization Table:** Maintain a 2D table `dp[mask][pos]` to store the minimum cost to visit all remaining unvisited cities starting from the current city `pos` given the `mask` of already visited cities. Maintain a `path` table to reconstruct the route.
    3. **Base Case:** If all cities are visited (i.e., `mask == (1<<n) - 1`, meaning all bits are 1), return the distance from the current `pos` back to the starting city `0`.
    4. **Recursive Step:** Loop through all possible cities `j`.
    5. Check if city `j` is unvisited using bitwise AND: `(mask & (1<<j)) == 0`.
    6. If unvisited, calculate the cost: `dist[pos][j] + tsp(mask | (1<<j), j)`. (The bitwise OR `|` marks city `j` as visited in the next recursive call).
    7. Update `dp[mask][pos]` with the minimum cost found and record the optimal next city in `path[mask][pos]`.
    8. **Path Reconstruction:** Start from `mask = 1` and `pos = 0`, repeatedly lookup the next city in the `path` table, update the mask, and print the route until all cities are visited.
* **Time Complexity:** $O(n^2 \cdot 2^n)$ (There are $n \cdot 2^n$ unique states, and for each state, we loop through up to $n$ cities to find the minimum cost. This is a massive improvement over the brute-force $O(n!)$ approach).
* **Space Complexity:** $O(n \cdot 2^n)$ (To store the `dp` and `path` tables).