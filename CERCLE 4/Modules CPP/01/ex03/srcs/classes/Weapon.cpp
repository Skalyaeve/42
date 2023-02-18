#include "../../includes/classes/Weapon.hpp"

Weapon::Weapon() :
type( "UNDEFINED" )
{
}

Weapon::Weapon( const std::string& str ) :
type( str )
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType( void ) const
{
	return this->type;
}

void Weapon::setType( const std::string& str )
{
	this->type = str;
}