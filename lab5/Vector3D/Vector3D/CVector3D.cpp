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

CVector3D CVector3D::operator+ (const CVector3D & vector1) const
{
	CVector3D rezult;
	rezult.x = x + vector1.x;
	rezult.y = y + vector1.y;
	rezult.z = z + vector1.z;
	return rezult;
}

CVector3D CVector3D::operator+ () const
{
	return *this;
}

CVector3D CVector3D::operator- (const CVector3D & vector1) const
{
	CVector3D rezult;
	rezult.x = x + vector1.x;
	rezult.y = y + vector1.y;
	rezult.z = z + vector1.z;
	return rezult;
}

CVector3D CVector3D::CVector3D::operator- () const
{
	CVector3D result;
	return result;
}

CVector3D operator* (const CVector3D & vector3d, double scalar)
{
	CVector3D result;
	result.x = vector3d.x * scalar;
	result.y = vector3d.y * scalar;
	result.z = vector3d.z * scalar;
	return result;
};

CVector3D operator* (double scalar, const CVector3D & vector3d)
{
	CVector3D result;
	result.x = scalar * vector3d.x;
	result.y = scalar * vector3d.y;
	result.z = scalar * vector3d.z;
	return result;
};