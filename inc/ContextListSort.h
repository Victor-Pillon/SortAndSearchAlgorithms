#ifndef CONTEXT_LIST_SORT_H
#define CONTEXT_LIST_SORT_H

#include <iostream>
#include <memory>
#include <vector>
#include "StrategyInterfaceListSort.h"

class ContextListSort
{
	public:
		explicit ContextListSort(std::unique_ptr<StrategyIListSort> &&strategy = {}) : sorterStrategy(std::move(strategy)){};
		void setStrategy(std::unique_ptr<StrategyIListSort> &&strategy);
		std::vector<int> sortedVector(std::vector<int> toSort) const;
	private:
		std::unique_ptr<StrategyIListSort> sorterStrategy;
};

#endif

