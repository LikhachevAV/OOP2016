#pragma once

std::string blankString;
std::string engineOffError =
"Can't turn off the cars engine! Current gear must be 0, speed must be 0 and engine must be turned on!";


void CarStatesCheck(CCar & car, bool isEngineOn, int gear, unsigned speed, Direction direction, std::string error)
{
	BOOST_CHECK_EQUAL(car.IsEngineOn(), isEngineOn);
	BOOST_CHECK(car.GetGear() == gear);
	BOOST_CHECK(car.GetSpeed() == speed);
	BOOST_CHECK(car.GetDirection() == direction);
	BOOST_CHECK_EQUAL(car.GetLastErrorDescription(), error);
}

struct CarFixture
{
	CCar car;
	CarFixture()
	{
		CarStatesCheck(car, false, 0, 0, Direction::stop, blankString);
	}
};

struct TurnedOnEngineCar : CarFixture
{
	TurnedOnEngineCar()
	{
		BOOST_CHECK(car.EngineOn());
		CarStatesCheck(car, true, 0, 0, Direction::stop, blankString);
	}
};

struct InReverseGearWithMaxSpeed20Car : TurnedOnEngineCar
{
	InReverseGearWithMaxSpeed20Car()
	{
		BOOST_CHECK(car.SetGear(-1));
		BOOST_CHECK(car.SetSpeed(20));
		CarStatesCheck(car, true, -1, 20, Direction::backward, blankString);
	}
};

struct InFirstGearWithMaxSpeed30 : TurnedOnEngineCar
{
	InFirstGearWithMaxSpeed30()
	{
		BOOST_CHECK(car.SetGear(1));
		BOOST_CHECK(car.SetSpeed(30));
		CarStatesCheck(car, true, 1, 30, Direction::forward, blankString);
	}
};

struct InSecondGearWithMaxSpeed50 : InFirstGearWithMaxSpeed30
{
	InSecondGearWithMaxSpeed50()
	{
		BOOST_CHECK(car.SetGear(2));
		BOOST_CHECK(car.SetSpeed(50));
		CarStatesCheck(car, true, 2, 50, Direction::forward, blankString);
	}
};

struct InThirdGearWithMaxSpeed60 : InSecondGearWithMaxSpeed50
{
	InThirdGearWithMaxSpeed60()
	{
		BOOST_CHECK(car.SetGear(3));
		BOOST_CHECK(car.SetSpeed(60));
		CarStatesCheck(car, true, 3, 60, Direction::forward, blankString);
	}
};

struct InFourthGearWithMaxSpeed90 : InThirdGearWithMaxSpeed60 {
	InFourthGearWithMaxSpeed90()
	{
		BOOST_CHECK(car.SetGear(4));
		BOOST_CHECK(car.SetSpeed(90));
		CarStatesCheck(car, true, 4, 90, Direction::forward, blankString);
	}
};

struct InFifthGearWithMaxSpeed150 : InFourthGearWithMaxSpeed90 {
	InFifthGearWithMaxSpeed150()
	{
		BOOST_CHECK(car.SetGear(5));
		BOOST_CHECK(car.SetSpeed(150));
		CarStatesCheck(car, true, 5, 150, Direction::forward, blankString);
	}
};

struct InNeutralGearWithMaxSpeed30 : InFirstGearWithMaxSpeed30
{
	InNeutralGearWithMaxSpeed30()
	{
		BOOST_CHECK(car.SetGear(0));
		CarStatesCheck(car, true, 0, 30, Direction::forward, blankString);
	}
};
