#include "stdafx.h"
#include "../Student/Student.h"

using namespace std;

string name("ivan");
string surname("ivanov");
string patronymic("ivanovich");
int age = 14;

BOOST_AUTO_TEST_SUITE(Constructor_can_not_create_student)
	BOOST_AUTO_TEST_CASE(with_blank_name)
	{	
		BOOST_CHECK_THROW(CStudent student("", name, patronymic, 14), invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(with_space_at_name)
	{
		BOOST_CHECK_THROW(CStudent student(" ", name, patronymic, 14), invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(with_blank_surname)
	{
		BOOST_CHECK_THROW(CStudent student(name, "", patronymic, 14), invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(with_space_at_surname)
	{
		BOOST_CHECK_THROW(CStudent student(name, " ", patronymic, 14), invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(with_space_at_patronymic)
	{
		BOOST_CHECK_THROW(CStudent student(name, surname, " ", 14), invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(with_age_less_than_14)
	{
		BOOST_CHECK_THROW(CStudent student(name, surname, patronymic, 13), out_of_range);
	}

	BOOST_AUTO_TEST_CASE(with_age_more_than_60)
	{
		BOOST_CHECK_THROW(CStudent student(name, surname, patronymic, 61), out_of_range);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(can_create_student)
	BOOST_AUTO_TEST_CASE(with_empty_name_surname_patronymic_values_and_14_age)
	{
		CStudent student(surname, name, "", 14);
		BOOST_CHECK_EQUAL(student.GetName(), name);
		BOOST_CHECK_EQUAL(student.GetSurname(), surname);
		BOOST_CHECK_EQUAL(student.GetPatronymic(), "");
		BOOST_CHECK_EQUAL(student.GetAge(), 14);
	}

	BOOST_AUTO_TEST_CASE(when_its_age_equal_60)
	{
		CStudent student(surname, name, patronymic, 60);
		BOOST_CHECK_EQUAL(student.GetName(), name);
		BOOST_CHECK_EQUAL(student.GetSurname(), surname);
		BOOST_CHECK_EQUAL(student.GetPatronymic(), patronymic);
		BOOST_CHECK_EQUAL(student.GetAge(), 60);
	}
BOOST_AUTO_TEST_SUITE_END()