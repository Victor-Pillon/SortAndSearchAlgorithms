#include "StrategyQuickSort.h"

std::vector<int> StrategyQuickSort::doSortAlgorithm(std::vector<int> toSort) {
    if (toSort.size() <= 1) {
        return toSort;
    }

    std::stack<std::pair<int, int>> stack;
    stack.push({0, toSort.size() - 1});

    while (!stack.empty()) {
        int low = stack.top().first;
        int high = stack.top().second;
        stack.pop();

        int pivotIndex = partition(toSort, low, high);

        if (low < pivotIndex - 1) {
            stack.push({low, pivotIndex - 1});
        }
        if (pivotIndex + 1 < high) {
            stack.push({pivotIndex + 1, high});
        }
    }

    return toSort;
}

int StrategyQuickSort::partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}