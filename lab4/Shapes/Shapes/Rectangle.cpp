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
	return 0.0;
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
	return 0.0;
}

double CRectangle::GetWidth() const
{
	return 0.0;
}
