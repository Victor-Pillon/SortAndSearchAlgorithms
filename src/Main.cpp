#include <iostream>
#include <vector>
#include <memory>
#include "ContextListSearch.h"
#include "ContextListSort.h"
#include "StrategyBubbleSort.h"
#include "StrategyInsertionSort.h"
#include "StrategySelectionSort.h"
#include "StrategyBinarySearch.h"


void printVector(std::vector<int> vec)
{
	for (int i=0; i<vec.size(); i++)
	{
		std::cout << "positon: " << i << " | " << "value: " << vec.at(i) << std::endl;
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) {
	//ListSorterContext sorterContext(std::unique_ptr<ListSorterStrategy>(new BubbleSortStrategy()));
	ContextListSort sorterContext;
	ContextListSearch searchContext;

	std::vector<int> testVec = {10, 9, 8, 7, 6, 5};
	printVector(testVec);
	
	sorterContext.setStrategy(std::unique_ptr<StrategyIListSort>(new StrategyInsertionSort()));
	testVec = sorterContext.sortedVector(testVec);
	printVector(testVec);

	searchContext.setStrategy(std::unique_ptr<StrategyIListSearch>(new StrategyBinarySearch()));
	std::cout << "found item on position: " << searchContext.searchVector(testVec, 9) << std::endl;	
}
