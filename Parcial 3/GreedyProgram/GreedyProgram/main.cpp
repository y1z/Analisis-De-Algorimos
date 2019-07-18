#include <iostream>

enum Coin
{
	Penny = 1,
	Penny2 = 2,
	Penny5 = 5,
	Penny10 = 10
};
//! increament 
auto IncreamentPennys =  [&](unsigned int &CoinCount,unsigned int &Value, Coin CoinAmount)
{
	Value += CoinAmount;
	CoinCount++;
	std::cout << Value << " Value " << '\n';
	std::cout << CoinCount << " Count of Coins" << '\n';
};


unsigned int AddCoins(unsigned int Total, unsigned int &CoinCount, unsigned int& Value)
{

	
	if (Value + Coin::Penny10 <= Total)
	{
		IncreamentPennys(CoinCount, Value, Coin::Penny10);
		AddCoins(Total, CoinCount, Value);
		return CoinCount;// to avoid unnecesary if's 
	}
	else	if (Value + Coin::Penny5 <= Total)
	{
		IncreamentPennys(CoinCount, Value, Coin::Penny5);
		AddCoins(Total, CoinCount, Value);
		return CoinCount;
	}
	else	if (Value + Coin::Penny2 <= Total)
	{
		IncreamentPennys(CoinCount, Value, Coin::Penny2);
		AddCoins(Total, CoinCount, Value);
		return CoinCount;
	}
	else	if (Value + Coin::Penny <= Total)
	{
		IncreamentPennys(CoinCount, Value, Coin::Penny);
		AddCoins(Total, CoinCount, Value);
		return CoinCount;
	}

	return 0;
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


	unsigned int Result = AddCoins(GloalValue, CoinCount, CurrentTotalValue);
	std::cout << "\nHere is the Result " << Result;

	Stop();

	//while (CurrentTotalValue < TotualGoal)
	//{

	//	std::cout << CurrentTotalValue << '\n';
	//	std::cout << CoinCount << '\n';

	//	if (CurrentTotalValue + Coin::Penny10 <= TotualGoal)
	//	{
	//		CurrentTotalValue += Coin::Penny10;
	//		CoinCount++;
	//		continue;
	//	}
	//	else if (CurrentTotalValue + Coin::Penny5 <= TotualGoal)
	//	{
	//		CurrentTotalValue += Coin::Penny5;
	//		CoinCount++;
	//		continue;
	//	}
	//	else if (CurrentTotalValue + Coin::Penny2 <= TotualGoal)
	//	{
	//		CurrentTotalValue += Coin::Penny2;
	//		CoinCount++;
	//		continue;
	//	}
	//	else if (CurrentTotalValue + Coin::Penny <= TotualGoal)
	//	{
	//		CurrentTotalValue += Coin::Penny;
	//		CoinCount++;
	//		continue;
	//	}


	//}
	//std::cout << CurrentTotalValue << '\n';
	//std::cout << CoinCount << '\n';


	return 0;
}




