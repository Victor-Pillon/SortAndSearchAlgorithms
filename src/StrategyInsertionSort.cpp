#include "StrategyInsertionSort.h"

std::vector<int> StrategyInsertionSort::doSortAlgorithm(std::vector<int> toSort) const
{
	std::vector<int> sortedArray = toSort; // Create a copy of the input vector
    int n = sortedArray.size();

    for (int i = 1; i < n; i++) {
        int key = sortedArray[i];
        int j = i - 1;

        while (j >= 0 && sortedArray[j] > key) {
            sortedArray[j + 1] = sortedArray[j];
            j--;
        }

        sortedArray[j + 1] = key;
    }

    return sortedArray; // Return the sorted copy
}
