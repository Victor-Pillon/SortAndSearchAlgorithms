#ifndef STRATEGY_IMPROVED_BUBBLE_SORT_H
#define STRATEGY_IMPROVED_BUBBLE_SORT_H

#include "StrategyInterfaceListSort.h"

class StrategyImprovedBubbleSort : public StrategyIListSort
{
	std::vector<int> doSortAlgorithm(std::vector<int> toSort) override;
};

#endif
