#ifndef STRATEGY_QUICK_SORT_H
#define STRATEGY_QUICK_SORT_H

#include "StrategyInterfaceListSort.h"
#include <iostream>
#include <stack>

class StrategyQuickSort : public StrategyIListSort
{
    public:
	    std::vector<int> doSortAlgorithm(std::vector<int> toSort) override;
    private:
        int partition(std::vector<int>& arr, int low, int high);
};

#endif
