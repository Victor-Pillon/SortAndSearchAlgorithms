#include <iostream>
#include <vector>
#include <memory>
#include "ContextListSearch.h"
#include "ContextListSort.h"
#include "StrategyBubbleSort.h"
#include "StrategyInsertionSort.h"
#include "StrategySelectionSort.h"


int main(int argc, char** argv) {
	//ListSorterContext sorterContext(std::unique_ptr<ListSorterStrategy>(new BubbleSortStrategy()));
	ContextListSort sorterContext;
	std::vector<int> testVec;
	testVec.push_back(10);
	testVec.push_back(9);
	testVec.push_back(8);
	testVec.push_back(7);
	testVec.push_back(6);
	testVec.push_back(5);
	
	for (auto &&i : testVec)
	{
		std::cout << i << std::endl;
	}

	std::cout <<std::endl;
	
	sorterContext.setStrategy(std::unique_ptr<StrategyIListSort>(new StrategyInsertionSort()));
	
	for (auto &&i : sorterContext.sortedVector(testVec))
	{
		std::cout << i << std::endl;
	}
	
}
