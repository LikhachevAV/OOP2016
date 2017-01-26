#pragma once
#include "IShape.h"
#include "CPoint.h"
class CShape : public IShape
{
public:
	CShape(std::string const& outlineColor);
	virtual ~CShape();
	double GetArea() const override = 0;
	double GetPerimeter() const override = 0;
	std::string ToString() const override = 0;
	std::string GetOutlineColor() const override;

private:
	std::string m_color;
};

double GetDistance(CPoint const & a, CPoint const & b);