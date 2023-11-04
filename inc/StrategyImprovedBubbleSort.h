#ifndef STRATEGY_IMPROVED_BUBBLE_SORT_H
#define STRATEGY_IMPROVED_BUBBLE_SORT_H

#include "StrategyInterfaceListSort.h"

class StrategyImprovedBubbleSort : public StrategyIListSort
{
	std::vector<int> doSortAlgorithm(std::vector<int> toSort, unsigned long long &comparisons, unsigned long long &exchanges) override;
};

#endif
