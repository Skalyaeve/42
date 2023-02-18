#include "../../includes/classes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm::AForm( "PresidentialPardonForm", "UNDEFINED", 25, 5 )
{
	std::cout << "[ DEFAULT ][ " << this << " ] PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& src ) :
	AForm::AForm( src )
{
	std::cout << "[ COPY ][ " << this << " ] PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string& str ) :
	AForm::AForm( "PresidentialPardonForm", str, 25, 5 )
{
	std::cout << "[ " << str << " ][ " << this << " ] PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[ " << this << " ] PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& src )
{
	std::cout << "[ " << this << " ] PresidentialPardonForm copy assignment operator called" << std::endl;
	this->setSgrade( src.getSgrade() );
	this->setEgrade( src.getEgrade() );
	this->setSignature( src.checkSignature() );
	this->setExecuteState( src.checkExec() );
	return *this;
}

const std::string PresidentialPardonForm::execute( const Bureaucrat& brc )
{
	const std::string ret = AForm::execute( brc );
	if ( ret != "done" )
		return ret;
	std::cout << "Zaphod Beeblebrox forgave " << this->getTarget() << std::endl;
	return ret;
}

PresidentialPardonForm* PresidentialPardonForm::photocopie( const std::string& str ) const
{
	return new PresidentialPardonForm( str );
}
