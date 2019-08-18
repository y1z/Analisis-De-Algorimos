#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
#include  <cinttypes>
/*!
 * \brief this class implements the following sorting algorithms
 * [x] BubbleSort,
 * [x] insertionSort,
 * [x] heapSort,
 * [x] quickSort,
 * [x] mergeSort,
 * [] countingSort,
 * [] radixSort,
 * [] BucketSort
 */
   
class CSorter
{
public:// constructors 
public:// functions  
	/*! bubble sort implementation*/
	void
		BubbleSort(std::vector<int>& UnSortedArray)

	{
		if (IsEmpty(UnSortedArray))
			return;// leave 

		for (std::size_t i = 0; i < UnSortedArray.size() - 1; ++i)
		{
			for (std::size_t j = 0; j < UnSortedArray.size() - 1; ++j)
			{
				if (UnSortedArray[j] > UnSortedArray[j + 1])
				{
					std::swap(UnSortedArray[j], UnSortedArray[j + 1]);
				}

			}

		}

	};
	/*! InsertionSort Implementation*/
	void
		InsertionSort(std::vector<int>& UnSortedArray)
	{
		if (IsEmpty(UnSortedArray))
			return;// leave 

		for (std::size_t i = UnSortedArray.size() - 1; i > 0; --i)
		{
			if (UnSortedArray[i] < UnSortedArray[i - 1])
			{
				std::size_t  CurrentPos = i;
				// don't go out of bounds 
				while (CurrentPos <= (UnSortedArray.size() - 1)
					&& UnSortedArray[CurrentPos] < UnSortedArray[CurrentPos - 1])
				{
					std::swap(UnSortedArray[CurrentPos], UnSortedArray[CurrentPos - 1]);
					CurrentPos++;
				}

			}

		}

	};

	void
		InsertionSort(std::vector<float>& UnSortedArray)
	{
		for (std::size_t i = UnSortedArray.size() - 1; i > 0; --i)
		{
			if (UnSortedArray[i] < UnSortedArray[i - 1])
			{
				std::int64_t  CurrentPos = i;
				// don't go out of bounds 
				while (CurrentPos <= (UnSortedArray.size() - 1)
					&& UnSortedArray[CurrentPos] < UnSortedArray[CurrentPos - 1])
				{
					std::swap(UnSortedArray[CurrentPos], UnSortedArray[CurrentPos - 1]);
					CurrentPos++;
				}

			}

		}

	};

	void
		HeapSort(std::vector<int>& UnSortedArray,
			std::size_t LowerLimit,
			std::size_t UpperLimit)
	{
		if (IsEmpty(UnSortedArray))
			return;// leave 
		// Building a max heap 
		std::size_t HeapLimit = UnSortedArray.size() - 1;
		std::size_t OrderedSection = 0;

		for (std::size_t i = (UnSortedArray.size() / 2); i >= 0; --i)
		{
			this->BuildMaxHeap(UnSortedArray, i, UpperLimit);
		}

		std::swap(UnSortedArray[UpperLimit], UnSortedArray[LowerLimit]);

		UpperLimit--;

		if (LowerLimit < UpperLimit)
		{
			this->HeapSort(UnSortedArray, LowerLimit, UpperLimit);
		}
	};
	/*! QuickSort Implementation */
	void
		QuickSort(std::vector<int>& UnSortedArray,
			std::int64_t LowerLimit,
			std::int64_t UpperLimit)
	{
		if (IsEmpty(UnSortedArray))
			return;// leave 

		if (LowerLimit < UpperLimit)
		{
			std::int64_t Pivot = Partition(UnSortedArray, LowerLimit, UpperLimit);
			this->QuickSort(UnSortedArray, LowerLimit, Pivot - 1);
			this->QuickSort(UnSortedArray, Pivot + 1, UpperLimit);
		}

	};

	void
		MergeSort(std::vector<int>& UnSortedArray,
			std::size_t LowerLimit,
			std::size_t UpperLimit)
	{
		if (IsEmpty(UnSortedArray))
			return;// leave 

		std::size_t Pivot = (UpperLimit + LowerLimit) / 2;

		if (LowerLimit < UpperLimit)
		{
			this->MergeSort(UnSortedArray, LowerLimit, Pivot);

			this->MergeSort(UnSortedArray, Pivot + 1, UpperLimit);

			this->Merge(UnSortedArray, LowerLimit, Pivot, UpperLimit);
		}

	};

	void
		CountingSort(std::vector<int>& UnSortedArray)
	{
		if (IsEmpty(UnSortedArray))
			return;// leave function

	};

	void
		RadixSort(std::vector<int>& UnSortedArray)
	{
		if (IsEmpty(UnSortedArray))
			return;// leave function
		
	};
	/*! bucket sort that can take arbitrary range */

	void
		BucketSort(std::vector<float>& UnSortedArray)
	{
		if (IsEmpty(UnSortedArray))
			return;// leave function

		static constexpr std::size_t TotalBuckets = 100;

		float BiggestValue = std::numeric_limits<float>::min();
		for (std::size_t i = 0; i < UnSortedArray.size() - 1; ++i)
		{
			// assign the BiggestValue 
			BiggestValue < UnSortedArray[i] ? BiggestValue = UnSortedArray[i] : 0;
		}
		// this value will normalize all other value to the range 0.0 ... 1.0 
		float NormalizingValue = (1 / BiggestValue);

		// make one hundred buckets 
		std::vector<std::vector<float>> Buckets(TotalBuckets, std::vector<float>());

		// Place the corresponding elements in the appropriate bucket 
		for (const float& Element : UnSortedArray)
		{
			std::size_t PlacementValue = (NormalizingValue * Element) * (TotalBuckets - 1);
			Buckets[PlacementValue].emplace_back(Element);
		}
		// sort the buckets 
		for (auto& Vector : Buckets)
		{
			if (!Vector.empty())
			{
				this->InsertionSort(Vector);
			}
		}

		std::size_t UnSortedIndex = 0;
		// Place the 
		for (auto& Vector : Buckets)
		{
			for (auto &VectorElement : Vector)
			{

				UnSortedArray[UnSortedIndex] = VectorElement;
				++UnSortedIndex;
			}

		}


	};

private:// functions that help with sorting 
	//! helps quick sort find it's partition 
	std::int64_t
		Partition(std::vector<int>& Array,
			std::int64_t LowerLimit,
			std::int64_t UpperLimit)
	{
		std::int64_t Result = LowerLimit - 1;
		std::int64_t PivotPos = UpperLimit;

		for (std::int64_t i = LowerLimit; i < UpperLimit; ++i)
		{
			if (Array[PivotPos] > Array[i])
			{
				++Result;
				std::swap(Array[i], Array[Result]);
			}
		}
		std::swap(Array[UpperLimit], Array[Result + 1]);

		return Result + 1;
	};
	/*! make a max heap aka the biggest element is at the top */
	void
		BuildMaxHeap(std::vector<int>& Array,
			std::size_t CurrentIndex,
			std::size_t Limit)
	{
		std::size_t GetLeftChild = (2 * CurrentIndex) + 1;
		std::size_t GetRightChild = (2 * CurrentIndex) + 2;

		std::size_t BiggestValueIndex = CurrentIndex;

		if (GetLeftChild <= Limit && (Array[GetLeftChild] > Array[BiggestValueIndex]))
		{
			// Get the left Child 
			BiggestValueIndex = GetLeftChild;
		}

		if (GetRightChild <= Limit && (Array[GetRightChild] > Array[BiggestValueIndex]))
		{
			BiggestValueIndex = GetRightChild;
		}

		if (CurrentIndex != BiggestValueIndex)
		{
			std::swap(Array[CurrentIndex], Array[BiggestValueIndex]);
			//BuildMaxHeap(Vec, BiggestNumberPlace, Limit);
			this->BuildMaxHeap(Array, CurrentIndex, Limit);
		}

	};
	/*! merges the resulting arrays in mergeSort*/
	void
		Merge(std::vector<int> &Array,
			std::size_t LowerLimit,
			std::size_t Middle,
			std::size_t UpperLimit)
	{
		std::size_t LowerArea = Middle - LowerLimit;
		std::size_t UpperArea = UpperLimit - Middle;

		if (LowerArea > 1 || UpperArea > 1)
		{
			this->QuickSort(Array, LowerLimit, UpperLimit);
		}
		// for the case that there are only 2 elements to be sorted 
		else if (Array[LowerLimit] > Array[UpperLimit])
		{
			std::swap(Array[LowerLimit], Array[UpperLimit]);
		}

	};

	bool IsEmpty(std::vector<int> &Array)
	{
		if (Array.empty())
			return true;

		return false;
	}

	bool IsEmpty(std::vector<float> &Array)
	{
		if (Array.empty())
			return true;

		return false;
	}
};

