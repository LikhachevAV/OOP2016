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
	stringstream strm;
	strm << fixed << setprecision(1)
		<< "(" << x << ", " << y << ")";
	return strm.str();
}
