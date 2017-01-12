#include "stdafx.h"
#include "..\car\CCar.h"
#include "CarNewTests.h"

BOOST_FIXTURE_TEST_SUITE(When_car_engine_is_off, CarFixture)

	BOOST_AUTO_TEST_SUITE(SetGear_function)
		BOOST_AUTO_TEST_CASE(can_not_set_reverse_gear)
		{
			BOOST_CHECK(!car.SetGear(-1));
			CarStatesCheck(car, false, 0, 0, Direction::stop);
		}
		BOOST_AUTO_TEST_CASE(can_not_set_same_gear)
		{
			BOOST_CHECK(!car.SetGear(0));
			CarStatesCheck(car, false, 0, 0, Direction::stop);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(SetSpeed_function)
		BOOST_AUTO_TEST_CASE(can_not_set_same_speed)
		{
			BOOST_CHECK(!car.SetSpeed(0));
			CarStatesCheck(car, false, 0, 0, Direction::stop);
		}
	BOOST_AUTO_TEST_SUITE_END()

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