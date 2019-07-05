#pragma once
#include <cmath>
#include <cinttypes>
#include <vector>
#include <map>
class Hash
{
public:
	Hash();
	~Hash();

	std::map<int, std::vector<int>> DivisionHash(std::vector<int>& Vec);
	std::map<int, std::vector<int>> MultipilcativeHash(std::vector<int>& Vec);
	//void MulHash

private:

	static constexpr const uint32_t m_HashDelimiter = 101;
};