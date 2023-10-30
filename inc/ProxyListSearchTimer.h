#ifndef PROXY_LIST_SEARCH_TIMER_H
#define PROXY_LIST_SEARCH_TIMER_H

#include "StrategyInterfaceListSearch.h"
#include <memory>
#include <chrono>

class ProxyListSearchTimer: public StrategyIListSearch
{
    public:
        explicit ProxyListSearchTimer(std::unique_ptr<StrategyIListSearch> &&strategy = {}) : searchStrategy(std::move(strategy)){};
        int doSearchAlgorithm(const std::vector<int> &toSearch, int target) override;
        int64_t getExecutionTime();

    private:
        std::unique_ptr<StrategyIListSearch> searchStrategy;
        std::chrono::nanoseconds executionTime;
};

#endif