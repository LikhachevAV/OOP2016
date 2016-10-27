#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "VectorProcessor.h"
#include <iterator>

using namespace std;

bool ReadVector(string const & fileName, vector<double> & result, string & error)
{
	ifstream inputFile(fileName);
	if (!inputFile.is_open())
	{
		error.append("File ")
			.append(fileName)
			.append(" reading error!");
		return false;
	}
	result.assign(istream_iterator<double>(cin), istream_iterator<double>());

	if (inputFile.fail())
	{
		error.append("Input file have non double numbers");
		return false;
	}
	return true;
}

void PrintVector(vector<double> numbers)
{
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, " "));
}

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		cout << "Invalid arguments count!" << endl
			<< "Usage: vector.exe <input file> <output file>" << endl;

		return 1;
	}

	string errorMessage = "";
	vector <double> numbers;
	if (!ReadVector(argv[0], numbers, errorMessage))
	{
		cout << errorMessage;
		return 1;
	}

	SortVector(numbers);
	PrintVector(numbers);

	cout << endl;
	return 0;
}