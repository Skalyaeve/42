#include "../../includes/classes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :
type( "UNDEFINED" )
{
	std::cout << "[ DEFAULT ][ " << this << " ] WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& src ) :
type( src.getType() )
{
	std::cout << "[ COPY ][ " << this << " ] WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[ " << this << " ] WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& src )
{
	std::cout << "[ " << this << " ] WrongAnimal copy assignment operator called" << std::endl;
	this->type = src.getType();
	return *this;
}

const std::string& WrongAnimal::getType( void ) const
{
	std::cout << "[ " << this << " ][ getType ] WrongAnimal member function called" << std::endl;
	return this->type;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "[ " << this << " ][ makeSound ] WrongAnimal member function called" << std::endl;
	std::cout << "* UNDEFINED SOUND *" << std::endl;
}
