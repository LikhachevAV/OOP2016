class CVector3D
{
public:

	CVector3D();

	CVector3D(double x0, double y0, double z0);

	double GetLength()const;

	void Normalize();

	CVector3D operator+ (const CVector3D & vector1)  const;

	CVector3D operator+ () const;

	CVector3D operator- (const CVector3D & vector1) const;

	CVector3D operator- () const;
	
	friend CVector3D operator* (const CVector3D & vector3d, double scalar);

	friend CVector3D operator* (double scalar, const CVector3D & vector3d);

	double x, y, z;
};
