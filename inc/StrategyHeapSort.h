#ifndef STRATEGY_HEAP_SORT_H
#define STRATEGY_HEAP_SORT_H

#include "StrategyInterfaceListSort.h"

class StrategyHeapSort : public StrategyIListSort
{
    public:
	    std::vector<int> doSortAlgorithm(std::vector<int> toSort, unsigned long long &comparisons, unsigned long long &exchanges) override;
    private:
        void heapify(std::vector<int>& arr, int n, int root, unsigned long long &comparisons, unsigned long long &exchanges);
};

#endif
