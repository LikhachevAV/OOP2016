#include "stdafx.h"
#include "..\car\CCar.h"
#include "CarTests.h"

BOOST_FIXTURE_TEST_SUITE(When_car_engine_is_off, CarFixture)

auto canNotSwitchAndCheckGearAndSpeed = [&](CCar car, int gear, unsigned speed) {
	BOOST_CHECK(!car.SetGear(gear));
	CarStatesCheck(car, false, 0, 0, Direction::stop);
	BOOST_CHECK(!car.SetSpeed(speed));
	CarStatesCheck(car, false, 0, 0, Direction::stop);
};

BOOST_AUTO_TEST_CASE(can_not_switch_less_than_MIN_GEAR_gear)
{
	canNotSwitchAndCheckGearAndSpeed(car, -2, 0);
	canNotSwitchAndCheckGearAndSpeed(car, -2, 151);
}
BOOST_AUTO_TEST_CASE(can_not_switch_reverse_gear)
{
	canNotSwitchAndCheckGearAndSpeed(car, -1, 20);
}
BOOST_AUTO_TEST_CASE(can_not_switch_same_gear)
{
	canNotSwitchAndCheckGearAndSpeed(car, 0, 0);
	canNotSwitchAndCheckGearAndSpeed(car, 0, 150);
	canNotSwitchAndCheckGearAndSpeed(car, 0, 151);
}
BOOST_AUTO_TEST_CASE(can_not_switch_first_gear_and_speed_30)
{
	canNotSwitchAndCheckGearAndSpeed(car, 1, 30);
}
BOOST_AUTO_TEST_CASE(can_not_switch_second_gear_and_speeds_20_50_51)
{
	canNotSwitchAndCheckGearAndSpeed(car, 2, 20);
	canNotSwitchAndCheckGearAndSpeed(car, 2, 50);
	canNotSwitchAndCheckGearAndSpeed(car, 2, 51);
}
BOOST_AUTO_TEST_CASE(can_not_switch_third_gear_and_speeds_29_30)
{
	canNotSwitchAndCheckGearAndSpeed(car, 3, 29);
	canNotSwitchAndCheckGearAndSpeed(car, 3, 30);
}
BOOST_AUTO_TEST_CASE(can_not_switch_fourth_gear_and_speeds_90_91)
{
	canNotSwitchAndCheckGearAndSpeed(car, 4, 90);
	canNotSwitchAndCheckGearAndSpeed(car, 4, 91);
}
BOOST_AUTO_TEST_CASE(can_not_switch_fifth_gear_and_speeds_150)
{
	canNotSwitchAndCheckGearAndSpeed(car, 5, 150);
}
BOOST_AUTO_TEST_CASE(can_not_switch_more_than_MAX_GEAR_gear)
{
	canNotSwitchAndCheckGearAndSpeed(car, 6, 150);
	canNotSwitchAndCheckGearAndSpeed(car, 6, 0);
}
BOOST_AUTO_TEST_SUITE_END()
//#########################

BOOST_FIXTURE_TEST_SUITE(When_car_engine_is_on, TurnedOnEngineCar)

	BOOST_AUTO_TEST_CASE(can_not_speed_up)
	{
		BOOST_CHECK(!car.SetSpeed(10));
		CarStatesCheck(car, true, 0, 0, Direction::stop);
	}
	BOOST_AUTO_TEST_CASE(can_not_set_same_gear)
	{
		BOOST_CHECK(!car.SetGear(0));
		CarStatesCheck(car, true, 0, 0, Direction::stop);
	}
	BOOST_AUTO_TEST_CASE(can_not_set_gear_less_than_MIN_GEAR)
	{
		BOOST_CHECK(!car.SetGear(-2));
		CarStatesCheck(car, true, 0, 0, Direction::stop);
	}
BOOST_AUTO_TEST_SUITE_END()
//#########################

BOOST_FIXTURE_TEST_SUITE(When_car_in_reverse_gear, InReverseGearWithMaxSpeed20Car)
	BOOST_AUTO_TEST_CASE(can_not_set_same_speed)
	{
		BOOST_CHECK(!car.SetSpeed(20));
		CarStatesCheck(car, true, -1, 20, Direction::backward);
	}
	BOOST_AUTO_TEST_CASE(can_not_set_same_gear)
	{
		BOOST_CHECK(!car.SetGear(-1));
		CarStatesCheck(car, true, -1, 20, Direction::backward);
	}
	BOOST_AUTO_TEST_CASE(can_not_set_speed_more_than_20)
	{
		BOOST_CHECK(!car.SetSpeed(21));
		CarStatesCheck(car, true, -1, 20, Direction::backward);
	}
	BOOST_AUTO_TEST_CASE(can_not_set_first_gear)
	{
		BOOST_CHECK(!car.SetGear(1));
		CarStatesCheck(car, true, -1, 20, Direction::backward);
	}
	BOOST_AUTO_TEST_CASE(can_set_neutral_gear)
	{
		BOOST_CHECK(car.SetGear(0));
		CarStatesCheck(car, true, 0, 20, Direction::backward);
	}
	BOOST_AUTO_TEST_CASE(can_not_set_first_gear_on_neutral_gear_on_speed_20)
	{
		BOOST_CHECK(car.SetGear(0));
		CarStatesCheck(car, true, 0, 20, Direction::backward);
		BOOST_CHECK(!car.SetGear(1));
		CarStatesCheck(car, true, 0, 20, Direction::backward);
	}
	BOOST_AUTO_TEST_CASE(can_not_speed_up_in_neutral_gear)
	{
		BOOST_CHECK(car.SetGear(0));
		CarStatesCheck(car, true, 0, 20, Direction::backward);
		BOOST_CHECK(car.SetSpeed(10));
		CarStatesCheck(car, true, 0, 10, Direction::backward);
		BOOST_CHECK(!car.SetSpeed(15));
		CarStatesCheck(car, true, 0, 10, Direction::backward);
	}
	BOOST_AUTO_TEST_CASE(can_not_set_reverse_gear_again_after_switch_in_neutral)
	{
		BOOST_CHECK(car.SetGear(0));
		CarStatesCheck(car, true, 0, 20, Direction::backward);
		BOOST_CHECK(!car.SetGear(-1));
		CarStatesCheck(car, true, 0, 20, Direction::backward);
	}
BOOST_AUTO_TEST_SUITE_END()
//#########################

BOOST_FIXTURE_TEST_SUITE(When_car_on_first_gear_and_its_speed_30, InFirstGearWithMaxSpeed30)
	BOOST_AUTO_TEST_CASE(can_not_set_reverse_gear)
	{
		BOOST_CHECK(!car.SetGear(-1));
		CarStatesCheck(car, true, 1, 30, Direction::forward);
	}
	BOOST_AUTO_TEST_CASE(can_not_set_same_gear)
	{
		BOOST_CHECK(!car.SetGear(1));
		CarStatesCheck(car, true, 1, 30, Direction::forward);
	}
	BOOST_AUTO_TEST_CASE(can_not_set_speed_more_than_30)
	{
		BOOST_CHECK(!car.SetSpeed(31));
		CarStatesCheck(car, true, 1, 30, Direction::forward);
	}
BOOST_AUTO_TEST_SUITE_END()
//#########################

BOOST_FIXTURE_TEST_SUITE(When_car_on_second_gear_and_its_speed_50, InSecondGearWithMaxSpeed50)
BOOST_AUTO_TEST_CASE(can_not_set_speed_more_than_50)
{
	BOOST_CHECK(!car.SetGear(51));
	CarStatesCheck(car, true, 2, 50, Direction::forward);
}
BOOST_AUTO_TEST_SUITE_END()
//#########################

BOOST_FIXTURE_TEST_SUITE(When_car_on_third_gear_and_its_speed_60, InThirdGearWithMaxSpeed60)
BOOST_AUTO_TEST_CASE(can_not_set_speed_more_than_60)
{
	BOOST_CHECK(!car.SetSpeed(61));
	CarStatesCheck(car, true, 3, 60, Direction::forward);
}
BOOST_AUTO_TEST_SUITE_END()
//#########################

BOOST_FIXTURE_TEST_SUITE(When_car_on_fourth_gear_and_its_speed_90, InFourthGearWithMaxSpeed90)
	BOOST_AUTO_TEST_CASE(can_not_set_speed_less_than_30)
	{
		BOOST_CHECK(!car.SetSpeed(29));
		CarStatesCheck(car, true, 4, 90, Direction::forward);
	}
BOOST_AUTO_TEST_SUITE_END()
//#########################

BOOST_FIXTURE_TEST_SUITE(When_car_on_fifth_gear_and_its_speed_150, InFifthGearWithMaxSpeed150)
BOOST_AUTO_TEST_CASE(can_set_speed_50)
{
	BOOST_CHECK(car.SetSpeed(50));
	CarStatesCheck(car, true, 5, 50, Direction::forward);
}
BOOST_AUTO_TEST_CASE(can_set_speed_more_than_150)
{
	BOOST_CHECK(!car.SetSpeed(151));
	CarStatesCheck(car, true, 5, 150, Direction::forward);
}
BOOST_AUTO_TEST_CASE(can_not_set_gear_more_than_5)
{
	BOOST_CHECK(!car.SetGear(6));
	CarStatesCheck(car, true, 5, 150, Direction::forward);
}

BOOST_AUTO_TEST_CASE(can_set_neutral_gear)
{
	BOOST_CHECK(car.SetGear(0));
	CarStatesCheck(car, true, 0, 150, Direction::forward);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(Reverse_gear, TurnedOnEngineCar)
	BOOST_AUTO_TEST_CASE(can_set_in_neutral_gear_on_speed_0)
	{
		BOOST_CHECK(car.SetGear(-1));
		CarStatesCheck(car, true, -1, 0, Direction::stop);
	}
	BOOST_AUTO_TEST_CASE(can_set_in_first_gear_on_speed_0)
	{
		BOOST_CHECK(car.SetGear(1));
		CarStatesCheck(car, true, 1, 0, Direction::stop);
		BOOST_CHECK(car.SetGear(-1));
		CarStatesCheck(car, true, -1, 0, Direction::stop);
	}
BOOST_AUTO_TEST_SUITE_END()
//#########################