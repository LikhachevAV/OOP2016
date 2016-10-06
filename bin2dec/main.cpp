#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count!" << endl
			<< "Usage: bin2dec.exe <binary number>" <<endl;

		return 1;
	}

	string inStr = argv[1];
	int inStrSize = inStr.size();
	if (inStrSize > 32)
	{
		cout << "Invalid arguments length!" << endl
			<< "Max numbers length must be 32, but found " << inStrSize << endl;
		return 1;
	}
	return 0;
}