#include "stdafx.h"
#include "CCar.h"

using namespace std;
struct Command
{
	string command;
	int value = 0;
};

bool ReadCommand(istream & in, Command & command)
{
	string commandStr;
	in >> commandStr;
	if (!in)
	{
		return false;
	}
	return true;
}

int main()
{
	Command command;
	while (cin.eof())
	{
		if (!ReadCommand(cin, command))
		{
			cout << "Command reading error!" << endl
				<< "possible commands: "
				<< "Info, EngineOn, EngineOff, SetGear<gear>, SetSpeed<gear>" << endl;
		}
	}
	return 0;
}