#pragma once
#include "IShape.h"

class ISolidShape :	public virtual IShape
{
public:
	virtual ~ISolidShape();
	virtual std::string GetFillColor() const = 0;
};
