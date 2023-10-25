#ifndef SELECTION_SORT_STRATEGY_H
#define SELECTION_SORT_STRATEGY_H

#include "StrategyInterfaceListSort.h"
#include <iostream>

class StrategySelectionSort : public StrategyIListSort
{
	std::vector<int> doSortAlgorithm(std::vector<int> toSort) const override;
};

#endif
