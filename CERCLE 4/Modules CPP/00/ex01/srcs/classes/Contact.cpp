#include "../../includes/classes/Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setValue( const int value, const std::string& str )
{
	if ( value == 1 )
		this->firstName = str;
	if ( value == 2 )
		this->lastName = str;
	if ( value == 3 )
		this->nickname = str;
	if ( value == 4 )
		this->phoneNumber = str;
	if ( value == 5 )
		this->darkestSecret = str;
}

const std::string& Contact::getValue( const int value ) const
{
	if ( value == 1 )
		return this->firstName;
	if ( value == 2 )
		return this->lastName;
	if ( value == 3 )
		return this->nickname;
	if ( value == 4 )
		return this->phoneNumber;
	return this->darkestSecret;
}