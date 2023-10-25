#include "ProxyListSortTimer.h"

std::vector<int> ProxyListSortTimer::doSortAlgorithm(std::vector<int> toSort)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> result = sortStrategy.get()->doSortAlgorithm(toSort);
    auto end = std::chrono::high_resolution_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return result;
}

int64_t ProxyListSortTimer::getExecutionTime()
{
    return executionTime.count();
}
