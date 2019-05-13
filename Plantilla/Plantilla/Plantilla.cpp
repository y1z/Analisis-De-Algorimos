#include <vector>
#include <random>
#include <chrono>
#include "..//..//Timer/Timer.h"

/*! output of the vector is 1,2,3,4,5,6,7,8,9 etc...*/
std::vector<int> GenerateVectorAscendentOrder(int Size)
{
	std::vector<int> Result;

	Result.reserve(Size);

	for (int i = 0; i < Size; ++i) {
		Result.push_back(i);
	}

	return Result;
}

/*! output of the vector is 9,8,7,6,5,4,3,2,1*/
std::vector<int> GenerateVectorDescendantOrder(int Size)
{
	std::vector<int> Result;

	Result.reserve(Size);

	for (int i = 0; i < Size; ++i) {
		Result.push_back(Size - i);
	}

	return Result;
}

/*! every element of the vector is random*/
std::vector<int> GenerateVectorRandomOrder(int Size)
{
	std::vector<int> Result;

	Result.reserve(Size);
	srand(time(0));

	for (int i = 0; i < Size; ++i) {
		Result.push_back(rand());
	}

	return Result;
}

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
				if (Vec[j] > Vec[j + 1]) {
					Swap(Vec[j], Vec[j + 1]);
					//isSorted = false;
				}
			}
			
			if (isSorted) { break; }

			isSorted = true;
		}
}
/*! this is an implementation of Insertion-sort*/
void InsertionSort(std::vector<int> &Vec)
{
	for (int i = Vec.size() - 1; i > 0; --i) {

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

/*! Just to print every element of a vector */
void PrintVector(const std::vector<int> &Vec) {
	for (auto Element : Vec) {
		printf("[%d] ", Element);
	}
	printf("\n");
}


int main()
{
	Timer timer;

	std::vector<int> TestVector = GenerateVectorDescendantOrder(100);

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
