#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(double side1, double side2, double side3)
{
	std::vector<double> sides = { side1, side2, side3 };
	std::sort(sides.begin(), sides.end());
	if (sides[0] < 0 ) //Have negative side
	{
		throw std::invalid_argument("Sides of the triangle can't have negative values");
	}
	if ((sides[2] == 0) || (sides[2] > sides[0] + sides[1])) // All sides have zero value or max side val more, than sum of two other
	{
		std::string error;
		error.append("Can't create triangle with sides ")
			.append(std::to_string(side1))
			.append(", ")
			.append(std::to_string(side2))
			.append(", ")
			.append(std::to_string(side3));
		throw std::domain_error(error);
	}

	if (sides[2] == (sides[0] + sides[1]))
	{
		m_isDegenerate = true;
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
	if (m_isDegenerate)
	{
		return 0;
	}
	double p = GetPerimeter() / 2;
	return sqrt(p * (p - m_side1) * (p - m_side2) * (p - m_side3));
}

double CTriangle::GetPerimeter() const
{
	return m_side1 + m_side2 + m_side3;
}

std::ostream & operator<<(std::ostream & out, CTriangle & triangle)
{
	out << "Triangle with sides " << std::to_string(triangle.GetSide1()) << " " 
		<< std::to_string(triangle.GetSide2()) << std::to_string(triangle.GetSide3()) << " "
		<< "have perimeter: " << std::to_string(triangle.GetPerimeter()) << " "
		<< "and area: " << std::to_string(triangle.GetArea());
	return out;
}