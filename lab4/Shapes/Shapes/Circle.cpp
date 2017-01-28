#include "stdafx.h"
#include "Circle.h"

CCircle::CCircle(CPoint const & center, double diameter, std::string const & outlineColor, std::string fillColor) :
	CSolidShape(outlineColor, fillColor),
	m_center(center),
	m_diameter(abs(diameter))
{
}

CCircle::~CCircle()
{
}

std::string CCircle::ToString() const
{
	std::stringstream strm;
	strm << std::fixed << std::setprecision(1)
		<< "circle " << m_center.ToString() << " " << m_diameter << " "
		<< GetOutlineColor() << " " << GetFillColor();
	return strm.str();
}

double CCircle::GetArea() const
{
	return M_PI * m_diameter * m_diameter / 4;
}

double CCircle::GetPerimeter() const
{
	return M_PI * m_diameter;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetDiameter() const
{
	return m_diameter;
}
