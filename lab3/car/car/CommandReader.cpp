#include "stdafx.h"
#include "CommandReader.h"

using namespace std;

bool ReadCommand(Command & command)
{
	string commandLine;
	if (!getline(cin, commandLine) && (commandLine.length() == 0))
	{
		cout << "Empty command error!";
		return false;
	}

	string commandName;
	for (size_t i = 0; i < commandLine.length(), commandLine[i] != '<'; ++i)
	{
		commandName.push_back(commandLine[i]);
	}

	if (commandArgsCount[commandName] == 0)
	{
		cout << "Bad command error!";
		return false;
	}
	command.name = commandName;
	return true;
}