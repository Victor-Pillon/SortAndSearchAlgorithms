#include "StrategyQuickSort.h"

std::vector<int> StrategyQuickSort::doSortAlgorithm(std::vector<int> toSort) {
    if (toSort.size() <= 1) {
        return toSort;
    }

    std::stack<std::pair<int, int>> stack;
    exchanges++;
    stack.push({0, toSort.size() - 1});

    while (!stack.empty()) {
        exchanges += 4;
        int low = stack.top().first;
        int high = stack.top().second;
        stack.pop();
        int pivotIndex = partition(toSort, low, high);

        comparisons++;
        if (low < pivotIndex - 1) {
            exchanges++;
            stack.push({low, pivotIndex - 1});
        }

        comparisons++;
        if (pivotIndex + 1 < high) {
            exchanges++;
            stack.push({pivotIndex + 1, high});
        }
    }

    return toSort;
}

int StrategyQuickSort::partition(std::vector<int>& arr, int low, int high) {
    exchanges += 2;
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            exchanges += 3;
            std::swap(arr[i], arr[j]);
        }
    }

    exchanges += 3;
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}