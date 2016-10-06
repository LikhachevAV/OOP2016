#include <iostream>
#include <string>

using namespace std;

int ERROR_STATE = -1;
int MAX_SIZE_LENGTH = 32;

int Bin2dec(string const & binString, unsigned long int & result, string & errorMessage)
{
	auto inStrSize = binString.size();
	if (inStrSize > MAX_SIZE_LENGTH)
	{
		errorMessage = errorMessage.append("Invalid arguments length!\nMax numbers length must be ")
			.append(to_string(MAX_SIZE_LENGTH)).append(", but found ").append(to_string(inStrSize));
		return ERROR_STATE;
	}

	result = 0;
	unsigned long int multiplier = 1;

	for (int i = inStrSize - 1; i >= 0; --i)
	{
		if (binString[i] == '1')
		{
			result += multiplier;
		}
		else if (binString[i] != '0')
		{
			errorMessage = errorMessage.append("Invalid argument type!\nUsage: bin2dec.exe <binary number>");
			return ERROR_STATE;
		}

		multiplier = multiplier << 1;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count!" << endl
			<< "Usage: bin2dec.exe <binary number>" << endl;

		return 1;
	}

	unsigned long int result;
	string errorMessage = "";

	if (Bin2dec(argv[1], result, errorMessage) == ERROR_STATE)
	{
		cout << errorMessage << endl;
		return 1;
	}

	cout << result << endl;
	return 0;
}