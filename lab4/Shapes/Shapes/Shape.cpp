#include "stdafx.h"
#include "Shape.h"

CShape::CShape(std::string const& outlineColor) :
	m_outlineColor(outlineColor)
{
}

CShape::~CShape()
{
}

std::string CShape::GetOutlineColor() const
{
	return m_outlineColor;
}

double Get2PointsDistance(CPoint const & a, CPoint const & b)
{
	return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

