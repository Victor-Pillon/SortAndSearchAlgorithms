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
#include "ProxyListSearchTimer.h"


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

	std::random_device rd;  // Create a random device
    std::mt19937 gen(rd()); // Initialize a Mersenne Twister pseudo-random generator

    // Create a distribution for random numbers within a certain range
    std::uniform_int_distribution<int> distribution(1, 100);

    std::vector<int> randomVector;
    randomVector.reserve(500); // Reserve space for 10,000 elements

    for (int i = 0; i < 500; i++) {
        int randomValue = distribution(gen); // Generate a random value
        randomVector.push_back(randomValue);  // Add it to the vector
    }

	//printVector(randomVector);
	
	sorterContext.setStrategy(std::unique_ptr<StrategyIListSort>(new StrategyInsertionSort()));
	randomVector = sorterContext.sortedVector(randomVector);
	//printVector(randomVector);

	searchContext.setStrategy(std::unique_ptr<StrategyIListSearch>(new StrategyBinarySearch()));
	std::cout << "found item on position: " << searchContext.searchVector(randomVector, 9) << std::endl;

	ProxyListSearchTimer* test = new ProxyListSearchTimer(std::unique_ptr<StrategyIListSearch>(new StrategyBinarySearch()));

	searchContext.setStrategy(std::unique_ptr<StrategyIListSearch>(test));
	std::cout << "found item on position: " << searchContext.searchVector(randomVector, 9) << std::endl;	
	std::cout << "time it took: " << test->getExecutionTime() << " nanoseconds" << std::endl;
}
