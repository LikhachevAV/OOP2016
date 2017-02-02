#include "stdafx.h"
#include "../Shapes/Triangle.h"
#include "TriangleTests.h"

using namespace std;

double GetTrianglePerimeter(CTriangle const & triangle)
{
	return Get2PointsDistance(triangle.GetVertexA(), triangle.GetVertexB()) +
		Get2PointsDistance(triangle.GetVertexB(), triangle.GetVertexC()) +
		Get2PointsDistance(triangle.GetVertexC(), triangle.GetVertexA());
};

double GetTriangleArea(CTriangle const & triangle)
{
	double semiPerimeter = GetTrianglePerimeter(triangle) / 2;
	double abLength = Get2PointsDistance(triangle.GetVertexA(), triangle.GetVertexB());
	double bcLength = Get2PointsDistance(triangle.GetVertexB(), triangle.GetVertexC());
	double caLength = Get2PointsDistance(triangle.GetVertexC(), triangle.GetVertexA());
	return sqrt(semiPerimeter *
	(semiPerimeter - abLength) *
	(semiPerimeter - bcLength) *
	(semiPerimeter - caLength));
}

BOOST_AUTO_TEST_SUITE(CTriangle_)

	BOOST_AUTO_TEST_CASE(_constructorcan_create_instance)
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
		BOOST_CHECK_EQUAL(t1.GetPerimeter(), GetTrianglePerimeter(t1));
		BOOST_CHECK_EQUAL(t1.GetArea(), GetTriangleArea(t1));
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(read_from_stream_operator)
	BOOST_AUTO_TEST_CASE(can_read_triangle)
	{
		CPoint point(0, 0);
		string outLineColor = "white";
		string fillColor = "white";
		CTriangle triangle(point, point, point, outLineColor, fillColor);
		string s = "(0.0, 1.1) (2.2, 2.2) (-2.0, 5.0) red green";
		stringstream strm(s);
		strm >> triangle;
		CTriangle expectedTriangle(CPoint(0.0, 1.1), CPoint(2.2, 2.2),
			CPoint(-2, 5), string("red"), string("green"));
		BOOST_CHECK(triangle.Equals(expectedTriangle));
	}

	BOOST_AUTO_TEST_CASE(throw_exception_when_can_not_read_outline_and_fill_colors)
	{
		CPoint point(0, 0);
		string outLineColor = "white";
		string fillColor = "white";
		CTriangle triangle(point, point, point, outLineColor, fillColor);
		string s = "(0.0, 1.1) (2.2, 2.2) (-2.0, 5.0)";
		stringstream strm(s);
		BOOST_CHECK_THROW(strm >> triangle, std::exception);
		CTriangle expectedTriangle(CPoint(0.0, 1.1), CPoint(2.2, 2.2),
			CPoint(-2, 5), string("red"), string("green"));
		BOOST_CHECK(!triangle.Equals(expectedTriangle));
	}

BOOST_AUTO_TEST_SUITE_END()
