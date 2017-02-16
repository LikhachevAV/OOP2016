#include "stdafx.h"
#include "Triangle.h"

CTriangle::CTriangle(double side1, double side2, double side3)
{
	std::vector<double> sides = { side1, side2, side3 };
	std::sort(sides.begin(), sides.end());
	if (sides[0] < 0 ) //Имеются стороны с отрицательным значением
	{
		throw std::invalid_argument("Sides of the triangle can't have negative values");
	}
	if ((sides[2] == 0) || (sides[2] > sides[0] + sides[1])) // Все стороны равны 0 или одна сторна длинне суммы двух других
	{
		std::string error;
		error.append("Сan't create triangle with sides ")
			.append(std::to_string(side1))
			.append(", ")
			.append(std::to_string(side2))
			.append(", ")
			.append(std::to_string(side3));
		throw std::invalid_argument(error);
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

bool IsTriangle(double side1, double side2, double side3)
{
	return (side1 >=0) && (side2 >= 0) && (side3 >= 0);
}
