#include "../../includes/classes/Animal.hpp"

Animal::Animal() :
type( "UNDEFINED" )
{
	std::cout << "[ DEFAULT ][ " << this << " ] Animal constructor called" << std::endl;
}

Animal::Animal( const Animal& src ) :
type( src.getType() )
{
	std::cout << "[ COPY ][ " << this << " ] Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "[ " << this << " ] Animal destructor called" << std::endl;
}

Animal& Animal::operator=( const Animal& src )
{
	std::cout << "[ " << this << " ] Animal copy assignment operator called" << std::endl;
	this->type = src.getType();
	return *this;
}

Brain* Animal::getBrain( void ) const
{
	return NULL;
}

const std::string& Animal::getType( void ) const
{
	std::cout << "[ " << this << " ][ getType ] Animal member function called" << std::endl;
	return this->type;
}

void Animal::makeSound( void ) const
{
	std::cout << "[ " << this << " ][ makeSound ] Animal member function called" << std::endl;
	std::cout << "* UNDEFINED SOUND *" << std::endl;
}

