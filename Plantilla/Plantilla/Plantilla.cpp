#include <vector>
#include <random>
#include <chrono>
#include "..//..//Timer/Timer.h"

/*! output of the vector is 1,2,3,4,5,6,7,8,9 etc...*/
std::vector<int> GenerateVectorAcendiente(int Size)
{
	std::vector<int> Result;

	Result.reserve(Size);

	for (int i = 0; i < Size; ++i) {
		Result.push_back(i);

	}

	return Result;
}

/*! output of the vector is 9,8,7,6,5,4,3,2,1*/
std::vector<int> GenerateVectorDecendent(int Size)
{
	std::vector<int> Result;

	Result.reserve(Size);

	for (int i = 0; i < Size; ++i) {
		Result.push_back(Size - i);

	}

	return Result;
}

/*! every element of the vector is random*/
std::vector<int> GenerateVectorRandom(int Size)
{
	std::vector<int> Result;

	Result.reserve(Size);
	srand(time(0));

	for (int i = 0; i < Size; ++i) {
		Result.push_back(rand());
	}

	return Result;
}


int main() {
	Timer timer;

	timer.StartTiming();
	std::vector<int> best = GenerateVectorAcendiente(600);
	timer.EndTiming();
	for (auto elemento : best) {
		printf("[%d]", elemento);
	}
	timer.GetResult();
	return 0;
}
