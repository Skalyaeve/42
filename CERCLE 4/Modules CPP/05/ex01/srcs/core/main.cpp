#include "../../includes/header.hpp"

int main( void )
{
	Bureaucrat	msk1( "Miskine", 1 );
	Bureaucrat	msk2( "Miskine", 150 );
	Form		form1( "a", 149, 149 );
	Form		form2( "b", 150, 150 );

	std::cout << std::endl;
	std::cout << "[ " << &form1 << " ]" << form1;
	std::cout << "[ " << &form2 << " ]" << form2;

	std::cout << std::endl;
	std::cout << msk2.getName() << " tranna sign [ " << &form1 << " ][ " << form1.getName() << " ] :" << std::endl;
	msk2.signForm( form1 );
	std::cout << msk2.getName() << " tranna sign [ " << &form2 << " ][ " << form2.getName() << " ] :" << std::endl;
	msk2.signForm( form2 );
	std::cout << msk2.getName() << " tranna sign [ " << &form2 << " ][ " << form2.getName() << " ] :" << std::endl;
	msk2.signForm( form2 );

	std::cout << std::endl;
	std::cout << "[ " << &form1 << " ]" << form1;
	std::cout << "[ " << &form2 << " ]" << form2;

	std::cout << std::endl;
	std::cout << msk1.getName() << " tranna sign [ " << &form1 << " ][ " << form1.getName() << " ] :" << std::endl;
	msk1.signForm( form1 );
	std::cout << msk1.getName() << " tranna sign [ " << &form1 << " ][ " << form1.getName() << " ] :" << std::endl;
	msk1.signForm( form1 );
	std::cout << msk1.getName() << " tranna sign [ " << &form2 << " ][ " << form2.getName() << " ] :" << std::endl;
	msk1.signForm( form2 );

	std::cout << std::endl;
	std::cout << "[ " << &form1 << " ]" << form1;
	std::cout << "[ " << &form2 << " ]" << form2;
	std::cout << std::endl;

	return 0;
}
