#include "../../includes/header.hpp"

int main( void )
{
	Bureaucrat				msk1( "Miskine1", 1 );
	Bureaucrat				msk2( "Miskine2", 150 );
	ShrubberyCreationForm	form1( "targetA" );
	PresidentialPardonForm	form2( "targetB" );
	RobotomyRequestForm		form3( "targetC" );

	std::cout << std::endl;
	std::cout << "[ " << &form1 << " ]" << form1;
	std::cout << "[ " << &form2 << " ]" << form2;
	std::cout << "[ " << &form3 << " ]" << form3;

	std::cout << std::endl;
	std::cout << msk1.getName() << " tranna sign [ " << &form1 << " ] :" << std::endl;
	msk1.signForm( form1 );
	std::cout << msk1.getName() << " tranna sign [ " << &form2 << " ] :" << std::endl;
	msk1.signForm( form2 );
	std::cout << msk1.getName() << " tranna sign [ " << &form3 << " ] :" << std::endl;
	msk1.signForm( form3 );

	std::cout << std::endl;
	std::cout << "[ " << &form1 << " ]" << form1;
	std::cout << "[ " << &form2 << " ]" << form2;
	std::cout << "[ " << &form3 << " ]" << form3;

	std::cout << std::endl;
	std::cout << msk2.getName() << " tranna execute [ " << &form1 << " ] :" << std::endl;
	msk2.executeForm( form1 );
	std::cout << msk2.getName() << " tranna execute [ " << &form2 << " ] :" << std::endl;
	msk2.executeForm( form2 );
	std::cout << msk2.getName() << " tranna execute [ " << &form3 << " ] :" << std::endl;
	msk2.executeForm( form3 );

	std::cout << std::endl;
	std::cout << "[ " << &form1 << " ]" << form1;
	std::cout << "[ " << &form2 << " ]" << form2;
	std::cout << "[ " << &form3 << " ]" << form3;

	std::cout << std::endl;
	std::cout << msk1.getName() << " tranna execute [ " << &form1 << " ] :" << std::endl;
	msk1.executeForm( form1 );
	std::cout << msk1.getName() << " tranna execute [ " << &form2 << " ] :" << std::endl;
	msk1.executeForm( form2 );
	std::cout << msk1.getName() << " tranna execute [ " << &form3 << " ] :" << std::endl;
	msk1.executeForm( form3 );

	std::cout << std::endl;
	std::cout << "[ " << &form1 << " ]" << form1;
	std::cout << "[ " << &form2 << " ]" << form2;
	std::cout << "[ " << &form3 << " ]" << form3;
	std::cout << std::endl;
	
	return 0;
}
