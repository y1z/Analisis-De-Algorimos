#pragma once
#include <vector>
#include <map>
#include <iostream>

/*! this  is a template because linear search is so simple you can
convert this algorithms to a template without trouble, and it searches
all the element 1 by 1.*/
template<class T>
bool LinearSearch(std::vector<T> &Vec, T &ItemToFind);
/*! BinarySearch Requires that the array already be sorted */
bool BinarySearchStart(std::vector<int> &Vec, int Number);
/*! does the binary search Recursively*/
bool BinarySearch(std::vector<int> &Vec, int Number, std::size_t LeftHalf, std::size_t RightHalf);
/*! this function is used to test the other search functions */
void SearchTesting(std::vector<int> &Vec);


template<class T>
inline bool LinearSearch(std::vector<T> &Vec, T &ItemToFind)
{
	for (auto PossibleMatch : Vec)
	{
		if (PossibleMatch == ItemToFind)
		{
			return true;
		}
	}

	return false;
}

inline bool BinarySearchStart(std::vector<int>& Vec, int Number)
{
	std::size_t RightHalf = Vec.size() - 1;
	std::size_t LeftHalf = 0;

	return BinarySearch(Vec, Number, LeftHalf, RightHalf);
}

inline bool BinarySearch(std::vector<int>& Vec, int Number, std::size_t LeftHalf, std::size_t RightHalf)
{
	std::size_t SearchPoint = (LeftHalf + RightHalf) / 2;

	if (Number == Vec[SearchPoint])
	{
		return true;
	}

	/*This is so we don't have stack-overflow*/
	if (LeftHalf < RightHalf - 1)
	{/*Move to the right */

		if (Number > Vec[SearchPoint])
		{
			LeftHalf = (RightHalf + LeftHalf) / 2;
			return	BinarySearch(Vec, Number, LeftHalf, RightHalf);
		}
		else/*Move to the left*/
		{
			RightHalf = (RightHalf + LeftHalf) / 2;
			return	BinarySearch(Vec, Number, LeftHalf, RightHalf);
		}

	}
	else// this is for when there are only options 2 left
	{
		if (Vec[LeftHalf] == Number)
		{
			return true;
		}
		else if (Vec[RightHalf] == Number)
		{
			return true;
		}

	}

	return false;
}

void SearchTesting(std::vector<int> &Vec)
{
	int SearchNumber = 0;
	int Algorithms = 0;
	printf_s("Tell me a number to look for \n");
	std::cin >> SearchNumber;
	printf_s("now tell me the method to use  \n");
	printf("1) Linear Search\n");
	printf("2) Binary Search\n");
	std::cin >> Algorithms;

	bool isFound = false;

	switch (Algorithms)
	{
	case(1):
		isFound = LinearSearch(Vec, SearchNumber);
		break;
	case(2):
		isFound = BinarySearchStart(Vec, SearchNumber);
		break;
	default:
		break;
	}
	if (isFound)
	{
		printf("Yes we found %d", SearchNumber);
	}
	else
	{
		printf("No we could not find %d", SearchNumber);
	}
	printf("\n\n would you like to search again ");
	bool SearchAgain = false;
	printf("\n 1) Yes \n 0) No \n");
	std::cin >> SearchAgain;

	if (SearchAgain) { SearchTesting(Vec); }



}



