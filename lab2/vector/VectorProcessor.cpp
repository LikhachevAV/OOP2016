﻿#include "stdafx.h"
#include "VectorProcessor.h"
#include <algorithm>
#include <numeric>
#include <functional>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;
using namespace std::placeholders;
using namespace boost::phoenix::placeholders;
using namespace boost::phoenix;
using boost::transform;

double MinValOfVector(std::vector<double> & numbers)
{
	vector<double> & copy(numbers);
	SortVector(copy);
	return copy[0];
}

void SortVector(std::vector<double> & numbers)
{
	sort(numbers.begin(), numbers.end());
}

void ProcessVector(std::vector<double> & numbers)
{
	auto IsPositive = [](double number){return number > 0; };

	size_t numberOfPositives = 0;

	// функция, суммирующая только положительные числа с подсчетом их количества
	auto addIfPositive = [&numberOfPositives](double acc, double current) {
		if (current > 0.0)
		{
			++numberOfPositives;
			return acc + current;
		}
		return acc;
	};

	auto sumOfPositives = accumulate(numbers.begin(), numbers.end(), 0.0, addIfPositive);

	double avg = (numberOfPositives > 0) ? sumOfPositives / numberOfPositives : 0.0;

	boost::transform(numbers, numbers.begin(), arg1 + avg);
}