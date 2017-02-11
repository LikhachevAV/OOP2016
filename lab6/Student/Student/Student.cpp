#include "stdafx.h"
#include "Student.h"

CStudent::CStudent(std::string const & surname, std::string const & name,
	std::string const & patronymic, int age)
{		
	if ((name.length() == 0) || (StringContainOnlySpaces(name)) || 
		(surname.length() == 0) || (StringContainOnlySpaces(surname)))
	{
		throw std::invalid_argument("Names and surnames values must be non empty and non space value");
	}

	if ((patronymic.length() > 0) && (StringContainOnlySpaces(patronymic)))
	{
		throw std::invalid_argument("Patronymic value must non space value");
	}

	if (age < MIN_AGE || age > MAX_AGE)
	{
		throw std::out_of_range("Age value must be between" + std::to_string(MIN_AGE)
			+ "and" + std::to_string(MAX_AGE));
	}
	try
	{
		m_name = name;
		m_surname = surname;
		m_patronymic = patronymic;
		m_age = age;
	}
	catch (std::exception)
	{
		throw;
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
	if (age < MIN_AGE || age > MAX_AGE)
	{
		throw std::out_of_range("Age value must be between " +
			std::to_string(MIN_AGE) + " and " +  std::to_string(MAX_AGE));
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
	if ((name.length() == 0) || (StringContainOnlySpaces(name)) ||
		(surname.length() == 0) || (StringContainOnlySpaces(surname)))
	{
		throw std::invalid_argument("Names and surnames values must be non empty and non space value");
	}

	if ((patronymic.length() > 0) && (StringContainOnlySpaces(patronymic)))
	{
		throw std::invalid_argument("Patronymic value must non space value");
	}
	try
	{
		m_name = name;
		m_surname = surname;
		m_patronymic = patronymic;
	}
	catch (std::exception)
	{
		throw;
	}
}

bool StringContainOnlySpaces(std::string const & s)
{
	for (int i = 0; i < (int)s.length(); ++i)
	{
		if (s[i] != ' ')
		{
			return false;
		}
	}
	return true;
}
