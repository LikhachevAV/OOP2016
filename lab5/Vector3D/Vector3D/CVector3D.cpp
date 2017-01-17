#include "stdafx.h"
#include "CVector3D.h"
#pragma warning (push, 3)
#pragma warning (pop)
#pragma warning(disable: 4503)

using namespace std;

CVector3D::CVector3D()
{
	x = y = z = 0.0;
}

CVector3D::CVector3D(double x0, double y0, double z0)
{
	x = x0;
	y = y0;
	z = z0;
}

CVector3D CVector3D::operator+ (CVector3D const & vector1) const
{
	CVector3D result;
	result.x = x + vector1.x;
	result.y = y + vector1.y;
	result.z = z + vector1.z;
	return result;
}

CVector3D CVector3D::operator+ () const
{
	return *this;
}

CVector3D CVector3D::operator- (CVector3D const & vector1) const
{
	CVector3D result;
	result.x = x - vector1.x;
	result.y = y - vector1.y;
	result.z = z - vector1.z;
	return result;
}

CVector3D CVector3D::CVector3D::operator- () const
{
	CVector3D result;
	return *this * -1;
}

CVector3D operator* (CVector3D const & vector3d, double scalar)
{
	CVector3D result;
	result.x = vector3d.x * scalar;
	result.y = vector3d.y * scalar;
	result.z = vector3d.z * scalar;
	return result;
};

CVector3D operator* (double scalar, CVector3D const & vector3d)
{
	CVector3D result;
	result.x = scalar * vector3d.x;
	result.y = scalar * vector3d.y;
	result.z = scalar * vector3d.z;
	return result;
};

void CVector3D::operator+= (CVector3D const & vector1)
{
	x += vector1.x;
	y += vector1.y;
	z += vector1.z;
};

void CVector3D::operator-= (CVector3D const & vector1)
{
	x -= vector1.x;
	y -= vector1.y;
	z -= vector1.z;
};

CVector3D CVector3D::operator/ (double scalar) const 
{
	if (scalar == 0)
	{
		throw invalid_argument("Divizion by zero error!");
	}
	CVector3D result;
	result.x = x / scalar;
	result.y = y / scalar;
	result.z = z / scalar;
	return result;
}

void CVector3D::operator*= (double scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

/* TODO:
/=
==
!=
GetLength()
Normalize()
*/