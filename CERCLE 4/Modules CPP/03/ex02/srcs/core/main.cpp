#include "../../includes/header.hpp"

int main( void )
{
	FragTrap	a( "Naroto" );
	ScavTrap	b( "Susuké" );
	std::cout << std::endl;

	a.highFivesGuys();
	b.guardGate();
	std::cout << std::endl;

	srand( time( NULL ) );
	while ( a.getEnergy() > 0 || b.getEnergy() > 0 )
	{
		int	aRand = rand();
		int	bRand = rand();
		if ( aRand > bRand )
		{
			if ( a.getHP() <= b.getAD() && rand() % 2 )
			{
				a.beRepaired( a.getAD() );
				std::cout << std::endl;
			}
			else
			{
				if ( a.getEnergy() > 0 )
				{
					a.attack( b.getName() );
					b.takeDamage( a.getAD() );
				}
				else
					a.attack( b.getName() );
				std::cout << std::endl;
			}
		}
		else if( bRand > aRand )
		{
			if ( b.getHP() <= a.getAD() && rand() % 2 )
			{
				b.beRepaired( b.getAD() );
				std::cout << std::endl;
			}
			else
			{
				if ( b.getEnergy() > 0 )
				{
					b.attack( a.getName() );
					a.takeDamage( b.getAD() );
				}
				else
					b.attack( a.getName() );
				std::cout << std::endl;
			}
		}

		if ( a.getHP() <= 0 || b.getHP() <= 0 )
		{
			if ( a.getHP() <= 0 )
				std::cout << "[ " << b.getName() << " ] beated [ " << a.getName() << " ]." << std::endl;
			else
				std::cout << "[ " << a.getName() << " ] beated [ " << b.getName() << " ]." << std::endl;
			std::cout << std::endl;
			break ;
		}
	}

	if ( a.getHP() > 0 && b.getHP() > 0 )
	{
		std::cout << "No winner today." << std::endl;
		std::cout << std::endl;
	}
	std::cout << "Well done Heroes !" << std::endl;
	std::cout << std::endl;

	return 0;
}
