#pragma once
#include <vector>

/*! this  is a template because linear search is so simple you can
convert this algorithms to a template without trouble*/
template<class T>
bool LinearSearch(std::vector<T> &Vec, T &ItemToFind);
/*! BinarySearch Requires that the array already be sorted */
bool BinarySearchStart(std::vector<int> &Vec, int Number);
/*! does the binary search Recursively*/
bool BinarySearch(std::vector<int> &Vec, int Number, std::size_t LeftHalf, std::size_t RightHalf);

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

	if (LeftHalf < RightHalf)
	{
		if (Number == Vec[SearchPoint])
		{
			return true;
		}/*Move to the right */
		else if (Number > Vec[SearchPoint])
		{
			LeftHalf += (RightHalf / 2);
			BinarySearch(Vec, Number, LeftHalf, RightHalf);
		}
		else/*Move to the left*/
		{
			RightHalf /= 2;
			BinarySearch(Vec, Number, LeftHalf, RightHalf);
		}

	}


	return false;
}

