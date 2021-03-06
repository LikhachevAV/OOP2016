﻿#pragma once
#include "stdafx.h"

static const unsigned MIN_SPEED = 0;
static const unsigned MAX_SPEED = 150;
static const int MIN_GEAR = -1;
static const int MAX_GEAR = 5;

struct SpeedRange
{
	unsigned min;
	unsigned max;
};
static const std::map<int, SpeedRange> availableSpeedRangesMap = { { -1,{ MIN_SPEED, 20 } },
{ 0,{ MIN_SPEED, MAX_SPEED } },
{ 1,{ 0, 30 } },
{ 2,{ 20, 50 } },
{ 3,{ 30, 60 } },
{ 4,{ 40, 90 } },
{ 5,{ 50, MAX_SPEED } } };

enum struct Direction { backward, stop, forward };

class CCar
{
public:
	bool const IsEngineOn();
	Direction const GetDirection();
	int const GetGear();
	unsigned const GetSpeed();
	std::string const GetLastErrorDescription();
	bool EngineOn();
	bool EngineOff();
	bool SetGear(int gear);
	bool SetSpeed(unsigned speed);
private:
	bool m_isEngineOn = false;
	int m_gear = 0;
	unsigned m_speed = 0;
	Direction m_direction = Direction::stop;
	std::string m_lastErrorDescription;
	void SetDirection();
};