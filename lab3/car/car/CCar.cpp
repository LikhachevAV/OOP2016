#include "stdafx.h"
#include "CCar.h"
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)
#pragma warning(disable: 4503)

using namespace std;
using namespace std::placeholders;
using namespace boost::phoenix::placeholders;
using namespace boost::phoenix;

bool CCar::IsEngineOn()
{
	return m_isEngineOn;
}

Direction CCar::GetDirection()
{
	return m_direction;
}

int CCar::GetGear()
{
	return m_gear;
}

unsigned CCar::GetSpeed()
{
	return m_speed;
}

bool CCar::EngineOn()
{
	if (m_isEngineOn)
	{
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
		cout << "Can't turn off the cars engine! Current gear must be 0, speed must be 0 and engine must be"
			<< " turned on!" << endl;
		return false;
	}
}

bool CCar::SetGear(int gear)
{
	unsigned currentGearMinSpeed = availableSpeedRangesMap.find(gear)->second.min;
	unsigned currentGearMaxSpeed = availableSpeedRangesMap.find(gear)->second.max;
	bool canSetGear = m_isEngineOn &&( (gear == -1) && (m_direction == Direction::stop) ||
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
		cout << "Can not set gear " << gear << "!" << endl;
		return false;
	}
}

bool CCar::SetSpeed(int speed)
{
	int currentGearMinSpeed = availableSpeedRangesMap.find(m_gear)->second.min;
	int currentGearMaxSpeed = availableSpeedRangesMap.find(m_gear)->second.max;
	bool canSetSpeed = speed >= currentGearMinSpeed && speed <= currentGearMaxSpeed;
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
		cout << "Speed at gear " << m_gear << " must be between "
			<< currentGearMinSpeed << " and " << currentGearMaxSpeed << '!' << endl;
		return false;
	}
}
