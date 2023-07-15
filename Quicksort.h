#ifndef QUICKSORT_H_EXISTS
#define QUICKSORT_H_EXISTS

void quicksort(std::vector<int>& arr, int left, int right);
int partition(std::vector<int>& arr, int left, int right);
int median_of_3(std::vector<int>& arr, int left, int right);
void insertionSortQS(std::vector<int>& arr, int left, int right);

extern int swapsQS;
extern int comparisonsQS;

#endif