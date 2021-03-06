#pragma once
#include "SolidShape.h"

class CTriangle :
	public CSolidShape
{
public:
	CTriangle(CPoint const &a, CPoint const &b, CPoint const &c,
		std::string const &outlineColor,
		std::string const &fillColor);
	~CTriangle();
	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
	CPoint GetVertexA() const;
	CPoint GetVertexB() const;
	CPoint GetVertexC() const;
	bool Equals(CTriangle const &triangle) const;

private:
	CPoint m_a;
	CPoint m_b;
	CPoint m_c;

	double GetAbLength() const;
	double GetBcLength() const;
	double GetCaLength() const;
};

std::istream & operator >> (std::istream & is, CTriangle & triangle);