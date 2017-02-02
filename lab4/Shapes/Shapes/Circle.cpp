#include "stdafx.h"
#include "Circle.h"

CCircle::CCircle(CPoint const & center, double radius, std::string const & outlineColor, std::string fillColor) :
	CSolidShape(outlineColor, fillColor),
	m_center(center),
	m_radius(abs(radius))
{
}

CCircle::~CCircle()
{
}

std::string CCircle::ToString() const
{
	std::stringstream strm;
	strm << std::fixed << std::setprecision(1)
		<< "circle " << m_center.ToString() << " " << m_radius << " "
		<< GetOutlineColor() << " " << GetFillColor();
	return strm.str();
}

double CCircle::GetArea() const
{
	return M_PI * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

bool CCircle::Equals(CCircle const & circe) const
{
	return m_center == circe.GetCenter() &&
		m_radius == circe.GetRadius() &&
		GetOutlineColor().compare(circe.GetOutlineColor()) == 0 &&
		GetFillColor().compare(circe.GetFillColor()) == 0;
}

std::istream & operator >> (std::istream & is, CCircle & circle)
{
	return is;
}
