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
	std::stringstream strm;
	strm << std::fixed << std::setprecision(1)
		<< "triangle with area: " << GetArea() << ", "
		<< "perimeter: " << GetPerimeter() << ", "
		<< "outline color: "
		<< GetOutlineColor() << " and "
		<< "fill color: "
		<< GetFillColor();
	return strm.str();
}

double CTriangle::GetArea() const
{
	double semiPerimeter = GetPerimeter() / 2;
	return sqrt(semiPerimeter  *
	(semiPerimeter - GetAbLength()) *
	(semiPerimeter - GetBcLength()) *
	(semiPerimeter - GetCaLength()));
}

double CTriangle::GetPerimeter() const
{
	return GetAbLength() + GetBcLength() + GetCaLength();
}

CPoint CTriangle::GetVertexA() const
{
	return m_a;
}

CPoint CTriangle::GetVertexB() const
{
	return m_b;
}

CPoint CTriangle::GetVertexC() const
{
	return m_c;
}

bool CTriangle::Equals(CTriangle const & triangle) const
{
	return m_a == triangle.GetVertexA() &&
		m_b == triangle.GetVertexB() &&
		m_c == triangle.GetVertexC() &&
		GetOutlineColor().compare(triangle.GetOutlineColor()) == 0 &&
		GetFillColor().compare(triangle.GetFillColor()) == 0;
}

double CTriangle::GetAbLength() const
{
	return Get2PointsDistance(m_a, m_b);
}

double CTriangle::GetBcLength() const
{
	return Get2PointsDistance(m_b, m_c);
}

double CTriangle::GetCaLength() const
{
	return Get2PointsDistance(m_c, m_a);
}

std::istream & operator >> (std::istream & is, CTriangle & triangle)
{
	CPoint a;
	CPoint b;
	CPoint c;
	std::string outLineColor;
	std::string fillClolor;
	if (!(is >> a >> b >> c >> outLineColor >> fillClolor))
	{
		throw std::exception("Triangle from istream reading exceprtion");
	}
	CTriangle resultTriangle(a, b, c, outLineColor, fillClolor);
	triangle = resultTriangle;
	return is;
}
