#pragma once
#include "SolidShape.h"
class CRectangle :
	public CSolidShape
{
public:
	CRectangle(CPoint leftTop, CPoint rightBottom,
		std::string outlineColor, std::string fillColor);
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

