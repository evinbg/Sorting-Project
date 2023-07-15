#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Quicksort.h"
#include "Heapsort.h"

void printMenu(); // prints the main menu
int checkInput(int options, std::string text); // checks if the user's input is valid
void doAction(int action); // does the action of the user input
void generateArrays(int seed); // generates the arrays with the given seed
void printArrays(); // prints the first 20 numbers of each array
void printArray(std::vector<int> arr); // prints the elements of a given array
std::vector<int> createArray(std::vector<int> arr); // to create copies of arrays to not mess with global arrays

void insertionSort(std::vector<int> arr);

std::vector<int> arr100(100), arr1000(1000), arr5000(5000), arr10000(10000); // the arrays used to sort

int main() {
	bool keepGoing = true;
	int action;

	generateArrays(time(NULL)); // computer time used as initial random seed

	std::cout << "The arrays of size 100, 1,000, 5,000, and 10,000 have already been generated randomly, " << std::endl
		      << "but you can regenerate them using a specific seed by choosing option 1" << std::endl << std::endl
		      << "Also, the numbers only generate randomly within the range of 0-20,000 so that the numbers don't generate too wildly" << std::endl << std::endl;

	while (keepGoing == true) { // loop to keep the application running
		printMenu();
		action = checkInput(5, "Enter an option: ");
		doAction(action);
	}

	return 0;
}

void printMenu() {
	std::cout << "[Sorting]" << std::endl;
	std::cout << "1: Create randomized arrays with seed" << std::endl;
	std::cout << "2: Print first 20 numbers of the arrays" << std::endl;
	std::cout << "3: Insertion Sort" << std::endl;
	std::cout << "4: Heap Sort" << std::endl;
	std::cout << "5: Quick Sort" << std::endl;
	std::cout << "0: Exit" << std::endl;
}

int checkInput(int options, std::string text) {
	bool keepGoing = true;
	bool intCheck;
	int num;
	std::string strInput;

	while (keepGoing == true) { // loops until valid input is given
		std::cout << text;
		std::getline(std::cin, strInput);
		intCheck = true;

		for (int i = 0; i < strInput.length(); i++) { // checks if the input is an integer
			if (std::isdigit(strInput[i]) == false) {
				std::cout << "You must enter an integer" << std::endl;
				intCheck = false;
				break;
			}
		}

		if (intCheck == true) {
			num = std::stoi(strInput);
			if (num > options && options != 0) { // checks if the integer input is within the given range, no limit if options = 0
				std::cout << "You must enter an option within the range 0 - " << options << std::endl;
			}
			else {
				keepGoing = false;
			}
		}
	}

	return num;
}

void doAction(int action) {
	if (action == 1) { // choose seed
		int seed;
		seed = checkInput(1000000000, "Enter an integer for the seed: ");
		generateArrays(seed);
		std::cout << std::endl;
	}

	else if (action == 2) { // print arrays
		std::cout << std::endl;
		printArrays();
	}

	else if (action == 3) { // insertionsort
		insertionSort(arr100);
		std::cout << std::endl;
		insertionSort(arr1000);
		std::cout << std::endl;
		insertionSort(arr5000);
		std::cout << std::endl;
		insertionSort(arr10000);
		std::cout << std::endl;
	}

	else if (action == 4) { // heapsort
		// arr100
		swapsHS = 0;
		comparisonsHS = 0;
		std::vector<int> arr100HS = createArray(arr100);
		heapsort(arr100HS);
		std::cout << "[Array of " << arr100HS.size() << "]" << std::endl << "Sorted: ";
		printArray(arr100HS);
		std::cout << std::endl << "Swaps: " << swapsHS << std::endl;
		std::cout << "Comparisons: " << comparisonsHS << std::endl;
		std::cout << std::endl;
		arr100HS.clear();

		// arr1000
		swapsHS = 0;
		comparisonsHS = 0;
		std::vector<int> arr1000HS = createArray(arr1000);
		heapsort(arr1000HS);
		std::cout << "[Array of " << arr1000HS.size() << "]" << std::endl << "Sorted: ";
		printArray(arr1000HS);
		std::cout << std::endl << "Swaps: " << swapsHS << std::endl;
		std::cout << "Comparisons: " << comparisonsHS << std::endl;
		std::cout << std::endl;
		arr1000HS.clear();

		// arr5000
		swapsHS = 0;
		comparisonsHS = 0;
		std::vector<int> arr5000HS = createArray(arr5000);
		heapsort(arr5000HS);
		std::cout << "[Array of " << arr5000HS.size() << "]" << std::endl;
		std::cout << "Swaps: " << swapsHS << std::endl;
		std::cout << "Comparisons: " << comparisonsHS << std::endl;
		std::cout << std::endl;
		arr5000HS.clear();

		// arr10000
		swapsHS = 0;
		comparisonsHS = 0;
		std::vector<int> arr10000HS = createArray(arr10000);
		heapsort(arr10000HS);
		std::cout << "[Array of " << arr10000HS.size() << "]" << std::endl;
		std::cout << "Swaps: " << swapsHS << std::endl;
		std::cout << "Comparisons: " << comparisonsHS << std::endl;
		std::cout << std::endl;
		arr10000HS.clear();
	}

	else if (action == 5) { // quicksort
		// arr100
		swapsQS = 0;
		comparisonsQS = 0;
		std::vector<int> arr100QS = createArray(arr100);
		quicksort(arr100QS, 0, arr100QS.size() - 1);
		std::cout << "[Array of " << arr100QS.size() << "]" << std::endl << "Sorted: ";
		printArray(arr100QS);
		std::cout << std::endl << "Swaps: " << swapsQS << std::endl;
		std::cout << "Comparisons: " << comparisonsQS << std::endl;
		std::cout << std::endl;
		arr100QS.clear();

		// arr1000
		swapsQS = 0;
		comparisonsQS = 0;
		std::vector<int> arr1000QS = createArray(arr1000);
		quicksort(arr1000QS, 0, arr1000QS.size() - 1);
		std::cout << "[Array of " << arr1000QS.size() << "]" << std::endl << "Sorted: ";
		printArray(arr1000QS);
		std::cout << std::endl << "Swaps: " << swapsQS << std::endl;
		std::cout << "Comparisons: " << comparisonsQS << std::endl;
		std::cout << std::endl;
		arr1000QS.clear();

		// arr5000
		swapsQS = 0;
		comparisonsQS = 0;
		std::vector<int> arr5000QS = createArray(arr5000);
		quicksort(arr5000QS, 0, arr5000QS.size() - 1);
		std::cout << "[Array of " << arr5000QS.size() << "]" << std::endl;
		std::cout << "Swaps: " << swapsQS << std::endl;
		std::cout << "Comparisons: " << comparisonsQS << std::endl;
		std::cout << std::endl;
		arr5000QS.clear();

		// arr10000
		swapsQS = 0;
		comparisonsQS = 0;
		std::vector<int> arr10000QS = createArray(arr10000);
		quicksort(arr10000QS, 0, arr10000QS.size() - 1);
		std::cout << "[Array of " << arr10000QS.size() << "]" << std::endl;
		std::cout << "Swaps: " << swapsQS << std::endl;
		std::cout << "Comparisons: " << comparisonsQS << std::endl;
		std::cout << std::endl;
		arr10000QS.clear();
	}

	else if (action == 0) { // exit
		exit(1);
	}

	else {
		exit(2);
	}
}

void generateArrays(int seed) {
	srand(seed);
	int num;
	for (int i = 0; i < 100; i++) {
		num = rand() % 20001;
		arr100[i] = num;
	}

	for (int j = 0; j < 1000; j++) {
		num = rand() % 20001;
		arr1000[j] = num;
	}

	for (int k = 0; k < 5000; k++) {
		num = rand() % 20001;
		arr5000[k] = num;
	}

	for (int l = 0; l < 10000; l++) {
		num = rand() % 20001;
		arr10000[l] = num;
	}
}

void printArrays() {
	std::cout << "Array of 100: [";
	for (int i = 0; i < 20; i++) {
		std::cout << arr100[i] << ", ";
	}
	std::cout << "...]" << std::endl << std::endl;

	std::cout << "Array of 1000: [";
	for (int j = 0; j < 20; j++) {
		std::cout << arr1000[j] << ", ";
	}
	std::cout << "...]" << std::endl << std::endl;

	std::cout << "Array of 5000: [";
	for (int k = 0; k < 20; k++) {
		std::cout << arr5000[k] << ", ";
	}
	std::cout << "...]" << std::endl << std::endl;

	std::cout << "Array of 10000: [";
	for (int l = 0; l < 20; l++) {
		std::cout << arr10000[l] << ", ";
	}
	std::cout << "...]" << std::endl << std::endl;
}

void insertionSort(std::vector<int> arr) {
	int swaps = 0;
	int comparisons = 0;

	int size = arr.size();

	// creating array to copy global array to not mess up the global array for future use
	std::vector<int> array(size);
	array = arr;

	for (int i = 1; i < size; i++) {
		int key = array[i];
		int j = i - 1;
		comparisons++; // must compare at least size - 1 times
		while (j >= 0 && key < array[j]) {
			if (j != i - 1) { // compare again if algorithm goes further than 1 place
				comparisons++;
			}
			array[j + 1] = array[j];
			swaps++;
			j = j - 1;
		}
		array[j + 1] = key;
	}

	std::cout << "[Array of " << size << "]";

	// printing sorted result
	if (size <= 1000) {
		std::cout << std::endl << "Sorted: ";
		printArray(array);
	}

	std::cout << std::endl << "Swaps: " << swaps << std::endl;
	std::cout << "Comparisons: " << comparisons << std::endl;
}

std::vector<int> createArray(std::vector<int> arr) {
	int size = arr.size();
	std::vector<int> array(size);
	array = arr;

	return array;
}

void printArray(std::vector<int> arr) {
	std::cout << "[";
	for (int i = 0; i < arr.size(); i++) {
		if (i != arr.size() - 1) {
			std::cout << arr[i] << ", ";
		}
		else {
			std::cout << arr[i] << "]" << std::endl;
		}
	}
}