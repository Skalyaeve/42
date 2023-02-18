#include "../../includes/classes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm::AForm( "ShrubberyCreationForm", "UNDEFINED", 145, 137 )
{
	std::cout << "[ DEFAULT ][ " << this << " ] ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) :
	AForm::AForm( src )
{
	std::cout << "[ COPY ][ " << this << " ] ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& str ) :
	AForm::AForm( "ShrubberyCreationForm", str, 145, 137 )
{
	std::cout << "[ " << str << " ][ " << this << " ] ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ " << this << " ] ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& src )
{
	std::cout << "[ " << this << " ] ShrubberyCreationForm copy assignment operator called" << std::endl;
	this->setSgrade( src.getSgrade() );
	this->setEgrade( src.getEgrade() );
	this->setSignature( src.checkSignature() );
	this->setExecuteState( src.checkExec() );
	return *this;
}

const std::string ShrubberyCreationForm::execute( const Bureaucrat& brc )
{
	const std::string ret = AForm::execute( brc );
	if ( ret != "done" )
		return ret;
	
	std::string		filename;
	filename += this->getTarget();
	filename += "_shrubbery";

	std::ofstream	file( filename.c_str() );
	file << "     a     " << std::endl;
	file << "    bbb    " << std::endl;
	file << "   ccccc   " << std::endl;
	file << "  ddddddd  " << std::endl;
	file << " eeeeeeeee " << std::endl;
	file << "fffffffffff" << std::endl;
	file << "     g     " << std::endl;
	file << "     hh    " << std::endl;

	file.close();

	return ret;
}

ShrubberyCreationForm* ShrubberyCreationForm::photocopie( const std::string& str ) const
{
	return new ShrubberyCreationForm( str );
}
