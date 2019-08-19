#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <assert.h>
#include <functional>
#include <string>
#include <utility>
#include  <cinttypes>
/*!
 * \brief this class implements the following sorting algorithms
 * [x] BubbleSort,
 * [x] insertionSort,
 * [x] heapSort,
 * [x] quickSort,
 * [x] mergeSort,
 * [x] countingSort,
 * [] radixSort,
 * [x] BucketSort
 */

class RadixFunctor
{
public:
	int operator()(int input) const
	{
		float TempForDigit = input;
		int Result = -1337;

		if (Minimum >= 10 && input <= Minimum)
		{ return 0; }


		std::string Temp = std::to_string(input);
		size_t Index = Temp.size() - Digit;

		Result = Temp[Index] - '0';


		return Result;
	}
	std::size_t Minimum = 1;
	std::size_t Digit = 1;
};

class CSorter
{
public:// constructors 
public:// functions  
	/*! bubble sort implementation*/
	void BubbleSort(std::vector<int>& UnSortedArray)

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
	void InsertionSort(std::vector<int>& UnSortedArray)
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
	/*! insertion sort for floats */
	void InsertionSort(std::vector<float>& UnSortedArray)
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

	void HeapSort(std::vector<int>& UnSortedArray,
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
	void QuickSort(std::vector<int>& UnSortedArray,
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
	//! merge sort implementation 
	void MergeSort(std::vector<int>& UnSortedArray,
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

	//! counting sort implementation 
	void CountingSort(std::vector<int>& UnSortedArray, RadixFunctor *Pred = nullptr)
	{
		if (IsEmpty(UnSortedArray))
			return;// leave function
		// find the biggest and smallest values 

		std::array<int, 2> MinMaxRange = FindRange(UnSortedArray, Pred);
		//create all possible numbers in the range
		std::vector<std::pair<int, int>> GeneratedRange;

		for (std::int64_t i = MinMaxRange[0] - 1; i < MinMaxRange[1] + 2; ++i)
		{
			// create all numbers in a range 
			GeneratedRange.emplace_back(i, 0);
		}

		if (GeneratedRange.empty())
		{
			// Something happed 
			assert(true == false);
			return;
		}

		if (Pred == nullptr)
		{
			for (std::size_t i = 0; i < GeneratedRange.size() - 1; ++i)
			{
				// Count every instance of a value 
				GeneratedRange[i].second = this->CountEachInstanceOf(UnSortedArray, GeneratedRange[i].first);
			}
		}
		else
		{
			for (std::size_t i = 0; i < GeneratedRange.size() - 1; ++i)
			{
				// Count every instance of a value 
				GeneratedRange[i].second = this->CountEachInstanceOf(UnSortedArray, GeneratedRange[i].first, Pred);
			}
		}

		for (std::size_t i = 1; i < GeneratedRange.size() - 1; ++i)
		{
			// add the count of every value.
			GeneratedRange[i].second += GeneratedRange[i - 1].second;
		}

		for (std::size_t i = GeneratedRange.size() - 1; i > 0; --i)
		{
			// rotating to the right 
			GeneratedRange[i].second = GeneratedRange[i - 1].second;
		}

		GeneratedRange[0].second = 0;
		//	for (auto Element : GeneratedRange)
		//	{
		//		std::cout << "{" << Element.second << "},";
		//	}
		//	std::cout << "\n\n";
		if (Pred == nullptr)
		{
			UnSortedArray = this->CreateSortedArrayWithCount(UnSortedArray, GeneratedRange);
		}
		else
		{
			UnSortedArray = this->CreateSortedArrayWithCount(UnSortedArray, GeneratedRange, Pred);
		}

	};

	void RadixSort(std::vector<int>& UnSortedArray)
	{
		if (IsEmpty(UnSortedArray))
			return;// leave function

		std::int64_t BiggestValue = std::numeric_limits<std::int64_t>::lowest();
		for (const auto& Element : UnSortedArray)
		{
			// find the biggest 
			(Element > BiggestValue) ? BiggestValue = Element : 0;
		}
		// find the how many digit are needed 
		std::size_t DigitCount = 0;
		while (BiggestValue > 0)
		{
			BiggestValue *= 0.1;
			DigitCount++;
		}

		RadixFunctor Functor;
		Functor.Minimum = 1;
		Functor.Digit = 1;
		for (std::size_t i = 0; i < DigitCount; ++i)
		{
			this->CountingSort(UnSortedArray, &Functor);
			Functor.Minimum *= 10;
			Functor.Digit++;

			for (auto & Element : UnSortedArray)
			{
				std::cout << '[' << Element << "],";
			}
			std::cout << "\n^^^^^^^^^^^^^^^^^^^^^^\n" << std::endl;
		}

	};
	/*! bucket sort that can take arbitrary range */
	void BucketSort(std::vector<float>& UnSortedArray)
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
	std::int64_t Partition(std::vector<int>& Array,
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
	/*! Partition Overload for RadixSort*/
	std::int64_t Partition(std::vector<std::pair<int, std::size_t>>& Array,
		std::int64_t LowerLimit,
		std::int64_t UpperLimit)
	{
		std::int64_t Result = LowerLimit - 1;
		std::int64_t PivotPos = UpperLimit;

		for (std::int64_t i = LowerLimit; i < UpperLimit; ++i)
		{
			if (Array[PivotPos].second > Array[i].second)
			{
				++Result;
				std::swap(Array[i], Array[Result]);
			}
		}
		std::swap(Array[UpperLimit], Array[Result + 1]);

		return Result + 1;
	};
	/*! make a max heap aka the biggest element is at the top */
	void BuildMaxHeap(std::vector<int>& Array,
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
	void Merge(std::vector<int> &Array,
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
	//! First one is the smallest, Second one is the biggest 
	std::array<int, 2> FindRange(std::vector<int> &Array, RadixFunctor *Pred = nullptr)
	{
		std::array<int, 2> Result =
		{
			std::numeric_limits<int>::max(),
			std::numeric_limits<int>::lowest()
		};

		if (Pred == nullptr)
		{
			for (int Value : Array)
			{
				if (Result[0] > Value)
				{
					Result[0] = Value;
				}
				if (Result[1] < Value)
				{
					Result[1] = Value;
				}
			}
		}

		else// this is for radix sort 
		{
			for (int Value : Array)
			{
				if (Result[0] > Value)
				{
					Result[0] = Pred->operator()(Value);
				}
				if (Result[1] < Value)
				{
					Result[1] = Pred->operator()(Value);
				}
			}
		}

		return Result;
	}
	//! count the total times a value is repeated 
	std::size_t CountEachInstanceOf(std::vector<int> &Array, int SearchValue, RadixFunctor *Pred = nullptr)
	{
		std::size_t Result = 0;
		if (Pred == nullptr)
		{
			for (const auto& Value : Array)
			{
				(Value == SearchValue) ? Result++ : 0;
			}

			return Result;
		}
		else
		{
			for (const auto& Value : Array)
			{
				(Pred->operator()(Value) == SearchValue) ? Result++ : 0;
			}
			return Result;
		}
	};

	//! Help Function for counting sort for placing the value in the appropriate place in the array 
	std::vector<int> CreateSortedArrayWithCount(std::vector<int> &UnSortedArray,
		const std::vector<std::pair<int, int>> &ValueAndCount,
		RadixFunctor *Pred = nullptr)
	{

		std::size_t UnSortedIndex = 0;
		std::vector<int> Result(UnSortedArray.size(), -1337);

		for (std::size_t i = 0; i < ValueAndCount.size() - 1; ++i)
		{
			// compare starting indexes and get the difference 
			std::size_t Difference = GetDiff(ValueAndCount[i].second, ValueAndCount[i + 1].second);
			while (Difference != 0)
			{
				// with no predicate
				if (Pred == nullptr)
				{
					for (auto& Element : UnSortedArray)
					{
						if (Difference == 0)
							break;
						if (ValueAndCount[i].first == Element)
						{
							Result[UnSortedIndex] = Element;
							UnSortedIndex++;
							--Difference;
						}
					}
				}
				else//this is for radix sort 
				{
					for (auto& Element : UnSortedArray)
					{
						if (Difference == 0)
							break;
						if (Pred->operator()(ValueAndCount[i].first) == Pred->operator()(Element))
						{
							Result[UnSortedIndex] = Element;
							UnSortedIndex++;
							--Difference;
						}
					}
				}
			}

		}

		return Result;
	};

	std::size_t GetDiff(std::size_t OldPoint,
		std::size_t NewPoint)
	{
		return NewPoint - OldPoint;
	}

	void DictateLocationWithPredicate(std::vector<std::pair<int, std::size_t>>& OriginalAndPlacement, RadixFunctor &Pred)
	{
		for (auto& Pair : OriginalAndPlacement)
		{
			Pair.second = Pred.operator()(Pair.first);
			std::cout << Pair.second << ",";
		}
		std::cout << "\n---------------------\n" << std::endl;
	}

	/*! QuickSort Overload for radixSort */
	void QuickSort(std::vector<std::pair<int, std::size_t>>& UnSortedArray,
		std::int64_t LowerLimit,
		std::int64_t UpperLimit)
	{

		if (LowerLimit < UpperLimit)
		{
			std::int64_t Pivot = Partition(UnSortedArray, LowerLimit, UpperLimit);
			this->QuickSort(UnSortedArray, LowerLimit, Pivot - 1);
			this->QuickSort(UnSortedArray, Pivot + 1, UpperLimit);
		}

	};
};

