#pragma once
#include "stdafx.h"
#include "..\Shapes\CLineSegment.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(GetPerimeter_function)
	BOOST_AUTO_TEST_CASE(return_zero_if_startPoin_and_endPoint_are_equal)
	{
		CPoint start(0, 0);
		CPoint end(0, 0);
		string color = "white";
		CLineSegment lineSegment = { start, end, color };
		BOOST_CHECK_EQUAL(0.0, lineSegment.GetPerimeter());
		lineSegment = CLineSegment(CPoint(10, 5), CPoint(10, 5), color);
		BOOST_CHECK_EQUAL(0.0, lineSegment.GetPerimeter());
		double perimeter = sqrt((start.x - end.x) * (start.x - end.x) + (start.y - end.y) * (start.y - end.y));
		BOOST_CHECK_EQUAL(perimeter, lineSegment.GetPerimeter());
	}

	BOOST_AUTO_TEST_CASE(return_perimeter_if_start_and_end_points_are_not_equal)
	{
		CPoint start(2, 7);
		CPoint end(17, -4.2);
		string color = "white";
		CLineSegment lineSegment = { start, end, color };
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(GetArea_function)
	BOOST_AUTO_TEST_CASE(always_return_zero)
	{
		string color = "white";
		CLineSegment lineSegment(CPoint(), CPoint(), color);
		BOOST_CHECK_EQUAL(0.0, lineSegment.GetArea());
		lineSegment = CLineSegment(CPoint(-2, 2), CPoint(18.2, 44.5), color);
		BOOST_CHECK_EQUAL(0.0, lineSegment.GetArea());
	}
BOOST_AUTO_TEST_SUITE_END()
