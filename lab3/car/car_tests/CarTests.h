#pragma once

void CarStatesCheck(CCar & car, bool isEngineOn, int gear, unsigned speed, Direction direction)
{
	BOOST_CHECK_EQUAL(car.IsEngineOn(), isEngineOn);
	BOOST_CHECK(car.GetGear() == gear);
	BOOST_CHECK(car.GetSpeed() == speed);
	BOOST_CHECK(car.GetDirection() == direction);
}

struct CarFixture
{
	CCar car;
	CarFixture()
	{
		CarStatesCheck(car, false, 0, 0, Direction::stop);
	}
};

struct TurnedOnEngineCar : CarFixture
{
	TurnedOnEngineCar()
	{
		BOOST_CHECK(car.EngineOn());
		CarStatesCheck(car, true, 0, 0, Direction::stop);
	}
};

struct InReverseGearWithMaxSpeed20Car : TurnedOnEngineCar
{
	InReverseGearWithMaxSpeed20Car()
	{
		BOOST_CHECK(car.SetGear(-1));
		BOOST_CHECK(car.SetSpeed(20));
		CarStatesCheck(car, true, -1, 20, Direction::backward);
	}
};

struct InFirstGearWithMaxSpeed30 : TurnedOnEngineCar
{
	InFirstGearWithMaxSpeed30()
	{
		BOOST_CHECK(car.SetGear(1));
		BOOST_CHECK(car.SetSpeed(30));
		CarStatesCheck(car, true, 1, 30, Direction::forward);
	}
};

struct InSecondGearWithMaxSpeed50 : InFirstGearWithMaxSpeed30
{
	InSecondGearWithMaxSpeed50()
	{
		BOOST_CHECK(car.SetGear(2));
		BOOST_CHECK(car.SetSpeed(50));
		CarStatesCheck(car, true, 2, 50, Direction::forward);
	}
};

struct InThirdGearWithMaxSpeed60 : InSecondGearWithMaxSpeed50
{
	InThirdGearWithMaxSpeed60()
	{
		BOOST_CHECK(car.SetGear(3));
		BOOST_CHECK(car.SetSpeed(60));
		CarStatesCheck(car, true, 3, 60, Direction::forward);
	}
};

struct InFourthGearWithMaxSpeed90 : InThirdGearWithMaxSpeed60 {
	InFourthGearWithMaxSpeed90()
	{
		BOOST_CHECK(car.SetGear(4));
		BOOST_CHECK(car.SetSpeed(90));
		CarStatesCheck(car, true, 4, 90, Direction::forward);
	}
};

struct InFifthGearWithMaxSpeed150 : InFourthGearWithMaxSpeed90 {
	InFifthGearWithMaxSpeed150()
	{
		BOOST_CHECK(car.SetGear(5));
		BOOST_CHECK(car.SetSpeed(150));
		CarStatesCheck(car, true, 5, 150, Direction::forward);
	}
};
