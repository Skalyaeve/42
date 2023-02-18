#include "../../includes/header.hpp"

Zombie*	zombieHorde( const int& n, const std::string& name )
{
	if ( n > 0 )
	{
		Zombie*	zombies = NULL;
		try
		{
			zombies = new Zombie[ n ];
		}
		catch( const std::exception& e )
		{
			std::cerr << "[ ERROR ] Fatal -> " << e.what() << '\n';
		}
		if ( !zombies )
			return NULL;
	
		std::cout << std::endl;
		int	index = -1;
		while ( ++index < n )
		{
			std::cout << "Giving name [ " <<  name  << " ] to Zombie #" << index + 1
				<< " [ " << &zombies[ index ] << " ]." << std::endl;
			zombies[ index ].setName( name );
		}
		std::cout << std::endl;
		return zombies;
	}
	return NULL;
}