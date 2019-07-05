#include "Hash.h"
#include "UtilityFunctions.h"
#include <iostream>

void PrintHashTable(const std::map<int, std::vector<int>> &Table)
{

	for (auto Buckit : Table)
	{
		for (auto Element : Buckit.second)
		{
			std::cout << Element << ",";
		}
		std::cout << "||||||END OF BUCKIT||||||\n";
	}
	std::cout << std::endl;

}


int main()
{
	Hash Hasher;

	auto Vector = GenerateVectorAscendentOrder(5000);

	auto HashTable = Hasher.MultipilcativeHash(Vector);

	PrintHashTable(HashTable);

	int a = 4; 
	return a;
}