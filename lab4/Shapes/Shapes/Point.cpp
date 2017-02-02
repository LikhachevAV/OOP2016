#include "stdafx.h"
#include "Point.h"

CPoint::CPoint(double x0, double y0) :
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

bool operator== (CPoint const &l, CPoint const &r)
{
	return ((l.x == r.x) && (l.y == r.y));
}

bool operator!= (CPoint const &l, CPoint const &r)
{
	return ((l.x != r.x) || (l.y != r.y));
}

std::istream &operator>> (std::istream &is, CPoint & point)
{
	char ch = ' ';
	double x;
	double y;
	auto throwException = []() {
		throw std::exception("Point format reading exception");
	};
	auto protectedReadCh = [&]() {
		if (!is.eof())
		{
			is.get(ch);
		}
		else 
		{
			throwException();
		}
	};
	protectedReadCh();
	if (ch == ' ')
	{
		protectedReadCh();
	} else
	if (ch != '(')
	{
		throwException();
	}
	if (!(is >> x))
	{
		throwException();
	}
	protectedReadCh();
	if (ch != ',')
	{
		throwException();
	}
	if (!(is >> y))
	{
		throwException();
	}
	protectedReadCh();
	if (ch != ')')
	{
		throwException();
	}
	CPoint resultPoint(x, y);
	point = resultPoint;
	return is;
}