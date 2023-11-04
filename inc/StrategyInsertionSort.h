#ifndef STRATEGY_INSERTION_SORT_H
#define STRATEGY_INSERTION_SORT_H

#include "StrategyInterfaceListSort.h"

class StrategyInsertionSort : public StrategyIListSort
{
	std::vector<int> doSortAlgorithm(std::vector<int> toSort, unsigned long long &comparisons, unsigned long long &exchanges) override;
};

#endif