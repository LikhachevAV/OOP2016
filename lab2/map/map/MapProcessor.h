#pragma once
#include <map>
#include <iostream>

void AddWordToMap(std::map<std::string, int> & words, std::string const & word);
void PrintWordsMap(std::ostream & out, const std::map<std::string, int> & wordsMap);