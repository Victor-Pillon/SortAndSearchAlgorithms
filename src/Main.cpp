#include <iostream>
#include <vector>
#include <memory>
#include <random>

#include "ContextListSearch.h"
#include "ContextListSort.h"

#include "StrategyBubbleSort.h"
#include "StrategyInsertionSort.h"
#include "StrategySelectionSort.h"

#include "StrategyBinarySearch.h"
#include "StrategyLinearSearch.h"

#include "ProxyListSearchTimer.h"
#include "ProxyListSortTimer.h"


void printVector(std::vector<int> vec)
{
	for (int i=0; i<vec.size(); i++)
	{
		std::cout << "positon: " << i << " | " << "value: " << vec.at(i) << std::endl;
	}
	std::cout << std::endl;
}

void populateRandomVector(std::vector<int> &randomVector, int size)
{
	std::random_device rd;  // Create a random device
    std::mt19937 gen(rd()); // Initialize a Mersenne Twister pseudo-random generator

    // Create a distribution for random numbers within a certain range
    std::uniform_int_distribution<int> distribution(1, 100);

    randomVector.reserve(size); // Reserve space for samples

    for (int i = 0; i < size; i++) {
        int randomValue = distribution(gen); // Generate a random value
        randomVector.push_back(randomValue);  // Add it to the vector
    }
}

int main(int argc, char** argv) {
	//ListSorterContext sorterContext(std::unique_ptr<ListSorterStrategy>(new BubbleSortStrategy()));
	ContextListSort sorterContext;
	ContextListSearch searchContext;

	std::vector<int> randomVector;
	populateRandomVector(randomVector, 10);

	// Uses normal strategy to organize array
	// sorterContext.setStrategy(std::unique_ptr<StrategyIListSort>(new StrategyInsertionSort()));
	// randomVector = sorterContext.sortedVector(randomVector);
	// //printVector(randomVector);

	// Uses a proxy to get the time of the sort in nanoseconds
	ProxyListSortTimer* sortProxy = new ProxyListSortTimer(std::unique_ptr<StrategyIListSort>(new StrategyInsertionSort()));
	sorterContext.setStrategy(std::unique_ptr<StrategyIListSort>(sortProxy));
	randomVector = sorterContext.sortedVector(randomVector);
	std::cout << "time it took for insertion sort: " << sortProxy->getExecutionTime() << " nanoseconds" << std::endl;
	printVector(randomVector);


	// Uses normal strategy to search array
	searchContext.setStrategy(std::unique_ptr<StrategyIListSearch>(new StrategyLinearSearch()));
	std::cout << "found item on position: " << searchContext.searchVector(randomVector, 9) << std::endl;


	// Uses a proxy to get the time of the search in nanoseconds
	ProxyListSearchTimer* searchProxy = new ProxyListSearchTimer(std::unique_ptr<StrategyIListSearch>(new StrategyBinarySearch()));
	searchContext.setStrategy(std::unique_ptr<StrategyIListSearch>(searchProxy));
	std::cout << "found item on position: " << searchContext.searchVector(randomVector, 9) << std::endl;	
	std::cout << "time it took to find the item: " << searchProxy->getExecutionTime() << " nanoseconds" << std::endl;
}
