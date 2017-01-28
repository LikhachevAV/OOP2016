#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(CPoint const & a, CPoint const & b, CPoint const & c,
	std::string const & outlineColor, std::string const & fillColor):
	CSolidShape(outlineColor, fillColor),
	m_a(a),
	m_b(b),
	m_c(c)
{
}

CTriangle::~CTriangle()
{
}

std::string CTriangle::ToString() const
{
	return std::string();
}

double CTriangle::GetArea() const
{
	return 0.0;
}

double CTriangle::GetPerimeter() const
{
	return 0.0;
}
