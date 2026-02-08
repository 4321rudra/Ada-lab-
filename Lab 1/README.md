# Lab-1




## 1. Modular Exponentiation (Power Function)
* **File:** `Lab1.1.cpp`
* **Aim:** To calculate $n^a$ (n raised to power a) efficiently using recursion.
* **Use Case:** Essential in cryptography (like RSA) for handling large numbers without overflow.
* **Algorithm:**
    1. Base Case: If power is 0, return 1.
    2. Recursive Step: Calculate $x = n^{a/2}$.
    3. If $a$ is even, return $x \times x$.
    4. If $a$ is odd, return $x \times x \times n$.
* **Time Complexity:** $O(\log n)$

---

## 2. String Permutations
* **File:** `Lab1.2.cpp`
* **Aim:** To generate all possible arrangements (permutations) of a given string.
* **Use Case:** Used in brute-force solvers (e.g., cracking passwords) and solving puzzles like N-Queens.
* **Algorithm:**
    1. Loop through the string from index `k` to `n`.
    2. Swap the current character with the character at index `k`.
    3. Recursively call the function for `k+1`.
    4. Swap back (Backtracking) to restore the original string.
* **Time Complexity:** $O(n \times n!)$

---

## 3. Tower of Hanoi
* **File:** `Lab1.3.cpp`
* **Aim:** To solve the Tower of Hanoi puzzle for $N$ disks.
* **Use Case:** A classic benchmark for testing recursive function performance and stack overhead.
* **Algorithm:**
    1. Move $n-1$ disks from Source to Helper.
    2. Move $n^{th}$ disk from Source to Destination.
    3. Move $n-1$ disks from Helper to Destination.
* **Time Complexity:** $O(2^n)$

---

## 4. Linear Search Benchmark
* **File:** `Lab1.4.cpp`
* **Aim:** To measure the actual execution time of Linear Search for varying input sizes.
* **Use Case:** Benchmarking hardware performance and understanding real-world algorithm latency.
* **Algorithm:**
    1. Fill an array with random numbers.
    2. Start a timer using `std::chrono`.
    3. Perform a linear search for a random key.
    4. Stop the timer and record the duration.
* **Time Complexity:** $O(n)$

---

## 5. Selection Sort (Recursive)
* **File:** `Lab1.5.cpp`
* **Aim:** To sort an array by repeatedly finding the minimum element recursively.
* **Use Case:** useful when memory writes are costly (minimizes swaps to $O(n)$).
* **Algorithm:**
    1. Find the minimum element in the unsorted subarray.
    2. Swap it with the first element of that subarray.
    3. Recursively call for the rest of the array.
* **Time Complexity:** $O(n^2)$

---

## 6. Bubble Sort (Recursive)
* **File:** `Lab1.6.cpp`
* **Aim:** To sort an array by swapping adjacent elements recursively.
* **Use Case:** Educational purposes for understanding sorting mechanics.
* **Algorithm:**
    1. Traverse the array and swap adjacent elements if they are out of order.
    2. This places the largest element at the end.
    3. Recursively call for the remaining $n-1$ elements.
* **Time Complexity:** $O(n^2)$

---

## 7. Horner's Rule
* **File:** `Lab1.7.cpp`
* **Aim:** To evaluate a polynomial expression with the minimum number of multiplications.
* **Use Case:** Used in numerical methods and computer graphics for fast curve calculation.
* **Algorithm:**
    1. Rewrite $a_nx^n + ... + a_0$ as $(...((a_n x + a_{n-1})x)...) + a_0$.
    2. Recursively multiply the accumulated result by $x$ and add the next coefficient.
* **Time Complexity:** $O(n)$

---

## 8. Find Missing Number
* **File:** `Lab1.8.cpp`
* **Aim:** To find a missing number in a sequence based on alternating parity (Odd/Even).
* **Use Case:** Simple data integrity checks in data streams.
* **Algorithm:**
    1. Traverse the array recursively.
    2. Check if two adjacent numbers have the same parity (e.g., both Odd).
    3. If yes, the missing number is between them.
* **Time Complexity:** $O(n)$

---

## 9. Bouncing Ball Simulation
* **File:** `Lab1.9.cpp`
* **Aim:** To simulate a bouncing ball affected by gravity and friction.
* **Use Case:** Physics engines in video games.
* **Algorithm:**
    1. Calculate potential velocity from height.
    2. Loop while velocity > threshold.
    3. Reduce height by a friction factor on every bounce.
    4. Count total bounces.
* **Time Complexity:** Simulation dependent (Iterative).

---

## 10. Truth Table Generator
* **File:** `Lab1.10.cpp`
* **Aim:** To generate all possible Truth/False combinations for $N$ variables.
* **Use Case:** Digital circuit design and logic testing.
* **Algorithm:**
    1. Start with an empty string.
    2. Recursively add "T" and recurse.
    3. Recursively add "F" and recurse.
    4. Print when string length equals $N$.
* **Time Complexity:** $O(2^n)$
---

## Lab 1.11: Find First Duplicate (Recursive)
**Aim:** To find the first occurrence of a duplicate element in an array and print its location using recursion.

**Use Case:** Used in data cleaning processes to identify redundant entries and in databases to enforce unique constraints (like Primary Keys).

**Algorithm:**
1. Define function findFirstDuplicate(arr, n, i, j).
2. Base Case 1: If i reaches n-1, print "No duplicate found" and return.
3. Base Case 2: If j reaches n, recurse for the next element: findFirstDuplicate(arr, n, i+1, i+2).
4. Check: If arr[i] == arr[j], print the duplicate value and index, then return.
5. Recursive Step: Check next neighbor: findFirstDuplicate(arr, n, i, j+1).

**Time Complexity:** O(n^2) (Equivalent to nested loops checking every pair).