#include "../../includes/classes/Dog.hpp"

Dog::Dog() :
	Animal::Animal()
{
	std::cout << "[ DEFAULT ][ " << this << " ] Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog( const Dog& src ) :
	Animal::Animal( src )
{
	std::cout << "[ COPY ][ " << this << " ] Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "[ " << this << " ] Dog destructor called" << std::endl;
}

Dog& Dog::operator=( const Dog& src )
{
	std::cout << "[ " << this << " ] Dog copy assignment operator called" << std::endl;
	this->type = src.getType();
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "[ " << this << " ][ makeSound ] Dog member function called" << std::endl;
	std::cout << "Wuf" << std::endl;
}
