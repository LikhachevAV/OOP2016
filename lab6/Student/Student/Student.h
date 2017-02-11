#pragma once

class CStudent
{
public:
	CStudent(std::string const & name,  std::string const & surname,
		std::string const & patronymic, int age);
	~CStudent();

	std::string GetName();
	std::string GetSurname();
	std::string GetPatronymic();
	int GetAge();
	void SetAge(int age);
	void Rename(std::string const & name, std::string const & surname,
		std::string const & patronymic);

private:
	std::string m_name;
	std::string m_surname;
	std::string m_patronymic;
	int m_age = 14;
};

