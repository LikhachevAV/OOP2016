#include "stdafx.h"
#include "../Triangle/Triangle.h"

using namespace std;

auto GetTrianglePerimeter(CTriangle const & triangle)
{
	return triangle.GetSide1() + triangle.GetSide2() + triangle.GetSide3();
}

auto GetTriangleArea(CTriangle const & triangle)
{
	auto p = GetTrianglePerimeter(triangle);
	auto area = sqrt(p * (p - triangle.GetSide1()) * 
		(p - triangle.GetSide2()) * (p - triangle.GetSide3()));
	return area;
}

BOOST_AUTO_TEST_SUITE(Can_not_create_triangle)

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

	BOOST_AUTO_TEST_CASE(with_all_zero_sides)
	{
		BOOST_CHECK_THROW(CTriangle triangle(0, 0, 0), std::domain_error);
	}

	BOOST_AUTO_TEST_CASE(with_two_zero_sides)
	{
		BOOST_CHECK_THROW(CTriangle triangle(0, 2, 0), std::domain_error);
	}

	BOOST_AUTO_TEST_CASE(with_max_size_more_than_sum_of_two_other_sides)
	{
		BOOST_CHECK_THROW(CTriangle triangle(3, 2, 6), std::domain_error);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(DegenerateTriangle)
	BOOST_AUTO_TEST_CASE(have_zero_area)
	{
		CTriangle degenerateTriangle(7, 3, 4);
		BOOST_CHECK_EQUAL(degenerateTriangle.GetSide1(), 7.0);
		BOOST_CHECK_EQUAL(degenerateTriangle.GetSide2(), 3.0);
		BOOST_CHECK_EQUAL(degenerateTriangle.GetSide3(), 4.0);
		BOOST_CHECK_EQUAL(degenerateTriangle.GetArea(), 0);
		BOOST_CHECK_EQUAL(degenerateTriangle.GetPerimeter(), GetTrianglePerimeter(degenerateTriangle));
	}
BOOST_AUTO_TEST_SUITE_END()