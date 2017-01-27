#pragma once
#include "stdafx.h"
#include "..\Shapes\Circle.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Circle_constructor)
	BOOST_AUTO_TEST_CASE(can_construct_circle_with_center_0_0)
	{
		CPoint center;
		double diameter = 12.2;
		string outlineColor = "red";
		string fillColor = "white";
		CCircle circle(center, diameter, outlineColor, fillColor);
		BOOST_CHECK(circle.GetCenter() == CPoint(0, 0));
		BOOST_CHECK_EQUAL(circle.GetOutlineColor(), outlineColor);
		BOOST_CHECK_EQUAL(circle.GetFillColor(), fillColor);
		BOOST_CHECK_EQUAL(circle.GetPerimeter(), diameter);
	}
BOOST_AUTO_TEST_SUITE_END()