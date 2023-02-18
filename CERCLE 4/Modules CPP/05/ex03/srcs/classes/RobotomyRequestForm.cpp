#include "../../includes/classes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm::AForm( "RobotomyRequestForm", "UNDEFINED", 72, 45 )
{
	std::cout << "[ DEFAULT ][ " << this << " ] RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& src ) :
	AForm::AForm( src )
{
	std::cout << "[ COPY ][ " << this << " ] RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string& str ) :
	AForm::AForm( "RobotomyRequestForm", str, 72, 45 )
{
	std::cout << "[ " << str << " ][ " << this << " ] RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[ " << this << " ] RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& src )
{
	std::cout << "[ " << this << " ] RobotomyRequestForm copy assignment operator called" << std::endl;
	this->setSgrade( src.getSgrade() );
	this->setEgrade( src.getEgrade() );
	this->setSignature( src.checkSignature() );
	this->setExecuteState( src.checkExec() );
	return *this;
}

const std::string RobotomyRequestForm::execute( const Bureaucrat& brc )
{
	const std::string ret = AForm::execute( brc );
	if ( ret != "done" )
		return ret;

	std::cout << "[ " << this << " ] * DRILL NOISES *" << std::endl;
	srand( time( NULL ) );
	if ( rand() % 2 )
		std::cout << "[ " << this << " ] " << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << "[ " << this << " ] operation failed" << std::endl;
	return ret;
}

RobotomyRequestForm* RobotomyRequestForm::photocopie( const std::string& str ) const
{
	return new RobotomyRequestForm( str );
}
