#include "ContextListSearch.h"

int ContextListSearch::searchVector(const std::vector<int> &toSearch, int target)
{
	if (searchStrategy) {
        return searchStrategy->doSearchAlgorithm(toSearch, target);
    } else {
        std::cout << "Context: Strategy isn't set" << std::endl;
        return -1;
    }
}

void ContextListSearch::setStrategy(std::unique_ptr<StrategyIListSearch> &&strategy)
{
	searchStrategy = std::move(strategy);
}
