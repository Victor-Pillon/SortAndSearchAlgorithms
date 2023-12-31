#include "StrategyBubbleSort.h"


std::vector<int> StrategyBubbleSort::doSortAlgorithm(std::vector<int> toSort, unsigned long long &comparisons, unsigned long long &exchanges)
{
    comparisons = 0;
    exchanges = 0;

	std::vector<int> sortedArray = toSort;  // Create a copy of the input vector
    int n = sortedArray.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            comparisons++;
            if (sortedArray[j] > sortedArray[j + 1]){
                exchanges += 3;
                std::swap(sortedArray[j], sortedArray[j + 1]);
            }
        }
    }

    return sortedArray;  // Return the sorted copy
}
