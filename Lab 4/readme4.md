# Week 4: Selection Algorithms

This directory contains the C++ implementation for Lab 4. The focus is on using the Quickselect algorithm to efficiently find specific order statistics (like the Kth smallest element) without needing to sort the entire dataset.

---

## Lab 4.1: Find the Kth Smallest Element (Quickselect)
**Aim:** To find the $K^{th}$ smallest element in an unsorted array using the Quickselect algorithm (which is based on the Quick Sort partitioning logic).

**Use Case:** * Highly useful in statistics to find the median, percentiles, or top-K elements in massive datasets. 
* It is much faster than sorting the entire array first (which takes O(n log n) time) when you only care about finding one specific element.

**Algorithm:**
1. **Partitioning:** Choose a pivot element (in this implementation, the last element).
2. Rearrange the array so that all elements smaller than the pivot are on the left, and all elements greater are on the right. 
3. **Check Position:** Let the final index of the pivot be `pos`.
   - If `pos` is exactly `k - 1`, the pivot is the $K^{th}$ smallest element. We are done!
   - If `pos > k - 1`, the element we are looking for must be in the left sub-array. Recursively search the left side.
   - If `pos < k - 1`, the element is in the right sub-array. Recursively search the right side (adjusting the value of $K$ relative to the new sub-array).

**Time Complexity:**
* **Average Case:** O(n) (We only recurse into one half of the array, so the work halves each time: $n + n/2 + n/4... \approx 2n$).
* **Worst Case:** O(n²) (Occurs if the array is already sorted and the pivot is consistently the maximum or minimum element, though this can be avoided by picking a random pivot).