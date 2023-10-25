#include "ContextListSearch.h"

int ContextListSearch::searchVector(std::vector<int> toSearch) const
{
	if (searchStrategy) {
        return searchStrategy->doSearchAlgorithm(toSearch);
    } else {
        std::cout << "Context: Strategy isn't set" << std::endl;
        return -1;
    }
}

void ContextListSearch::setStrategy(std::unique_ptr<StrategyIListSearch> &&strategy)
{
	searchStrategy = std::move(strategy);
}
