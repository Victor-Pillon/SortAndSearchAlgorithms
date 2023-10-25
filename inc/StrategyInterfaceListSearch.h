#ifndef STRATEGY_INTERFACE_LIST_SEARCH_H
#define STRATEGY_INTERFACE_LIST_SEARCH_H

#include <vector>


class StrategyIListSearch
{
	public:
		virtual ~StrategyIListSearch() = default;
		virtual int doSearchAlgorithm(const std::vector<int> &toSearch, int target) const = 0;
};

#endif
