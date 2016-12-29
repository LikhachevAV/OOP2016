#include "stdafx.h"
#include "CommandReader.h"

using namespace std;

bool ReadCommand(istream & input, Command & command)
{
	string commandLine;
	if (!getline(input, commandLine) && (commandLine.length() == 0))
	{
		cout << "Empty command error!";
		return false;
	}
	size_t i = 0;
	string commandName;
	for (i = 0; i < commandLine.length(), commandLine[i] != '<'; ++i)
	{
		commandName.push_back(commandLine[i]);
	}

	if (commandArgsCount[commandName] == 0)
	{
		cout << "Bad command error!";
		return false;
	}
	command.name = commandName;
	string commandValue;
	if (commandLine[i] != '<')
	{
		++i;
	}
	if (commandArgsCount[commandName] == 2 && commandLine[i] == '<')
	{ 
		while (commandLine.length() && commandLine[i] != '>')
		{
			commandValue.push_back(commandLine[i]);
			++i;
		}
	}
	command.value = stoi(commandValue);
	return true;
}