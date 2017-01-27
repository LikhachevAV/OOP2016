#pragma once
#include "stdafx.h"
#include "..\Shapes\Circle.h"
#include "CircleTests.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Circle_constructor)
	BOOST_AUTO_TEST_CASE(can_construct_circle_with_center_0_0)
	{
		CPoint center;
		double diameter = 12.2;
		string outlineColor = "red";
		string fillColor = "white";
		CCircle circle(center, diameter, outlineColor, fillColor);
		//BOOST_CHECK_EQUAL(circle.GetCenter(), CPoint(0, 0)); // todo
		//BOOST_CHECK_EQUAL();
	}
BOOST_AUTO_TEST_SUITE_END()