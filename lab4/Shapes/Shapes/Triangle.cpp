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
	double semiPerimeter = GetPerimeter() / 2;
	return sqrt(semiPerimeter  *
	(semiPerimeter - GetAbLength()) *
	(semiPerimeter - GetBcLength()) *
	(semiPerimeter - GetCaLength()));
}

double CTriangle::GetPerimeter() const
{
	return Get2PointsDistance(m_a, m_b) +
		Get2PointsDistance(m_b, m_c) +
		Get2PointsDistance(m_c, m_a);
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
