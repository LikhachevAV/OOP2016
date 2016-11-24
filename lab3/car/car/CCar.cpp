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

bool CCar::EngineOn()
{
	return true;
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