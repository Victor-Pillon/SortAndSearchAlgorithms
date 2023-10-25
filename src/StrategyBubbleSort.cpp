#include "StrategyBubbleSort.h"


std::vector<int> StrategyBubbleSort::doSortAlgorithm(std::vector<int> toSort)
{
	std::vector<int> sortedArray = toSort;  // Create a copy of the input vector
    int n = sortedArray.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (sortedArray[j] > sortedArray[j + 1]) {
                std::swap(sortedArray[j], sortedArray[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped in the inner loop, the array is already sorted.
        if (!swapped) {
            break;
        }
    }

    return sortedArray;  // Return the sorted copy
}
