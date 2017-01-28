#pragma once
#include "stdafx.h"
#include "..\Shapes\Circle.h"

using namespace std;

double GetCircleArea(double diameter)
{
	return M_PI * diameter * diameter / 4;
}

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
		auto perimeter = M_PI * diameter;
		BOOST_CHECK_EQUAL(circle.GetPerimeter(), perimeter);
		auto area = GetCircleArea(diameter);
		BOOST_CHECK_EQUAL(circle.GetArea(), area); 
		string circleOutStr = "circle (0.0, 0.0) 12.2 red white";
		BOOST_CHECK_EQUAL(circle.ToString(), circleOutStr);
	}

	BOOST_AUTO_TEST_CASE(can_construct_circle_with_center_in_not_0_0_point)
	{
		CPoint center(-3, 2.5);
		double diameter = 10;
		string outlineColor = "purple";
		string fillColor = "blue";
		CCircle circle(center, diameter, outlineColor, fillColor);
		BOOST_CHECK(circle.GetCenter() == CPoint(-3, 2.5));
		BOOST_CHECK_EQUAL(circle.GetOutlineColor(), outlineColor);
		BOOST_CHECK_EQUAL(circle.GetFillColor(), fillColor);
		auto perimeter = M_PI * diameter;
		BOOST_CHECK_EQUAL(circle.GetPerimeter(), perimeter);
		auto area = GetCircleArea(diameter);
		BOOST_CHECK_EQUAL(circle.GetArea(), area);
		string circleOutStr = "circle (-3.0, 2.5) 10.0 purple blue";
		BOOST_CHECK_EQUAL(circle.ToString(), circleOutStr);
	}
BOOST_AUTO_TEST_SUITE_END()