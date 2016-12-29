#include "stdafx.h"
#include "CommandReader.h"

bool ReadCommand(std::istream & input, Command & command)
{
	std:: string commandLine;
	if (!getline(input, commandLine) && (commandLine.length() == 0))
	{
		std::cout << "Empty command error!";
		return false;
	}
	size_t i = 0;
	std::string commandName;
	for (i = 0; i < commandLine.length(), commandLine[i] != '<'; ++i)
	{
		commandName.push_back(commandLine[i]);
	}

	if (commandArgsCount[commandName] == 0)
	{
		std::cout << "Bad command error!";
		return false;
	}
	command.name = commandName;
	std::string commandValue;
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