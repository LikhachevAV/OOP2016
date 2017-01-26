#pragma once
#include "CPoint.h"
#include "Shape.h"

class CLineSegment : public CShape
{
public:
	CLineSegment(CPoint const & startPoint, CPoint const & endPoint, std::string const & outlineColor);
	double GetArea() const override = 0;
	double GetPerimeter() const override;
	std::string ToString() const override;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};