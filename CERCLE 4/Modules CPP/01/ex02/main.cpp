#include <iostream>

int main( void )
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	pStr = &str;
	std::string&	rStr = str;

	std::cout << "Memory address of string variable ->\t" << &str << std::endl;
	std::cout << "Memory address of string pointer ->\t" << &pStr << std::endl;
	std::cout << "Memory address of string ref ->\t\t" << &rStr << std::endl << std::endl;
	std::cout << "Value of string variable ->\t\t" << str << std::endl;
	std::cout << "Value pointed by pointer ->\t\t" << *pStr << std::endl;
	std::cout << "Value pointed by ref ->\t\t\t" << rStr << std::endl;
	return (0);
}