#include "stdafx.h"
#include "CPoint.h"

using namespace std;

CPoint::CPoint(double x0, double y0):
	x(x0),
	y(y0)
{
}

string CPoint::ToString()
{
	string pointStr;
	pointStr.append("point [")
		.append(to_string(x))
		.append(", ")
		.append(to_string(y))
		.append(']');
	return pointStr;
}
