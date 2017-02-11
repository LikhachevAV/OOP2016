#include "stdafx.h"
#include "Student.h"


CStudent::CStudent(std::string const & surname, std::string const & name,
	std::string const & patronymic, int age)
{		
	if ((name.length() > 0) && (name.compare(" ") != 0) && 
		(surname.length() > 0) && (surname.compare(" ") != 0))
	{
		m_name = name;
		m_surname = surname;
	}
	else
	{
		throw std::invalid_argument("Names and surnames values must be non empty and non space value");
	}

	if ((name.length() > 0) && (patronymic.compare(" ") == 0))
	{
		throw std::invalid_argument("Patronymic value must non space value");
	}
	else
	{
		m_patronymic = patronymic;
	}

	if (age < 14 || age > 60)
	{
		throw std::out_of_range("Age value must be between 14 and 60");
	}
	else
	{
		m_age = age;
	}
}


CStudent::~CStudent()
{
}

std::string CStudent::GetName()
{
	return m_name;
}

std::string CStudent::GetSurname()
{
	return m_surname;
}

std::string CStudent::GetPatronymic()
{
	return m_patronymic;
}

int CStudent::GetAge()
{
	return m_age;
}

void CStudent::SetAge(int age)
{
	if (age < 14 || age > 60)
	{
		throw std::out_of_range("Age value must be between 14 and 60");
	}
	if (age <= m_age)
	{
		throw std::domain_error("New age must be more, than current");
	}
	else
	{
		m_age = age;
	}
}

void CStudent::Rename(std::string const & name, std::string const & surname, std::string const & patronymic)
{
	if ((name.length() > 0) && (name.compare(" ") != 0) &&
		(surname.length() > 0) && (surname.compare(" ") != 0))
	{
		m_name = name;
		m_surname = surname;
	}
	else
	{
		throw std::invalid_argument("Names and surnames values must be non empty and non space value");
	}

	if ((name.length() > 0) && (patronymic.compare(" ") == 0))
	{
		throw std::invalid_argument("Patronymic value must non space value");
	}
	else
	{
		m_patronymic = patronymic;
	}
}
