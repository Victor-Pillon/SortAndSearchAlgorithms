#ifndef LIST_SEARCH_STRATEGY_H
#define LIST_SEARCH_STRATEGY_H

#include <vector>


class StrategyIListSearch
{
	public:
		virtual ~StrategyIListSearch() = default;
		virtual int doSearchAlgorithm(std::vector<int> toSearch) const = 0;
};

#endif
