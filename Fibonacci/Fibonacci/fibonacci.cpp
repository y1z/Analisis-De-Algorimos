#include <iostream>
#include "..//..//Timer/Timer.h"

/*Fibonacci --- Yhaliff Said Barraza Zubia */

/*!
\note I'm starting the Fibonacci sequence from 0
\author Yhaliff Said Barraza
*/

//! Here the Recursive version of the Fibonacci sequence
int RecursiveFibonacci(int Index)
{
	//! this is for handling exceptions
	if (Index == 0) { return 0; }

	if (Index == 1)
	{
		return 0;
	}
	else if (Index == 2) {
		return 1;
	}
	return RecursiveFibonacci(Index - 1) + RecursiveFibonacci(Index - 2);
}

int NonRecursiveFibonacci(int Index) {
	//! this are just the first 2 values of Fibonacci
	int FirstValue = 0;
	int SecondValue = 1;

	int Result = 0;

	if (Index == 1) { return FirstValue; }
	if (Index == 2) { return SecondValue; }

	// I'm subtracting 2 from index because it would give me 
	// a correct number, but it would be 2 ahead of the recursive function
	for (int i = 0; i < Index - 2; ++i) {

		Result = FirstValue + SecondValue;
		FirstValue = SecondValue;
		SecondValue = Result;
	}

	return Result;
}



int main() {

	int UserInput = 0;
	int ResultRecursive = 0;
	int ResultIterative = 0;

	while (true)
	{

		printf("Pleas input which number of the Fibonacci sequence you would like \n");
		std::cin >> UserInput;

		/*! will measure the time it takes the recursive version to finish*/
		Timer TimerRecursive;
		/*! will measure the time ti takes the Iterative version to finish*/
		Timer TimerIterative;

		//! timing the Recursive Version 
		TimerRecursive.StartTiming();
		ResultRecursive = RecursiveFibonacci(UserInput);
		printf("Heres the Result for the Recursive Function [%d]\n", ResultRecursive);
		TimerRecursive.EndTiming();

		//! timing the Iterative Version
		TimerIterative.StartTiming();
		ResultIterative = NonRecursiveFibonacci(UserInput);
		printf("Heres the Result for the Iterative Function [%d]\n", ResultIterative);
		TimerIterative.EndTiming();
	}

	return 0;
}
