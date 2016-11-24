#include "stdafx.h"
#include "..\car\CCar.h"


BOOST_AUTO_TEST_SUITE(EngineOn_function)
	CCar car;

	BOOST_AUTO_TEST_CASE(engine_is_off_by_default)
	{
		BOOST_CHECK(!car.IsEngineOn());
	}

	BOOST_AUTO_TEST_CASE(turned_off_engine_turn_on)
	{
		BOOST_CHECK(car.EngineOn());
		BOOST_CHECK(car.IsEngineOn());
	}

	BOOST_AUTO_TEST_CASE(dont_change_turned_on_engine_state)
	{
		BOOST_CHECK(!car.EngineOn());
		BOOST_CHECK(car.IsEngineOn());
	}

BOOST_AUTO_TEST_SUITE_END()
