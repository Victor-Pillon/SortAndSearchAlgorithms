#ifndef LISTSORTERSTRATEGY_H
#define LISTSORTERSTRATEGY_H

#include <vector>


class StrategyIListSort
{
	public:
		virtual ~StrategyIListSort() = default;
		virtual std::vector<int> doSortAlgorithm(std::vector<int> toSort) const = 0;
};

#endif
