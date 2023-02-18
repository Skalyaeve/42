#include "../../includes/classes/HumanB.hpp"


HumanB::HumanB() :
name( "UNDEFINED" ), mainWeapon( NULL )
{
}

HumanB::HumanB( const std::string& name ) :
name( name ), mainWeapon( NULL )
{
}

HumanB::HumanB( const std::string& name, Weapon& mainWeapon ) :
name( name ), mainWeapon( &mainWeapon )
{
}

HumanB::~HumanB()
{
}

const std::string& HumanB::getName( void ) const
{
	return this->name;
}

void HumanB::attack( void ) const
{
	if ( this->mainWeapon )
		std::cout << this->name << " attacks with their " << this->mainWeapon->getType() << "." << std::endl;
	else
		std::cout << this->name << " attacks with their hands." << std::endl;
}

void HumanB::setWeapon( Weapon& mainWeapon )
{
	this->mainWeapon = &mainWeapon;
}