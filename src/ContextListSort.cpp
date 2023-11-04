#include "ContextListSort.h"

std::vector<int> ContextListSort::sortedVector(std::vector<int> toSort, unsigned long long &comparisons, unsigned long long &exchanges) const
{
	if (sorterStrategy) {
        return sorterStrategy->doSortAlgorithm(toSort, comparisons, exchanges);
    } else {
        std::cout << "Context: Strategy isn't set" << std::endl;
        return toSort;
    }
}

void ContextListSort::setStrategy(std::unique_ptr<StrategyIListSort> &&strategy)
{
	sorterStrategy = std::move(strategy);
}
