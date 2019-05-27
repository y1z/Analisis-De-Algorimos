#pragma once
#include <vector> 
#include "UtilityFunctions.h"
/// Forward declarations 
/*! functions that help the sorting functions */
void BuildMaxHeap(std::vector<int> &Vec, int CurrentPlace, int Limit);
void Merge(std::vector<int> &Vec, int LowerLimit, int middle, int UpperLimit);
void QuickSort(std::vector<int> &Vec, int LowerLimit, int UpperLimit);
int Partition(std::vector<int> &Vec, int LowerLimit, int UpperLimit);
/*! Starter functions, aka functions for the benchmarking function 
so i don't have to rewrite that function*/
void StartHeapSort(std::vector<int> &Vec);
void StartQuickSort(std::vector<int> &Vec);
void StartMergeSort(std::vector<int> &Vec);


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
void HeapSort(std::vector<int> &Vec, int LowerLimit, int UpperLimit)
{
	// Building a max heap 
	uint32_t HeapLimit = Vec.size() - 1;
	uint32_t OrderedSection = 0;

	for (int i = (Vec.size() / 2); i >= 0; --i)
	{
		BuildMaxHeap(Vec, i, UpperLimit);
	}
	Swap(Vec[UpperLimit], Vec[LowerLimit]);

	UpperLimit--;

	if (LowerLimit < UpperLimit)
	{
		HeapSort(Vec, LowerLimit, UpperLimit);
	}

}
/*! finds the biggest number */
void BuildMaxHeap(std::vector<int> &Vec, int CurrentPlace, int Limit)
{
	/*!
 2*i+1 //<- get the left node
 2*i+2 //<- get the right node
 **/
 // child
	int GetLeftChild = (2 * CurrentPlace) + 1;
	int GetRightChild = (2 * CurrentPlace) + 2;
	int GetParent = (CurrentPlace - 1) / 2;

	uint32_t BiggestNumberPlace = CurrentPlace;

	if (GetLeftChild <= Limit && (Vec[GetLeftChild] > Vec[BiggestNumberPlace]))
	{
		BiggestNumberPlace = GetLeftChild;
	}

	if (GetRightChild <= Limit && (Vec[GetRightChild] > Vec[BiggestNumberPlace]))
	{
		BiggestNumberPlace = GetRightChild;
	}

	if (CurrentPlace != BiggestNumberPlace)
	{
		Swap(Vec[CurrentPlace], Vec[BiggestNumberPlace]);
		//BuildMaxHeap(Vec, BiggestNumberPlace, Limit);
		BuildMaxHeap(Vec, CurrentPlace, Limit);
	}


}
/*! this is to start the merge sort*/
void MergeSort(std::vector<int> &Vec, int LowerLimit, int UpperLimit)
{
	int Pivot = (UpperLimit + LowerLimit) / 2;

	if (LowerLimit < UpperLimit)
	{
		MergeSort(Vec, LowerLimit, Pivot);

		MergeSort(Vec, Pivot + 1, UpperLimit);

		Merge(Vec, LowerLimit, Pivot, UpperLimit);
	}


}
/*! for ordering the resulting 'arrays'*/
void Merge(std::vector<int> &Vec, int LowerLimit, int middle, int UpperLimit)
{
	// for when the array is bigger than 1
	int LowerArea = middle - LowerLimit;
	int UpperArea = UpperLimit - middle;

	if (LowerArea > 1 || UpperArea > 1)
	{
		QuickSort(Vec, LowerLimit, UpperLimit);
	}
	// for the case that there are only 2 elements to be sorted 
	else if (Vec[LowerLimit] > Vec[UpperLimit])
	{
		Swap(Vec[LowerLimit], Vec[UpperLimit]);
	}

}
/*! this is to help find a pivot for quick-sort*/
int Partition(std::vector<int> &Vec, int LowerLimit, int UpperLimit)
{
	int GreaterThanPivotCount = LowerLimit - 1;
	int PivotPos = UpperLimit;

	for (int i = LowerLimit; i < UpperLimit; ++i)
	{

		if (Vec[PivotPos] > Vec[i])
		{
			++GreaterThanPivotCount;
			Swap(Vec[i], Vec[GreaterThanPivotCount]);
		}

	}
	Swap(Vec[UpperLimit], Vec[GreaterThanPivotCount + 1]);

	return GreaterThanPivotCount + 1;
}

/*! this is going to used in the merge-sort*/
void QuickSort(std::vector<int> &Vec, int LowerLimit, int UpperLimit)
{
	if (LowerLimit < UpperLimit)
	{
		int Pivot = Partition(Vec, LowerLimit, UpperLimit);
		//PrintVector(Vec);
		QuickSort(Vec, LowerLimit, Pivot - 1);
		QuickSort(Vec, Pivot + 1, UpperLimit);
	}
}


inline void StartHeapSort(std::vector<int>& Vec)
{
	HeapSort(Vec, 0, Vec.size() - 1);
}

inline void StartQuickSort(std::vector<int>& Vec)
{
	QuickSort(Vec, 0, Vec.size() - 1);
}

inline void StartMergeSort(std::vector<int>& Vec)
{
	MergeSort(Vec, 0, Vec.size() - 1);
}
