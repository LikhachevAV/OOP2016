#include "stdafx.h"
#include "CPoint.h"

CPoint::CPoint(double x0, double y0):
	x(x0),
	y(y0)
{
}

std::string CPoint::ToString() const
{
	std::stringstream strm;
	strm << std::fixed << std::setprecision(1)
		<< "(" << x << ", " << y << ")";
	return strm.str();
}
