#pragma once
#include "stdafx.h"
#include "..\Shapes\CPoint.h"
#include "..\Shapes\CLineSegment.h"

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

BOOST_AUTO_TEST_SUITE(GetPerimeter_function)
	BOOST_AUTO_TEST_CASE(return_zero_if_startPoin_and_endPoint_are_equal)
	{
		CPoint start(0, 0);
		CPoint end(0, 0);
		string color = "white";
		CLineSegment lineSegment = { start, end, color };
		//BOOST_CHECK_EQUAL("(0.0, 0.0)", point.ToString());
		//point = CPoint(2.22, 4.49);
		//BOOST_CHECK_EQUAL("(2.2, 4.5)", point.ToString());
	}
BOOST_AUTO_TEST_SUITE_END()
