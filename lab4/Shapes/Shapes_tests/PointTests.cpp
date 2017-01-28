#pragma once
#include "stdafx.h"
#include "..\Shapes\Point.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(CPoint_)
	
	BOOST_AUTO_TEST_CASE(have_0_0_coordinates_by_default)
	{	
		CPoint point;
		BOOST_CHECK_EQUAL(point.x, 0.0);
		BOOST_CHECK_EQUAL(point.y, 0.0);
	}
	
	BOOST_AUTO_TEST_CASE(can_set_coordinates_at_constructor)
	{
		CPoint point(3.0, 5.0);
		BOOST_CHECK_EQUAL(point.x, 3.0);
		BOOST_CHECK_EQUAL(point.y, 5.0);
	}

	BOOST_AUTO_TEST_CASE(can_set_coordinates_after_constructor)
	{
		CPoint point;
		point.x = 7;
		point.y = 22;
		BOOST_CHECK_EQUAL(point.x, 7.0);
		BOOST_CHECK_EQUAL(point.y, 22.0);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ToString_function)
	BOOST_AUTO_TEST_CASE(return_CPoiint_instance_coordinates_in_text_format)
	{
		CPoint point;
		BOOST_CHECK_EQUAL("(0.0, 0.0)", point.ToString());
		point = CPoint(2.22, 4.49);
		BOOST_CHECK_EQUAL("(2.2, 4.5)", point.ToString());
	}
BOOST_AUTO_TEST_SUITE_END()

struct twoPointsWithDefaultWalue
{
	CPoint a;
	CPoint b;
};

BOOST_FIXTURE_TEST_SUITE(double_equal_operator, twoPointsWithDefaultWalue)
	BOOST_AUTO_TEST_CASE(return_true_when_points_are_equal)
	{
		BOOST_CHECK(a == b);
		double x = -2.2;
		double y = 32.4;
		a = CPoint(x, y);
		b = CPoint(x, y);
		BOOST_CHECK(a == b);
	}

	BOOST_AUTO_TEST_CASE(return_false_when_coordinates_x_are_not_equal)
	{
		a.x = -1.2;
		BOOST_CHECK(!(a == b));
	}

	BOOST_AUTO_TEST_CASE(return_false_when_coordinates_y_are_not_equal)
	{
		b.y = 822.3;
		BOOST_CHECK(!(a == b));
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(not_equals_operator, twoPointsWithDefaultWalue)
	BOOST_AUTO_TEST_CASE(return_false_when_points_are_equal)
	{
		BOOST_CHECK(!(a != b));
	}

	BOOST_AUTO_TEST_CASE(return_true_when_coordinates_x_are_not_equal)
	{
		a.x = 72;
		BOOST_CHECK(a != b);
	}

	BOOST_AUTO_TEST_CASE(return_true_when_coordinates_y_are_not_equal)
	{
		b.y = -2.92;
		BOOST_CHECK(a != b);
	}

	BOOST_AUTO_TEST_CASE(return_true_when_coordinates_x_and_y_are_not_equal)
	{
		a.x = 87;
		b.y = -2.92;
		BOOST_CHECK(a != b);
	}
BOOST_AUTO_TEST_SUITE_END()