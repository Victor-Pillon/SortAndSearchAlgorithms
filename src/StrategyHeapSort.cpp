#include "StrategyHeapSort.h"

std::vector<int> StrategyHeapSort::doSortAlgorithm(std::vector<int> toSort, unsigned long long &comparisons, unsigned long long &exchanges) {
    exchanges = 0;
    comparisons = 0;
    
    std::vector<int> sortedArray = toSort;  // Create a copy of the input vector
    int n = sortedArray.size();

    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(sortedArray, n, i, comparisons, exchanges);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        exchanges += 3;
        std::swap(toSort[0], toSort[i]);
        heapify(sortedArray, i, 0, comparisons, exchanges);
    }

    return sortedArray;
}

void StrategyHeapSort::heapify(std::vector<int>& arr, int n, int root, unsigned long long &comparisons, unsigned long long &exchanges) {
    exchanges += 3;
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    comparisons++;
    if (left < n && arr[left] > arr[largest]) {
        exchanges++;
        largest = left;
    }

    comparisons++;
    if (right < n && arr[right] > arr[largest]) {
        exchanges++;
        largest = right;
    }

    comparisons++;
    if (largest != root) {
        exchanges += 3; 
        std::swap(arr[root], arr[largest]);
        heapify(arr, n, largest, comparisons, exchanges);
    }
}

