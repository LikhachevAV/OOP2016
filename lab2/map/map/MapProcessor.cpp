#include "stdafx.h"
#include "MapProcessor.h"
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;

void AddWord(map<string, int>& words, const string & word)
{
	++words[word];
}

