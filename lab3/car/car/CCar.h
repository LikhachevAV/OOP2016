#pragma once
#include "stdafx.h"

static const unsigned MIN_SPEED = 0;
static const unsigned MAX_SPEED = 150;
struct SpeedRange
{
	unsigned min;
	unsigned max;
};
static const std::map<int, SpeedRange> availableSpeedRangesMap = { { -1,{ MIN_SPEED, 20 } },
																   { 0,{ 0, 0 } },
																   { 1,{ 0, 30 } },
																   { 2,{ 20, 50 } },
																   { 3,{ 30, 60 } },
															   	   { 4,{ 40, 90 } },
																   { 5,{ 50, MAX_SPEED } } };

enum struct Direction { backward, stop, forward };

class CCar
{
private:
	bool m_isEngineOn = false;
	int m_gear = 0;
	unsigned m_speed = 0;
	Direction m_direction = Direction::stop;
	std::string m_lastErrorDescription;
	void SetDirection();

public:
	const bool IsEngineOn();
	const Direction GetDirection();
	const int GetGear();
	const unsigned GetSpeed();
	const std::string GetLastErrorDescription();
	bool EngineOn();
	bool EngineOff();
	bool SetGear(int gear);
	bool SetSpeed(unsigned speed);
};