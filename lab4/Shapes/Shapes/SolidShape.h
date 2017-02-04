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
	
	virtual std::string GetFillColor() const final override;
	virtual std::string GetOutlineColor() const final;
	virtual ~CSolidShape();

private:
	std::string m_fillColor;
};