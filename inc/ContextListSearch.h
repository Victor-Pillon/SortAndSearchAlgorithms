#ifndef CONTEXT_LIST_SEARCH_H
#define CONTEXT_LIST_SEARCH_H

#include <iostream>
#include <memory>
#include <vector>
#include "StrategyInterfaceListSearch.h"

class ContextListSearch
{
	public:
		explicit ContextListSearch(std::unique_ptr<StrategyIListSearch> &&strategy = {}) : searchStrategy(std::move(strategy)){};
		void setStrategy(std::unique_ptr<StrategyIListSearch> &&strategy);
		int searchVector(const std::vector<int> &toSearch, int target) const;
	private:
		std::unique_ptr<StrategyIListSearch> searchStrategy;
};

#endif