#include "stdafx.h"
#include "IShape.h"
#include "Circle.h"

void DoSomething(const IShape & shape)
{
	(void)&shape;
}

int main1()
{
	CCircle circle({ 100, 100 }, 100, "red", "green");
	DoSomething(circle);
	return 0;
}