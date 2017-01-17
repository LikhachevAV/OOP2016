#include "targetver.h"

class CVector3D
{
public:

	CVector3D();
	CVector3D(double x0, double y0, double z0);

	double GetLength()const;
	void Normalize();
	CVector3D operator+ (CVector3D const & vector1)  const;
	CVector3D operator+ () const;
	CVector3D operator- (CVector3D const & vector1) const;
	CVector3D operator- () const;
	friend CVector3D operator* (CVector3D const & vector3d, double scalar);
	friend CVector3D operator* (double scalar, CVector3D const & vector3d);
	void operator+= (CVector3D const & vector1);
	void operator-= (CVector3D const & vector1);
	CVector3D operator/ (double scalar) const;
	void operator*= (double scalar);
	void operator/= (double scalar);
	bool operator==(CVector3D const & vector1) const;
	bool operator!=(CVector3D const & vector1) const;

	double x, y, z;
};
