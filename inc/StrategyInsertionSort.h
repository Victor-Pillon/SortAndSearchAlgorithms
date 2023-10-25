#ifndef INSERTION_SORT_STRATEGY_H
#define INSERTION_SORT_STRATEGY_H

#include "StrategyInterfaceListSort.h"
#include <iostream>

class StrategyInsertionSort : public StrategyIListSort
{
	std::vector<int> doSortAlgorithm(std::vector<int> toSort) const override;
};

#endif