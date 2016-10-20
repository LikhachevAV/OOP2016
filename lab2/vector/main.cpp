#include "stdafx.h"
#include "VectorProcessor.h"
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count!" << endl
			<< "Usage: vector.exe <input file> <output file>" << endl;

		return 1;
	}
	return 0;
}

bool ReadVector(string const &fileName, vector<double> &result, string &error)
{

	vector<double> numbers;
	return 0;
}

void PrintVector(vector<double> numbers)
{
	setprecision(4);
	cout << "Output vector: ";
	for (double it: numbers)
	{
		cout << it << " ";
	}
}