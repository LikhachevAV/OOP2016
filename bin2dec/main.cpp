#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	int MAX_SIZE_LENGTH = 32;
	if (argc != 2)
	{
		cout << "Invalid arguments count!" << endl
			<< "Usage: bin2dec.exe <binary number>" <<endl;

		return 1;
	}

	string inStr = argv[1];
	auto inStrSize = inStr.size();
	if (inStrSize > MAX_SIZE_LENGTH)
	{
		cout << "Invalid arguments length!" << endl
			<< "Max numbers length must be 32, but found " << inStrSize << endl;
		return 1;
	}

	unsigned long int result = 0;
	unsigned long int multiplier = 1;
	bool owerflow = inStrSize == MAX_SIZE_LENGTH;

	for (int i = inStrSize - 1; i >= 0 ; --i)
	{
		owerflow = owerflow && (inStr[i] == '1');
		if (inStr[i] == '1')
		{
			if (owerflow)
			{
				cout << "Error! Result owerflow!" << endl;
				return 1;
			}
			result += multiplier;
		}
		else
		if (inStr[i] != '0')
		{
			cout << "Invalid argument type!" << endl
				<< "Usage: bin2dec.exe <binary number>" << endl;
			return 1;
		}
		
		multiplier = multiplier << 1;
	}

	cout << result << endl;
	return 0;
}