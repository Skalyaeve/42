#include "../../includes/classes/Brain.hpp"

Brain::Brain()
{
	std::cout << "[ DEFAULT ][ " << this << " ] Brain constructor called" << std::endl;
	for ( short i = 0; i < 100; i++ )
		this->ideas[ i ] = "UNSET IDEA";
}

Brain::Brain( const Brain& src )
{
	std::cout << "[ COPY ][ " << this << " ] Brain constructor called" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "[ " << this << " ] Brain destructor called" << std::endl;
}

Brain& Brain::operator=( const Brain& src )
{
	std::cout << "[ " << this << " ] Brain copy assignment operator called" << std::endl;
	for ( short i = 0; i < 100; i++ )
		this->ideas[ i ] = src.getIdea( i );
	return *this;
}

const std::string& Brain::getIdea( const int& index ) const
{
	std::cout << "[ " << this << " ][ getIdea ] Brain member function called" << std::endl;
	if ( index < 0 || index > 99 )
	{
		std::cout << "[ ERROR ] : Ideas range is 0 - 99, returning value of index 0" << std::endl;
		return this->ideas[ 0 ];
	}
	return this->ideas[ index ];
}

void Brain::setIdea( const int& index, const std::string& str )
{
	std::cout << "[ " << this << " ][ setIdea ] Brain member function called" << std::endl;
	if ( index < 0 || index > 99 )
		std::cout << "[ ERROR ] : Ideas range is 0 - 99" << std::endl;
	else
		this->ideas[ index ] = str;
}
