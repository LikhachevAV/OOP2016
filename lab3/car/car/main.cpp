#include "stdafx.h"
#include "CCar.h"
#include "CommandReader.h"

using namespace std;

void Info(CCar & car) {
	auto engineStatus = [&]() {
		return car.IsEngineOn() ? "on" : "off";
	};

	auto direction = [&]() {
		switch (car.GetDirection())
		{
		case Direction::backward:
			return "backward";
		case Direction::stop:
			return "stop";
		case Direction::forward:
			return "forward";
		default:
			return "";
		}
	};

	cout << "Car engine is " << engineStatus() << endl
		<< "Current direction: " << direction() << endl
		<< "current gear: " << car.GetGear() << endl
		<< "current speed: " << car.GetSpeed() << endl;
}

void HandleCommand(CCar & car, const Command & command)
{

	if (command.name == "Info")
	{
		Info(car);
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
		cout << "Please, enter command for car: ";
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