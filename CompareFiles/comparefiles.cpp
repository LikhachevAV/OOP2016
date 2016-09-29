#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int FILE_COMPARATION_ERROR = -1;
const int FILES_ARE_EQUAL = 0;

int CompareFiles(const string & fileName1, const string & fileName2, string & error)
{
	ifstream firstFile(fileName1);
	if (!firstFile.is_open())
	{
		error = error.append("Failed to open ").append(fileName1).append(" for reading");
		return FILE_COMPARATION_ERROR;
	}

	ifstream secondFile(fileName2);
	if (!secondFile.is_open())
	{
		error = error.append("Failed to open ").append(fileName1).append(" for reading");
		return FILE_COMPARATION_ERROR;
	}
	char ch1, ch2;
	int lineNumber = 1;

	auto ReadFiles = [&] {
		firstFile.get(ch1);
		secondFile.get(ch2);
		return firstFile && secondFile;
	};

	while (ReadFiles())
	{
		if (ch1 != ch2)
		{
			return lineNumber;
		}
		if (ch1 == '\n')
		{
			++lineNumber;
		}
	}

	if (firstFile || secondFile)
	{
		return lineNumber;
	}
}

int main(int argc, char * argv[])
{
	string errorMessage = "";
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: comparefile.exe <file1> <file2>\n";
		return 1;
	}

	int comparationResult = CompareFiles(argv[1], argv[2], errorMessage);
	if (comparationResult == FILE_COMPARATION_ERROR)
	{
		cout << errorMessage << '\n';
		return 1;
	}
	else if (comparationResult == FILES_ARE_EQUAL)
	{
		cout << "Files are equal\n";
		return 0;
	}
	else
	{
		cout << "Files are different. Line number is " << comparationResult << '\n';
		return 1;
	}
	return 0;
}