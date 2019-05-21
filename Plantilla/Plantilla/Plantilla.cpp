#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include "..//..//Timer/Timer.h"
#include "UtilityFunctions.h"
void BuildMaxHeap(std::vector<int> &Vec, int CurrentPlace, int Limit);

/*! to swap 2 elements*/
void Swap(int &LeftSideValue, int &RightSideValue)
{
	int Temp = LeftSideValue;
	LeftSideValue = RightSideValue;
	RightSideValue = Temp;
}

/*! this is an my version of bubbleSort*/
void BubbleSort(std::vector<int> &Vec)
{
	// to not have to sort an necessarily
	bool isSorted = true;

	for (auto Elemento : Vec)
	{
		for (int j = 0; j < Vec.size() - 1; ++j)
		{
			if (Vec[j] > Vec[j + 1])
			{
				Swap(Vec[j], Vec[j + 1]);
				isSorted = false;
			}
		}

		if (isSorted) { break; }

		isSorted = true;
	}
}

/*! this is an implementation of Insertion-sort*/
void InsertionSort(std::vector<int> &Vec)
{
	for (int i = Vec.size() - 1; i > 0; --i)
	{
		if (Vec[i] < Vec[i - 1])
		{
			// this is so we don't go out of bounds 
			int CurrentPos = i;
			// making sure we don't go out of bonds
			while (CurrentPos <= (Vec.size() - 1) && Vec[CurrentPos] < Vec[CurrentPos - 1])
			{
				Swap(Vec[CurrentPos - 1], Vec[CurrentPos]);
				CurrentPos++;
			}
		}
	}
}
/*!This is an implementation of HeapSort*/
void HeapSort(std::vector<int> &Vec)
{
	// Building a max heap 
	uint32_t HeapLimit = Vec.size() - 1;
	uint32_t OrderedSection = 0;

	for (int i = Vec.size() /2 ; i >= 0; --i)
	{
		BuildMaxHeap(Vec, i, HeapLimit);
		//Swap(Vec[HeapLimit], Vec[OrderedSection]);
		//printf("Order : ");
		//PrintVector(Vec);
		//OrderedSection++;
		//HeapLimit--;
	}

}

void BuildMaxHeap(std::vector<int> &Vec, int CurrentPlace, int Limit)
{
	/*!
 2*i+1 //<- get the left node
 2*i+2 //<- get the right node
 i/2-1 //<- get the parent node
 **/
 // child
	int GetLeftChild = (2 * CurrentPlace) + 1;
	int GetRightChild = (2 * CurrentPlace) + 2;
	int GetParent = (CurrentPlace - 1) / 2;

	uint32_t BiggestNumberPlace = CurrentPlace;

	printf("entering :");
	PrintVector(Vec);

	//if (CurrentPlace > 0)
	//{

	//	if (Vec[GetParent] < Vec[CurrentPlace])
	//	{
	//		printf("Swaping : %d , %d \n", Vec[GetParent], Vec[CurrentPlace]);
	//		Swap(Vec[GetParent], Vec[CurrentPlace]);
	//		BuildMaxHeap(Vec, GetParent, Limit);
	//	}

	//}
	//if (BiggestNumberPlace != 0 && Vec[GetParent] < Vec[BiggestNumberPlace])
	//{
	//	BiggestNumberPlace = GetParent;
	//}

	if (GetRightChild <= Limit && Vec[GetRightChild] > Vec[BiggestNumberPlace])
	{
		BiggestNumberPlace = GetRightChild;

		//printf("\nSwaping : %d , %d \n", Vec[GetRightChild], Vec[CurrentPlace]);
		//Swap(Vec[GetRightChild], Vec[CurrentPlace]);
		//BuildMaxHeap(Vec, GetRightChild, Limit);
	}

	if (GetLeftChild <= Limit && Vec[GetLeftChild] > Vec[BiggestNumberPlace])
	{
		BiggestNumberPlace = GetLeftChild;
		//printf("\nSwaping : %d , %d \n", Vec[GetLeftChild], Vec[CurrentPlace]);
		//Swap(Vec[GetLeftChild], Vec[CurrentPlace]);
		//BuildMaxHeap(Vec, GetLeftChild, Limit);
	//	BuildMaxHeap(Vec, CurrentPlace, Limit);

	}

	if (CurrentPlace != BiggestNumberPlace)
	{
		Swap(Vec[CurrentPlace], Vec[BiggestNumberPlace]);
		BuildMaxHeap(Vec, BiggestNumberPlace, Limit);
	}

}

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

int main()
{
	Timer timer;
	FunctionPointer ptr_BubbleSort = BubbleSort;
	FunctionPointer ptr_InsertionSort = InsertionSort;
	std::vector<int> TestVector = GenerateVectorAscendentOrder(11);

	HeapSort(TestVector);

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
