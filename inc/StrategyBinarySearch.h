#ifndef STRATEGY_BINARY_SEARCH_H
#define STRATEGY_BINARY_SEARCH_H

#include "StrategyInterfaceListSearch.h"

class StrategyBinarySearch : public StrategyIListSearch
{
	int doSearchAlgorithm(const std::vector<int> &toSearch, int target) override;
};

#endif
