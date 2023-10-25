#include "StrategyLinearSearch.h"

int StrategyLinearSearch::doSearchAlgorithm(const std::vector<int> &toSearch, int target)
{
	for(int i=0; i<toSearch.size(); i++)
        if(toSearch.at(i) == target) return i;
    
    return -1;  // Element not found in the array
}
