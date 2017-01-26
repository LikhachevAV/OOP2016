#include "stdafx.h"
#include "SolidShape.h"

CSolidShape::CSolidShape(const std::string & outlineColor, const std::string & fillColor) :
	CShape(outlineColor),
	m_fillColor(fillColor)
{
}

std::string CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

CSolidShape::~CSolidShape()
{
}
