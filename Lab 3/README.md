# Lab-3

## Lab 3.1: Merge Sort Benchmarking
**Aim:** To analyze the time complexity of the Merge Sort algorithm by measuring its execution time for varying input sizes (1,000 to 10,000 elements).

**Use Case:**
* **External Sorting:** Used when the data to be sorted is too large to fit in memory (RAM) and must be stored on disk (e.g., database sorting).
* **Linked Lists:** It is the preferred algorithm for sorting linked lists because it can be implemented without extra space for pointers.
* **Stable Sort:** Used when the order of equal elements matters (e.g., sorting a list of people by age, then by name).

**Algorithm:**
1.  **Divide:** Calculate `mid = low + (high - low) / 2` to divide the array into two halves.
2.  **Conquer:** Recursively call `mergesort` for the first half (`low` to `mid`) and the second half (`mid+1` to `high`).
3.  **Combine:** Merge the two sorted halves into a single sorted array using a temporary array.
    * Compare elements from both halves and pick the smaller one.
    * Copy remaining elements if any.
    * Copy the sorted elements back to the original array.

**Time Complexity:**
* **Best, Average, & Worst Case:** $O(n \log n)$
* *Note:* It guarantees $O(n \log n)$ performance regardless of the input distribution, unlike Quick Sort.

---

## Lab 3.2: Quick Sort Benchmarking
**Aim:** To measure the efficiency of the Quick Sort algorithm using the last element as the pivot.

**Use Case:**
* **System Sorts:** It is often the default sorting algorithm in standard libraries (like C++ `std::sort` or Java `Arrays.sort`) due to its fast average performance and cache efficiency.
* **In-Place Sorting:** Preferred when memory space is limited, as it does not require the $O(n)$ auxiliary space that Merge Sort needs.

**Algorithm:**
1.  **Partition:** Select a **pivot** element (in this code, the last element `arr[high]`).
2.  Rearrange the array such that:
    * All elements smaller than the pivot are on the left.
    * All elements greater than the pivot are on the right.
3.  Place the pivot in its correct sorted position.
4.  **Recursion:** Recursively apply the same logic to the sub-array on the left of the pivot and the sub-array on the right of the pivot.

**Time Complexity:**
* **Average Case:** $O(n \log n)$ (Very fast in practice).
* **Worst Case:** $O(n^2)$ (Occurs when the array is already sorted or reverse sorted, and the pivot selection is poor).