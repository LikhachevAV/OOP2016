#pragma once
#include "ISolidShape.h"
#include "Point.h"
#include "SolidShape.h"
class CCircle : public CSolidShape
{
public:

	CCircle(CPoint const &center, double radius, std::string const &outlineColor, std::string fillColor);
	~CCircle();
	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
	CPoint GetCenter() const;
	double GetRadius() const;
	bool Equals(CCircle const &circe) const;

private:
	CPoint m_center;
	double m_radius = 0;
};

std::istream &operator >> (std::istream &is, CCircle &circle);