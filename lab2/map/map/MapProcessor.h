#pragma once
#include <map>
#include <iostream>

void AddWordToMap(std::map<std::string, int> & words, const std::string & word);
void PrintWordsMap(std::ostream & out, const std::map<std::string, int> & wordsMap);