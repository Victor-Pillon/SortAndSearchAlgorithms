#ifndef STRATEGY_LINEAR_SEARCH_H
#define STRATEGY_LINEAR_SEARCH_H

#include "StrategyInterfaceListSearch.h"

class StrategyLinearSearch : public StrategyIListSearch
{
	int doSearchAlgorithm(const std::vector<int> &toSearch, int target) override;
};

#endif
