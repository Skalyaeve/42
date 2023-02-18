#include "../../includes/classes/Cat.hpp"

Cat::Cat() :
	AAnimal::AAnimal(),
brain( new Brain() )
{
	std::cout << "[ DEFAULT ][ " << this << " ] Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat( const Cat& src ) :
	AAnimal::AAnimal( src ),
brain( src.getBrain() )
{
	std::cout << "[ COPY ][ " << this << " ] Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "[ " << this << " ] Cat destructor called" << std::endl;
	delete this->brain;
}

Cat& Cat::operator=( const Cat& src )
{
	std::cout << "[ " << this << " ] Cat copy assignment operator called" << std::endl;
	this->type = src.getType();
	*( this->brain ) = *( src.getBrain() );
	return *this;
}

Brain* Cat::getBrain( void ) const
{
	return this->brain;
}

void Cat::makeSound( void ) const
{
	std::cout << "[ " << this << " ][ makeSound ] Cat member function called" << std::endl;
	std::cout << "Mew" << std::endl;
}
