#include "../../includes/classes/AAnimal.hpp"

AAnimal::AAnimal() :
type( "UNDEFINED" )
{
	std::cout << "[ DEFAULT ][ " << this << " ] AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal& src ) :
type( src.getType() )
{
	std::cout << "[ COPY ][ " << this << " ] AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "[ " << this << " ] AAnimal destructor called" << std::endl;
}

AAnimal& AAnimal::operator=( const AAnimal& src )
{
	std::cout << "[ " << this << " ] AAnimal copy assignment operator called" << std::endl;
	this->type = src.getType();
	return *this;
}

Brain* AAnimal::getBrain( void ) const
{
	return NULL;
}

const std::string& AAnimal::getType( void ) const
{
	std::cout << "[ " << this << " ][ getType ] AAnimal member function called" << std::endl;
	return this->type;
}

void AAnimal::makeSound( void ) const
{
	std::cout << "[ " << this << " ][ makeSound ] AAnimal member function called" << std::endl;
	std::cout << "* UNDEFINED SOUND *" << std::endl;
}

