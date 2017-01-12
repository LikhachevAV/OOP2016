#include "stdafx.h"
#include "..\car\CCar.h"
#include "CarNewTests.h"

BOOST_FIXTURE_TEST_SUITE(When_car_engine_is_off, CarFixture)

auto switchAndCheckGearAndSpeed = [&](CCar car, int gear, unsigned speed) {
	BOOST_CHECK(!car.SetGear(gear));
	CarStatesCheck(car, false, 0, 0, Direction::stop);
	BOOST_CHECK(!car.SetSpeed(speed));
	CarStatesCheck(car, false, 0, 0, Direction::stop);
};
		
	BOOST_AUTO_TEST_CASE(can_not_switch_less_than_MIN_GEAR_gear)
	{	
		switchAndCheckGearAndSpeed(car, -2, 0);
		switchAndCheckGearAndSpeed(car , -2, 151);
	}
	BOOST_AUTO_TEST_CASE(can_not_switch_reverse_gear)
	{
		switchAndCheckGearAndSpeed(car, -1, 20);
	}
	BOOST_AUTO_TEST_CASE(can_not_switch_same_gear)
	{
		switchAndCheckGearAndSpeed(car, 0, 0);
		switchAndCheckGearAndSpeed(car, 0, 150);
		switchAndCheckGearAndSpeed(car, 0, 151);
	}
	BOOST_AUTO_TEST_CASE(can_not_switch_first_gear_and_speed_30)
	{
		switchAndCheckGearAndSpeed(car, 1, 30);
	}
	BOOST_AUTO_TEST_CASE(can_not_switch_second_gear_and_speeds_20_50_51)
	{
		switchAndCheckGearAndSpeed(car, 2, 20);
		switchAndCheckGearAndSpeed(car, 2, 50);
		switchAndCheckGearAndSpeed(car, 2, 51);
	}
	BOOST_AUTO_TEST_CASE(can_not_switch_third_gear_and_speeds_29_30)
	{
		switchAndCheckGearAndSpeed(car, 3, 29);
		switchAndCheckGearAndSpeed(car, 3, 30);
	}
	BOOST_AUTO_TEST_CASE(can_not_switch_fourth_gear_and_speeds_90_91)
	{
		switchAndCheckGearAndSpeed(car, 4, 90);
		switchAndCheckGearAndSpeed(car, 4, 91);
	}
	BOOST_AUTO_TEST_CASE(can_not_switch_fifth_gear_and_speeds_150)
	{
		switchAndCheckGearAndSpeed(car, 5, 150);
	}
	BOOST_AUTO_TEST_CASE(can_not_switch_more_than_MAX_GEAR_gear)
	{
		switchAndCheckGearAndSpeed(car, 6, 150);
		switchAndCheckGearAndSpeed(car, 6, 0);
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