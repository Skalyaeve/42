#include "../../includes/classes/HumanA.hpp"

HumanA::HumanA( const std::string& name, Weapon& mainWeapon ) :
name( name ), mainWeapon( mainWeapon )
{
}

HumanA::~HumanA()
{
}

const std::string&	HumanA::getName( void ) const
{
	return this->name;
}

void HumanA::attack( void ) const
{
	std::cout << this->name << " attacks with " << this->mainWeapon.getType() << std::endl;
}

void HumanA::setWeapon( Weapon& mainWeapon )
{
	this->mainWeapon = mainWeapon;
}