#include <vector>
#include <random>
#include <numeric>
#include <algorithm>//<-- para el std::is_sorted()
#include <fstream>
#include "..//..//Timer/Timer.h"
#include "UtilityFunctions.h"
#include "Sorting_Header.h"
/*! my own type def of a function pointer */
using FunctionPointer = void(*)(std::vector<int>&);

/*! write to a file for later use */
void BeachMarking(FunctionPointer SortingFunction, uint32_t StratingValue)
{
	std::ofstream ResultFile;
	Timer timer;
	ResultFile.open("ResultFile.txt", std::ios::app);
	// for reseting the original value
	uint32_t StratingValueCopy = StratingValue;

	ResultFile << "Case Theta : ";
	for (int i = 0; i < 10; ++i)
	{
		std::vector<int> AvergeCaseVector = GenerateVectorRandomOrder(StratingValue);
		timer.StartTiming();
		SortingFunction(AvergeCaseVector);
		timer.EndTiming();
		ResultFile << timer.GetResultMicroSeconds() << '\t';
		StratingValue += 200;
	}
	ResultFile << '\n';
	StratingValue = StratingValueCopy;

	ResultFile << "Case Omega : ";
	// big Omega 
	for (int i = 0; i < 10; ++i)
	{
		std::vector<int> BestCaseVector = GenerateVectorAscendentOrder(StratingValue);
		timer.StartTiming();
		SortingFunction(BestCaseVector);
		timer.EndTiming();
		ResultFile << timer.GetResultMicroSeconds() << '\t';
		StratingValue += 200;
	}
	ResultFile << '\n';
	StratingValue = StratingValueCopy;

	ResultFile << "Case Big O : ";
	for (int i = 0; i < 10; ++i)
	{
		std::vector<int> WorstCaseVector = GenerateVectorDescendantOrder(StratingValue);
		timer.StartTiming();
		SortingFunction(WorstCaseVector);
		timer.EndTiming();
		ResultFile << timer.GetResultMicroSeconds() << '\t';
		StratingValue += 200;
	}
	ResultFile << "\n\n";
	ResultFile.close();
}
/// main function
int main()
{
	Timer timer;
	FunctionPointer ptr_BubbleSort = BubbleSort;
	FunctionPointer ptr_InsertionSort = InsertionSort;

	std::vector<int> TestVector = GenerateVectorDescendantOrder(900);

	MergeSort(TestVector, 0, TestVector.size() - 1);

	if (std::is_sorted(TestVector.begin(), TestVector.end()))
	{
		printf_s("The Vector is sorted ");
	}
	else
	{
		printf_s("The Vector is NOT sorted ");
	}

	PrintVector(TestVector);

	uint32_t TestingAmount = 300;

	/*BeachMarking(ptr_BubbleSort, TestingAmount);

	BeachMarking(ptr_InsertionSort, TestingAmount);*/

	printf("Here is the Vector before being sorted \n");

	PrintVector(TestVector);
	timer.StartTiming();
	InsertionSort(TestVector);
	timer.EndTiming();

	printf("Here is the Vector After being sorted \n");

	PrintVector(TestVector);
	timer.GetResult();
	return 0;
}
