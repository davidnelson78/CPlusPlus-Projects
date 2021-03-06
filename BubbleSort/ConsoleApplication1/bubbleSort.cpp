// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <cstdlib>
#include <stdio.h>
#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

void swap(int *xp, int *yp) {
	int temp = *xp;

	*xp = *yp;
	*yp = temp;
}
// A function to implement bubble sort

void bubbleSort(int arr[], int n) {
	int i, j;

	for (i = 0; i < n - 1; i++) //unsorted partition decrement

								// Last i elements are already in place

		for (j = 0; j < n - i - 1; j++) //loops through unsorted and swaps

			if (arr[j] > arr[j + 1]) // if left is greater call swap

				swap(&arr[j], &arr[j + 1]);
}

/* Function to print an array */

void printArray(int arr[], int size) {
	int i;

	for (i = 0; i < size; i++)

		printf("%d ", arr[i]);

	printf("n");
}
// Driver program to test above functions

int getMilliCount() {                 //programmer defined function for getting system time
	timeb tb;                    //returns system time

	ftime(&tb);

	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;         //gets system time by using tb reference to system time

	return nCount;
}

int getMilliSpan(int nTimeStart) {
	int nSpan = getMilliCount() - nTimeStart;                      //calculates time elapsed takes difference between end of the loop run less start time.

	return nSpan;
}

int main() {
	printf("\n\nStarting timer...");

	int start = getMilliCount();                                      //gets start time

																	  // CODE I WANT TO TIME

	int n = 5000;

	//quadratic

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//do stuff
		}
	}

	int milliSecondsElapsed = getMilliSpan(start);  //uses another built in method millispan

	cout << "\n\nStart time = " << start << " milliseconds";

	cout << endl << endl;

	cout << "\n\nTime Elapsed timer...";

	cout << "\n\nElapsed time = " << milliSecondsElapsed << " milliseconds";

	cout << "\n\nEnd Time Elapsed timer...";

	int end = getMilliCount();                //gets end time

	cout << "\n\nEnding time = " << end << " milliseconds";

	cout << endl << endl;

	return 1;
}