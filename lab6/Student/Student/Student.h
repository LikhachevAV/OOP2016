#pragma once

class CStudent
{
public:
	CStudent(std::string const & surname,  std::string const & name,
		std::string const & patronymic, int age);
	~CStudent();

	std::string GetName();
	std::string GetSurname();
	std::string GetPatronymic();
	int GetAge();

private:
	std::string m_name;
	std::string m_surname;
	std::string m_patronymic;
	int m_age = 14;
};

