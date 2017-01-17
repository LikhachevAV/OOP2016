#include "stdafx.h"
#include "..\Vector3D\CVector3D.h"

using namespace std;

struct TwoVectors3DFixtureOne
{
	CVector3D vector1, vector2;
	double	x1 = 15.0, y1 = 2.5, z1 = -3.0,
			x2 = 2.0, y2 = 1.5, z2 = 1.0;
	TwoVectors3DFixtureOne()
	{
		vector1 = CVector3D(x1, y1, z1);
		vector2 = CVector3D(x2, y2, z2);
	}
};

BOOST_AUTO_TEST_SUITE(CVector3D_)

	BOOST_AUTO_TEST_CASE(init_Vector3D_with_default_values)
	{
		CVector3D vector1;
		BOOST_CHECK(vector1.x == 0.0);
		BOOST_CHECK(vector1.y == 0.0);
		BOOST_CHECK(vector1.z == 0.0);
	}

	BOOST_AUTO_TEST_CASE(init_Vector3D_with_parameters)
	{
		CVector3D vector1(15.0, 2.5, -3.0);
		BOOST_CHECK(vector1.x == 15.0);
		BOOST_CHECK(vector1.y == 2.5);
		BOOST_CHECK(vector1.z == -3.0);
	}

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(Operator_, TwoVectors3DFixtureOne)
	BOOST_AUTO_TEST_CASE(plus_return_vector_with_sum_values_of_two_vectors)
	{
		CVector3D sumVector = vector1 + vector2;
		BOOST_CHECK_EQUAL(sumVector.x, (vector1.x + vector2.x));
		BOOST_CHECK_EQUAL(sumVector.y, (vector1.y + vector2.y));
		BOOST_CHECK_EQUAL(sumVector.z, (vector1.z + vector2.z));
	}
BOOST_AUTO_TEST_SUITE_END()