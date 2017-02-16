#include "stdafx.h"
#include "../Triangle/Triangle.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Can_not_create_triangle)
	BOOST_AUTO_TEST_CASE(with_all_zero_sides)
	{	
		BOOST_CHECK_THROW(CTriangle triangle(0, 0, 0), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(with_negative_side1)
	{
		BOOST_CHECK_THROW(CTriangle triangle(-1, 1, 1), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(with_negative_side2)
	{
		BOOST_CHECK_THROW(CTriangle triangle(1, -1, 1), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(with_negative_side3)
	{
		BOOST_CHECK_THROW(CTriangle triangle(1, 1, -1), std::invalid_argument);
	}
BOOST_AUTO_TEST_SUITE_END()
