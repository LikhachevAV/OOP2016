#include "stdafx.h"
#include "..\map\MapProcessor.h"
//#include <iostream>

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

BOOST_AUTO_TEST_CASE(add_word)
{
	WordType myMap;
	AddWordToMap(myMap, string("s"));
	AddWordToMap(myMap, string("s"));

	WordType myMap1;
	
	BOOST_CHECK_EQUAL(myMap["s"], 2);
	BOOST_CHECK(MapsAreEqual(myMap, myMap));

	cout << myMap[string("s")] << endl;
}

BOOST_AUTO_TEST_CASE(print_word)
{
	WordType myMap;
	AddWordToMap(myMap, string("s"));
	AddWordToMap(myMap, string("m"));
	AddWordToMap(myMap, string("m"));
	PrintWordsMap(cout, myMap);
}

BOOST_AUTO_TEST_SUITE_END()
