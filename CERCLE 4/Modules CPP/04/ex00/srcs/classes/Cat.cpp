#include "../../includes/classes/Cat.hpp"

Cat::Cat() :
	Animal::Animal()
{
	std::cout << "[ DEFAULT ][ " << this << " ] Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat( const Cat& src ) :
	Animal::Animal( src )
{
	std::cout << "[ COPY ][ " << this << " ] Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "[ " << this << " ] Cat destructor called" << std::endl;
}

Cat& Cat::operator=( const Cat& src )
{
	std::cout << "[ " << this << " ] Cat copy assignment operator called" << std::endl;
	this->type = src.getType();
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << "[ " << this << " ][ makeSound ] Cat member function called" << std::endl;
	std::cout << "Mew" << std::endl;
}
