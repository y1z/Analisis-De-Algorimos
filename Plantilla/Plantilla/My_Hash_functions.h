#pragma once
#include <map>
#include <vector>
#include "Search_Header.h"
// this is all has function work on the same delimiter 
int constexpr static HashDelimiter = 37;

/*! will be used to find elements in the hashTable*/
bool SearchHashTable(std::map<int, std::vector<int>> &HashTable, int SearchValue);

std::map<int, std::vector<int>> GenerateHashTable(std::vector<int> &Vec);

inline std::map<int, std::vector<int>> GenerateHashTable(std::vector<int>& Vec)
{
	// This is temporary 
	std::map<int, std::vector<int>> HashTable;
	for (int Value : Vec)
	{
		int Key = Value % HashDelimiter;
		auto isInserted = HashTable.find(Key);
		if (isInserted == HashTable.end())
		{
			std::vector<int> Buckit;
			HashTable.insert(std::make_pair(Key, Buckit));
		}
		else
		{
			isInserted->second.emplace_back(Value);
		}
	}
	return HashTable;
}

inline bool SearchHashTable(std::map<int, std::vector<int>>& HashTable, int SearchValue)
{
	int KeyLocation = SearchValue % HashDelimiter;

	auto PossibleMapLocaction = HashTable.find(KeyLocation);
	if (PossibleMapLocaction == HashTable.end())
	{
		return false;
	}
	else
	{
		return LinearSearch(PossibleMapLocaction->second, SearchValue);
	}
	return false;
}