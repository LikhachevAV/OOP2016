#include "stdafx.h"
#include "..\map\MapProcessor.h"
#include <iostream>

using namespace std;

bool MapsAreEqual(const map<string, int> & x, const map<string, int> & y)
{
	return x == y;
}

BOOST_AUTO_TEST_SUITE(AddWordToMap_function)

	BOOST_AUTO_TEST_CASE(dont_add_empty_string)
	{
		map<string, int> myMap;
		string s;
		AddWordToMap(myMap, s);
		BOOST_CHECK(myMap.empty());
	}

	BOOST_AUTO_TEST_CASE(add_non_empty_words_and_count_them)
	{
		map<string, int> myMap;
		AddWordToMap(myMap, "hello");
		AddWordToMap(myMap, "world");
		AddWordToMap(myMap, "hello");
		map<string, int> expectedMap = {{"hello",2},{"world",1}};
		BOOST_CHECK(MapsAreEqual(myMap, expectedMap));
	}

	BOOST_AUTO_TEST_CASE(must_be_non_case_senisitiv)
	{
		map<string, int> myMap;
		AddWordToMap(myMap, "hello");
		AddWordToMap(myMap, "world");
		AddWordToMap(myMap, "Hello");
		AddWordToMap(myMap, "WoRlD");
		map<string, int> expectedMap = { { "hello",2 },{ "world",2 } };
		BOOST_CHECK(MapsAreEqual(myMap, expectedMap));
	}

BOOST_AUTO_TEST_SUITE_END()
