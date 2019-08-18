#include <vector>
#include <algorithm>//<-- para el std::is_sorted()
#include <fstream>
#include <map>
//-----------------------
#include "..//..//Timer/Timer.h"
#include "UtilityFunctions.h"
//#include "Sorting_Header.h"
#include "Search_Header.h"
#include "Sorting_Header.h"
#include "..//..//Extra/SortingClass.h"

/*! my own type def of a function pointer */
using FunctionPointer = void(*)(std::vector<int>&);

/*! write to a file for later use */
inline void BeachMarking(FunctionPointer SortingFunction, uint32_t StratingValue, uint32_t Iterations = 10, uint32_t Increament = 200)
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
		StratingValue += Increament;
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
		StratingValue += Increament;
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
		StratingValue += Increament;
	}
	ResultFile << "\n\n";
	ResultFile.close();
}

void Stop()
{
	std::cout << "\nPress Enter twice";
	std::cin.ignore();
	std::cin.get();
}

/// main function
int main()
{
	Timer timer;

	CSorter Sorter;

	constexpr int16_t TestAmount = 300;

	std::vector<int> Ascendant = GenerateVectorAscendentOrder(TestAmount);
	std::vector<int> Descendant = GenerateVectorDescendantOrder(TestAmount);
	std::vector<int> Random = GenerateVectorRandomOrder(TestAmount);

	std::vector<float> RandomFloats = GenerateVectorRandomOrderF(300, 300);

	
//	Sorter.InsertionSort(Ascendant);
//	Sorter.InsertionSort(Descendant);
//	Sorter.InsertionSort(Random);

	//Sorter.HeapSort(Ascendant, 0, Ascendant.size() - 1);
	//Sorter.HeapSort(Descendant,0, Descendant.size() - 1);
	//Sorter.HeapSort(Random,0, Random.size() - 1);


	Sorter.BucketSort(RandomFloats);

	if (std::is_sorted(Ascendant.begin(), Ascendant.end()))
	{
		printf("Ascendant Array is sorted \n\n");
	}

	if (std::is_sorted(Descendant.begin(), Descendant.end()))
	{
		printf("Descendant Array is sorted \n\n");
	}

	if (std::is_sorted(Random.begin(), Random.end()))
	{
		printf("Random Array is sorted \n\n");
	}

	if(std::is_sorted(RandomFloats.begin(),RandomFloats.end()))
	{
		printf("Random float Array is sorted \n\n");
	}
	std::cout << "after Sorting : ";

	for (auto Element : RandomFloats)
	{
		std::cout << "[" << Element << "]";
	}
	std::cout << "\n---------------\n" << std::endl;

	Stop();

	return 0;
}
