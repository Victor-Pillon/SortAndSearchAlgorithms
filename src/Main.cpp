#include <iostream>
#include <vector>
#include <memory>
#include <random>

#include "Defines.h"

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
	randomVector.clear();
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

void populateOrderedVector(std::vector<int> &orderedVector, int size)
{
	orderedVector.clear();

	for(int i=0; i<size; i++)
		orderedVector.push_back(i);
}

void populateDisorderedVector(std::vector<int> &disorderedVector, int size)
{
	disorderedVector.clear();

	for(int i=size; i>size; i--)
		disorderedVector.push_back(i);
} 

int main(int argc, char** argv) {
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

	while (true)
	{
		switch (menu)
		{
		case Menu::QUANTITY:
			std::cout << "Select the quantity to be analysed: " << std::endl; 
			std::cout << "1. 1.000" << std::endl; 
			std::cout << "2. 10.000" << std::endl; 
			std::cout << "3. 100.00" << std::endl;
			std::cout << "4. All" << std::endl;
			std::cout << "Selected:";
			std::cin >> tempOption; 
			selectedQuantity = static_cast<QuantityOptions>(tempOption);
			menu = Menu::ORDER;
			break;

		case Menu::ORDER:
			std::cout << "Select the order to be analysed: " << std::endl; 
			std::cout << "1. Ordered" << std::endl; 
			std::cout << "2. Random" << std::endl; 
			std::cout << "3. Disordered" << std::endl;
			std::cout << "4. All" << std::endl;
			std::cout << "5. Back" << std::endl;
			std::cout << "Selected:";
			std::cin >> tempOption; 
			selectedOrder = static_cast<OrderOptions>(tempOption);
			menu = Menu::ALGORITHM;
			break;
		
		case Menu::ALGORITHM:
			/* code */
			break;
		
		default:
			break;
		}
	}
	return 0;
}
