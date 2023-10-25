#ifndef PROXY_LIST_SORT_TIMER_H
#define PROXY_LIST_SORT_TIMER_H

#include "StrategyInterfaceListSort.h"
#include <memory>
#include <iostream>
#include <chrono>

class ProxyListSortTimer: public StrategyIListSort
{
    public:
        explicit ProxyListSortTimer(std::unique_ptr<StrategyIListSort> &&strategy = {}) : sortStrategy(std::move(strategy)){};
        std::vector<int> doSortAlgorithm(std::vector<int> toSort) override;
        int64_t getExecutionTime();

    private:
        std::unique_ptr<StrategyIListSort> sortStrategy;
        std::chrono::nanoseconds executionTime;
};

#endif
