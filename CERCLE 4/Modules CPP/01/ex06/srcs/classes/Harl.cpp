#include "../../includes/classes/Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain( const std::string str, const int iterations ) const
{
	void				( Harl::*level[ 4 ] )() const = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	const std::string	ref[ 4 ] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	if ( iterations == 4 )
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}
	switch ( str.compare( ref[ iterations ] ) )
	{
		case ( 0 ) :
		{
			for ( int i = iterations; i < 4; i++ )
			{
				( this->*( level[ i ] ) )();
				if ( i < 3 )
					std::cout << std::endl;
			}
			break ;
		}
		default : this->complain( str, iterations + 1 );
	}
}

void Harl::debug( void ) const
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) const
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) const
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) const
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
}