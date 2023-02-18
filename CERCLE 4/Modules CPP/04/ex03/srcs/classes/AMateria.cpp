#include "../../includes/classes/AMateria.hpp"

AMateria::AMateria() :
type( "UNDEFINED" )
{
	std::cout << "[ DEFAULT ][ " << this << " ] AMateria constructor called" << std::endl;
}

AMateria::AMateria( const std::string& str ) :
type( str )
{
	std::cout << "[ " << str << " ][ " << this << " ] AMateria constructor called" << std::endl;
}

AMateria::AMateria( const AMateria& src ) :
type( src.getType() )
{
	std::cout << "[ COPY ][ " << this << " ] AMateria constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "[ " << this << " ] AMateria destructor called" << std::endl;
}

AMateria& AMateria::operator=( const AMateria& src )
{
	std::cout << "[ " << this << " ] AMateria copy assignment operator called" << std::endl;
	( void )src;
	return *this;
}

const std::string& AMateria::getType( void ) const
{
	return this->type;
}

void AMateria::use( const ICharacter& target )
{
	std::cout << "* shoots an UNDEFINED MATERIA at " << target.getName() << " *" << std::endl;
}