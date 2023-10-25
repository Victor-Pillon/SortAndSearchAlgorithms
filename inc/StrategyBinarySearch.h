#ifndef STRATEGY_BINARY_SEARCH_H
#define STRATEGY_BINARY_SEARCH_H

#include "StrategyInterfaceListSearch.h"
#include <iostream>

class StrategyBinarySearch : public StrategyIListSearch
{
	int doSearchAlgorithm(const std::vector<int> &toSearch, int target) const override;
};

#endif
