#include "../../includes/header.hpp"

int main( int ac, char **av )
{
	int			index = 0;
	Zombie*		zombies = NULL;
	std::string	name;

	if ( ac == 1 )
	{
		std::cout << "Usage: ./Zombiez [ zombie1 ] [ zombie2 ] [ ... ]" << std::endl;
		return 0;
	}
	while ( ++index < ac )
	{
		name = av[ index ];
		if ( index % 2 )
			randomChump( name );
		else
		{
			zombies = newZombie( name );
			if ( !zombies )
			{
				std::cout << "Alloc failed, exiting simulation..." << std::endl;
				break ;
			}
			std::cout << "Zombie [ " << zombies
				<< " ] dynamically allocated ( pointed by [ " << &zombies << " ] )" << std::endl
				<< "\tis now being used in this string, you can call him [ " << zombies->getName()
				<< " ]." << std::endl << "It will now be deleted." << std::endl;
			delete ( zombies );
			zombies = NULL;
		}
		if ( index + 1 != ac )
			std::cout << std::endl;
	}
	if ( zombies )
		delete zombies;
	return 0;
}