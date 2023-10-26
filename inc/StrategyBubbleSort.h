#ifndef STRATEGY_BUBBLE_SORT_H
#define STRATEGY_BUBBLE_SORT_H

#include "StrategyInterfaceListSort.h"
#include <iostream>

class StrategyBubbleSort : public StrategyIListSort
{
	std::vector<int> doSortAlgorithm(std::vector<int> toSort) override;
};

#endif