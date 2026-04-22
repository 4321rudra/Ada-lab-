# Week 11: All-Pairs Shortest Path (Dynamic Programming)

This directory contains the C++ implementation for Lab 11. The focus this week is on computing the shortest paths between every pair of vertices in a graph using the Floyd-Warshall algorithm, which is a prime example of bottom-up Dynamic Programming.

---

## Lab 11.1: Floyd-Warshall Algorithm
* **File:** `apsp.cpp`
* **Aim:** To find the shortest paths between all pairs of vertices in a weighted directed graph and reconstruct the optimal route between any two given nodes.
* **Use Case:** * Network routing and calculating distance matrices for map/GIS applications.
    * Analyzing network connectivity and evaluating the "center" or most critical nodes in social network analysis.
* **Algorithm:**
    1. **Initialization:** Create a `cost` matrix that initially mirrors the given adjacency matrix `A`. Create a 3D `route` array to memorize the intermediate nodes used for the shortest paths.
    2. **Iterate Intermediate Vertices ($k$):** Loop $k$ from 0 to $n-1$. This represents the intermediate node being considered for a new path.
    3. **Iterate Source ($i$) and Destination ($j$):** For every pair of nodes $(i, j)$, check if routing through node $k$ is cheaper than the currently known path.
    4. **DP Transition:** If `cost[i][k] + cost[k][j] < cost[i][j]`, update `cost[i][j]` with this new minimum cost and record $k$ in the `route` array.
    5. **Path Reconstruction:** Use a recursive function `printPath` that checks the `route` array. If an intermediate node exists, it recursively prints the path from $i$ to $k$, and then from $k$ to $j$.
* **Time Complexity:** O(V³) (Where V is the number of vertices $n$. This is due to the three nested loops for $k$, $i$, and $j$).
* **Space Complexity:** O(V³) (In this specific implementation, due to the 3D `route` matrix, though the algorithm strictly only requires O(V²) space for the cost matrix and a 2D predecessor matrix).