#include <iostream>
#include <fstream>
#include <string>
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

uint64_t NonRecursiveFibonacci(int Index) {
	//! this are just the first 2 values of Fibonacci
	uint64_t FirstValue = 0;
	uint64_t SecondValue = 1;

	uint64_t Result = 0;

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

/*! this function test the NonRecursiveFibonacci function and
writes the results to a file */
void BenchmarkIterativeFibonacci() {

	// increases in units of 1
	int SimulatedInput = 0;

	std::ofstream OutputFile;
	OutputFile.open("Iterative Times.txt", std::ios::trunc);

	Timer TimerIterative;

	/*!Testing value from 1 to 40 */
	for (int i = 0; i < 400; ++i) {

		if (i % 10 == 0) {
			SimulatedInput++;
			OutputFile << '\n';
		}

		TimerIterative.StartTiming();
		NonRecursiveFibonacci(SimulatedInput);
		TimerIterative.EndTiming();

		OutputFile << TimerIterative.GetResult() << '\t';
	}
	std::cout << "Here is the Simulated INput [" << SimulatedInput << ']';
	OutputFile.close();
}

/*! this function test the Recursive Fibonacci function and
writes the results to a file */
void BenchmarkRecursiveFibonacci() {

	// increases in units of 1
	int SimulatedInput = 0;

	std::ofstream OutputFile;
	OutputFile.open("Recursive Times.txt", std::ios::trunc);

	Timer TimerIterative;

	/*!Testing value from 1 to 40 */
	for (int i = 0; i < 400; ++i) {

		if (i % 10 == 0) {
			SimulatedInput++;
			OutputFile << '\n';
		}
		TimerIterative.StartTiming();
		RecursiveFibonacci(SimulatedInput);
		TimerIterative.EndTiming();

		OutputFile << TimerIterative.GetResult() << '\t';
	}
	std::cout << "Here is the Simulated INput [" << SimulatedInput << ']';
	OutputFile.close();
}

void BenchmarkMenu() {
	int UserInput = 0;

	printf("Would you like to benchmark the Fibonacci sequence\n 1) Yes \n2) No \n");
	std::cin >> UserInput;
	if (UserInput == 1) {
		printf("which would you Like to Benchmark \n1) Iterative \n2) Recursive \n 3) I made a mistake\n");
		std::cin >> UserInput;
		switch (UserInput)
		{
		case(1):
			BenchmarkIterativeFibonacci();
			break;
		case(2):
			BenchmarkRecursiveFibonacci();
			break;
		case(3):

			break;
		default:
			break;
		}

	}
}


int main() {

	int UserInput = 0;
	uint64_t ResultRecursive = 0;
	uint64_t ResultIterative = 0;

	while (true)
	{

		printf("Pleas input which number of the Fibonacci sequence you would like \n");
		/*! will measure the time it takes the recursive version to finish*/
		Timer TimerRecursive;
		/*! will measure the time ti takes the Iterative version to finish*/
		Timer TimerIterative;

		std::cin >> UserInput;
		if (UserInput < 0) {
			break;
		}

		//! timing the Recursive Version 
		printf("//////////// Starting Recursive Fibonacci //////////////\n");
		TimerRecursive.StartTiming();
		ResultRecursive = RecursiveFibonacci(UserInput);
		TimerRecursive.EndTiming();
		printf("Heres the Result for the Recursive Function [%d]\n\n", ResultRecursive);

		printf("//////////// Starting Iterative Fibonacci //////////////\n");
		//! timing the Iterative Version
		TimerIterative.StartTiming();
		ResultIterative = NonRecursiveFibonacci(UserInput);
		TimerIterative.EndTiming();
		printf("Heres the Result for the Iterative Function [%d]\n\n", ResultIterative);
	}


	return 0;
}
