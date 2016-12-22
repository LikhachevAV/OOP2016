#include "stdafx.h"
#include "CCar.h"
#include "CommandReader.h"

using namespace std;

int main()
{
	Command command;
	while (cin.eof())
	{
		if (!ReadCommand(command))
		{
			cout << "Command reading error!" << endl
				<< "possible commands: "
				<< "Info, EngineOn, EngineOff, SetGear<gear>, SetSpeed<gear>" << endl;
		}
	}
	return 0;
}