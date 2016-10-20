#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "VectorProcessor.h"

using namespace std;

const vector<char> possibleSymbols = {'-', '0', '1', '2', '3', '4', '5', '6', '7', '8' , '9', '.'};

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

	char ch;
	vector<double> numbers;
	bool stop = false;
	string outNumber = ";"
	while (!EOF(inputFile))
	{
		if (ch = inputFile.get())
		{

		}

	}

	return true;
}

void PrintVector(vector<double> numbers)
{
	setprecision(4);
	cout << "Output vector:";
	for (double it : numbers)
	{
		cout << " " << it;
	}
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

	cout << endl;
	return 0;
}