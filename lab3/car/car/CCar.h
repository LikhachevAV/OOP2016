#pragma once
#include <iostream>

class CCar
{
public:
	void Info(std::ostream & stream)const;
	bool EngineOn();
	bool EngineOff();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	bool m_isEngineOn = false;
	int m_currentGear = 0;
	unsigned m_currentSpeed = 0;
};