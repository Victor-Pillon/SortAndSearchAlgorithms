#ifndef STRATEGY_INTERFACE_LIST_SEARCH_H
#define STRATEGY_INTERFACE_LIST_SEARCH_H

#include <vector>


class StrategyIListSearch
{
	public:
		virtual ~StrategyIListSearch() = default;
		virtual int doSearchAlgorithm(std::vector<int> toSearch) const = 0;
};

#endif
