#include "../../includes/classes/MateriaCure.hpp"

MateriaCure::MateriaCure() :
AMateria::AMateria( "cure" )
{
	std::cout << "[ DEFAULT ][ " << this << " ] MateriaCure constructor called" << std::endl;
}

MateriaCure::MateriaCure( const MateriaCure& src ) :
AMateria::AMateria( src )
{
	std::cout << "[ COPY ][ " << this << " ] MateriaCure constructor called" << std::endl;
}

MateriaCure::~MateriaCure()
{
	std::cout << "[ " << this << " ] MateriaCure destructor called" << std::endl;
}

MateriaCure& MateriaCure::operator=( const MateriaCure& src )
{
	std::cout << "[ " << this << " ] MateriaCure copy assignment operator called" << std::endl;
	( void )src;
	return *this;
}

MateriaCure* MateriaCure::clone( void ) const
{
	return new MateriaCure( *this );
}

void MateriaCure::use( const ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}