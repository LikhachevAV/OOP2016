#include "targetver.h"

class CVector3D
{
public:

	CVector3D() = default;
	CVector3D(double x0, double y0, double z0);

	double GetLength()const;
	const CVector3D Normalize();
	const CVector3D operator+ (CVector3D const & vector1)  const;
	const CVector3D operator+ () const;
	const CVector3D operator- (CVector3D const & vector1) const;
	const CVector3D operator- () const;
	CVector3D operator+= (CVector3D const & vector1);
	CVector3D operator-= (CVector3D const & vector1);
	const CVector3D operator/ (double scalar) const;
	CVector3D operator*= (double scalar);
	CVector3D operator/= (double scalar);
	bool operator==(CVector3D const & vector1) const;
	bool operator!=(CVector3D const & vector1) const;

	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
};

CVector3D operator* (CVector3D const & vector3d, double scalar);
CVector3D operator* (double scalar, CVector3D const & vector3d);
double DotProduct(CVector3D const& vector1, CVector3D const& vector2);
const CVector3D CrossProduct(CVector3D const& vector1, CVector3D const& vector2);