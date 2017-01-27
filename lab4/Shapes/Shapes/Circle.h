#pragma once
#include "ISolidShape.h"
#include "CPoint.h"
#include "SolidShape.h"
class CCircle : public CSolidShape
{
public:

	CCircle(CPoint const &center, double diameter, std::string const &outlineColor, std::string fillColor);
	~CCircle();
	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
	CPoint GetCenter() const;

private:
	CPoint m_center;
	double m_diameter = 0;
};
