#include <iostream>
#include <vector>
#include "Quicksort.h"

int swapsQS = 0, comparisonsQS = 0; // variables to keep track of quicksort swaps and comparisons

void quicksort(std::vector<int>& arr, int left, int right) {
	int cutoff = 10; // number of elements - 1 at which it switches to insertion sort to avoid too much recursion in stack
	if (left + cutoff <= right) {
		int pivot_index = partition(arr, left, right);

		quicksort(arr, left, pivot_index - 1); // recursively quicksorting the elements less than the number at the partition_index
		quicksort(arr, pivot_index + 1, right); // recursively quicksorting the elements larger than the number at the partition_index
	}
	else {
		insertionSortQS(arr, left, right);
	}
}

int partition(std::vector<int>& arr, int left, int right) {
	int pivot = median_of_3(arr, left, right);

	int i = left - 1; // starts at -1 at the very start

	for (int j = left; j < right - 1; j++) { // always increases j pointer, which starts at 0 at the very start, and goes to the number right before the pivot
		comparisonsQS++;
		if (arr[j] < pivot) { // if current element is smaller than the pivot
			i++;
			if (i != j) { // do not swap if i and j are the same
				std::swap(arr[i], arr[j]);
				swapsQS++;
			}
		}
	}

	std::swap(arr[i + 1], arr[right - 1]); // swapping i + 1 (an element larger than the pivot) and the pivot
	swapsQS++;
	return (i + 1); // returning the new index of the pivot
}

int median_of_3(std::vector<int>& arr, int left, int right) {
	int center = (left + right) / 2;

	comparisonsQS += 3;

	// sorting the first, middle, and last elements
	if (arr[center] < arr[left]) {
		std::swap(arr[left], arr[center]);
		swapsQS++;
	}
	if (arr[right] < arr[left]) {
		std::swap(arr[left], arr[right]);
		swapsQS++;
	}
	if (arr[right] < arr[center]) {
		std::swap(arr[center], arr[right]);
		swapsQS++;
	}

	std::swap(arr[center], arr[right - 1]); // switching center and right - 1 for pivot, right - 1 because right will always be larger due to the sorting
	swapsQS++;
	return (arr[right - 1]); // returning pivot
}

void insertionSortQS(std::vector<int>& arr, int left, int right) { // insertion sort implementation used for quicksort
	int size = arr.size();

	for (int i = left + 1; i < right; i++) {
		int key = arr[i];
		int j = i - 1;
		comparisonsQS++; // must compare at least size - 1 times
		while (j >= 0 && key < arr[j]) {
			if (j != i - 1) { // compare again if algorithm goes further than 1 place
				comparisonsQS++;
			}
			arr[j + 1] = arr[j];
			swapsQS++;
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}