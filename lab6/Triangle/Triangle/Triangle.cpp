#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(double side1, double side2, double side3)
{
	if (!IsTriangle(side1, side2, side3))
	{
		throw std::invalid_argument("Sides of the triangle must have non negative values");
	}
	if ((side1 == 0) && (side2 == 0) && (side3 == 0))
	{
		throw std::domain_error("All sides of the triangle cann't have zero value at the same time");
	}
	m_side1 = side1;
	m_side2 = side2;
	m_side3 = side3;
}

CTriangle::~CTriangle()
{
}

double CTriangle::GetSide1() const
{
	return m_side1;
}

double CTriangle::GetSide2() const
{
	return m_side2;
}

double CTriangle::GetSide3() const
{
	return m_side3;
}

double CTriangle::GetArea() const
{
	double p = GetPerimeter() / 2;
	return sqrt(p * (p - m_side1) * (p - m_side2) * (p - m_side3));
}

double CTriangle::GetPerimeter() const
{
	return m_side1 + m_side2 + m_side3;
}

bool CTriangle::IsDegenerate() const
{
	return false;
}

bool IsTriangle(double side1, double side2, double side3)
{
	return (side1 >=0) && (side2 >= 0) && (side3 >= 0);
}
