#include "../../includes/classes/Zombie.hpp"

Zombie::Zombie() :
name( "UNDEFINED" )
{
}

Zombie::Zombie( const std::string& name ) :
name( name )
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