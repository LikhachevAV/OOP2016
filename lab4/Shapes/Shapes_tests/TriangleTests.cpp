#include "stdafx.h"
#include "../Shapes/Triangle.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(CTriangle_)

auto getTrianglePerimeter = [&](CTriangle const & triangle) {
	return Get2PointsDistance(triangle.GetVertexA(), triangle.GetVertexB()) +
		Get2PointsDistance(triangle.GetVertexB(), triangle.GetVertexC()) +
		Get2PointsDistance(triangle.GetVertexC(), triangle.GetVertexA());
};
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
		BOOST_CHECK_EQUAL(t1.GetOutlineColor(), outlineColor);
		BOOST_CHECK_EQUAL(t1.GetFillColor(), fillColor);
		BOOST_CHECK_EQUAL(t1.GetPerimeter(), getTrianglePerimeter(t1));
	}
BOOST_AUTO_TEST_SUITE_END()