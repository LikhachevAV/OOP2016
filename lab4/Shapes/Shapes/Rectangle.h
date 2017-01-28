#pragma once
#include "SolidShape.h"
class CRectangle :
	public CSolidShape
{
public:
	CRectangle(CPoint const &leftTop, CPoint const & rightBottom,
		std::string const &outlineColor, std::string const &fillColor);
	~CRectangle();
	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetHeight() const;
	double GetWidth() const;

private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
};

