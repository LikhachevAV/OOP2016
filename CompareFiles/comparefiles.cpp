#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: comparefile.exe <input file> <output file>\n";
		return 1;
	}

	ifstream firstFile(argv[1]);
	if (!firstFile.is_open()) 
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
 	}

	ifstream secondFile(argv[2]);
	if (!secondFile.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading\n";
		return 1;
	}
	char ch1, ch2;
	int lineNumber(1);

	auto ReadFiles = [&] {
		firstFile.get(ch1);
		secondFile.get(ch2);
		return firstFile && secondFile;
	};

	while(ReadFiles())
	{
		if (ch1 != ch2)
		{
			cout << "Files are different. Line number is " << lineNumber << "\n";
			return 1;
		}
		if(ch1 == '\n')	
		{
			++lineNumber;
		}
	}

	if (firstFile || secondFile)
	{
		cout << "Files are different. Line number is " << lineNumber << "\n";
		return 1;
	}

	cout << "Files are equal\n";
	return 0;
}