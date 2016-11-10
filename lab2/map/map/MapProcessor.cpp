#include "stdafx.h"
#include "MapProcessor.h"
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;

void AddWordToMap(map<string, int> & wordsMap, const string & word)
{
	if (word.size() > 1)
	{
		++wordsMap[word];
	}
}

void PrintWordsMap(ostream & out, map<string, int> const & wordsMap)
{
	for (auto & it : wordsMap)
	{
		out << it.first << " -> " << it.second << endl;
	}
}