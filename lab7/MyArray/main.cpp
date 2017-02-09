#include "stdafx.h"
#include "MyArray.h"
#include <iostream>

using namespace std;

void main(void)
{
	CMyArray<string> array;
	array.Append("Vasya");
	array.Append("say");
	array.Append("Hello");
	cout << "Print array, using begin, end iterators: " << endl;
	for (auto it = array.begin(); it != array.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}