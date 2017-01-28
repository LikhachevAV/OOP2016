#include "stdafx.h"
#include "../Shapes/Rectangle.h"
using namespace std;

BOOST_AUTO_TEST_SUITE(CRectangle_)
	BOOST_AUTO_TEST_CASE(can_create_rectangle_instance)
	{
		CPoint leftTop(1, 3);
		CPoint rightBottom(4, 3);
		string outlineColor = "blue";
		string fillColor = "green";
		CRectangle rectangle(leftTop, rightBottom, outlineColor, fillColor);
		BOOST_CHECK(rectangle.GetLeftTop() == leftTop);
		BOOST_CHECK(rectangle.GetRightBottom() == rightBottom);
	}
BOOST_AUTO_TEST_SUITE_END()