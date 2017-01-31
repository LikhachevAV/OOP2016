#pragma once
#include "IShape.h"
#include "Point.h"

class CShape : public IShape
{
public:
	CShape(std::string const& outlineColor);
	virtual ~CShape();
	std::string ToString() const override = 0;
	std::string GetOutlineColor() const override;

private:
	std::string m_outlineColor;
};

double Get2PointsDistance(CPoint const& a, CPoint const& b);