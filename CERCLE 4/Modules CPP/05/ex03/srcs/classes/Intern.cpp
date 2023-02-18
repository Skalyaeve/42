#include "../../includes/classes/Intern.hpp"

Intern::Intern()
{
	std::cout << "[ DEFAULT ][ " << this << " ] Intern constructor called" << std::endl;
	formType[ 0 ] = new PresidentialPardonForm( "<input form's target here>" );
	formType[ 1 ] = new RobotomyRequestForm( "<input form's target here>" );
	formType[ 2 ] = new ShrubberyCreationForm( "<input form's target here>" );
}

Intern::Intern( const Intern& src )
{
	std::cout << "[ COPY ][ " << this << " ] Intern constructor called" << std::endl;
	formType[ 0 ] = new PresidentialPardonForm( "<input form's target here>" );
	formType[ 1 ] = new RobotomyRequestForm( "<input form's target here>" );
	formType[ 2 ] = new ShrubberyCreationForm( "<input form's target here>" );
	( void )src;
}

Intern::~Intern()
{
	std::cout << "[ " << this << " ] Intern destructor called" << std::endl;
	delete formType[ 0 ];
	delete formType[ 1 ];
	delete formType[ 2 ];
}

Intern& Intern::operator=( const Intern& src )
{
	std::cout << "[ " << this << " ] Intern copy assignment operator called" << std::endl;
	( void )src;
	return *this;
}

AForm*	Intern::makeForm( const std::string& name, const std::string& target ) const
{
	AForm*	form = NULL;
	const std::string	type[ 3 ] = { "presidential pardon", "robotomy request", "shrubbery creation" };

	try
	{
		for ( int i = 0; i < 3; i++ )
			if ( !name.compare( type[ i ] ) )
				form = this->formType[ i ]->photocopie( target );
		if ( form )
			std::cout << "[ " << this << " ] Intern created [ " << form << " ] " << form->getName() << ", target is " << form->getTarget() << std::endl;
		else
			throw Intern::UnknowType();
	}
	catch ( const std::exception& e )
	{
		std::cerr << "[ " << this << " ][ ERROR ] : making new form -> " << e.what() << ", can't make form" << std::endl;
	}
	return form;
}
