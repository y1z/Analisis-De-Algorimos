#include "Hash.h"
Hash::Hash()
{}

Hash::~Hash()
{}
// generated within the function 
std::map<int, std::vector<int>> Hash::DivisionHash(std::vector<int>& Vec)
{
	std::map<int, std::vector<int>> Result;

	for (int Value : Vec)
	{
		int Key = Value % m_HashDelimiter;
		auto isInserted = Result.find(Key);
		if (isInserted == Result.end())
		{
			std::vector<int> Buckit;
			Result.insert(std::make_pair(Key, Buckit));
		}
		else
		{
			isInserted->second.emplace_back(Value);
		}
	}
	return Result;
}

std::map<int, std::vector<int>> Hash::MultipilcativeHash(std::vector<int>& Vec)
{

	std::map<int, std::vector<int>> Result;

	for (int Value : Vec)
	{
		float NumAndFraction = 0.6180339887f * Value;
		// para separar tomar tomar el componente fracionario 
		int Num = NumAndFraction;
		float JustFraction = NumAndFraction - Num;

		int key = JustFraction * 2048;

		auto isInserted = Result.find(key);
		if (isInserted == Result.end())
		{
			std::vector<int> Buckit;
			Result.insert(std::make_pair(key, Buckit));
		}
		else
		{
			isInserted->second.emplace_back(Value);
		}
	}
	return Result;
}
