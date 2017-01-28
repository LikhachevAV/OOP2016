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
	double abLength = Get2PointsDistance(m_a, m_b);
	double bcLength = Get2PointsDistance(m_b, m_c);
	double caLength = Get2PointsDistance(m_c, m_a);
	double perimeter = GetPerimeter();
	return sqrt(perimeter *
	(perimeter - abLength) *
	(perimeter - bcLength) *
	(perimeter - caLength));
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
