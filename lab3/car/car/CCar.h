#pragma once
#include <iostream>
#include <map>

static const int MIN_SPEED = 0;
static const int MAX_SPEED = 150;
static const std::map<int, SpeedRange> availableSpeedRangesMap = { { -1,{ MIN_SPEED,20 } },
																   { 0,{ 0, 0 } },
																   { 1,{ 0, 30 } },
																   { 2,{ 20, 50 } },
																   { 3,{ 30, 60 } },
															   	   { 4,{ 40, 90 } },
																   { 5,{ 50, 150 } } };

struct SpeedRange
{ 
	int min;
	int max;
};

enum struct Direction {backward, stop, forward};

class CCar
{
public:
	void Info(std::ostream & stream)const;
	bool IsEngineOn();
	bool EngineOn();
	bool EngineOff();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	bool m_isEngineOn = false;
	int m_currentGear = 0;
	unsigned m_currentSpeed = 0;
	Direction m_currentDirection = Direction::stop;
	bool canSetGear(int gear);
	bool canSetSpeed(int speed);
};