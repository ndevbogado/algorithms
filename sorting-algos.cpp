/*
This is a comprehesive list of the most known sorting algorithms

MAIN SORTING ALGORITHMS:

	BUBBLE-SORT
	SELECTION-SORT
	QUICK-SORT

OTHER (COMPLEX) SORTING ALGORITHMS: 

	INSERTION SORT -------- Improved version of selection sort.
	MODIFIED BUBBLE SORT --	Improved version of bubble sort.
	EXCHANGE SORT --------- Similar to bubble sort, but compares elements to the first value.
	SHELL SORT ------------ Similar to bubble sort, but compares elements that are a certain distance away from each other.
	HEAP SORT -------------	Similat to selection sort, but uses a 'heap' data structure for storage.
	MERGE SORT ------------ Similar to quicksort, but combines sorted arrays (partitions) and can be used effectively with linked lists.
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <chrono>

void bubbleSort (int (&array)[], int length, int sortDirection);
void selectionSort (int (&array)[], int size, int sortDirection);
void printArray (int array[], int length);
void randomArray (int (&array)[], int length);

using namespace std;
using namespace std::chrono;

int main () {
	
	int sortDirection;
	cout<<"What type of sort do you want to do? (Type '1' to sort from min-to-max or '2' to sort from max-to-min): ";
	cin>>sortDirection;

	int array[5];
	randomArray(array, 5);
	cout<<"Original Array: ";
	printArray(array,5);
	
	auto start = high_resolution_clock::now();
	bubbleSort(array, 5, sortDirection);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop-start);
	cout<<"Bubble-Sorted Array: ";
	printArray(array,5);
	cout<<"in : "<< duration.count()<<" nanoSeg"<<endl;

	
	start = high_resolution_clock::now();
	selectionSort(array, 5, sortDirection);
	stop = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(stop-start);
	cout<<"Selection-Sort Array: ";
	printArray(array,5);
	cout<<"in : "<< duration.count()<<" nanoSeg"<<endl;
}

void bubbleSort( int (&array)[], int length, int sortDirection) {
	int maxPermutation = length - 1;
	int aux;
	bool continueLoop;

	do {
		continueLoop = false;
		for ( int i = 0 ; i < maxPermutation ; i++ ) {
			if(sortDirection == 1){
				if (array[i] > array[i+1]) {
					aux = array[i+1];
					array[i+1] = array[i];
					array[i] = aux;
					continueLoop = true;
				}
			} else if (sortDirection == 2) {
				if (array[i] < array[i+1]) {
					aux = array[i+1];
					array[i+1] = array[i];
					array[i] = aux;
					continueLoop = true;
				}
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

void randomArray(int (&array)[], int length) {
	srand(time(0));	
	for (int i = 0 ; i < length; i++) {
		array[i] = rand()%100;
	}
}

void selectionSort(int (&array)[], int size, int sortDirection) {
	//read the array and seeks the lowest value. Then compares array[0] with the position of the lowest value and swaps them. Continue the process, starting from array[1] with the lowest value between array[1] and array[size-1] and reiterate the process.

	int currentValue;
	int*min = &currentValue;
	int*max = &currentValue;
	int aux;
	int position;
	for (int i = 0 ; i < size ; i++) {
		currentValue = array[i];

		for (int j = i ; j < size ; j++) {
			switch (sortDirection) {
				case 1: 
					//*min points to currentValue, when user choosed sort direction '1' (min-to-max).
					if (array[j] < *min) {
						*min = array[j]; 
						position = j;
					}
					break;
				case 2: 
					//*max points to currentValue, when user choosed sort direction '2' (max-to-min).
					if (array[j] > *max) {
						*max = array[j];
						position = j;
					}
					break;
				default:
					break;
			}
		}

		if (currentValue != array[i]) {
			aux = array[position];
			array[position] = array[i];
			array[i] = aux; 
		}
	}
}
