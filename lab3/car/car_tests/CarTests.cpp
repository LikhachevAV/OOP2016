﻿#include "stdafx.h"
#include "..\car\CCar.h"

struct CarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(Car, CarFixture)

	BOOST_AUTO_TEST_SUITE(EngineOn_function)
		BOOST_AUTO_TEST_CASE(engine_is_off_by_default)
		{
			BOOST_CHECK(!car.IsEngineOn());
		}

		BOOST_AUTO_TEST_CASE(can_turned_off_engine_turn_on)
		{
			BOOST_CHECK(car.EngineOn());
			BOOST_CHECK(car.IsEngineOn());
		}

		BOOST_AUTO_TEST_CASE(dont_change_turned_on_engine_state)
		{
			BOOST_CHECK(car.EngineOn());
			BOOST_CHECK(!car.EngineOn());
			BOOST_CHECK(car.IsEngineOn());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(EngineOff_function)
		BOOST_AUTO_TEST_CASE(dont_change_turned_off_engine_state)
		{
			BOOST_CHECK(!car.EngineOff());
			BOOST_CHECK(!car.IsEngineOn());
		}
	BOOST_AUTO_TEST_SUITE_END()

	struct TurnedOnEngineCar : CarFixture
	{
		TurnedOnEngineCar()
		{
			car.EngineOn();
		}
	};

	BOOST_FIXTURE_TEST_SUITE(CarFixture, TurnedOnEngineCar)
		BOOST_AUTO_TEST_CASE(can_turn_off_turned_on_engine)
		{
			BOOST_CHECK(car.EngineOff());
			BOOST_CHECK(!car.IsEngineOn());
		}

		BOOST_AUTO_TEST_CASE(can_not_turn_off_when_speed_is_not_0)
		{
			BOOST_CHECK(car.SetGear(1));
			BOOST_CHECK(car.SetSpeed(30));
			BOOST_CHECK(!car.EngineOff());
			BOOST_CHECK(car.IsEngineOn());
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()