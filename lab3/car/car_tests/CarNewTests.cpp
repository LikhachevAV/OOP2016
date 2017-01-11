#include "stdafx.h"
#include "..\car\CCar.h"

struct CarFixture
{
	CCar car;
	CarFixture()
	{
		assert(!car.IsEngineOn());
		assert(car.GetGear() == 0);
		assert(car.GetSpeed() == 0);
		assert(car.GetDirection() == Direction::stop);
	}
};

struct TurnedOnEngineCar : CarFixture
{
	TurnedOnEngineCar()
	{
		car.EngineOn();
		assert(car.IsEngineOn());
		assert(car.GetGear() == 0);
		assert(car.GetSpeed() == 0);
		assert(car.GetDirection() == Direction::stop);
	}
};

struct InReverseGearWithMaxSpeed20Car : TurnedOnEngineCar
{
	InReverseGearWithMaxSpeed20Car()
	{
		car.SetGear(-1);
		car.SetSpeed(20);
		assert(car.IsEngineOn());
		assert(car.GetGear() == -1);
		assert(car.GetSpeed() == 20);
		assert(car.GetDirection() == Direction::backward);
	}
};

struct InFirstGearWithMaxSpeed30 : TurnedOnEngineCar
{
	InFirstGearWithMaxSpeed30()
	{
		car.SetGear(1);
		car.SetSpeed(30);
		assert(car.IsEngineOn());
		assert(car.GetGear() == 1);
		assert(car.GetSpeed() == 30);
		assert(car.GetDirection() == Direction::forward);
	}
};

struct InSecondGearWithMaxSpeed50 : InFirstGearWithMaxSpeed30
{
	InSecondGearWithMaxSpeed50()
	{
		car.SetGear(2);
		car.SetSpeed(50);
		assert(car.IsEngineOn());
		assert(car.GetGear() == 2);
		assert(car.GetSpeed() == 50);
		assert(car.GetDirection() == Direction::forward);
	}
};

struct InThirdGearWithMaxSpeed60 : InSecondGearWithMaxSpeed50
{
	InThirdGearWithMaxSpeed60()
	{
		car.SetGear(3);
		car.SetSpeed(60);
		assert(car.IsEngineOn());
		assert(car.GetGear() == 3);
		assert(car.GetSpeed() == 60);
		assert(car.GetDirection() == Direction::forward);
	}
};

struct InFourthGearWithMaxSpeed90 : InThirdGearWithMaxSpeed60{
	InFourthGearWithMaxSpeed90()
	{
		car.SetGear(4);
		car.SetSpeed(90);
		assert(car.IsEngineOn());
		assert(car.GetGear() == 4);
		assert(car.GetSpeed() == 90);
		assert(car.GetDirection() == Direction::forward);
	}
};

struct InFifthGearWithMaxSpeed150 : InFourthGearWithMaxSpeed90 {
	InFifthGearWithMaxSpeed150()
	{
		car.SetGear(5);
		car.SetSpeed(150);
		assert(car.IsEngineOn());
		assert(car.GetGear() == 5);
		assert(car.GetSpeed() == 150);
		assert(car.GetDirection() == Direction::forward);
	}
};

BOOST_FIXTURE_TEST_SUITE(WhenCarEngineIsOff, CarFixture)

	BOOST_AUTO_TEST_SUITE(SetGear_function)
		BOOST_AUTO_TEST_CASE(can_not_set_gear)
		{
			BOOST_CHECK(!car.SetGear(1));
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(WhenCarEngineIsOn, TurnedOnEngineCar)

BOOST_AUTO_TEST_SUITE(SetGear_function)
BOOST_AUTO_TEST_CASE(can_set_gear)
	{
		BOOST_CHECK(car.SetGear(1));
	}
	BOOST_AUTO_TEST_SUITE_END()

		BOOST_AUTO_TEST_SUITE_END()

