#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(CPoint leftTop, CPoint rightBottom, std::string outlineColor, std::string fillColor):
	m_leftTop(leftTop),
	m_rightBottom(rightBottom),
	CSolidShape(outlineColor, fillColor)
{
}

CRectangle::~CRectangle()
{
}

std::string CRectangle::ToString() const
{
	return std::string();
}

double CRectangle::GetArea() const
{
	return 0.0;
}

double CRectangle::GetPerimeter() const
{
	return 2 * (GetHeight() + GetWidth());
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

double CRectangle::GetHeight() const
{
	return abs(m_leftTop.y - m_rightBottom.y);
}

double CRectangle::GetWidth() const
{
	return abs(m_rightBottom.x - m_leftTop.x);
}
