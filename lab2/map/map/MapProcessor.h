#pragma once
#include <map>

double GetVectorsMinVal(std::vector<double> & numbers);
void SortVector(std::vector<double> & numbers);
void ProcessVector(std::vector<double> & numbers);
void AddWord(std::map<std::string, int> & words, const std::string & word);