# Week 9: Dynamic Programming

This directory contains the C++ implementation for Lab 9. The focus this week is on Dynamic Programming, a method for solving complex problems by breaking them down into simpler, overlapping subproblems and storing their solutions.

---

## Lab 9.1: Multistage Graph Shortest Path
* **File:** `multistagebackward.cpp`
* **Aim:** To find the minimum cost path from a source vertex to a destination vertex in a multistage directed graph using Dynamic Programming.
* **Use Case:** * Resource allocation where decisions are made in distinct phases.
    * Supply chain optimization (routing goods through various transit hubs).
    * Finding the most cost-effective sequence of operations in manufacturing.
* **Algorithm:**
    1. Represent the graph using an Adjacency Matrix where `graph[i][j]` is the edge weight from node `i` to node `j`.
    2. Initialize a `cost` array to store the minimum cost from each node to the destination, and a `path` array to track the optimal route. Set them to Infinity (`INF`) and `-1` respectively.
    3. **Base Case:** Set the cost of the destination node (`n-1`) to `0`.
    4. **Iterate Backwards:** Loop from the second-to-last node (`n-2`) down to the source node (`0`).
    5. For each node `i`, check all possible outgoing edges to subsequent nodes `j`.
    6. **DP Transition:** Update `cost[i]` to the minimum of `(graph[i][j] + cost[j])` across all valid connections. Store the winning `j` in `path[i]`.
    7. Once the loop finishes, `cost[0]` holds the absolute minimum cost. Print the path by tracing the `path` array from `0` to the destination.
* **Time Complexity:** $O(V^2)$ (Where $V$ is the number of vertices. The nested loops iterate through the adjacency matrix to check all possible vertex pairs). 
* **Space Complexity:** $O(V^2)$ for the adjacency matrix, plus $O(V)$ for the `cost` and `path` arrays.