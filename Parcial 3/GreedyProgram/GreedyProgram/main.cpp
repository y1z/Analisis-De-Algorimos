#include <iostream>

enum Coin
{
	Penny = 1,
	Penny2 = 2,
	Penny5 = 5,
	Penny10 = 10
};
//! increment the penny's and makes the code cleaner 
auto IncrementPennys =  [&](unsigned int &CoinCount,unsigned int &Value, Coin CoinAmount)
{
	Value += CoinAmount;
	CoinCount++;
	std::cout << Value << " Value " << '\n';
	std::cout << CoinCount << " Count of Coins" << '\n';
};

//! add coins in the most efficient form possible 
unsigned int RecursiveAddCoins(unsigned int Total, unsigned int &CoinCount, unsigned int& Value)
{
	if (Value + Coin::Penny10 <= Total)
	{
		IncrementPennys(CoinCount, Value, Coin::Penny10);
		RecursiveAddCoins(Total, CoinCount, Value);
		return CoinCount;// to avoid unnecesary if's 
	}
	else	if (Value + Coin::Penny5 <= Total)
	{
		IncrementPennys(CoinCount, Value, Coin::Penny5);
		RecursiveAddCoins(Total, CoinCount, Value);
		return CoinCount;
	}
	else	if (Value + Coin::Penny2 <= Total)
	{
		IncrementPennys(CoinCount, Value, Coin::Penny2);
		RecursiveAddCoins(Total, CoinCount, Value);
		return CoinCount;
	}
	else	if (Value + Coin::Penny <= Total)
	{
		IncrementPennys(CoinCount, Value, Coin::Penny);
		RecursiveAddCoins(Total, CoinCount, Value);
		return CoinCount;
	}

	return 0;
}
/*! Add Coins in the most efficient form possible */
unsigned int IterativeAddCoins(unsigned int Total, unsigned int &CoinCount, unsigned int& Value)
{
	while (Value < Total)
	{
		std::cout << Value << '\n';
		std::cout << CoinCount << '\n';
		if (Value + Coin::Penny10 <= Total)
		{
			Value += Coin::Penny10;
			CoinCount++;
			continue;
		}
		else if (Value + Coin::Penny5 <= Total)
		{
			Value += Coin::Penny5;
			CoinCount++;
			continue;
		}
		else if (Value + Coin::Penny2 <= Total)
		{
			Value += Coin::Penny2;
			CoinCount++;
			continue;
		}
		else if (Value + Coin::Penny <= Total)
		{
			Value += Coin::Penny;
			CoinCount++;
			continue;
		}

	}
	std::cout << Value << '\n';
	std::cout << CoinCount << '\n';
	return CoinCount;
}

void Stop()
{
	std::cin.ignore();
	std::cin.get();
}

int main()
{
	unsigned int GloalValue = 72;
	unsigned int CurrentTotalValue = 0;
	unsigned int CoinCount = 0;

	printf("Give me a positive number and i will give you minimal number of coins needed to achive the result \n");
	printf("the value we have access to are 10,5,2 and 1 \n");
	printf("Give me a positive Value ");
	std::cin >> GloalValue;


	unsigned int Result = RecursiveAddCoins(GloalValue, CoinCount, CurrentTotalValue);
	std::cout << "\nHere is the Result " << Result;

	Stop();

	return 0;
}
