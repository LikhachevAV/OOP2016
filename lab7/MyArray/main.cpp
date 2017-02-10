#include "stdafx.h"
#include "MyArray.h"
#include <iostream>

using namespace std;
template <typename T>
void PrintCMyArray(CMyArray<T> & arr, bool forward)
{
	iterator
	if (forward)
	{
		string msg = string("Print array, using begin, end iterators:");
		auto it1 = arr.begin();
		auto it2 = arr.end();
	}
	else
	{
		string msg = string("Print array rewerse, using rbegin, rend iterators:");
		auto it1 = arr.rbegin();
		auto it2 = arr.rend();
	}
	auto printArray = [&](auto it1, auto it2) {
		cout << msg << endl;
		for (auto it = it1; it != it2; it++)
		{
			cout << *it << " ";
		}
		cout << endl << endl;
	};
	printArray(msg, it1, it2);
}

int main()
{
	CMyArray<string> stringArray;
	stringArray.Append("Vasya");
	stringArray.Append("say");
	stringArray.Append("Hello");
	stringArray.Append("!");

	/*auto printArrInLoop = [&](string & msg, CMyArray<T> * arr0) {
		for (auto it = arr0->begin(); it != arr0->end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl << endl;
	};
*/
	/*
	cout << "Print string array, using begin, end iterators: " << endl;
	for (auto it = stringArray.begin(); it != stringArray.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << endl;
	*/

	PrintCMyArray(stringArray, true);
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
	return 0;
}