#include "StrategyInsertionSort.h"

std::vector<int> StrategyInsertionSort::doSortAlgorithm(std::vector<int> toSort, unsigned long long &comparisons, unsigned long long &exchanges)
{
    exchanges = 0;
    comparisons = 0;

	std::vector<int> sortedArray = toSort; // Create a copy of the input vector
    int n = sortedArray.size();

    for (int i = 1; i < n; i++) {
        exchanges += 2;
        int key = sortedArray[i];
        int j = i - 1;
        
        while (j >= 0 && sortedArray[j] > key) {
            comparisons += 2;
            exchanges += 2;
            sortedArray[j + 1] = sortedArray[j];
            j--;
        }

        exchanges++;
        sortedArray[j + 1] = key;
    }

    return sortedArray; // Return the sorted copy
}
