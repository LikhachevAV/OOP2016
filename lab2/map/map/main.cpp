#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "MapProcessor.h"
#include <iterator>

using namespace std;

int ReadWordFromSteam(istream & is, string & word)
{
	char ch;
	while ((is.get(ch)) && ch != '\n' && ch != '\t' && ch != ' ' && !is.eof())
	{
		word.push_back(ch);
	}
	if (word.size() < 1)
	{
		return 1;
	}
	return 0;
}


int main()
{
	map<string, int> wordsCounterMap;
	string s;
	cout << "Enter input words to count them: \n";
	while (!cin.eof())
	{
		s = "";
		if (!ReadWordFromSteam(cin, s))
		{
			cout << "Input data reading error";
			return 1;
		}
		AddWordToMap(wordsCounterMap, s);
	}
	PrintWordsMap(cout, wordsCounterMap);
	return 0;
}