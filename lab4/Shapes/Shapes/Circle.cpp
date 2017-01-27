#include "stdafx.h"
#include "Circle.h"

CCircle::CCircle(CPoint const & center, double diameter, std::string const & outlineColor, std::string fillColor) :
	CSolidShape(outlineColor, fillColor),
	m_center(center),
	m_diameter(diameter)
{
}

CCircle::~CCircle()
{
}

std::string CCircle::ToString() const
{
	std::string s;
	return s;
}

double CCircle::GetArea() const
{
	return M_PI * m_diameter * m_diameter / 4;
}

double CCircle::GetPerimeter() const
{
	return m_diameter;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}
