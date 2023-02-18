#include "../../includes/header.hpp"

int main( int ac, char **av )
{
	if ( ac != 3 )
	{
		std::cout << "Usage : ./ZombiezHorde [ nbrOfZombies ] [ name ]" << std::endl;
		return -1;
	}

	int				index = -1;
	const int		zombiesCount = atoi( av[ 1 ] );
	const Zombie*	zombies = zombieHorde( zombiesCount, av[ 2 ] );

	if ( !zombies )
		return 1;
	while ( ++index < zombiesCount )
	{
		std::cout << "Zombie #" << index + 1 << " -> [ " << &zombies[ index ]
			<< " ] named [ " << zombies[ index ].getName() << " ] exist." << std::endl;
		zombies[ index ].announce();
		if ( index + 1 != zombiesCount )
			std::cout << std::endl;
	}
	if ( zombies )
	{
		std::cout << std::endl;
		delete[] zombies;
	}
	return 0;
}