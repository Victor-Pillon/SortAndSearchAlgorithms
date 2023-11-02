#include "Defines.h"

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

void displayQuantityMenu()
{
	using namespace std;

	cout << "Select the quantity to be analysed: " << endl; 
	cout << "1. 1.000" << endl; 
	cout << "2. 10.000" << endl; 
	cout << "3. 100.00" << endl;
	cout << "4. All" << endl;
	cout << "Selected:";
	cin >> tempOption; 
	selectedQuantity = static_cast<QuantityOptions>(tempOption);
	menu = Menu::ORDER;
}

void displayOrdersMenu()
{
	using namespace std;

	cout << "Select the order to be analysed: " << endl; 
	cout << "1. Ordered" << endl; 
	cout << "2. Random" << endl; 
	cout << "3. Disordered" << endl;
	cout << "4. All" << endl;
	cout << "5. Back" << endl;
	cout << "Selected:";
	cin >> tempOption; 
	selectedOrder = static_cast<OrderOptions>(tempOption);
	menu = selectedOrder != OrderOptions::BACK_ORDERS ? Menu::ALGORITHM : Menu::QUANTITY;
}

void displayAlgorithmMenu()
{
	using namespace std;

	cout << "Select the Algorithm to be analysed: " << endl; 
	cout << "1. Bubble Sort" << endl; 
	cout << "2. Improved Bubble Sort" << endl; 
	cout << "3. Insertion Sort" << endl;
	cout << "4. Selection Sort" << endl;
	cout << "5. Merge Sort" << endl;
	cout << "6. Quick Sort" << endl;
	cout << "7. Heap Sort" << endl;
	cout << "8. All" << endl;
	cout << "9. Back" << endl;
	cout << "Selected:";
	cin >> tempOption; 
	selectedAlgorithm = static_cast<AlgorithmOptions>(tempOption);
	cout << selectedAlgorithm;
	menu = selectedAlgorithm != AlgorithmOptions::BACK_ALGORITHMS ? Menu::QUANTITY : Menu::ORDER;
}


int main(int argc, char** argv) 
{
	while (true)
	{
		system("cls");
		switch (menu)
		{
		case Menu::QUANTITY:
			displayQuantityMenu();
			break;

		case Menu::ORDER:
			displayOrdersMenu();
			break;

		case Menu::ALGORITHM:
			displayAlgorithmMenu();
			break;

		default:
			break;
		}
	}
	return 0;
}
