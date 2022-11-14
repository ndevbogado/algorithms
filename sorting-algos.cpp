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
#include <cstdlib>
#include <time.h>

void bubbleSort (int (&array)[], int length, int sortDirection);
void selectionSort (int (&array)[], int size);
void printArray (int array[], int length);
void randomArray (int (&array)[], int length);

using namespace std;

int main () {
	
	int sortDirection;
	cout<<"What type of sort do you want to do? (Type '1' to sort from min-to-max or '2' to sort from max-to-min): ";
	cin>>sortDirection;

	int array[5];
	randomArray(array, 5);
	cout<<"Original Array: ";
	printArray(array,5);

	bubbleSort(array, 5, sortDirection);
	cout<<"Bubble-Sorted Array: ";
	printArray(array,5);

	selectionSort(array, 5);
	cout<<"Selection-Sort Array: ";
	printArray(array,5);
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

void selectionSort(int (&array)[], int size) {
	//read the array and seeks the lowest value. Then compares array[0] with the position of the lowest value and swaps them. Continue the process, starting from array[1] with the lowest value between array[1] and array[size-1] and reiterate the process.
	int min;
	int aux;
	int position;
	for (int i = 0 ; i < size ; i++) {
		min = array[i];
		for (int j = i ; j < size ; j++) {
			if (array[j] < min) {
				min = array[j]; 
				position = j;
			}
		}
		if (min != array[i]) {
			aux = array[position];
			array[position] = array[i];
			array[i] = aux; 
		}
	}
}
