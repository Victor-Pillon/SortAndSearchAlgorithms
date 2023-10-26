#ifndef STRATEGY_HEAP_SORT_H
#define STRATEGY_HEAP_SORT_H

#include "StrategyInterfaceListSort.h"
#include <iostream>

class StrategyHeapSort : public StrategyIListSort
{
    public:
	    std::vector<int> doSortAlgorithm(std::vector<int> toSort) override;
    private:
        void heapify(std::vector<int>& arr, int n, int root);
};

#endif
