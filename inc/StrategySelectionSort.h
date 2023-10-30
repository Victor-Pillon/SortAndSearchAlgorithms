#ifndef STRATEGY_SELECTION_SORT_H
#define STRATEGY_SELECTION_SORT_H

#include "StrategyInterfaceListSort.h"

class StrategySelectionSort : public StrategyIListSort
{
	std::vector<int> doSortAlgorithm(std::vector<int> toSort) override;
};

#endif
