#include "../../includes/classes/MateriaIce.hpp"

MateriaIce::MateriaIce() :
AMateria::AMateria( "ice" )
{
	std::cout << "[ DEFAULT ][ " << this << " ] MateriaIce constructor called" << std::endl;
}

MateriaIce::MateriaIce( const MateriaIce& src ) :
AMateria::AMateria( src )
{
	std::cout << "[ COPY ][ " << this << " ] MateriaIce constructor called" << std::endl;
}

MateriaIce::~MateriaIce()
{
	std::cout << "[ " << this << " ] MateriaIce destructor called" << std::endl;
}

MateriaIce& MateriaIce::operator=( const MateriaIce& src )
{
	std::cout << "[ " << this << " ] MateriaIce copy assignment operator called" << std::endl;
	( void )src;
	return *this;
}

MateriaIce* MateriaIce::clone( void ) const
{
	return new MateriaIce( *this );
}

void MateriaIce::use( const ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}