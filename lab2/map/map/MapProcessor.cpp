#include "stdafx.h"
#include "MapProcessor.h"
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;

void AddWord(map<string, int> & words, const string & word)
{
	++words[word];
}

void PrintWords(ostream & out, map<string, int> const & words)
{
	
	for (auto & it : words)
	{
		out << it.first << " -> " << it.second << endl;
	}
}