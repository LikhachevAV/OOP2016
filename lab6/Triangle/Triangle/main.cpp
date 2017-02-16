#include "stdafx.h"
#include "Triangle.h"

using namespace std;

bool ReadTriangle(istream & in, vector<double> & sides)
{
	string line;
	getline(in, line);
	stringstream strm(line);
	return strm >> sides[0] &&
		strm >> sides[1] &&
		strm >> sides[3];
}

int main()
{
	vector<double> sides(3);
	while (!cin.eof())
	{
		cout << "Please, enter triangle sides: ";
		if (!ReadTriangle(cin, sides))
		{
			cout << "Triangle sides reading error!" << endl;
		}
		else
		{
			try
			{
				CTriangle triangle(sides[0], sides[1], sides[2]);
				cout << triangle << endl;
			}
			catch(exception e)
			{
				cout << e.what() << endl;
			}
		}
	}
	return 0;
}