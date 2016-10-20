#include "stdafx.h"
#include "..\vector\VectorProcessor.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

	// Создает пустой вектор из пустого вектора
	BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
	{
		vector<double> emptyVector;
		ProcessVector(emptyVector);
		BOOST_CHECK(emptyVector.empty());
	}

	BOOST_AUTO_TEST_CASE(sorting_vector_test)
	{
		vector<double> myVector = {0.0, 1.0, -1.0};
		vector<double> expectedVector = { -1.0, 0.0, 1.0 };
		SortVector(myVector);
		BOOST_CHECK(VectorsAreEqual(myVector, expectedVector));
	}

	BOOST_AUTO_TEST_CASE(vector_min_val_test)
	{
		vector<double> myVector = { 0.0, 1.0, -1.0 };
		double expectedMinVal = -1.0;
		double minVal = GetVectorsMinVal(myVector);
		BOOST_CHECK_EQUAL(minVal, expectedMinVal);
	}

	BOOST_AUTO_TEST_CASE(multiplied_vector_test)
	{
		vector<double> myVector = { 0.0, 1.0, -1.0 };
		vector<double> expectedVector = { -1.0, 0.0, 1.0 };
		ProcessVector(myVector);
		BOOST_CHECK(VectorsAreEqual(myVector, expectedVector));
	}

	BOOST_AUTO_TEST_CASE(multiplied_vector_test_2)
	{
		vector<double> myVector = { 0.0, 1.0, -5.0 };
		vector<double> expectedVector = { -5.0, 0.0, 25.0 };
		ProcessVector(myVector);
		BOOST_CHECK(VectorsAreEqual(myVector, expectedVector));
	}

	BOOST_AUTO_TEST_CASE(vector_with_one_negative_number_test)
	{
		vector<double> myVector = { -7.0 };
		vector<double> expectedVector = {49.0};
		ProcessVector(myVector);
		BOOST_CHECK(VectorsAreEqual(myVector, expectedVector));
	}

BOOST_AUTO_TEST_SUITE_END()
