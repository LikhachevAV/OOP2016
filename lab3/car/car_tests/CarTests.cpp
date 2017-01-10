#include "stdafx.h"
#include "..\car\CCar.h"

struct CarFixture
{
	CCar car;
};

BOOST_FIXTURE_TEST_SUITE(Car, CarFixture)

	BOOST_AUTO_TEST_SUITE(SetGear_function)
		BOOST_AUTO_TEST_CASE(can_not_set_gear_on_turned_off_engine)
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
			BOOST_CHECK_EQUAL(car.GetGear(), 1);
			BOOST_CHECK(car.SetSpeed(30));
			BOOST_CHECK_EQUAL(car.GetSpeed(), (unsigned)30);
			BOOST_CHECK(!car.EngineOff());
			BOOST_CHECK(car.IsEngineOn());
		}

		BOOST_AUTO_TEST_CASE(can_not_set_same_gear)
		{
			BOOST_CHECK(car.SetGear(1));
			BOOST_CHECK_EQUAL(car.GetGear(), 1);
			BOOST_CHECK(!car.SetGear(1));
		}

		BOOST_AUTO_TEST_CASE(can_not_set_first_gear_when_direction_is_backward)
		{
			car.SetGear(-1);
			car.SetSpeed(20);
			BOOST_CHECK(!car.SetGear(1));
			BOOST_CHECK_EQUAL(car.GetGear(), -1);
			BOOST_CHECK_EQUAL((int)car.GetDirection(), (int)Direction::backward);
			BOOST_CHECK_EQUAL(car.GetSpeed(), (unsigned)20);
		}

		struct TurnedOnEngineCarWithSpeed30OnFirstGear : TurnedOnEngineCar
		{
			TurnedOnEngineCarWithSpeed30OnFirstGear()
			{
				car.SetGear(1);
				car.SetSpeed(30);
			}
		};

		BOOST_FIXTURE_TEST_SUITE(TurnedOnEngineCar, TurnedOnEngineCarWithSpeed30OnFirstGear)
			BOOST_AUTO_TEST_CASE(when_it_is_we_can_set_speed_20_and_can_not_set_rewerse_gear)
			{
				BOOST_CHECK(car.SetSpeed(20));
				BOOST_CHECK(!car.SetGear(-1));
				BOOST_CHECK_EQUAL(car.GetGear(), 1);
			}

			BOOST_AUTO_TEST_CASE(when_it_is_we_can_shift_gears_forward_and_set_speeds)
			{
				BOOST_CHECK(!car.SetGear(-1));
				BOOST_CHECK(!car.EngineOff());
				BOOST_CHECK(!car.SetSpeed(31));
				BOOST_CHECK(car.SetGear(2));
				BOOST_CHECK(car.SetSpeed(50));
				BOOST_CHECK(!car.SetSpeed(51));
				BOOST_CHECK(car.SetGear(3));
				BOOST_CHECK(car.SetSpeed(60));
				BOOST_CHECK(!car.SetSpeed(61));
				BOOST_CHECK(car.SetGear(4));
				BOOST_CHECK(car.SetSpeed(90));
				BOOST_CHECK(!car.SetSpeed(91));
				BOOST_CHECK(car.SetGear(5));
				BOOST_CHECK(car.SetSpeed(150));
				BOOST_CHECK(!car.SetSpeed(151));
			}
		BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()