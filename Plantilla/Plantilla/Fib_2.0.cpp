#include "Fib_2.0.h"

uint64_t Fib(int N)
{
	static std::map<int, uint64_t> StoredResults;

	auto StoredResult = StoredResults.find(N);

	if (StoredResult != StoredResults.end())
	{
		return StoredResult->second;
	}

	uint64_t FirstResult = 0;
	uint64_t SecondResult = 1;

	if (N == 0) { FirstResult; }
	if (N == 1) { SecondResult; }
	
	uint64_t Result = 0;

	for (int i = 0; i < N - 2; ++i)
	{
		Result = FirstResult + SecondResult;
		FirstResult = SecondResult;
		SecondResult = Result;
	}
	StoredResults.insert(std::make_pair(N, Result));

	return Result;
}
