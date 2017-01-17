#include "stdafx.h"
#include "CVector3D.h"
#pragma warning (push, 3)
#pragma warning (pop)
#pragma warning(disable: 4503)

using namespace std;

CVector3D::CVector3D(double x0, double y0, double z0):
	x(x0),
	y(y0),
	z(z0)
{
}

double CVector3D::GetLength()const
{
	return sqrt(x * x + y * y + z * z);
}

const CVector3D CVector3D::Normalize()
{
	double length = GetLength();
	if (length != 0)
	{
		x /= length;
		y /= length;
		z /= length;
	}
	return *this;
}

double DotProduct(CVector3D const& vector1, CVector3D const& vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}

const CVector3D CVector3D::operator+ (CVector3D const & vector1) const
{
	return{ x + vector1.x, y + vector1.y, z + vector1.z };
}

const CVector3D CVector3D::operator+ () const
{
	return *this;
}

const CVector3D CVector3D::operator- (CVector3D const & vector1) const
{
	return{ x - vector1.x, y - vector1.y, z - vector1.z };
}

const CVector3D CVector3D::CVector3D::operator- () const
{
	return{ -x, -y, -z };
}

CVector3D operator* (CVector3D const & vector3d, double scalar)
{
	return{ vector3d.x * scalar, vector3d.y * scalar, vector3d.z * scalar };
};

CVector3D operator* (double scalar, CVector3D const & vector3d)
{
	return{ scalar * vector3d.x, scalar * vector3d.y, scalar * vector3d.z };
};

CVector3D CVector3D::operator+= (CVector3D const & vector1)
{
	x += vector1.x;
	y += vector1.y;
	z += vector1.z;
	return *this;
};

CVector3D  CVector3D::operator-= (CVector3D const & vector1)
{
	x -= vector1.x;
	y -= vector1.y;
	z -= vector1.z;
	return *this;
};

const CVector3D CVector3D::operator/ (double scalar) const 
{
	if (scalar == 0)
	{
		throw invalid_argument("Divizion by zero error!");
	}
	return{ x / scalar, y / scalar, z / scalar };
}

CVector3D CVector3D::operator*= (double scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

CVector3D CVector3D::operator/= (double scalar)
{
	if (scalar == 0)
	{
		throw invalid_argument("Divizion by zero error!");
	}
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

bool CVector3D::operator==(CVector3D const & vector1) const
{
	return (x == vector1.x) && (y == vector1.y) && (z == vector1.z);
}

bool CVector3D::operator!=(CVector3D const & vector1) const
{
	return (x != vector1.x) || (y != vector1.y) || (z != vector1.z);
}
