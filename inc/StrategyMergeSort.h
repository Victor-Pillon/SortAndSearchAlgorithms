#ifndef STRATEGY_MERGE_SORT_H
#define STRATEGY_MERGE_SORT_H

#include "StrategyInterfaceListSort.h"

class StrategyMergeSort : public StrategyIListSort
{
    public:
	    std::vector<int> doSortAlgorithm(std::vector<int> toSort) override;
    private:
        std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right);
} ;

#endif
