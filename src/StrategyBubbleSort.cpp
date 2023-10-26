#include "StrategyBubbleSort.h"


std::vector<int> StrategyBubbleSort::doSortAlgorithm(std::vector<int> toSort)
{
	std::vector<int> sortedArray = toSort;  // Create a copy of the input vector
    int n = sortedArray.size();

    for (int i = 0; i < n - 1; i++) 
        for (int j = 0; j < n - i - 1; j++) 
            if (sortedArray[j] > sortedArray[j + 1]) 
                std::swap(sortedArray[j], sortedArray[j + 1]);

    return sortedArray;  // Return the sorted copy
}
