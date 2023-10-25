#ifndef STRATEGY_INSERTION_SORT_H
#define STRATEGY_INSERTION_SORT_H

#include "StrategyInterfaceListSort.h"
#include <iostream>

class StrategyInsertionSort : public StrategyIListSort
{
	std::vector<int> doSortAlgorithm(std::vector<int> toSort) override;
};

#endif