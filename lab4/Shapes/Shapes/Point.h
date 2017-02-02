#pragma once
#include "stdafx.h"

class CPoint
{
public:
	double x = 0;
	double y = 0;

	CPoint(double x0, double y0);

	CPoint() = default;

	std::string ToString() const;
};

bool operator== (CPoint const &l, CPoint const &r);

bool operator!= (CPoint const &l, CPoint const &r);

CPoint FromString(std::string const &inStr);