#pragma once
#include <map>
#include <iostream>

void AddWord(std::map<std::string, int> & words, const std::string & word);
void PrintWords(std::ostream & out, const std::map<std::string, int> & words);