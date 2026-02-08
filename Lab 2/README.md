# Lab-2


## Lab 2.1: Insertion Sort Benchmarking
**Aim:** To analyze the time complexity of the Insertion Sort algorithm by measuring its execution time for varying input sizes (1,000 to 10,000 elements).

**Use Case:** * Efficient for small data sets.
* Very fast for data that is already "substantially" sorted (adaptive).
* Used in hybrid sorting algorithms (like Timsort used in Python) for small chunks of data.

**Algorithm:**
1. Generate an array of random integers.
2. Iterate from `i = 1` to `n`:
   - Store the current element `key = arr[i]`.
   - Compare `key` with elements in the sorted sub-array (to its left).
   - Shift elements greater than `key` one position to the right.
   - Insert `key` into its correct position.
3. Measure the time taken for this process using `std::chrono`.
4. Repeat for different input sizes and calculate average duration.

**Time Complexity:** * **Worst Case:** $O(n^2)$ (Reverse sorted)
* **Best Case:** $O(n)$ (Already sorted)

---

## Lab 2.2: Binary Search Benchmarking
**Aim:** To measure the efficiency of the Binary Search algorithm on a sorted dataset.

**Use Case:** * Used in databases (SQL indexing) for fast data retrieval.
* Standard library implementations (like `std::binary_search` in C++ or `bisect` in Python).
* Debugging (Git Bisect) to find which commit introduced a bug.

**Algorithm:**
1. Generate an array of random integers.
2. **Pre-requisite:** Sort the array (using Insertion Sort) because Binary Search requires sorted data.
3. Start the Timer.
4. Set `first = 0`, `last = n-1`.
5. Loop while `first <= last`:
   - Calculate `mid = (first + last) / 2`.
   - If `arr[mid] == target`, return found.
   - If `target > arr[mid]`, search right half (`first = mid + 1`).
   - If `target < arr[mid]`, search left half (`last = mid - 1`).
6. Stop Timer and record duration.

**Time Complexity:** * **Search Time:** $O(\log n)$ (Logarithmic - extremely fast).
* **Note:** The total program time includes sorting ($O(n^2)$), but the benchmark specifically measures the search operation ($O(\log n)$).