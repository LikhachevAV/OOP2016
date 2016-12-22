#pragma once
#include "stdafx.h"
#include <sstream>

std::map<std::string, int> commandArgsCount = {
	{ "Info", 1 },
	{ "EngineOn", 1 },
	{ "EngineOff", 1 },
	{ "Exit", 1 },
	{ "SetGear", 2 },
	{ "SetSpeed", 2 }
};

struct Command
{
	std::string name;
	int value = 0;
};

bool ReadCommand(Command & command);