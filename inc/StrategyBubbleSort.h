#ifndef BUBBLE_SORT_STRATEGY_H
#define BUBBLE_SORT_STRATEGY_H

#include "StrategyInterfaceListSort.h"
#include <iostream>

class StrategyBubbleSort : public StrategyIListSort
{
	std::vector<int> doSortAlgorithm(std::vector<int> toSort) const override;
};

#endif
