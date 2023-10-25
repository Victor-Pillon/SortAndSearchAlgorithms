#include "ProxyListSearchTimer.h"
#include <thread>

int ProxyListSearchTimer::doSearchAlgorithm(const std::vector<int> &toSearch, int target)
{
    auto start = std::chrono::high_resolution_clock::now();
    int result = searchStrategy.get()->doSearchAlgorithm(toSearch, target);
    auto end = std::chrono::high_resolution_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return result;
}

int64_t ProxyListSearchTimer::getExecutionTime()
{
    return executionTime.count();
}
