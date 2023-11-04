#include "StrategyImprovedBubbleSort.h"


std::vector<int> StrategyImprovedBubbleSort::doSortAlgorithm(std::vector<int> toSort, unsigned long long &comparisons, unsigned long long &exchanges)
{   
    exchanges = 0;
    comparisons = 0;

	std::vector<int> sortedArray = toSort;  // Create a copy of the input vector
    int n = sortedArray.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons ++;
            if (sortedArray[j] > sortedArray[j + 1]) {
                exchanges += 4;
                std::swap(sortedArray[j], sortedArray[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped in the inner loop, the array is already sorted.
        comparisons++;
        if (!swapped) {
            break;
        }
    }

    return sortedArray;  // Return the sorted copy
}
