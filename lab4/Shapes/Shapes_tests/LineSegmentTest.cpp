#include "stdafx.h"
#include "..\Shapes\CLineSegment.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(ToString_function)
BOOST_AUTO_TEST_CASE(return_CPoiint_instance_coordinates_in_text_format)
{
	CPoint point;
	BOOST_CHECK_EQUAL("(0.0, 0.0)", point.ToString());
	point = CPoint(2.22, 4.49);
	BOOST_CHECK_EQUAL("(2.2, 4.5)", point.ToString());
}
BOOST_AUTO_TEST_SUITE_END()
