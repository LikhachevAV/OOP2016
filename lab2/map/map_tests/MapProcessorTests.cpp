#include "stdafx.h"
#include "..\map\MapProcessor.h"
#include <iostream>

using namespace std;

typedef map <string, int> WordType;

bool MapsAreEqual(WordType x, WordType y)
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

BOOST_AUTO_TEST_CASE(add_word_test)
{
	WordType myMap;
	AddWord(myMap, string("s"));
	AddWord(myMap, string("s"));

	WordType myMap1;
	
	BOOST_CHECK_EQUAL(myMap["s"], 2);
	BOOST_CHECK(MapsAreEqual(myMap, myMap));

	cout << myMap[string("s")] << endl;
	//BOOST_CHECK(emptyVector.empty());
}

BOOST_AUTO_TEST_SUITE_END()
