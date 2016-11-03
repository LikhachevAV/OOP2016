#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "MapProcessor.h"
#include <iterator>

using namespace std;

void PrintVector(vector<double> numbers)
{
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, " "));
}

int main()
{
	vector <double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
	ProcessVector(numbers);
	SortVector(numbers);
	PrintVector(numbers);
	cout << endl;
	return 0;
}