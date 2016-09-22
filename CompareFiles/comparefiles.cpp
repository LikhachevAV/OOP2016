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

	// �������� ���������� ���� ifstream 
	// (input file stream, ����� ��� ������ �� ������� �����), ������������������ ���
	// ������ �������� �����
	ifstream input1(argv[1]);

	// �������� ����� is_open() � ������� input,
	// ������� ������ true, ���� ���� ��� ������
	if (!input1.is_open()) 
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
 	}

	// �������� ���������� ���� ifstream 
	// (input file stream, ����� ��� ������ �� ������� �����), ������������������ ���
	// ������ �������� �����
	ifstream input2(argv[2]);
	if (!input2.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading\n";
		return 1;
	}

	char ch1, ch2;
	// ��������� � ���������� ch ������ �� �������� ������
	// ���������� ��������, ���������� � bool, ������� ������������� �� ������
	
	int lineNumber = 1;
	bool b, b1, b2;
	while (b = ((b1 = input1.get(ch1)) && (b2 = input2.get(ch2))))
	{
		if (!(ch1 == ch2))
		{
			cout << ch1 << ':' << ch2 << '\n';
			cout << "Files are different. Line number is " << lineNumber << "\n";
			return 1;
		}
		if(ch1 == '\n')	
		{
			++lineNumber;
		}
	}
	
	if ((b1 || b2) && (ch1 == ch2))
		{
			cout << ch1 << ':' << ch2 << '\n';
			cout << "Files are different. Line number is " << lineNumber << "\n";
			return 1;
		}
	cout << "Files are equal\n";
	return 0;
}
