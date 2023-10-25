#include "StrategyBinarySearch.h"

int StrategyBinarySearch::doSearchAlgorithm(const std::vector<int> &toSearch, int target) const
{
	int left = 0;
    int right = toSearch.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (toSearch[mid] == target) {
            return mid;  // Found the target element, return its index
        }

        if (toSearch[mid] < target) {
            left = mid + 1;  // The target is in the right half of the array
        } else {
            right = mid - 1;  // The target is in the left half of the array
        }
    }

    return -1;  // Element not found in the array
}
