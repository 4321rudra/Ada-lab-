# Week 7: Minimum Spanning Tree (MST) Algorithms

This directory contains the C++ implementations for Lab 7. The focus of this week is on finding the Minimum Spanning Tree of a connected, undirected graph using Greedy Algorithms. A Minimum Spanning Tree connects all vertices in a graph with the minimum possible total edge weight, without forming any cycles.

---

## Lab 7.1: Kruskal's Algorithm
* **File:** `kruskal.cpp`
* **Aim:** To find the Minimum Spanning Tree of a graph by progressively adding the lightest edges, provided they do not form a cycle.
* **Use Case:** * Network design (e.g., laying out electrical wiring, telecommunication lines, or LANs with the least amount of cable).
    * Best suited for **sparse graphs** (graphs with fewer edges).
* **Algorithm:**
    1. Represent the graph as a list of edges.
    2. **Sort** all edges in ascending order based on their weights.
    3. Initialize a **Disjoint Set (Union-Find)** data structure to keep track of the connected components and detect cycles. (This implementation optimizes it using *Path Compression* and *Union by Rank*).
    4. Iterate through the sorted edges:
       - If the current edge connects two different components (i.e., `find(u) != find(v)`), it does not form a cycle. Include it in the MST and `unite` the two components.
       - If it connects vertices in the same component, discard it.
    5. Repeat until all vertices are connected.
* **Time Complexity:** O(E log E) or O(E log V) (The dominant operation is sorting the edges. The Disjoint Set operations take near-constant time, amortized O(α(V))).

---

## Lab 7.2: Prim's Algorithm
* **File:** `prims.cpp`
* **Aim:** To find the Minimum Spanning Tree of a graph by growing a single tree from a starting vertex, adding the cheapest possible connection from the tree to an unvisited vertex at each step.
* **Use Case:** * Also used in network design and routing protocols. 
    * Best suited for **dense graphs** (graphs with a large number of edges) because it relies on vertices rather than sorting all edges.
* **Algorithm:**
    1. Represent the graph using an **Adjacency List**.
    2. Maintain a `key` array (to store the minimum weight to reach a vertex), a `parent` array (to store the MST structure), and a `inMST` boolean array (to track included vertices).
    3. Initialize all keys to Infinity (`INF`), except the starting vertex (key = 0).
    4. Use a **Priority Queue (Min-Heap)** to efficiently fetch the vertex with the minimum key value.
    5. Loop until the Priority Queue is empty:
       - Extract the minimum vertex `u` and mark it as included in the MST.
       - Iterate through all adjacent vertices `v` of `u`.
       - If `v` is not in the MST and the edge weight `u-v` is smaller than the current `key[v]`, update `key[v]`, set `parent[v] = u`, and push `v` into the Priority Queue.
* **Time Complexity:** O(E log V) (Using an Adjacency List and a Min-Heap Priority Queue makes the extraction and updating steps highly efficient).