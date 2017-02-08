#include <iostream>

class Vasya
{
public:
	Vasya()
	{
		std::cout << "Vasya, say hello!\n";
	}
	//virtual ~Vasya() //destructor must be virtual
	~Vasya()
	{
		std::cout << "Vasya, say goodbye!\n";
	}
};

class VasyasSon : public Vasya
{
public:
	VasyasSon()
	{
		std::cout << "\tVasyas son, say hello!\n";
	}

	~VasyasSon()
	{
		std::cout << "\tVasyas son, say goodbye!\n";
	}
};

void main()
{
	Vasya *s1 = new VasyasSon();
	delete s1;
}