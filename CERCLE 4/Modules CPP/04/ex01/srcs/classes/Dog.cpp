#include "../../includes/classes/Dog.hpp"

Dog::Dog() :
	Animal::Animal(),
brain( new Brain() )
{
	std::cout << "[ DEFAULT ][ " << this << " ] Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog( const Dog& src ) :
	Animal::Animal( src ),
brain( src.getBrain() )
{
	std::cout << "[ COPY ][ " << this << " ] Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "[ " << this << " ] Dog destructor called" << std::endl;
	delete this->brain;
}

Dog& Dog::operator=( const Dog& src )
{
	std::cout << "[ " << this << " ] Dog copy assignment operator called" << std::endl;
	this->type = src.getType();
	this->brain = src.getBrain();
	return *this;
}

Brain* Dog::getBrain( void ) const
{
	return this->brain;
}

void Dog::makeSound( void ) const
{
	std::cout << "[ " << this << " ][ makeSound ] Dog member function called" << std::endl;
	std::cout << "Wuf" << std::endl;
}
