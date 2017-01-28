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
	return Get2PointsDistance(m_startPoint, m_endPoint);
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

std::string CLineSegment::ToString() const
{
	std::stringstream strm;
	strm << std::fixed << std::setprecision(1)
		<< "line start point "
		<< m_startPoint.ToString()
		<< ", "
		<< "end point "
		<< m_endPoint.ToString()
		<< ", "
		<< "color "
		<< GetOutlineColor();
	return strm.str();
}