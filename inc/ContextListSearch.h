#ifndef LIST_SEARCH_CONTEXT_H
#define LIST_SEARCH_CONTEXT_H

#include <iostream>
#include <memory>
#include <vector>
#include "StrategyInterfaceListSearch.h"

class ContextListSearch
{
	public:
		explicit ContextListSearch(std::unique_ptr<StrategyIListSearch> &&strategy = {}) : searchStrategy(std::move(strategy)){};
		void setStrategy(std::unique_ptr<StrategyIListSearch> &&strategy);
		int searchVector(std::vector<int> toSearch) const;
	private:
		std::unique_ptr<StrategyIListSearch> searchStrategy;
};

#endif