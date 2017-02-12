#include "stdafx.h"
#include "../Triangle/Triangle.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Constructor_can_create_triangle)
	BOOST_AUTO_TEST_CASE(with_same_sides)
	{	
		CTriangle triangle(1, 1, 1);
	}

BOOST_AUTO_TEST_SUITE_END()
