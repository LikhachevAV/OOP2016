#include "stdafx.h"
#include "..\map\MapProcessor.h"
#include <iostream>
#include "MapProcessorTests.h"

using namespace std;

bool MapsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

BOOST_AUTO_TEST_CASE(dont_change_empty_vector)
{
	map<string, int> myMap;
	myMap["s"] = 1;
	++myMap["s"];
	cout << myMap["s"] << endl;
	//BOOST_CHECK(emptyVector.empty());
}

BOOST_AUTO_TEST_SUITE_END()
