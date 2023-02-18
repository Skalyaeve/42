#include "../../includes/classes/WrongCat.hpp"

WrongCat::WrongCat() :
	WrongAnimal::WrongAnimal()
{
	std::cout << "[ DEFAULT ][ " << this << " ] WrongCat constructor called" << std::endl;
	this->type = "Cat";
}

WrongCat::WrongCat( const WrongCat& src ) :
	WrongAnimal::WrongAnimal( src )
{
	std::cout << "[ COPY ][ " << this << " ] WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "[ " << this << " ] WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat& src )
{
	std::cout << "[ " << this << " ] WrongCat copy assignment operator called" << std::endl;
	this->type = src.getType();
	return *this;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "[ " << this << " ][ makeSound ] WrongCat member function called" << std::endl;
	std::cout << "Mew" << std::endl;
}
