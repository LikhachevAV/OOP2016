#include "stdafx.h"
#include "../Shapes/Triangle.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(CTriangle_)
	BOOST_AUTO_TEST_CASE(constructor_can_create_instance)
	{
		CPoint a(0, 0);
		CPoint b(9, 3);
		CPoint c(-2, -2);
		std::string outlineColor = "blue";
		std::string fillColor = "green";
		CTriangle t1(a, b, c, outlineColor, fillColor);
		BOOST_CHECK(t1.GetVertexA() == a);
		BOOST_CHECK(t1.GetVertexB() == b);
		BOOST_CHECK(t1.GetVertexC() == c);
	}
BOOST_AUTO_TEST_SUITE_END()