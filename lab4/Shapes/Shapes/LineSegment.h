#pragma once
#include "Point.h"
#include "Shape.h"

class CLineSegment : public CShape
{
public:
	CLineSegment(CPoint const & startPoint, CPoint const & endPoint, std::string const & outlineColor);
	~CLineSegment();
	double GetPerimeter() const override;
	std::string ToString() const override;
	double GetArea() const override;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
};