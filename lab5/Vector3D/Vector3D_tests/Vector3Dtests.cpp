#include "stdafx.h"
#include "..\Vector3D\CVector3D.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(CVector3D_constructor)

	BOOST_AUTO_TEST_CASE(init_Vector3D_with_default_values)
	{
		CVector3D vector3d;
		BOOST_CHECK(vector3d.x == 0.0);
		BOOST_CHECK(vector3d.y == 0.0);
		BOOST_CHECK(vector3d.z == 0.0);
	}

	BOOST_AUTO_TEST_CASE(init_Vector3D_with_parameters)
	{
		CVector3D vector3d(15.0, 2.5, -3.0);
		BOOST_CHECK(vector3d.x == 15.0);
		BOOST_CHECK(vector3d.y == 2.5);
		BOOST_CHECK(vector3d.z == -3.0);
	}

BOOST_AUTO_TEST_SUITE_END()
