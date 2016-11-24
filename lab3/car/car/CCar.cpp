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
	if (CCar::m_isEngineOn)
	{
		return false;
	}
	else
	{
		CCar::m_isEngineOn = true;
		return true;
	}
	
}

bool CCar::EngineOff()
{
	return true;
}

bool CCar::SetGear(int gear)
{
	return true;
}

bool CCar::SetSpeed(int speed)
{
	return true;
}