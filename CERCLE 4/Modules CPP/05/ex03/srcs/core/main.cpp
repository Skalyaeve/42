#include "../../includes/header.hpp"

int main( void )
{
	Intern		msk;
	AForm*		newForm;

	std::cout << std::endl;
	std::cout << "Intern tranna make presidential pardon form" << std::endl;
	newForm = msk.makeForm( "presidential pardon", "targetA");
	if ( newForm )
	{
		std::cout << "[ " << newForm << " ]" << *newForm << std::endl;
		delete newForm;
	}

	std::cout << std::endl;
	std::cout << "Intern tranna make robotomy request form" << std::endl;
	newForm = msk.makeForm( "robotomy request", "targetB");
	if ( newForm )
	{
		std::cout << "[ " << newForm << " ]" << *newForm << std::endl;
		delete newForm;
	}

	std::cout << std::endl;
	std::cout << "Intern tranna make shrubbery creation form" << std::endl;
	newForm = msk.makeForm( "shrubbery creation", "targetC");
	if ( newForm )
	{
		std::cout << "[ " << newForm << " ]" << *newForm << std::endl;
		delete newForm;
	}

	std::cout << std::endl;
	std::cout << "Intern tranna make undefined form" << std::endl;
	newForm = msk.makeForm( "undefined", "targetD");
	if ( newForm )
	{
		std::cout << "[ " << newForm << " ]" << *newForm << std::endl;
		delete newForm;
	}
	std::cout << std::endl;

	return 0;
}
