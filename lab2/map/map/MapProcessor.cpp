#include "stdafx.h"
#include "MapProcessor.h"
#pragma warning (disable:4503)
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;

void AddWordToMap(map<string, int> & wordsMap, string const & word)
{
	if (word.length() > 1)
	{
		string s;
		for (std::string::size_type i = 0; i < word.length(); ++i)
		{
			s.push_back(tolower(word[i]));
		}
		++wordsMap[s];
	}
}

void PrintWordsMap(ostream & out, map<string, int> const & wordsMap)
{
	for (auto & it : wordsMap)
	{
		out << it.first << " -> " << it.second << endl;
	}
}