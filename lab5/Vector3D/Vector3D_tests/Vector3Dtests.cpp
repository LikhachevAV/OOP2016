#include "stdafx.h"
#include "..\Vector3D\CVector3D.h"

using namespace std;

struct TwoVectors3DFixtureOne
{
	CVector3D vector1, vector2;
	double	x1 = 15.0, y1 = 2.5, z1 = -3.0,
			x2 = 2.0, y2 = 1.5, z2 = 1.0;
	TwoVectors3DFixtureOne()
	{
		vector1 = CVector3D(x1, y1, z1);
		vector2 = CVector3D(x2, y2, z2);
	}
};

BOOST_AUTO_TEST_SUITE(CVector3D_)

	BOOST_AUTO_TEST_CASE(init_Vector3D_with_default_values)
	{
		CVector3D vector1;
		BOOST_CHECK(vector1.x == 0.0);
		BOOST_CHECK(vector1.y == 0.0);
		BOOST_CHECK(vector1.z == 0.0);
	}

	BOOST_AUTO_TEST_CASE(init_Vector3D_with_parameters)
	{
		CVector3D vector1(15.0, 2.5, -3.0);
		BOOST_CHECK(vector1.x == 15.0);
		BOOST_CHECK(vector1.y == 2.5);
		BOOST_CHECK(vector1.z == -3.0);
	}

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(Operator_, TwoVectors3DFixtureOne)
	BOOST_AUTO_TEST_CASE(binary_plus_return_vector_with_sum_values_of_two_vectors)
	{
		CVector3D sumVector = vector1 + vector2;
		BOOST_CHECK_EQUAL(sumVector.x, (vector1.x + vector2.x));
		BOOST_CHECK_EQUAL(sumVector.y, (vector1.y + vector2.y));
		BOOST_CHECK_EQUAL(sumVector.z, (vector1.z + vector2.z));
	}

	BOOST_AUTO_TEST_CASE(unary_plus_return_self_vector)
	{
		CVector3D resultVector = +vector1;
		BOOST_CHECK_EQUAL(resultVector.x, vector1.x);
		BOOST_CHECK_EQUAL(resultVector.y, vector1.y);
		BOOST_CHECK_EQUAL(resultVector.z, vector1.z);
	}

	BOOST_AUTO_TEST_CASE(unary_minus_return_vector_multipied_on_minus_one)
	{
		CVector3D resultVector = -vector1;
		BOOST_CHECK_EQUAL(resultVector.x, vector1.x * -1);
		BOOST_CHECK_EQUAL(resultVector.y, vector1.y * -1);
		BOOST_CHECK_EQUAL(resultVector.z, vector1.z * -1);
	}

	BOOST_AUTO_TEST_CASE(binary_minus_return_vector_result_of_difference_between_two_vectors)
	{
		CVector3D resultVector = vector1 - vector2;
		BOOST_CHECK_EQUAL(resultVector.x, (vector1.x - vector2.x));
		BOOST_CHECK_EQUAL(resultVector.y, (vector1.y - vector2.y));
		BOOST_CHECK_EQUAL(resultVector.z, (vector1.z - vector2.z));
	}

	BOOST_AUTO_TEST_CASE(multiply_vector_on_scalar_multiply_vectors_fields_on_scalar_value)
	{
		auto scalar = 5;
		CVector3D resultVector = vector1 * scalar;
		BOOST_CHECK_EQUAL(resultVector.x, vector1.x * scalar);
		BOOST_CHECK_EQUAL(resultVector.y, vector1.y * scalar);
		BOOST_CHECK_EQUAL(resultVector.z, vector1.z * scalar);
	}

	BOOST_AUTO_TEST_CASE(multiply_scalar_on_vector_multiply_vectors_fields_on_scalar_value)
	{
		auto scalar = -3.2;
		CVector3D resultVector = scalar * vector1;
		BOOST_CHECK_EQUAL(resultVector.x, vector1.x * scalar);
		BOOST_CHECK_EQUAL(resultVector.y, vector1.y * scalar);
		BOOST_CHECK_EQUAL(resultVector.z, vector1.z * scalar);
	}

	BOOST_AUTO_TEST_CASE(plus_equals_operator_changes_fields_of_first_vector_result_will_be_sum_of_their_appropriate_fields)
	{
		vector1 += vector2;
		BOOST_CHECK_EQUAL(vector1.x, vector2.x + x1);
		BOOST_CHECK_EQUAL(vector1.y, vector2.y + y1);
		BOOST_CHECK_EQUAL(vector1.z, vector2.z + z1);
	}

	BOOST_AUTO_TEST_CASE(plus_equals_operator_changes_fields_of_first_vector_result_will_be_sum_of_their_appropriate_fields_)
	{
		vector2 += vector1;
		BOOST_CHECK_EQUAL(vector2.x, vector1.x + x2);
		BOOST_CHECK_EQUAL(vector2.y, vector1.y + y2);
		BOOST_CHECK_EQUAL(vector2.z, vector1.z + z2);
	}

	BOOST_AUTO_TEST_CASE(minus_equals_operator_changes_fields_of_first_vector_result_will_be_difference_of_their_appropriate_fields)
	{
		vector1 -= vector2;
		BOOST_CHECK_EQUAL(vector1.x, x1 - x2);
		BOOST_CHECK_EQUAL(vector1.y, y1 - y2);
		BOOST_CHECK_EQUAL(vector1.z, z1 - z2);
	}

	BOOST_AUTO_TEST_CASE(minus_equals_operator_changes_fields_of_first_vector_result_will_be_difference_of_their_appropriate_fields_)
	{
		vector2 -= vector1;
		BOOST_CHECK_EQUAL(vector2.x, x2 - x1);
		BOOST_CHECK_EQUAL(vector2.y, y2 - y1);
		BOOST_CHECK_EQUAL(vector2.z, z2 - z1);
	}

	BOOST_AUTO_TEST_CASE(division_on_scalar_operator_divide_vectors_fields_on_scalar_value)
	{
		auto scalar = 12;
		CVector3D result = vector1 / scalar;
		BOOST_CHECK_EQUAL(result.x, (x1 / scalar));
		BOOST_CHECK_EQUAL(result.y, (y1 / scalar));
		BOOST_CHECK_EQUAL(result.z, (z1 / scalar));
	}

	BOOST_AUTO_TEST_CASE(division_on_scalar_operator_throw_exception_by_divizion_zero)
	{
		auto scalar = 0;
		bool isThrowedException = false;
		std::string exceptionText = "Divizion by zero error!";
		try
		{
			CVector3D result = vector1 / scalar;
		}
		catch (invalid_argument& e)
		{
			isThrowedException = true;
			BOOST_CHECK_EQUAL(e.what(), exceptionText);
		}
		BOOST_CHECK(isThrowedException);
	}

	BOOST_AUTO_TEST_CASE(mutiply_equals_operator_multiply_vectors_fields_on_scalar)
	{
		auto scalar = 0.2;
		vector1 *= scalar;
		BOOST_CHECK_EQUAL(vector1.x, (x1 * scalar));
		BOOST_CHECK_EQUAL(vector1.y, (y1 * scalar));
		BOOST_CHECK_EQUAL(vector1.z, (z1 * scalar));
	}

	BOOST_AUTO_TEST_CASE(divizion_equals_operator_divide_vectors_fields_on_scalar)
	{
		auto scalar = 3.5;
		vector1 /= scalar;
		BOOST_CHECK_EQUAL(vector1.x, (x1 / scalar));
		BOOST_CHECK_EQUAL(vector1.y, (y1 / scalar));
		BOOST_CHECK_EQUAL(vector1.z, (z1 / scalar));
	}

	BOOST_AUTO_TEST_CASE(division_equal_on_scalar_operator_throw_exception_by_divizion_zero)
	{
		auto scalar = 0;
		bool isThrowedException = false;
		std::string exceptionText = "Divizion by zero error!";
		try
		{
			vector1 /= scalar;
		}
		catch (invalid_argument& e)
		{
			isThrowedException = true;
			BOOST_CHECK_EQUAL(e.what(), exceptionText);
		}
		BOOST_CHECK(isThrowedException);
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(operator_double_equal, TwoVectors3DFixtureOne)
	BOOST_AUTO_TEST_CASE(return_true_when_all_fields_of_both_vectors_are_equal)
	{
		CVector3D vector3(vector1);
		BOOST_CHECK(vector3 == vector1);
		BOOST_CHECK(vector3.x == vector1.x);
		BOOST_CHECK(vector3.y == vector1.y);
		BOOST_CHECK(vector3.z == vector1.z);
	}

	BOOST_AUTO_TEST_CASE(return_false_when_not_all_fields_of_both_vectors_are_equal)
	{
		CVector3D vector3(vector1);
		vector3.x++;
		BOOST_CHECK(!(vector3 == vector1));
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(operator_not_equal, TwoVectors3DFixtureOne)
	BOOST_AUTO_TEST_CASE(return_true_when_not_all_fields_of_both_vectors_are_equal)
	{
		BOOST_CHECK(vector2 != vector1);
		BOOST_CHECK(vector1.x != vector2.x || vector1.y != vector2.y || vector1.z != vector2.z);
	}

	BOOST_AUTO_TEST_CASE(return_false_when_all_fields_of_both_vectors_are_equal)
	{
		CVector3D vector3(vector1);
		vector3.x++;
		BOOST_CHECK(vector3 != vector1);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(GetLength_function_return_length_of_vector)
{
	CVector3D v1(3, 0, 0);
	BOOST_CHECK_EQUAL(v1.GetLength(), 3);
}

BOOST_AUTO_TEST_CASE(GetLength_function_return_length_of_vector1)
{
	CVector3D v1(2, -2, 0);
	BOOST_CHECK_EQUAL(v1.GetLength(), sqrt(8));
}