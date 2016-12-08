#include "stdafx.h"
#include "..\car\CCar.h"

struct CarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(Car, CarFixture)

	BOOST_AUTO_TEST_SUITE(SetGear_function)
		BOOST_AUTO_TEST_CASE(can_not_set_gear_on_turned_of_engine)
		{
			BOOST_CHECK(!car.SetGear(1));
		}
	BOOST_AUTO_TEST_SUITE_END()


	BOOST_AUTO_TEST_SUITE(IsEngineOn_function)
		BOOST_AUTO_TEST_CASE(return_false_on_just_declared_car)
		{
			BOOST_CHECK(!car.IsEngineOn());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(EngineOn_function)

		BOOST_AUTO_TEST_CASE(can_turn_on_car_engine_when_it_is_turned_off)
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

		BOOST_AUTO_TEST_CASE(can_not_turn_off_engine_when_speed_is_not_0)
		{
			BOOST_CHECK(car.SetGear(1));
			BOOST_CHECK(car.SetSpeed(30));
			BOOST_CHECK(!car.EngineOff());
			BOOST_CHECK(car.IsEngineOn());
		}

		BOOST_AUTO_TEST_CASE(can_set_first_gear_and_set_speed_30_when_engine_is_turned_on_and_speed_is_0)
		{
			car.EngineOn();
			BOOST_CHECK(car.SetGear(1));
			car.SetSpeed(30);
			BOOST_CHECK(car.SetGear(1));
		}

		struct TurnedOnEngineCarWithSpeed30OnFirstGear : TurnedOnEngineCar
		{
			TurnedOnEngineCarWithSpeed30OnFirstGear()
			{
				car.SetSpeed(30);
			}
		};

		BOOST_FIXTURE_TEST_SUITE(TurnedOnEngineCar, TurnedOnEngineCarWithSpeed30OnFirstGear)
			BOOST_AUTO_TEST_CASE(can_set_second_gear_when_speed_is_30_and_can_not_set_first_gear_when_more_than_30)
			{
				car.EngineOn();
				car.SetGear(1);
				car.SetSpeed(30);
				car.SetGear(2);
				car.SetSpeed(31);
				BOOST_CHECK(!car.SetGear(1));
			}
		BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()