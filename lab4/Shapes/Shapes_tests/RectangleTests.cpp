#include "stdafx.h"
#include "../Shapes/Rectangle.h"
using namespace std;

auto getWidth = [&](CRectangle rectangle) {
	return	abs(rectangle.GetRightBottom().x - rectangle.GetLeftTop().x);
};

auto getHeight = [&](CRectangle rectangle) {
	return abs(rectangle.GetLeftTop().y - rectangle.GetRightBottom().y);
};

auto getTrianglePerimeter = [&](CRectangle rectangle) {
	return 2 * (getWidth(rectangle) + getHeight(rectangle));
};

auto getArea = [&](CRectangle rectangle) {
	return getWidth(rectangle) * getHeight(rectangle);
};

BOOST_AUTO_TEST_SUITE(CRectangle_)
	BOOST_AUTO_TEST_CASE(can_create_rectangle_instance)
	{
		CPoint leftTop(1, 13);
		CPoint rightBottom(4, 3);
		string outlineColor = "blue";
		string fillColor = "green";
		CRectangle rectangle(leftTop, rightBottom, outlineColor, fillColor);
		BOOST_CHECK(rectangle.GetLeftTop() == leftTop);
		BOOST_CHECK(rectangle.GetRightBottom() == rightBottom);
		BOOST_CHECK_EQUAL(rectangle.GetWidth(), getWidth(rectangle));
		BOOST_CHECK_EQUAL(rectangle.GetHeight(), getHeight(rectangle));
		BOOST_CHECK_EQUAL(rectangle.GetPerimeter(), getTrianglePerimeter(rectangle));
		BOOST_CHECK_EQUAL(rectangle.GetArea(), getArea(rectangle));
		string rectangleOutStr = "rectangle (1.0, 13.0) (4.0, 3.0) blue green";
		BOOST_CHECK_EQUAL(rectangle.ToString(), rectangleOutStr);
	}
BOOST_AUTO_TEST_SUITE_END()