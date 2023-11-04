#ifndef STRATEGY_QUICK_SORT_H
#define STRATEGY_QUICK_SORT_H

#include "StrategyInterfaceListSort.h"
#include <stack>

class StrategyQuickSort : public StrategyIListSort
{
    public:
	    std::vector<int> doSortAlgorithm(std::vector<int> toSort, unsigned long long &comparisons, unsigned long long &exchanges) override;
    private:
        int partition(std::vector<int>& arr, int low, int high, unsigned long long &comparisons, unsigned long long &exchanges);
};

#endif
