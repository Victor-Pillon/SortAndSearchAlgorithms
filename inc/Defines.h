#include <vector>
#include <memory>
#include <random>
#include <stdlib.h>
#include <iostream>

#include "ContextListSearch.h"
#include "ContextListSort.h"

#include "StrategyBubbleSort.h"
#include "StrategyImprovedBubbleSort.h"
#include "StrategyInsertionSort.h"
#include "StrategySelectionSort.h"
#include "StrategyMergeSort.h"
#include "StrategyQuickSort.h"
#include "StrategyHeapSort.h"

#include "StrategyBinarySearch.h"
#include "StrategyLinearSearch.h"

#include "ProxyListSearchTimer.h"
#include "ProxyListSortTimer.h"


enum Menu {
	QUANTITY = 0,
	ORDER,
	ALGORITHM
};

enum QuantityOptions {
	ONE_THOUSAND = 1,
	TEN_THOUSAND,
	ONE_HUNDREAD_THOUSAND,
	ALL_QUANTITIES,
};

enum OrderOptions {
	ORDERED = 1,
	DISORDERED,
	RANDOM,
	ALL_ORDERS,
	BACK_ORDERS
};

enum AlgorithmOptions {
	BUBBLE_SORT = 1,
	IMPROVED_BUBBLE_SORT,
	INSERTION_SORT,
	SELECTION_SORT,
	MERGE_SORT,
	QUICK_SORT,
	HEAP_SORT,
	ALL_ALGORITHMS,
	BACK_ALGORITHMS
};

ContextListSort sorterContext;
ContextListSearch searchContext;
ProxyListSearchTimer* searchProxy;
ProxyListSortTimer* sortProxy; 

std::vector<int> randomVector;
std::vector<int> orderedVector;
std::vector<int> disorderedVector;

Menu menu = Menu::QUANTITY;
int tempOption;
QuantityOptions selectedQuantity = QuantityOptions::ALL_QUANTITIES;
OrderOptions selectedOrder = OrderOptions::ALL_ORDERS;
AlgorithmOptions selectedAlgorithm = AlgorithmOptions::ALL_ALGORITHMS;