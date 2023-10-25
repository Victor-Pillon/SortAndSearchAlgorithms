#ifndef STRATEGY_INTERFACE_LIST_SORTER_H
#define STRATEGY_INTERFACE_LIST_SORTER_H

#include <vector>


class StrategyIListSort
{
	public:
		virtual ~StrategyIListSort() = default;
		virtual std::vector<int> doSortAlgorithm(std::vector<int> toSort) const = 0;
};

#endif
