# Sorting Project

This project was created for my Data Structures and Algorithms course. It creates randomized arrays of integers and implements the insertion sort, quicksort, and heapsort
algorithms.

## Functions
* Creates randomized arrays of sizes: 100, 1000, 5000, and 10000
* Sorts the arrays with insertion sort
* Builds max heaps of the arrays
* Sorts the arrays with heapsort
* Sorts the arrays with quicksort using the median of 3 and insertion sort at a certain cutoff version of the algorithm
* Shows the number of comparisons and swaps each implementation of the sorting algorithms use

## Grade Received
100% (30/30)

## Compiling Instructions
I created this project on Microsoft Visual Studio 2022, so creating a new empty C++ project and 
inserting the files into the Source Files should allow the code to run in Visual Studio. 
You have to put the multilist_input.txt file in the Visual Studio project's directory, 
which usually looks something like: `C:\Users\Username\source\repos\Sorting\Sorting\`
  
I also included a makefile, so the code can run on the Unix command line. The command to run the 
code is `make run`.
