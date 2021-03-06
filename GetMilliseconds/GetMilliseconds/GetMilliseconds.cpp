// GetMilliseconds.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>

#include <iostream>

#include <cstdlib>

#include

timeb.h >

using namespace std;

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