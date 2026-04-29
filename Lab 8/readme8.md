# Week 8: Graph Traversal and Optimized Shortest Path

This directory contains the C++ implementation for Lab 8. The focus of this week is on advanced graph algorithms: detecting cycles using Depth First Search (DFS) and implementing an optimized version of Dijkstra's Algorithm to not only find shortest distances but also reconstruct the exact paths taken.

---

## Lab 8.1: Cycle Detection and Path Printing (Dijkstra's)
* **File:** `cycledetectNdPrintPath.cpp`
* **Aim:** To detect if an undirected graph contains a cycle using DFS, and to compute and print the exact shortest path from a source node to all other nodes using an optimized Dijkstra's algorithm.
* **Use Case:** * **Cycle Detection:** Used in network topology to prevent routing loops, and in operating systems to detect deadlocks.
    * **Path Printing:** Used in GPS navigation systems where knowing the total distance isn't enough; the user needs the exact turn-by-turn route (reconstructed via the `parent` array).
* **Algorithm (Cycle Detection - DFS):**
    1. Maintain a `visited` boolean array.
    2. Start a DFS traversal. For the current node, iterate through all its neighbors.
    3. If a neighbor is not visited, recursively call DFS and pass the current node as the `parent`.
    4. If a neighbor is already `visited` and is **not** the `parent` of the current node, a back-edge exists, meaning a cycle is detected.
* **Algorithm (Shortest Path - Dijkstra's):**
    1. Represent the graph using an Adjacency List.
    2. Maintain a `dist` array (initialized to Infinity) and a `parent` array (initialized to -1). Set the distance of the source node to 0.
    3. Use a Priority Queue (Min-Heap) to continually extract the node with the smallest known distance.
    4. **Relaxation:** For the extracted node, check all its neighbors. If `dist[node] + weight < dist[neighbor]`, update `dist[neighbor]`, set `parent[neighbor] = node`, and push the neighbor into the queue.
    5. **Path Reconstruction:** Use a recursive function to backtrack through the `parent` array from the destination node back to the source to print the exact path.
* **Time Complexity:** * **Cycle Detection:** O(V + E) (Where V is vertices and E is edges, as DFS visits every vertex and edge once).
    * **Shortest Path:** O(E log V) (The use of a Min-Heap priority queue makes extracting the minimum distance extremely fast).
* **Space Complexity:** O(V + E) for storing the graph as an adjacency list, plus O(V) for the distance, parent, and priority queue structures.