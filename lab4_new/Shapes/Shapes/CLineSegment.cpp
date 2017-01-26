#include "stdafx.h"
#include "CLineSegment.h"

CLineSegment::CLineSegment(CPoint const & startPoint, CPoint const & endPoint, std::string const & outlineColor) :
	m_startPoint(startPoint),
	m_endPoint(endPoint),
	CShape(outlineColor)
{
}

CLineSegment::~CLineSegment()
{
}

double CLineSegment::GetPerimeter() const
{
	return GetDistance(m_startPoint, m_endPoint);
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

std::string CLineSegment::ToString() const
{
	return "";
}