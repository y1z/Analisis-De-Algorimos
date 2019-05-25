#include <vector>
#include <algorithm>//<-- para el std::is_sorted()
#include <fstream>
#include "..//..//Timer/Timer.h"
#include "UtilityFunctions.h"
#include "Sorting_Header.h"
#include "Search_Header.h"
/*! my own type def of a function pointer */
using FunctionPointer = void(*)(std::vector<int>&);

/*! write to a file for later use */
void BeachMarking(FunctionPointer SortingFunction, uint32_t StratingValue, uint32_t Iterations = 10)
{
	std::ofstream ResultFile;
	Timer timer;
	ResultFile.open("ResultFile.txt", std::ios::app);
	// for reseting the original value
	uint32_t StratingValueCopy = StratingValue;

	ResultFile << "Case RandomOrder : ";
	for (int i = 0; i < Iterations; ++i)
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

	ResultFile << "Case AscendentOrder : ";
	// big Omega 
	for (int i = 0; i < Iterations; ++i)
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

	ResultFile << "Case DescendantOrder : ";
	for (int i = 0; i < Iterations; ++i)
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

	std::vector<int> TestVector = GenerateVectorDescendantOrder(900);

	MergeSort(TestVector, 0, TestVector.size() - 1);

	SearchTesting(TestVector);


	if (std::is_sorted(TestVector.begin(), TestVector.end()))
	{
		printf_s("The Vector is sorted ");
	}
	else
	{
		printf_s("The Vector is NOT sorted ");
	}

	PrintVector(TestVector);

	return 0;
}
