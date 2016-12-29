#pragma once
#include "stdafx.h"

std::map<std::string, int> commandArgsCount = {
	{ "Info", 1 },
	{ "EngineOn", 1 },
	{ "EngineOff", 1 },
	{ "SetGear", 2 },
	{ "SetSpeed", 2 }
};

struct Command
{
	std::string name;
	int value = 0;
};

bool ReadCommand(std::istream & input, Command & command);