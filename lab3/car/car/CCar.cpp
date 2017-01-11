﻿#include "stdafx.h"
#include "CCar.h"
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)
#pragma warning(disable: 4503)

using namespace std;
using namespace std::placeholders;
using namespace boost::phoenix::placeholders;
using namespace boost::phoenix;

const bool CCar::IsEngineOn()
{
	return m_isEngineOn;
}

const Direction CCar::GetDirection()
{
	return m_direction;
}

const int CCar::GetGear()
{
	return m_gear;
}

const unsigned CCar::GetSpeed()
{
	return m_speed;
}

const string CCar::GetLastErrorDescription()
{
	return m_lastErrorDescription;
}

bool CCar::EngineOn()
{
	if (m_isEngineOn)
	{
		m_lastErrorDescription = "Engine is already on!";
		return false;
	}
	else
	{
		m_isEngineOn = true;
		return true;
	}
}

bool CCar::EngineOff()
{
	bool canTurnOffEngine = (m_gear == 0) && (m_speed == 0) && m_isEngineOn;
	if (canTurnOffEngine)
	{
		m_isEngineOn = false;
		return true;
	}
	else
	{
		m_lastErrorDescription = "";
		m_lastErrorDescription.append("Can't turn off the cars engine!")
			.append(" Current gear must be 0,speed must be 0 and engine must be turned on!");
		return false;
	}
}

bool CCar::SetGear(int gear)
{
	unsigned currentGearMinSpeed = availableSpeedRangesMap.find(gear)->second.min;
	unsigned currentGearMaxSpeed = availableSpeedRangesMap.find(gear)->second.max;
	bool canSetGear = m_isEngineOn &&
		m_gear != gear &&
		(gear == 0 || (gear == -1) && (m_direction == Direction::stop) ||
		((m_direction == Direction::stop || m_direction == Direction::forward) &&
			m_speed <= currentGearMaxSpeed && m_speed >= currentGearMinSpeed && gear != -1));
	if (canSetGear)
	{
		m_gear = gear;
		m_direction = (gear == -1) ? Direction::backward : Direction::forward;
		return true;
	}
	else
	{
		m_lastErrorDescription = "";
		m_lastErrorDescription.append("Can not set gear ")
			.append(to_string(gear))
			.append("!");
		return false;
	}
}

bool CCar::SetSpeed(unsigned speed)
{
	unsigned currentGearMinSpeed = availableSpeedRangesMap.find(m_gear)->second.min;
	unsigned currentGearMaxSpeed = availableSpeedRangesMap.find(m_gear)->second.max;
	bool canSetSpeed = m_speed != speed &&
		speed >= currentGearMinSpeed &&
		speed <= currentGearMaxSpeed;
	if (canSetSpeed)
	{
		m_speed = speed;
		if (m_speed == 0)
		{
			m_direction = Direction::stop;
		}
		return true;
	}
	else
	{
		m_lastErrorDescription.append("Speed at gear ")
			.append(to_string(m_gear))
			.append(" must be between ")
			.append(to_string(currentGearMinSpeed))
			.append(" and ")
			.append(to_string(currentGearMaxSpeed))
			.append("!");
		return false;
	}
}
