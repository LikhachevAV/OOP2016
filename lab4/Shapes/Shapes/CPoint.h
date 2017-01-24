#include "stdafx.h"

class CPoint
{
public:
	double x = 0;
	double y = 0;

	CPoint(double x0, double y0);

	CPoint() = default;

	std::string ToString();
};
