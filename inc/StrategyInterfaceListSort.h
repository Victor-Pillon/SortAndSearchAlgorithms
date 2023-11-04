#ifndef STRATEGY_INTERFACE_LIST_SORTER_H
#define STRATEGY_INTERFACE_LIST_SORTER_H

#include <vector>

class StrategyIListSort
{
	public:
		virtual ~StrategyIListSort() = default;
		virtual std::vector<int> doSortAlgorithm(std::vector<int> toSort, unsigned long long &comparisons, unsigned long long &exchanges) = 0;
};

#endif
