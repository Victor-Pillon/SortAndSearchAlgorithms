#include "Defines.h"


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

	for(int i=0; i<size; i++)
		disorderedVector.push_back(size-i);
} 

template<typename Option>
MenuReturns displayOptionMenu(
	std::string title, 
	std::vector<Option> &optionsSelected, 
	std::map<Option, std::string> &optionsMap
	)	
{
	using namespace std;

	cout << title;

	for(const Option &optionSelected: optionsSelected)
	{
		cout << " | " << optionsMap[optionSelected];
	}

	cout << endl;

	int i, j, tempOption, allSelected, allClear;

	for (i = 0; i < optionsMap.size(); i++)
	{
		cout << i+1 << ". ";
		cout << optionsMap[static_cast<Option>(i)] << endl;
	}

	i++;
	allSelected = i;
	cout << allSelected << ". All" << endl;

	i++;
	allClear = i;
	cout << allClear << ". Clear" << endl;

	i++;

	for (j = 0; j < menuOptions.size(); j++)
	{
		cout << j+i << ". ";
		cout << menuOptions[static_cast<MenuReturns>(j)] << endl;
	}
	 
	cout << "Selected:";
	cin >> tempOption; 

	if(tempOption < 1 || tempOption > (optionsMap.size()+menuOptions.size()+2))
		throw std::invalid_argument("This option does not exists");


	if(tempOption > optionsMap.size()+2)
	{
		MenuReturns selectedReturn = static_cast<MenuReturns>(tempOption-(optionsMap.size()+menuOptions.size()+1));
		if(selectedReturn==MenuReturns::GO_NEXT && optionsSelected.empty()) return MenuReturns::STAY;
		return selectedReturn;
	}

	Option selectedOption = static_cast<Option>(tempOption-1);

	if(tempOption == allSelected)
	{
		optionsSelected.clear();
		for(i=0; i<optionsMap.size(); i++)
			optionsSelected.push_back(static_cast<Option>(i));
	}
	else if (tempOption == allClear)
	{
		optionsSelected.clear();
	}
	else if(!optionsSelected.empty())
	{
		auto position = std::find(optionsSelected.begin(), optionsSelected.end(), selectedOption);
		
		if(position == optionsSelected.end())
			optionsSelected.push_back(selectedOption);
		else
			optionsSelected.erase(position);
	}
	else
		optionsSelected.push_back(selectedOption);

	return MenuReturns::STAY;
}


MenuReturns displayStartMenu()
{
	using namespace std;

	int tempOption;

	cout << "Selected options will be run do you wish to procede:" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cout << "Selected:";
	cin >> tempOption;

	if(tempOption < 1 || tempOption > 2)
		throw std::invalid_argument("");

	if (tempOption == 1) return MenuReturns::GO_NEXT;
	else return MenuReturns::GO_BACK;
}

void executeProgram()
{
	using namespace std;

	ofstream outputFile("out.csv");
	if(outputFile.is_open())
		outputFile << "Algorithm,Order,Quantity,Execution,Exchanges,Comparisons" << endl;

	for(const QuantityOptions &selectedQuantity: selectedQuantities)
	{
		for(const OrderOptions &selectedOrder: selectedOrders)
		{
			for(const AlgorithmOptions &selectedAlgorithm: selectedAlgorithms)
			{
				ContextListSort sorterContext;
				ProxyListSortTimer *sortProxy;
				std::vector<int> toSortVector;
				StrategyIListSort *toUseStrategy;
				mapOrders[selectedOrder](toSortVector, mapQuantities[selectedQuantity]);
				switch (selectedAlgorithm)
				{
				case AlgorithmOptions::BUBBLE_SORT:
					toUseStrategy = new StrategyBubbleSort();
					break;
				case AlgorithmOptions::IMPROVED_BUBBLE_SORT:
					toUseStrategy = new StrategyImprovedBubbleSort();
					break;
				case AlgorithmOptions::INSERTION_SORT:
					toUseStrategy = new StrategyInsertionSort();
					break;
				case AlgorithmOptions::SELECTION_SORT:
					toUseStrategy = new StrategySelectionSort();
					break;
				case AlgorithmOptions::MERGE_SORT:
					toUseStrategy = new StrategyMergeSort();
					break;
				case AlgorithmOptions::QUICK_SORT:
					toUseStrategy = new StrategyQuickSort();
					break;
				case AlgorithmOptions::HEAP_SORT:
					toUseStrategy = new StrategyHeapSort();
					break;
				}

				sortProxy = new ProxyListSortTimer( unique_ptr<StrategyIListSort>(toUseStrategy));
				unsigned long long comparisons, exchanges;
				int64_t exectionTime;

				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
				cout << "Running Algorithm: " << algorithmOptions[selectedAlgorithm] << endl;
				cout << "Vector type: " << ordersOptions[selectedOrder] << endl;
				cout << "Vector size: " << toSortVector.size() << endl;
				sorterContext.setStrategy(std::unique_ptr<StrategyIListSort>(sortProxy));
				sorterContext.sortedVector(toSortVector, comparisons, exchanges);
				exectionTime = sortProxy->getExecutionTime();
				cout << "Took: " << exectionTime << " nanoseconds" << endl;
				cout << "Made: " << exchanges << " exchanges" << endl;
				cout << "Made: " << comparisons << " comparisons" << endl;

				if(outputFile.is_open())
				{
					outputFile << algorithmOptions[selectedAlgorithm] << ',';
					outputFile << ordersOptions[selectedOrder] << ',';
					outputFile << toSortVector.size() << ',';
					outputFile << exectionTime << ',';
					outputFile << exchanges << ',';
					outputFile << comparisons << ',';
					outputFile << endl;
				}

			}
		}
	}
	if(outputFile.is_open()) outputFile.close();
}

void goNextMenu()
{
	if(currentMenu == Menu::START)
		currentMenu = Menu::QUANTITY;
	else
		currentMenu = static_cast<Menu>(currentMenu+1);
}

void goBackMenu()
{
	if(currentMenu != Menu::QUANTITY)
		currentMenu = static_cast<Menu>(currentMenu-1);
}


int main(int argc, char** argv) 
{
	MenuReturns menuReturn;
	while (true)
	{
		try
		{
			std::cin.clear();
			fflush(stdin);

			switch (currentMenu)
			{
			case Menu::QUANTITY:
				menuReturn = displayOptionMenu(
					"Select the quantity: ", 
					selectedQuantities, quantitiesOptions);
				break;

			case Menu::ORDER:
				menuReturn = displayOptionMenu(
					"Select the Orders: ",
					selectedOrders, ordersOptions);
				break;

			case Menu::ALGORITHM:
				menuReturn = displayOptionMenu(
					"Select the Algorithms: ", 
					selectedAlgorithms, algorithmOptions);
				break;

			case Menu::START:
				menuReturn = displayStartMenu();
				if (menuReturn == MenuReturns::GO_NEXT) executeProgram();
				break;

			default:
				std::cout << "Menu does not exists" << std::endl;
				currentMenu = Menu::QUANTITY;
				break;
			}

			if(menuReturn == MenuReturns::GO_NEXT && currentMenu == Menu::START) break;
			else if (menuReturn == MenuReturns::GO_NEXT) goNextMenu();
			else if (menuReturn == MenuReturns::GO_BACK) goBackMenu();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Unkown input try again" << std::endl;
		}
		std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	}
	return 0;
}
