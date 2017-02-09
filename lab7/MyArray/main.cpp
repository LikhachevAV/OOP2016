#include "stdafx.h"
#include "MyArray.h"
#include <iostream>

using namespace std;

void main(void)
{
	CMyArray<string> stringArray;
	stringArray.Append("Vasya");
	stringArray.Append("say");
	stringArray.Append("Hello");
	stringArray.Append("!");

	cout << "Print string array, using begin, end iterators: " << endl;
	for (auto it = stringArray.begin(); it != stringArray.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << endl;

	cout << "Print reverse string array, using rbegin, rend iterators: " << endl;
	for (auto it = stringArray.rbegin(); it != stringArray.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << endl;

	CMyArray<double> doubleArray;
	for (double d = 2.2; d < 10; d += 1.1)
	{
		doubleArray.Append(d);
	}

	cout << std::fixed << std::setprecision(1) <<"Print double array, using begin, end iterators: " << endl;
	for (auto it = doubleArray.begin(); it != doubleArray.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << endl;

	cout << "Print reverse double array, using rbegin, rend iterators: " << endl;
	for (auto it = doubleArray.rbegin(); it != doubleArray.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << endl;
}