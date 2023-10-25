#include "StrategySelectionSort.h"


std::vector<int> StrategySelectionSort::doSortAlgorithm(std::vector<int> toSort)
{
	std::vector<int> sortedArray = toSort; // Create a copy of the input vector
    int n = sortedArray.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (sortedArray[j] < sortedArray[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(sortedArray[i], sortedArray[minIndex]);
        }
    }

    return sortedArray; // Return the sorted copy
}
