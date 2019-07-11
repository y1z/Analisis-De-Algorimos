#include <vector>
#include <algorithm>//<-- para el std::is_sorted()
#include <fstream>
#include <map>
#include "..//..//Timer/Timer.h"
#include "UtilityFunctions.h"
#include "Sorting_Header.h"
#include "Search_Header.h"
#include "My_Hash_functions.h"
#include "Node.h"
#include "BinaryTree.h"
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
/// main function
int main()
{
	Timer timer;
	DS::BinaryTree tree;

	int MiddleValue = 150;
	int *temp = &MiddleValue;

	tree.SetRootNodeValue(temp);

	std::vector<int> TestVector = GenerateVectorAscendentOrder(300);
//	std::vector<int> TestVector = GenerateVectorDescendantOrder(300);
	//std::vector<int> TestVector = GenerateVectorRandomOrder(300);

	for (int i = 0; i < TestVector.size() - 1; ++i)
	{
		tree.AddNode(&TestVector[i]);
	}

	tree.PrintTree();

	tree.RemoveNode(3);


	tree.RemoveNode(75);

	tree.RemoveNode(9);

	Node * FoundNode =	  tree.SearchNode(90);
	std::cout << "\n\n the value of the node : " << FoundNode->GetValue()<< "\n\n The resulting tree \n";
	tree.PrintTree();







	//FunctionPointer QuickSortTest = StartQuickSort;

 // //MergeSort(TestVector, 0, TestVector.size() - 1);

	//auto hashTable = GenerateHashTable(TestVector);

	//for (auto &Vec : hashTable)
	//{
	//	PrintVector(Vec.second);
	//}
	//int searchValue = 30;

	//std::cout << "give me a value\n";
	//std::cin >> searchValue;

	//if (SearchHashTable(hashTable, searchValue))
	//{
	//	printf("found the value %d",searchValue);
	//}
	//else
	//{
	//	printf("Did NOT find %d", searchValue);
	//}

	////BeachMarking(QuickSortTest, 100, 15);
	//
	////SearchTesting(TestVector);

	//if (std::is_sorted(TestVector.begin(), TestVector.end()))
	//{
	//	printf_s("The Vector is sorted ");
	//}
	//else
	//{
	//	printf_s("The Vector is NOT sorted ");
	//}

	//PrintVector(TestVector);

	return 0;
}
