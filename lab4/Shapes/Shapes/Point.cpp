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

CPoint FromString(std::string const &inStr)
{	
	std::stringstream strm(inStr);
	char ch = '#';
	double x;
	double y;
	auto throwException = [] () {
		throw std::exception("Point format reading exception");
	};
	if (!strm.get(ch) || (ch != '('))
	{
		throwException();
	}
	if (!(strm >> x))
	{
		throwException();
	}
	if (!strm.get(ch) || (ch != ','))
	{
		throwException();
	}
	if (!(strm >> y))
	{
		throwException();
	}
	if (!strm.get(ch) || (ch != ')'))
	{
		throwException();
	}
	return CPoint(x, y);
}

std::istream &operator>> (std::istream &is, CPoint & point)
{
	char ch = ' ';
	auto throwException = []() {
		throw std::exception("Point format reading exception");
	};
	if (is.get(ch) && ch == ' ')
	{
		is.get(ch);
	} else
	if (ch != '(')
	{
		throwException();
	}
	if (!(is >> point.x) || !(is.get(ch) || ch != ','))
	{
		throwException();
	}
	if (!(is >> point.y) || !(is.get(ch) || ch != ')'))
	{
		throwException();
	}
	return is;
}