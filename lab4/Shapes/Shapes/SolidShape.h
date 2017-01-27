#pragma once
#include "Shape.h"
#include "ISolidShape.h"

class CSolidShape : public CShape, public ISolidShape
{
public:
	CSolidShape(
		const std::string & outlineColor,
		const std::string & fillColor
	);
	double GetArea() const override = 0;
	double GetPerimeter() const override = 0;
	std::string GetFillColor() const final override;
	std::string GetOutlineColor() const final;
	virtual ~CSolidShape();

private:
	std::string m_fillColor;
};