#include "stdafx.h"
#include "CommandReader.h"

bool ReadCommand(std::istream & input, Command & command)
{
	std:: string commandLine;
	if (!getline(input, commandLine) || (commandLine.length() == 0))
	{
		std::cout << "Empty command error!";
		return false;
	}
	size_t i = 0;
	std::string commandName;
	while (i < commandLine.length() && commandLine[i] != '<')
	{
		commandName.push_back(commandLine[i]);
		++i;
	}

	if (commandArgumentsCount[commandName] == 0)
	{
		std::cout << "Bad command error!";
		return false;
	}
	command.name = commandName;
	std::string commandValue;

	if (commandArgumentsCount[commandName] == 2 && commandLine[i] == '<')
	{ 
		++i;
		while (commandLine.length() && commandLine[i] != '>')
		{
			commandValue.push_back(commandLine[i]);
			++i;
		}
	}
	if (commandValue.length() != 0)
	{
		command.value = stoi(commandValue);
	}
	return true;
}