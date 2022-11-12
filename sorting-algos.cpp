// This is a comprehesive list of the most known sorting algorithms

//BUBBLE SORT:
// The simplest in terms of code but it's the most inefficient: The number of iterations can be much higher than the elements to sort.


//SELECTION SORT:


//QUICK SORT:



// OTHER (COMPLEX) SORTING ALGORITHMS: 
/*
	INSERTION SORT -------- Improved version of selection sort.
	MODIFIED BUBBLE SORT --	Improved version of bubble sort.
	EXCHANGE SORT --------- Similar to bubble sort, but compares elements to the first value.
	SHELL SORT ------------ Similar to bubble sort, but compares elements that are a certain distance away from each other.
	HEAP SORT -------------	Similat to selection sort, but uses a 'heap' data structure for storage.
	MERGE SORT ------------ Similar to quicksort, but combines sorted arrays (partitions) and can be used effectively with linked lists.
*/


#include <iostream>
#include <fstream>

void bubbleSort( int (&array)[], int length );
void printArray (int array[], int length );
using namespace std;

int main () {
	int array[5] = {5, 1, 10, 2, 0};
	cout<<"Original Array: ";
	printArray(array,5);
	bubbleSort(array, 5);
	cout<<"Bubble-Sorted Array: ";
	printArray(array,5);
}

void bubbleSort( int (&array)[], int length ) {
	int maxPermutation = length - 1;
	int aux;
	bool continueLoop;
	
	do {
		continueLoop = false;
		for ( int i = 0 ; i < maxPermutation ; i++ ) {
			if (array[i] > array[i+1]) {
				aux = array[i+1];
				array[i+1] = array[i];
				array[i] = aux;
				continueLoop = true;
			}
		}
	} while (continueLoop);
}

void printArray ( int array[], int length ) {
	cout<<"[ ";
	for (int i = 0 ; i < length ; i++) {
		if (i == length - 1) {
			cout<<array[i]<<" ]"<<endl;
		} else {
			cout<<array[i]<<", ";
		}
	}
}

