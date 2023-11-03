#include <vector>
#include <memory>
#include <random>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include <algorithm>

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
	ALGORITHM,
	START
};

enum MenuReturns
{
	GO_NEXT = 0,
	GO_BACK,
	STAY
};

enum QuantityOptions {
	ONE_THOUSAND = 0,
	TEN_THOUSAND,
	ONE_HUNDREAD_THOUSAND,
};

enum OrderOptions {
	ORDERED = 0,
	DISORDERED,
	RANDOM,
};

enum AlgorithmOptions {
	BUBBLE_SORT = 0,
	IMPROVED_BUBBLE_SORT,
	INSERTION_SORT,
	SELECTION_SORT,
	MERGE_SORT,
	QUICK_SORT,
	HEAP_SORT,
};

std::map<QuantityOptions, std::string> quantitiesOptions = {
	{QuantityOptions::ONE_THOUSAND, "1.000"},
	{QuantityOptions::TEN_THOUSAND, "10.000"},
	{QuantityOptions::ONE_HUNDREAD_THOUSAND, "100.000"},
};

std::map<OrderOptions, std::string> ordersOptions = {
	{OrderOptions::ORDERED, "Ordered"},
	{OrderOptions::DISORDERED, "Disordered"},
	{OrderOptions::RANDOM, "Random"}
};

std::map<AlgorithmOptions, std::string> algorithmOptions = {
	{AlgorithmOptions::BUBBLE_SORT, "Bubble Sort"},
	{AlgorithmOptions::IMPROVED_BUBBLE_SORT, "Improved Bubble Sort"},
	{AlgorithmOptions::INSERTION_SORT, "Insertion Sort"},
	{AlgorithmOptions::SELECTION_SORT, "Selection Sort"},
	{AlgorithmOptions::MERGE_SORT, "Merge Sort"},
	{AlgorithmOptions::QUICK_SORT, "Quick Sort"},
	{AlgorithmOptions::HEAP_SORT, "Heap Sort"},
};

std::map<MenuReturns, std::string> menuOptions = {
	{MenuReturns::GO_NEXT, "Next"},
	{MenuReturns::GO_BACK, "Back"},
};

ContextListSort sorterContext;
ContextListSearch searchContext;
ProxyListSearchTimer* searchProxy;
ProxyListSortTimer* sortProxy; 

std::vector<int> randomVector;
std::vector<int> orderedVector;
std::vector<int> disorderedVector;

Menu currentMenu = Menu::QUANTITY;
int tempOption;
MenuReturns menuReturn;
std::vector<QuantityOptions> selectedQuantities;
std::vector<OrderOptions> selectedOrders;
std::vector<AlgorithmOptions> selectedAlgorithms;