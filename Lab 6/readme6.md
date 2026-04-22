# Week 6: Greedy Algorithms (Scheduling and Shortest Path)

This directory contains the C++ implementations for Lab 6. This week focuses on the Greedy strategy, making the locally optimal choice at each stage with the hope of finding a global optimum.

---

## Lab 6.1: Activity Selection Problem
* **File:** `activityselection.cpp`
* **Aim:** To find the maximum number of activities that can be performed by a single person or machine, given their start and finish times, assuming only one activity can be worked on at a time.
* **Use Case:** Resource scheduling systems, such as booking conference rooms without overlaps, CPU task scheduling, or manufacturing machine time allocation.
* **Algorithm:**
    1. Pair the start and finish times for each activity.
    2. Sort the activities in ascending order based strictly on their **finish times**.
    3. Select the first activity from the sorted list and mark its finish time.
    4. Iterate through the remaining sorted activities:
       - If the start time of the current activity is greater than or equal to the finish time of the previously selected activity, select it and update the last finish time.
* **Time Complexity:** O(n log n) (The dominant operation is the sorting step. The subsequent linear scan to select activities only takes O(n)).

---

## Lab 6.2: Dijkstra's Single Source Shortest Path
* **File:** `djikstra.cpp`
* **Aim:** To find the shortest path from a given source vertex to all other vertices in a weighted graph (with non-negative weights).
* **Use Case:** Used heavily in GPS navigation systems (like Google Maps) to find the fastest route between cities, and in computer networks (like OSPF routing protocols) to route data packets efficiently.
* **Algorithm:**
    1. Create a `dist` array initialized to Infinity (`INF`) for all vertices except the source, which is set to `0`.
    2. Create a `visited` boolean array to keep track of processed vertices.
    3. Loop `V-1` times (where V is the number of vertices):
       - Find the unvisited vertex with the minimum distance value.
       - Mark this minimum vertex as `visited`.
       - Relax the edges: Check all adjacent vertices of this newly visited vertex. If an unvisited adjacent vertex has a distance greater than the current vertex's distance + edge weight, update its distance to this new, shorter value.
    4. Print the final `dist` array containing the shortest distances.
* **Time Complexity:** O(V^2) where V is the number of vertices. (Note: This specific implementation uses an adjacency matrix and a linear search for the minimum element. It can be optimized to O(E log V) in the future using an adjacency list and a priority queue).