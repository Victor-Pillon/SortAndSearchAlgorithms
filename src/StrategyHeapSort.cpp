#include "StrategyHeapSort.h"

std::vector<int> StrategyHeapSort::doSortAlgorithm(std::vector<int> toSort) {
    int n = toSort.size();

    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(toSort, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        std::swap(toSort[0], toSort[i]);
        heapify(toSort, i, 0);
    }

    return toSort;
}

void StrategyHeapSort::heapify(std::vector<int>& arr, int n, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        std::swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}

