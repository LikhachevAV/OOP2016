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
	return 0.0;
}

double CCircle::GetPerimeter() const
{
	return 0.0;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}
