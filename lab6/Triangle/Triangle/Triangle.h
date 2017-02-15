#pragma once

class CTriangle
{
public:
	CTriangle(double side1, double side2, double side3);
	~CTriangle();
	double GetSide1() const;
	double GetSide2() const;
	double GetSide3() const;
	double GetArea() const;
	double GetPerimeter() const;

private:
	double m_side1 = 0;
	double m_side2 = 0;
	double m_side3 = 0;
	bool IsDegenerate() const;
};

bool IsTriangle(double side1, double side2, double side3);