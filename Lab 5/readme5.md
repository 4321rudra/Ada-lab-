# Week 5: Greedy Algorithms and Divide & Conquer

This directory contains the C++ implementations for Lab 5. The focus of this week is on solving optimization problems using the Greedy approach and reducing time complexity using the Divide and Conquer strategy.

---

## Lab 5.1: Fractional Knapsack (Greedy Approach)
* **File:** `knapsack.cpp`
* **Aim:** To maximize the total profit of items placed in a knapsack of limited capacity. The program compares three greedy strategies: sorting by profit/weight ratio, sorting by maximum profit, and sorting by minimum weight.
* **Use Case:** Resource allocation, financial portfolio optimization, and cargo loading where items can be broken down into smaller fractions (unlike the 0/1 Knapsack problem).
* **Algorithm:**
    1. Calculate the profit-to-weight ratio for all items.
    2. Sort the items in descending order based on this ratio.
    3. Initialize total profit to 0 and remaining capacity to the maximum capacity.
    4. Loop through the sorted items:
       - If the item's weight is less than or equal to the remaining capacity, add the whole item and update profit/capacity.
       - If the item's weight is greater, take a fraction of the item that exactly fills the remaining capacity, add the fractional profit, and break the loop.
* **Time Complexity:** O(n log n) (The dominant operation is sorting the array of items).

---

## Lab 5.2: Min-Max using Divide and Conquer
* **File:** `MinnMax.cpp`
* **Aim:** To find the minimum and maximum elements in an array simultaneously using the Divide and Conquer strategy, minimizing the total number of comparisons.
* **Use Case:** Useful in computer graphics (finding bounding boxes), statistical analysis, and systems where memory reads/comparisons are computationally expensive.
* **Algorithm:**
    1. **Base Cases:** - If the array has 1 element, min and max are that element.
       - If the array has 2 elements, compare them once to set min and max.
    2. **Divide:** Split the array into two halves at the middle index.
    3. **Conquer:** Recursively find the min and max of the left half and the right half.
    4. **Combine:** Compare the two minimums to find the absolute minimum, and the two maximums to find the absolute maximum.
* **Time Complexity:** O(n). Specifically, it takes exactly (3n/2 - 2) comparisons, which is mathematically more efficient than the 2n comparisons required by a standard linear scan.

---

## Lab 5.3: Strassen's Matrix Multiplication
* **File:** `strassenmul.cpp`
* **Aim:** To multiply two square matrices efficiently using Strassen's Divide and Conquer algorithm.
* **Use Case:** High-performance computing, deep learning convolution layers, and scientific simulations where massive multi-dimensional arrays need to be multiplied quickly.
* **Algorithm:**
    1. Pad the matrices with zeros if their dimension N is not a power of 2 (or if N is odd).
    2. **Base Case:** If the matrices are 2x2, perform Strassen's 7 specific multiplications (M1 to M7) instead of the standard 8.
    3. **Divide:** Split the N x N matrices into four (N/2 x N/2) sub-matrices.
    4. **Conquer:** Recursively compute the 7 intermediate matrices (M1 through M7) using specific combinations of additions and subtractions of the sub-matrices.
    5. **Combine:** Add and subtract the M matrices to form the 4 quadrants of the final result matrix C.
* **Time Complexity:** O(n^2.81) (This is significantly faster than the traditional O(n^3) matrix multiplication for very large values of n).