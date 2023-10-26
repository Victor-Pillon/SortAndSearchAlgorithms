#include "StrategyMergeSort.h"

std::vector<int> StrategyMergeSort::doSortAlgorithm(std::vector<int> toSort) {
    if (toSort.size() <= 1) {
        return toSort;
    }

    // Split the input vector into two halves
    int middle = toSort.size() / 2;
    std::vector<int> left(toSort.begin(), toSort.begin() + middle);
    std::vector<int> right(toSort.begin() + middle, toSort.end());

    // Recursively sort the two halves
    left = doSortAlgorithm(left);
    right = doSortAlgorithm(right);

    // Merge the sorted halves
    return merge(left, right);
}

std::vector<int> StrategyMergeSort::merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    // Copy any remaining elements from the left and right vectors
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}