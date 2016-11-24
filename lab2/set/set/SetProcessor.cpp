#include "stdafx.h"
#include "SetProcessor.h"
#include <algorithm>
#include <numeric>
#include <functional>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;

set<int>CrossSet(set<int>const&set1, set<int>const&set2)
{
	set<int> crossSet;
	return crossSet;
}

void PrintSet(std::set<int>const&set)
{
	for ( auto it = set.begin(); it != set.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}