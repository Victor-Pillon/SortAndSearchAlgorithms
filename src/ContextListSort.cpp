#include "ContextListSort.h"

std::vector<int> ContextListSort::sortedVector(std::vector<int> toSort) const
{
	if (sorterStrategy) {
        return sorterStrategy->doSortAlgorithm(toSort);
    } else {
        std::cout << "Context: Strategy isn't set" << std::endl;
        return toSort;
    }
}

void ContextListSort::setStrategy(std::unique_ptr<StrategyIListSort> &&strategy)
{
	sorterStrategy = std::move(strategy);
}
