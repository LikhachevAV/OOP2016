#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(CPoint const &leftTop, CPoint const & rightBottom,
	std::string const &outlineColor, std::string const &fillColor):
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
	std::stringstream strm;
	strm << std::fixed << std::setprecision(1)
		<< "rectangle with area: " << GetArea() << ", "
		<< "perimeter: " << GetPerimeter() << ", "
		<< "outline color: "
		<< GetOutlineColor() << " and "
		<< "fill color: "
		<< GetFillColor();
	return strm.str();
}

double CRectangle::GetArea() const
{
	return GetHeight() * GetWidth();
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

std::istream & operator >> (std::istream & is, CRectangle & rectangle)
{
	CPoint leftTop;
	CPoint rightBottom;
	std::string outLineColor;
	std::string fillClolor;
	if (!(is >> leftTop >> rightBottom >> outLineColor >> fillClolor))
	{
		throw std::exception("Triangle from istream reading exceprtion");
	}
	CRectangle resultRectangle(leftTop, rightBottom, outLineColor, fillClolor);
	rectangle = resultRectangle;
	return is;
}