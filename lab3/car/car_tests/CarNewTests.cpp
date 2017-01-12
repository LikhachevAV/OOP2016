#include "stdafx.h"
#include "..\car\CCar.h"
#include "CarNewTests.h"

BOOST_FIXTURE_TEST_SUITE(When_car_engine_is_off, CarFixture)
		
	BOOST_AUTO_TEST_CASE(can_not_switch_gears_and_set_speed)
	{
		auto switchAndCheckGearAndSpeed = [&] (int gear, unsigned speed) {
			BOOST_CHECK(!car.SetGear(gear));
			CarStatesCheck(car, false, 0, 0, Direction::stop);
			BOOST_CHECK(!car.SetSpeed(speed));
			CarStatesCheck(car, false, 0, 0, Direction::stop);
		};
		switchAndCheckGearAndSpeed(-2, 151);
		switchAndCheckGearAndSpeed(-1, 20);
		switchAndCheckGearAndSpeed(0, 0);
		switchAndCheckGearAndSpeed(0, 150);
		switchAndCheckGearAndSpeed(1, 30);
		switchAndCheckGearAndSpeed(2, 50);
		switchAndCheckGearAndSpeed(2, 51);
		switchAndCheckGearAndSpeed(3, 30);
		switchAndCheckGearAndSpeed(4, 90);
		switchAndCheckGearAndSpeed(5, 150);
		switchAndCheckGearAndSpeed(5, 49);
	}

BOOST_AUTO_TEST_SUITE_END()
//#########################

BOOST_FIXTURE_TEST_SUITE(When_car_engine_is_on, TurnedOnEngineCar)

	BOOST_AUTO_TEST_SUITE(SetGear_function)
		BOOST_AUTO_TEST_CASE(can_not_set_same_gear)
		{
			BOOST_CHECK(!car.SetGear(0));
			CarStatesCheck(car, true, 0, 0, Direction::stop);
		}
		BOOST_AUTO_TEST_CASE(can_set_firs_gear)
		{
			BOOST_CHECK(car.SetGear(1));
			CarStatesCheck(car, true, 1, 0, Direction::stop);
		}
		BOOST_AUTO_TEST_CASE(can_set_reverse_gear)
		{
			BOOST_CHECK(car.SetGear(-1));
			CarStatesCheck(car, true, -1, 0, Direction::stop);
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()