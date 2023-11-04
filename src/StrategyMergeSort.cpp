#include "StrategyMergeSort.h"

std::vector<int> StrategyMergeSort::doSortAlgorithm(std::vector<int> toSort, unsigned long long &comparisons, unsigned long long &exchanges) {

    exchanges = 0;
    comparisons = 0;
    
    if (toSort.size() <= 1) {
        return toSort;
    }

    // Split the input vector into two halves
    exchanges += 3;
    int middle = toSort.size() / 2;
    std::vector<int> left(toSort.begin(), toSort.begin() + middle);
    std::vector<int> right(toSort.begin() + middle, toSort.end());

    // Recursively sort the two halves
    exchanges += 2;
    left = doSortAlgorithm(left, comparisons, exchanges);
    right = doSortAlgorithm(right, comparisons, exchanges);

    // Merge the sorted halves
    return merge(left, right, comparisons, exchanges);
}

std::vector<int> StrategyMergeSort::merge(const std::vector<int>& left, const std::vector<int>& right, unsigned long long &comparisons, unsigned long long &exchanges) {
    std::vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        comparisons++;
        if (left[i] < right[j]) {
            exchanges++;
            result.push_back(left[i]);
            i++;
        } else {
            exchanges++;
            result.push_back(right[j]);
            j++;
        }
    }

    // Copy any remaining elements from the left and right vectors
    while (i < left.size()) {
        exchanges++;
        result.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        exchanges++;
        result.push_back(right[j]);
        j++;
    }

    return result;
}