#include "stdafx.h"
#include <iostream>
#include <set>
#include "SetProcessor.h"

using namespace std;

int GetSumOfNumbersNumerals(int number)
{
	number = abs(number);
	int sum = 0;
	while (number >= 1)
	{
		int summand = number % 10;
		sum += summand;
		number /= 10;
	}
	return sum;
}

void main()
{
	int N = -404;
	int r = GetSumOfNumbersNumerals(N);
	set<int> set1;
	for (int i = 0; i < 10; ++i)
	{
		set1.insert(i);
	}
}