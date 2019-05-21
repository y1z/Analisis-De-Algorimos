#pragma once
#include <vector>
#include <ctime>
/*! output of the vector is 1,2,3,4,5,6,7,8,9 etc...*/
std::vector<int> GenerateVectorAscendentOrder(int Size)
{
	std::vector<int> Result;

	Result.reserve(Size);

	for (int i = 0; i < Size; ++i)
	{
		Result.push_back(i);
	}

	return Result;
}

/*! output of the vector is 9,8,7,6,5,4,3,2,1*/
std::vector<int> GenerateVectorDescendantOrder(int Size)
{
	std::vector<int> Result;

	Result.reserve(Size);

	for (int i = 0; i < Size; ++i)
	{
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

	for (int i = 0; i < Size; ++i)
	{
		Result.push_back(rand());
	}

	return Result;
}

/*! Just to print every element of a vector */
void PrintVector(const std::vector<int> &Vec)
{
	for (auto Element : Vec)
	{
		printf("[%d] ", Element);
	}
	printf("\n");
}