#include "stdafx.h"
#include "Shape.h"


CShape::CShape(std::string const& outlineColor):
	m_color(outlineColor)
{
}

std::string CShape::GetOutlineColor() const
{
	return m_color;
}

CShape::~CShape()
{
}
double GetDistance(CPoint const & a, CPoint const & b)
{
	return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

