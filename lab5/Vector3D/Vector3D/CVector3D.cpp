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