#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "VectorProcessor.h"
#include <iterator>

using namespace std;

bool ReadVector(vector<double> & result, string & error)
{
	result.assign(istream_iterator<double>(cin), istream_iterator<double>());
	return true;
}

void PrintVector(vector<double> numbers)
{
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, " "));
}

int main(int argc)
{
	string errorMessage;
	vector <double> numbers;
	ReadVector(numbers, errorMessage);
	SortVector(numbers);
	PrintVector(numbers);

	cout << endl;
	return 0;
}