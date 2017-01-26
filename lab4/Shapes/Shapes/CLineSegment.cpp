#include "stdafx.h"
#include "CLineSegment.h"

CLineSegment::CLineSegment(CPoint const & startPoint, CPoint const & endPoint, std::string const & outlineColor) :
	m_startPoint(startPoint),
	m_endPoint(endPoint),
	CShape(outlineColor)
{}

double CLineSegment::GetPerimeter() const
{
	return 0.0;
}