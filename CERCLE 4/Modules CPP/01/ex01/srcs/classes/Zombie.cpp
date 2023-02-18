#include "../../includes/classes/Zombie.hpp"

Zombie::Zombie() :
name( "UNDEFINED" )
{
	std::cout << "Unamed zombie created." << std::endl;
}

Zombie::Zombie( const std::string& str ) :
name( str )
{
	std::cout << "Zombie [ " << this->name << " ] created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie [ " << this->name << " ] destroyed." << std::endl;
}

void Zombie::announce( void ) const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

const std::string& Zombie::getName( void ) const
{
	return this->name;
}

void Zombie::setName( const std::string& str )
{
	this->name = str;
}
