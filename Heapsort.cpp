#include <iostream>
#include <vector>
#include "Heapsort.h"

int swapsHS = 0, comparisonsHS = 0; // variables to keep track of heapsort swaps and comparisons

void heapify(std::vector<int>& arr, int size, int index) { // percolate down algorithm
	int largest = index;
	int lchild = (2 * index) + 1;
	int rchild = (2 * index) + 2;

	if (lchild < size && arr[lchild] > arr[largest]) { // sets left child largest if it is larger than its parent
		largest = lchild;
		comparisonsHS++;
	}
	if (rchild < size && arr[rchild] > arr[largest]) { // sets right child largest if it is larger than its parent or the left child
		largest = rchild;
		comparisonsHS++;
	}
	if (largest != index) { // if one of the children were larger than the parent
		std::swap(arr[index], arr[largest]);
		swapsHS++;
		heapify(arr, size, largest); // recursively heapify again
	}
}

void buildMaxHeap(std::vector<int>& arr) { // algorithm for building max heap in linear time
	int size = arr.size();
	int index = (size / 2) - 1;

	for (int i = index; i >= 0; i--) {
		heapify(arr, size, i);
	}
}

void heapsort(std::vector<int>& arr) {
	buildMaxHeap(arr);

	int size = arr.size();
	for (int i = size - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]); // swapping max to the end of the heap
		swapsHS++;
		heapify(arr, i, 0); // size is decreased by 1 each time there is a deleteMax, and a new max will be in the root
	}
}