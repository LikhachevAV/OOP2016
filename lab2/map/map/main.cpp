#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "MapProcessor.h"
#include <iterator>

using namespace std;

void ReadWordFromSteam(istream & is, string & word)
{
	char ch;
	while ((is.get(ch)) && (ch != '\n') && (ch != '\t') && (ch != ' '))
	{	
		word.push_back(ch);
	}
}


int main()
{
	map<string, int> wordsCounterMap;
	string s;
	cout << "Enter input words to count them: \n";
	while (!cin.eof())
	{
		s = "";
		ReadWordFromSteam(cin, s);
		AddWordToMap(wordsCounterMap, s);
	}
	PrintWordsMap(cout, wordsCounterMap);
	return 0;
}