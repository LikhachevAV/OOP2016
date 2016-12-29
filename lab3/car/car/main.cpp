#include "stdafx.h"
#include "CCar.h"
#include "CommandReader.h"

using namespace std;

void HandleCommand(CCar & car, const Command & command)
{

	if (command.name == "Info")
	{
		car.Info();
	}
	else if (command.name == "EngineOn")
	{
		car.EngineOn();
	}
	else if (command.name == "EngineOff")
	{
		car.EngineOff();
	}
	else if (command.name == "SetGear")
	{
		car.SetGear(command.value);
	}
	else if (command.name == "SetSpeed")
	{
		car.SetSpeed(command.value);
	}
	else
	{
		cout << "Invalid command!" << endl;
	}
}

int main()
{
	Command command;
	CCar myCar;
	while (!cin.eof())
	{
		if (ReadCommand(cin, command))
		{
			HandleCommand(myCar, command);
		}
		else
		{
			cout << "Command reading error!" << endl
				<< "possible commands: "
				<< "Info, EngineOn, EngineOff, SetGear<gear>, SetSpeed<gear>" << endl;
		}
	}
	return 0;
}