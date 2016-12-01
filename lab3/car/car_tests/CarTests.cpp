#include "stdafx.h"
#include "..\car\CCar.h"


BOOST_AUTO_TEST_SUITE(EngineOn_function)
	CCar car;

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
		BOOST_CHECK(!car.EngineOn());
		BOOST_CHECK(car.IsEngineOn());
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(EngineOff_function)
	CCar car;

	BOOST_AUTO_TEST_CASE(dont_change_turned_off_engine_state)
	{
		BOOST_CHECK(!car.EngineOff());
		BOOST_CHECK(!car.IsEngineOn());
	}

	BOOST_AUTO_TEST_CASE(can_turned_off_turned_on_engine)
	{
		car.EngineOn();
		BOOST_CHECK(car.EngineOff());
		BOOST_CHECK(!car.IsEngineOn());
	}

	//TODO: добавить тесты в случае с ненулевой скоростью и ненейтральной передачей

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(SetGear_function)
CCar car;
	BOOST_AUTO_TEST_CASE(can_not_set_gear_on_turned_of_engine)
	{
		BOOST_CHECK(!car.SetGear(1));
	}

	BOOST_AUTO_TEST_CASE(can_set_first_gear)
	{
		car.EngineOn();
		BOOST_CHECK(car.SetGear(1));
		car.SetSpeed(30);
		BOOST_CHECK(car.SetGear(1));
	}

	BOOST_AUTO_TEST_CASE(can_not_set_first_gear)
	{
		car.EngineOn();
		car.SetGear(1);
		car.SetSpeed(31);
		BOOST_CHECK(!car.SetGear(1));
	}

	BOOST_AUTO_TEST_CASE(can_not_set_first_gear_when_direction_is_backward)
	{
		car.SetSpeed(0);
		car.SetGear(0);
		car.SetGear(-1);
		car.SetSpeed(20);
		BOOST_CHECK(!car.SetGear(1));
	}
BOOST_AUTO_TEST_SUITE_END()
