#include "../../includes/classes/PhoneBook.hpp"

PhoneBook::PhoneBook() : count( 0 )
{
}

PhoneBook::~PhoneBook()
{
}

Contact& PhoneBook::getMember( const int index )
{
	return this->members[ index ];
}

const int& PhoneBook::showCount( void ) const
{
	return this->count;
}

void	PhoneBook::updateCount( void )
{
	this->count++;
	if ( this->count > 8 )
		this->count = 8;
}