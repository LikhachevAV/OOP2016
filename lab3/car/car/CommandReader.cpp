#include <iostream>
#include <string>
#include <map>
#include <sstream>

static std::map<std::string, bool> commandsArgsCount =	{
										{"Info", false},
										{"EngineOn", false},
										{"EngineOff", false },
										{"Exit", false },
										{"SetGear", true},
										{"SetSpeed", true }
									};

struct Command
{
	std::string name;
	int value = 0;
};

bool ReadCommand(std::istream & in, Command & command)
{
	std::string commandLine;
	if (!std::getline(in, commandLine) && commandLine.length() == 0)
	{
		std::cout << "Empty command error!";
		return false;
	}
	
	std::string commandStr = [&] {
		std::string tmpS;
		for (int i = 0; i < commandLine.length() && commandLine[i] != '<';  ++i)
		{
			tmpS.push_back(commandLine[i]);
		}
		return tmpS;};
	if (commandsArgsCount[commandStr] == 0)
	{
		std::cout << "Bad command error!";
	}
	return true;
}