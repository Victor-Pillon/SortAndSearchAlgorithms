#include "StrategySelectionSort.h"


std::vector<int> StrategySelectionSort::doSortAlgorithm(std::vector<int> toSort, unsigned long long &comparisons, unsigned long long &exchanges)
{
	std::vector<int> sortedArray = toSort; // Create a copy of the input vector
    int n = sortedArray.size();

    for (int i = 0; i < n - 1; i++) {
        exchanges++;
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (sortedArray[j] < sortedArray[minIndex]) {
                exchanges++;
                minIndex = j;
            }
        }
        comparisons++;
        if (minIndex != i) {
            exchanges += 3;
            std::swap(sortedArray[i], sortedArray[minIndex]);
        }
    }

    return sortedArray; // Return the sorted copy
}
