#ifndef HEAPSORT_H_EXISTS
#define HEAPSORT_H_EXISTS

void heapify(std::vector<int>& arr, int size, int index);
void buildMaxHeap(std::vector<int>& arr);
void heapsort(std::vector<int>& arr);

extern int swapsHS;
extern int comparisonsHS;

#endif