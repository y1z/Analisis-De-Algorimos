#include <iostream>
#include "..//..//Cronometro/CronometroGeneral.h"

/*Fibonacci --- Yhaliff Said Barraza Zubia */
/**
*@note I'm beginning the sequence with the number 0.
*/

//! Here the Recursive version of the Fibonacci sequence
int RecursiveFibonacci(int Index)
{
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
	//! 
	int firstValue = 0;
	int SecondValue = 1;
	
	int NewValue = 0;

	if (Index == 1) { return firstValue; }
	if (Index == 2) { return SecondValue; }

	for (int i = 0; i < Index; ++i) {
		


	}
	return NewValue;
}



void main() {
	/*! will measure the time it takes the recursive version to finish*/
	Cronometro TimerRecursive;

	Cronometro TimerIterative;

	int UserInput = 0;
	int ResultRecursive = 0;
	int ResultIterative = 0;

	while (true)
	{
		printf("Pleas input which number of the Fibonacci sequence you would like \n");
		std::cin >> UserInput;
		ResultRecursive = RecursiveFibonacci(UserInput);
		printf("Heres the Result [%d]\n",ResultRecursive);

	}

}