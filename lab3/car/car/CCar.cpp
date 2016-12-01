#include "stdafx.h"
#include "CCar.h"
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;
using namespace std::placeholders;
using namespace boost::phoenix::placeholders;
using namespace boost::phoenix;

void CCar::Info(std::ostream & stream)const
{
	
}

bool CCar::IsEngineOn()
{
	return m_isEngineOn;
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
	bool canTurnOffEngine = (m_currentGear == 0) && (m_currentSpeed == 0) && m_isEngineOn;
	if (canTurnOffEngine)
	{
		m_isEngineOn = false;
		return true;
	}
	else
	{
		cout << "Can't turn off the cars engine! Current gear must be 0, speed must be 0 and engine must be"
			<< " turned on!";
		return false;
	}
	
}

bool CCar::canSetGear(int gear)
{
	// Зависит от параметров:
	//m_direction;
	//m_speed;
	//m_currentGear
	return true;
}

bool CCar::canSetSpeed(int speed)
{
	return true;
}

bool CCar::SetGear(int gear)
{
	if (canSetGear(gear))
	{
		m_currentGear = gear;
		m_currentDirection = (gear == -1) ? Direction::backward : Direction::forward;
		return true;
	}
	else
	{
		return false;
	}
}

bool CCar::SetSpeed(int speed)
{
	if (canSetSpeed(speed))
	{
		m_currentSpeed = speed;
		if (m_currentSpeed == 0)
		{
			m_currentDirection = Direction::stop;
		}
		return true;
	}
	else
	{
		return false;
	}
	
}