#pragma once
#include <vector>
#include <random>
#include <ctime>
#include <cstdio>


void Swap(int &LeftSideValue, int &RightSideValue);
/*! this generates a has table */
std::map<int, std::vector<int>> GenerateHashTable(std::vector<int> &Vec);

/*! to swap 2 elements*/
inline void Swap(int &LeftSideValue, int &RightSideValue)
{
	int Temp = LeftSideValue;
	LeftSideValue = RightSideValue;
	RightSideValue = Temp;
}

/*! to swap 2 floats */
inline void Swap(float &LeftSideValue, float &RightSideValue)
{
	float Temp = LeftSideValue;
	LeftSideValue = RightSideValue;
	RightSideValue = Temp;
}

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
/*! Generates a vector with float */
std::vector<float> GenerateVectorRandomOrderF(int Range, int Size)
{
	std::vector<float> Results;

	for (int i = 0; i < Size; i++)
	{
		float Element = rand() % Range + (float) rand() / RAND_MAX;
		Results.emplace_back(Element);
	}

	return Results;
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

